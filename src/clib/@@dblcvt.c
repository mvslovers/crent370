/* @@DBLCVT.C */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <ctype.h>
#include <errno.h>
#include <float.h>
#include <limits.h>
#include <stddef.h>

void
__dblcvt(double num, char cnvtype, size_t nwidth, int nprecision, char *result)
{
    double b,round;
    int i,j,exp,pdigits,format;
    char sign, work[125];

    /* save original data & set sign */
    if ( num < 0 ) {
        b = -num;
        sign = '-';
    }
    else {
        b = num;
        sign = ' ';
    }

    /*
      Now scale to get exponent
    */
    exp = 0;
    if( b > 1.0 ) {
        while ((b >= 10.0) && (exp < 120)) {
            ++exp;
            b=b / 10.0;
        }
    }
    else if ( b == 0.0 ) {
        exp=0;
    }
    /* 1.0 will get exp = 0 */
    else if ( b < 1.0 ) {
        while ((b < 1.0) && (exp > -120)) {
            --exp;
            b=b*10.0;
        }
    }

    if ((exp <= -120) || (exp >= 120)) {
        exp = 0;
        b = 0.0;
    }

    /*
      now decide how to print and save in FORMAT.
         -1 => we need leading digits
          0 => print in exp
         +1 => we have digits before dp.
    */
    switch (cnvtype) {
        case 'E':
        case 'e':
            format = 0;
            break;
        case 'f':
        case 'F':
            if ( exp >= 0 ) {
                format = 1;
            }
            else {
                format = -1;
            }
            break;
        default:
            /* Style e is used if the exponent from its
               conversion is less than -4 or greater than
               or equal to the precision.
            */
            if ( exp >= 0 ) {
                if ( nprecision > exp ) {
                    format=1;
                }
                else {
                    format=0;
                }
            }
            else {
                /*  if ( nprecision > (-(exp+1) ) ) { */
                if ( exp >= -4) {
                    format=-1;
                }
                else {
                    format=0;
                }
            }
            break;
    }

    /*
    Now round
    */
    switch (format) {
        case 0:    /* we are printing in standard form */
            if (nprecision < DBL_MANT_DIG) /* we need to round */ {
                j = nprecision;
            }
            else {
                j=DBL_MANT_DIG;
            }

            round = 1.0/2.0;
            i = 0;
            while (++i <= j) {
                round = round/10.0;
            }
            b = b + round;
            if (b >= 10.0) {
                b = b/10.0;
                exp = exp + 1;
            }
            break;

        case 1:      /* we have a number > 1  */
                         /* need to round at the exp + nprecisionth digit */
            if (exp + nprecision < DBL_MANT_DIG) /* we need to round */ {
                j = exp + nprecision;
            }
            else {
                j = DBL_MANT_DIG;
            }

            round = 0.5;
            i = 0;
            while (i++ < j) {
                round = round/10;
            }

            b = b + round;
            if (b >= 10.0) {
                b = b/10.0;
                exp = exp + 1;
            }
            break;

        case -1:   /* we have a number that starts 0.xxxx */
            if (nprecision < DBL_MANT_DIG) /* we need to round */ {
                j = nprecision + exp + 1;
            }
            else {
                j = DBL_MANT_DIG;
            }

            round = 5.0;
            i = 0;
            while (i++ < j) {
                round = round/10;
            }

            if (j >= 0) {
                b = b + round;
            }

            if (b >= 10.0) {
                b = b/10.0;
                exp = exp + 1;
            }

            if (exp >= 0) {
                format = 1;
            }
            break;
    }

    /*
       Now extract the requisite number of digits
    */
    if (format==-1) {
        /*
             Number < 1.0 so we need to print the "0."
             and the leading zeros...
        */
        result[0]=sign;
        result[1]='0';
        result[2]='.';
        result[3]=0x00;
        while (++exp) {
            --nprecision;
            strcat(result,"0");
        }
        i=b;
        --nprecision;
        work[0] = (char)('0' + i % 10);
        work[1] = 0x00;
        strcat(result,work);

        pdigits = nprecision;

        while (pdigits-- > 0) {
            b = b - i;
            b = b * 10.0;
            i = b;
            work[0] = (char)('0' + i % 10);
            work[1] = 0x00;
            strcat(result,work);
        }
    }
    /*
       Number >= 1.0 just print the first digit
    */
    else if (format==+1) {
        i = b;
        result[0] = sign;
        result[1] = '\0';
        work[0] = (char)('0' + i % 10);
        work[1] = 0x00;
        strcat(result,work);
        nprecision = nprecision + exp;
        pdigits = nprecision ;

        while (pdigits-- > 0) {
            if ( ((nprecision-pdigits-1)==exp) ) {
                strcat(result,".");
            }
            b = b - i;
            b = b * 10.0;
            i = b;
            work[0] = (char)('0' + i % 10);
            work[1] = 0x00;
            strcat(result,work);
        }
    }
    /*
       printing in standard form
    */
    else {
        i = b;
        result[0] = sign;
        result[1] = '\0';
        work[0] = (char)('0' + i % 10);
        work[1] = 0x00;
        strcat(result,work);
        strcat(result,".");

        pdigits = nprecision;

        while (pdigits-- > 0) {
            b = b - i;
            b = b * 10.0;
            i = b;
            work[0] = (char)('0' + i % 10);
            work[1] = 0x00;
            strcat(result,work);
        }
    }

    if (format==0) { /* exp format - put exp on end */
        work[0] = 'E';
        if ( exp < 0 ) {
            exp = -exp;
            work[1]= '-';
        }
        else {
            work[1]= '+';
        }
        work[2] = (char)('0' + (exp/10) % 10);
        work[3] = (char)('0' + exp % 10);
        work[4] = 0x00;
        strcat(result, work);
    }
    else {
        /* get rid of trailing zeros for g specifier */
        if (cnvtype == 'G' || cnvtype == 'g') {
            char *p;

            p = strchr(result, '.');
            if (p != NULL) {
                p++;
                p = p + strlen(p) - 1;
                while (*p != '.' && *p == '0') {
                    *p = '\0';
                    p--;
                }
                if (*p == '.') {
                    *p = '\0';
                }
            }
        }
    }

    /* printf(" Final Answer = <%s> fprintf gives=%g\n",
                result,num); */
    /*
     do we need to pad
    */
    if(result[0] == ' ') {
        strcpy(work,result+1);
    }
    else {
        strcpy(work,result);
    }
    pdigits=nwidth-strlen(work);
    result[0]= 0x00;
    while(pdigits>0) {
        strcat(result," ");
        pdigits--;
    }
    strcat(result,work);
    return;
}

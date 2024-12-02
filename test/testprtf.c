#include <stdlib.h>
#include <stdio.h>
#include <clibprtf.h>

int main(int argc, char **argv)
{
    double  val     = 0.0;
    int i;

    printf_("%%f | %%20f | %%20.10f | %%13.10f | %%g | %%13.3g\n");
    for(i=0; i < 25; i++) {
        printf_("%f | %20f | %20.10f | %13.10f | %g | %13.3g\n", val, val, val, val, val, val);

        val += 1.1001;
    }

    return 0;
}

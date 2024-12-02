#define PDF_PRIVATE
#include "../pdf2/pdfi.h"

__asm__("\n&FUNC    SETC 'pdf_add_stream_text_mark'");
PDFSTREAM *pdf_add_stream_text_mark(PDF *pdf, PDFSTREAM *pdfstream, PDF_WATERMARK_STYLE style, const char *strokecolor, const char *fillcolor, unsigned fontsize, const char *font, const char *text)
{
    char buf[1024];

    if (!font) font = "/F0";
    if (!text) text = "";

    if (pdfstream) {
        /* character metrics */
        double   char_width = (double)0.6;
        /* box dimensions */
        double   crop_width = (double)pdf->cropw;   /* crop width */
        double   crop_height = (double)pdf->croph;  /* crop height */
        /* distance between LL and UR corners */
        double   distance_between = (double) sqrt( (double)(( pow(crop_width,2.0) ) + ( pow(crop_height,2.0) )) );
        /* ratios */
        double   ratio_width = distance_between / crop_width;
        double   ratio_height = distance_between / crop_height;
        /* slope */
        double   slope = (double) atan( (double)(crop_height / crop_width) );
        /* sine and cosine */
        double   slope_sine = (double) sin ( (double)slope );
        double   slope_cosine = (double) cos ( (double)slope );
        /* height of text rect */
        double   text_x = (double)(fontsize * -slope_sine);
        double   text_y = (double)(fontsize * slope_cosine);
        /* lower right X,Y of text rect */
        double   lower_left_x, lower_left_y;
        /* upper left X,Y of text rect */
        double   upper_left_x, upper_left_y;
        /* upper right X,Y of text rect */
        double   upper_right_x, upper_right_y;
        /* lower right X,Y of text rect */
        double   lower_right_x, lower_right_y;
        /* width of text rect */
        double   box_width;
        /* scaling factor */
        double   scaling_width, scaling_zoom;
        /* render mode */
        unsigned render_mode;


        /* lower right X,Y of text rect */
        if (crop_width < crop_height) {
            lower_left_x = (double)fabs( text_x );
            lower_left_y = ( fontsize / 2 ) * ratio_width - text_y;
        }
        else if ( crop_width > crop_height ) {
            lower_left_x = ( fontsize / 2 ) * ratio_height;
            lower_left_y = 0;
        }
        else {
            lower_left_x = (double)fabs( text_x );
            lower_left_y = 0;
        }

        /* upper left X,Y of text rect */
        upper_left_x = text_x + lower_left_x;
        upper_left_y = text_y + lower_left_y;

        /* upper right X,Y of text rect */
        upper_right_x = crop_width - lower_left_x;
        upper_right_y = crop_height - lower_left_y;

        /* lower right X,Y of text rect */
        lower_right_x = upper_right_x - text_x;
        lower_right_y = upper_right_y - text_y;

        /* width of text rect */
        box_width = (double)sqrt( ( pow((lower_right_x - lower_left_x),2.0) ) + ( pow((lower_right_y - lower_left_y),2.0) ) );

        /* scaling factor */
        scaling_width = (double)(strlen(text) * char_width);
        scaling_zoom = (double)((box_width / ( scaling_width * fontsize ) ) * 100);

        /* text X offset */
        text_x = lower_left_x + ( ( upper_left_x - lower_left_x ) / 2.0f );
        text_y = lower_left_y + ( ( upper_left_y - lower_left_y ) / 2.0f );
        distance_between  = (double)sqrt( ( pow(text_x,2.0f) ) + ( pow(text_y,2.0f) ) );

        if (pdf->options & PDF_OPTION_DEBUG) pdf_add_streamf(pdf, pdfstream, "\r\n%% watermark\r\n");

        /* draw bounding box */
        if (style == PDF_WATERMARK_TDBOXED) {
            pdf_add_streamf(pdf, pdfstream,
                "q 0 1 1 RG 0 %g m %g 0 l %g %g m %g %g l %g %g l %g %g l %g %g l s Q\r\n",
                crop_height, crop_width, lower_left_x, (double)( crop_height - lower_left_y ),
                upper_left_x, (double)( crop_height - upper_left_y ), upper_right_x,
                (double)( crop_height - upper_right_y ), lower_right_x, (double)( crop_height - lower_right_y ),
                lower_left_x, (double)( crop_height - lower_left_y ));
        }
        else if (style == PDF_WATERMARK_BUBOXED) {
            pdf_add_streamf(pdf, pdfstream,
                "q 0 1 1 RG 0 0 m %g %g l %g %g m %g %g l %g %g l %g %g l %g %g l s Q\r\n",
                crop_width, crop_height, lower_left_x, lower_left_y, upper_left_x, upper_left_y,
                upper_right_x, upper_right_y, lower_right_x, lower_right_y, lower_left_x, lower_left_y);
        }

        /* save graphic state */
        pdf_add_streamf(pdf, pdfstream, "q\r\n");

        /* start text object and set font, color, mode */
        pdf_add_streamf(pdf, pdfstream, "BT\r\n");

        /* text matrix */
        if (style == PDF_WATERMARK_TOPDOWN || style == PDF_WATERMARK_TDBOXED) {
            pdf_add_streamf(pdf, pdfstream, "%g %g %g %g 0 %g Tm\r\n",
                slope_cosine, -slope_sine, slope_sine, slope_cosine, crop_height);
        }
        else {
            pdf_add_streamf(pdf, pdfstream, "%g %g %g %g 0 0 Tm\r\n",
                slope_cosine, slope_sine, -slope_sine, slope_cosine);
        }

        /* font, displacement and zoom */
        pdf_add_streamf(pdf, pdfstream, "%s %u Tf\r\n", font, fontsize );
        pdf_add_streamf(pdf, pdfstream, "%g %g Td\r\n", distance_between, (double)(-.250 * fontsize));
        pdf_add_streamf(pdf, pdfstream, "%g Tz\r\n", scaling_zoom);

        /* color and mode */
        render_mode = 2;
        if (strokecolor) {
            const char *p = pdf_color_spec(pdf->colors, strokecolor, buf);

            if (p) strokecolor = p;

            pdf_add_streamf(pdf, pdfstream, "%s RG\r\n", strokecolor);
            if (!fillcolor) render_mode = 1;
        }

        if (fillcolor) {
            const char *p = pdf_color_spec(pdf->colors, fillcolor, buf);
            if (p) fillcolor = p;

            pdf_add_streamf(pdf, pdfstream, "%s rg\r\n", fillcolor);
            if (!strokecolor) render_mode = 0;
        }

        pdf_add_streamf(pdf, pdfstream, "%u Tr\r\n", render_mode);

        /* add the watermark text */
        pdf_add_streamf(pdf, pdfstream, "(%s)'\r\n", pdf_escape(text, buf));

        /* end text and restore graphics state */
        pdf_add_streamf(pdf, pdfstream, "ET\r\nQ\r\n");
    }

    return pdfstream;
}

#define PDF_PRIVATE
#include "clibpdfi.h"

static int find_128_encoding(char ch);
static int pdf_barcode_128a_ch(PDF *pdf, PDFO *page,
                               int x, int y, int width, int height,
                               unsigned colour, int index, int code_len);
static int pdf_add_barcode_128a(PDF *pdf, PDFO *page,
                                int x, int y, int width, int height,
                                const char *string, unsigned colour);
static int pdf_barcode_39_ch(PDF *pdf, PDFO *page,
                             int x, int y, int char_width, int height,
                             unsigned colour, char ch);
static int pdf_add_barcode_39(PDF *pdf, PDFO *page,
                              int x, int y, int width, int height,
                              const char *string, unsigned colour);

__asm__("\n&FUNC    SETC 'pdf_add_barcode'");
int pdf_add_barcode(PDF *pdf, PDFO *page, int code, int x, int y,
                    int width, int height, const char *string, unsigned colour)
{
    if (!string || !*string)
        return 0;

    switch (code) {
    case PDF_BARCODE_128A:
        return pdf_add_barcode_128a(pdf, page, x, y, width, height, string,
                                    colour);
    case PDF_BARCODE_39:
        return pdf_add_barcode_39(pdf, page, x, y, width, height, string,
                                  colour);
    default:
        return pdf_set_err(pdf, -EINVAL, "Invalid barcode code %d", code);
    }
}

static const struct {
    unsigned code;
    char ch;
} code_128a_encoding[] = {
    {0x212222, ' '},  {0x222122, '!'},  {0x222221, '"'},   {0x121223, '#'},
    {0x121322, '$'},  {0x131222, '%'},  {0x122213, '&'},   {0x122312, '\''},
    {0x132212, '('},  {0x221213, ')'},  {0x221312, '*'},   {0x231212, '+'},
    {0x112232, ','},  {0x122132, '-'},  {0x122231, '.'},   {0x113222, '/'},
    {0x123122, '0'},  {0x123221, '1'},  {0x223211, '2'},   {0x221132, '3'},
    {0x221231, '4'},  {0x213212, '5'},  {0x223112, '6'},   {0x312131, '7'},
    {0x311222, '8'},  {0x321122, '9'},  {0x321221, ':'},   {0x312212, ';'},
    {0x322112, '<'},  {0x322211, '='},  {0x212123, '>'},   {0x212321, '?'},
    {0x232121, '@'},  {0x111323, 'A'},  {0x131123, 'B'},   {0x131321, 'C'},
    {0x112313, 'D'},  {0x132113, 'E'},  {0x132311, 'F'},   {0x211313, 'G'},
    {0x231113, 'H'},  {0x231311, 'I'},  {0x112133, 'J'},   {0x112331, 'K'},
    {0x132131, 'L'},  {0x113123, 'M'},  {0x113321, 'N'},   {0x133121, 'O'},
    {0x313121, 'P'},  {0x211331, 'Q'},  {0x231131, 'R'},   {0x213113, 'S'},
    {0x213311, 'T'},  {0x213131, 'U'},  {0x311123, 'V'},   {0x311321, 'W'},
    {0x331121, 'X'},  {0x312113, 'Y'},  {0x312311, 'Z'},   {0x332111, '['},
    {0x314111, '\\'}, {0x221411, ']'},  {0x431111, '^'},   {0x111224, '_'},
    {0x111422, '`'},  {0x121124, 'a'},  {0x121421, 'b'},   {0x141122, 'c'},
    {0x141221, 'd'},  {0x112214, 'e'},  {0x112412, 'f'},   {0x122114, 'g'},
    {0x122411, 'h'},  {0x142112, 'i'},  {0x142211, 'j'},   {0x241211, 'k'},
    {0x221114, 'l'},  {0x413111, 'm'},  {0x241112, 'n'},   {0x134111, 'o'},
    {0x111242, 'p'},  {0x121142, 'q'},  {0x121241, 'r'},   {0x114212, 's'},
    {0x124112, 't'},  {0x124211, 'u'},  {0x411212, 'v'},   {0x421112, 'w'},
    {0x421211, 'x'},  {0x212141, 'y'},  {0x214121, 'z'},   {0x412121, '{'},
    {0x111143, '|'},  {0x111341, '}'},  {0x131141, '~'},   {0x114113, '\0'},
    {0x114311, '\0'}, {0x411113, '\0'}, {0x411311, '\0'},  {0x113141, '\0'},
    {0x114131, '\0'}, {0x311141, '\0'}, {0x411131, '\0'},  {0x211412, '\0'},
    {0x211214, '\0'}, {0x211232, '\0'}, {0x2331112, '\0'},
};

__asm__("\n&FUNC    SETC 'find_128_encoding'");
static int find_128_encoding(char ch)
{
    int i;

    for (i = 0; i < PDF_ARRAY_SIZE(code_128a_encoding); i++) {
        if (code_128a_encoding[i].ch == ch)
            return i;
    }
    return -1;
}

__asm__("\n&FUNC    SETC 'pdf_barcode_128a_ch'");
static int pdf_barcode_128a_ch(PDF *pdf, PDFO *page,
                               int x, int y, int width, int height,
                               unsigned colour, int index, int code_len)
{
    unsigned code = code_128a_encoding[index].code;
    int line_width = width / 11;
    int i;

    for (i = 0; i < code_len; i++) {
        unsigned char shift = (code_len - 1 - i) * 4;
        unsigned char mask = (code >> shift) & 0xf;

        if (!(i % 2))
            pdf_add_filled_rectangle(pdf, page, x, y, line_width * mask,
                                     height, 0, colour);
        x += line_width * mask;
    }
    return x;
}

__asm__("\n&FUNC    SETC 'pdf_add_barcode_128a'");
static int pdf_add_barcode_128a(PDF *pdf, PDFO *page,
                                int x, int y, int width, int height,
                                const char *string, unsigned colour)
{
    const char *s;
    int len = strlen(string) + 3;
    int char_width = width / len;
    int checksum, i;

    if (char_width / 11 <= 0)
        return pdf_set_err(pdf, -EINVAL,
                           "Insufficient width to draw barcode");

    for (s = string; *s; s++)
        if (find_128_encoding(*s) < 0)
            return pdf_set_err(pdf, -EINVAL, "Invalid barcode character 0x%x",
                               *s);

    x = pdf_barcode_128a_ch(pdf, page, x, y, char_width, height, colour, 104,
                            6);
    checksum = 104;

    for (i = 1, s = string; *s; s++, i++) {
        int index = find_128_encoding(*s);
        x = pdf_barcode_128a_ch(pdf, page, x, y, char_width, height, colour,
                                index, 6);
        checksum += index * i;
    }
    x = pdf_barcode_128a_ch(pdf, page, x, y, char_width, height, colour,
                            checksum % 103, 6);
    pdf_barcode_128a_ch(pdf, page, x, y, char_width, height, colour, 106, 7);
    return 0;
}

/* Code 39 character encoding. Each 4-bit value indicates:
 * 0 => wide bar
 * 1 => narrow bar
 * 2 => wide space
 */
static const struct {
    unsigned code;
    char ch;
} code_39_encoding[] = {
    {0x012110, '1'}, {0x102110, '2'}, {0x002111, '3'},
    {0x112010, '4'}, {0x012011, '5'}, {0x102011, '6'},
    {0x112100, '7'}, {0x012101, '8'}, {0x102101, '9'},
    {0x112001, '0'}, {0x011210, 'A'}, {0x101210, 'B'},
    {0x001211, 'C'}, {0x110210, 'D'}, {0x010211, 'E'},
    {0x100211, 'F'}, {0x111200, 'G'}, {0x011201, 'H'},
    {0x101201, 'I'}, {0x110201, 'J'}, {0x011120, 'K'},
    {0x101120, 'L'}, {0x001121, 'M'}, {0x110120, 'N'},
    {0x010121, 'O'}, {0x100121, 'P'}, {0x111020, 'Q'},
    {0x011021, 'R'}, {0x101021, 'S'}, {0x110021, 'T'},
    {0x021110, 'U'}, {0x120110, 'V'}, {0x020111, 'W'},
    {0x121010, 'X'}, {0x021011, 'Y'}, {0x120011, 'Z'},
    {0x121100, '-'}, {0x021101, '.'}, {0x120101, ' '},
    {0x121001, '*'}, // 'stop' character
};

__asm__("\n&FUNC    SETC 'pdf_barcode_39_ch'");
static int pdf_barcode_39_ch(PDF *pdf, PDFO *page,
                             int x, int y, int char_width, int height,
                             unsigned colour, char ch)
{
    int nw = char_width / 12;
    int ww = char_width / 4;
    int i;
    unsigned code;

    if (nw <= 1 || ww <= 1)
        return pdf_set_err(pdf, -EINVAL,
                           "Insufficient width for each character");

    for (i = 0; i < PDF_ARRAY_SIZE(code_39_encoding); i++) {
        if (code_39_encoding[i].ch == ch) {
            code = code_39_encoding[i].code;
            break;
        }
    }
    if (i == PDF_ARRAY_SIZE(code_39_encoding))
        return pdf_set_err(pdf, -EINVAL, "Invalid Code 39 character %c 0x%x",
                           ch, ch);

    for (i = 5; i >= 0; i--) {
        int pattern = (code >> i * 4) & 0xf;
        if (pattern == 0) { // wide
            if (pdf_add_filled_rectangle(pdf, page, x, y, ww - 1, height, 0,
                                         colour) < 0)
                return pdf->errval;
            x += ww;
        }
        if (pattern == 1) { // narrow
            if (pdf_add_filled_rectangle(pdf, page, x, y, nw - 1, height, 0,
                                         colour) < 0)
                return pdf->errval;
            x += nw;
        }
        if (pattern == 2) { // space
            x += nw;
        }
    }
    return x;
}

__asm__("\n&FUNC    SETC 'pdf_add_barcode_39'");
static int pdf_add_barcode_39(PDF *pdf, PDFO *page,
                              int x, int y, int width, int height,
                              const char *string, unsigned colour)
{
    int len = strlen(string);
    int char_width = width / (len + 2);

    x = pdf_barcode_39_ch(pdf, page, x, y, char_width, height, colour, '*');
    if (x < 0)
        return x;

    while (string && *string) {
        x = pdf_barcode_39_ch(pdf, page, x, y, char_width, height, colour,
                              *string);
        if (x < 0)
            return x;
        string++;
    };

    x = pdf_barcode_39_ch(pdf, page, x, y, char_width, height, colour, '*');
    if (x < 0)
        return x;

    return 0;
}

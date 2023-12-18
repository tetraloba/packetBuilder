/* "ff0f" -> "255 15" のように変換する*/
#include <stdio.h>
#define INPUT_FILE "./packet_hex.txt"
#define OUTPUT_FILE "./packet.txt"

char char_to_hex(char);
int main(void){
    FILE *fp_in = fopen(INPUT_FILE, "r");
    if (!fp_in) {
        puts("ファイルが開けません");
        return 1;
    }
    FILE *fp_out = fopen(OUTPUT_FILE, "w");
    if (!fp_out) {
        puts("ファイルが開けません");
        return 1;
    }
    char c1, c2;
    while (fscanf(fp_in, " %c%c", &c1, &c2) != EOF) {
        c1 = char_to_hex(c1) * 16 + char_to_hex(c2);
        fprintf(fp_out, "%d ", (int)(0 <= c1 ? c1 : c1 + 256));
    }
    fclose(fp_in);
    fclose(fp_out);
    return 0;
}
char char_to_hex(char c){
    if ('0' <= c && c <= '9') {
        return c - '0';
    } else if ('a' <= c && c <= 'f') {
        return c - 'a' + 10;
    } else if ('A' <= c && c <= 'F') {
        return c - 'A' + 10;
    }
    fprintf(stderr, "Character '%c' is not HEX!", c);
    return 0;
}
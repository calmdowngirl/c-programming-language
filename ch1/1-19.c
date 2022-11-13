#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define MAX_LEN 1000
#define MAX_LINE 100

static void copy_line(const char* src, char* dest);
static void reverse_print(char* str);

void main() {
    char str[MAX_LEN + 1];
    char line[MAX_LINE][MAX_LEN];
    int c, nc, nl;
    c = nc = nl = 0;
    bool out = true;
    while ((c = getchar()) != EOF && nc < MAX_LEN && nl < MAX_LINE) {
        if (c != '\n') {
            out = false;
            str[nc++] = c;
        } else if (!out) {
            out = true;
            str[nc] = '\0';
            copy_line(str, (char*)line[nl]);
            nc = 0;
            // printf("nl: %d\n", nl);
            ++nl;
        }
    }

    for (size_t i = 0; i < nl; i++) {
        reverse_print(line[i]);
    }
}

static void copy_line(const char* src, char* dest) {
    size_t i = 0;
    while ((dest[i] = src[i]) != '\0') {
        ++i;
    }
}

static void reverse_print(char* str) {
    int i = strlen(str);
    if (i == 0) return;
    while (i-- > 0) {
        printf("%c", str[i]);
    }
    printf("\n");
}
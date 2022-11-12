#include <ctype.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#define N_PRINTABLES 95

static int get_idx(char* chs, char c);

void main() {
    char chs[N_PRINTABLES] = {'\0'};
    uint64_t nc[N_PRINTABLES] = {0};
    uint8_t width = 0;
    uint64_t height = 0;
    int c, i, j;
    while ((c = getchar()) != EOF) {
        if (isspace(c)) c = ' ';
        int pos = get_idx(chs, c);
        // printf("\n%d\n", pos);
        if (pos >= 0) {
            ++nc[pos];
            height = nc[pos] > height ? nc[pos] : height;
        } else if ((pos = strlen(chs)) < N_PRINTABLES) {
            chs[pos] = c;
            ++nc[pos];
            height = nc[pos] > height ? nc[pos] : height;
        } else {
            break;
        }
        // printf("\n%d, %c, %u\n", pos, chs[pos], nc[pos]);
    }
    width = strlen(chs);

    printf("\n%s\n", "--- HORIZONTAL ---");

    for (i = 0; nc[i] != '\0'; ++i) {
        printf("%c ", chs[i]);
        for (j = 0; j < nc[i]; j++) {
            printf("%s", "|");
        }
        printf(" %lu\n", nc[i]);
    }

    // printf("\n%s\n", "--- VERTICAL ---");

    // for (i = 0; i < width; ++i) {
    //     printf("%c \t", chs[i]);
    // }
    // printf("\n");
    // for (i = 0; i < width; ++i) {
    //     nc[i] = height - nc[i];
    // }
    // for (i = 0; i < height; ++i) {
    //     for (j = 0; j < width; ++j) {
    //         if (nc[j]) {
    //             printf("%s\t", "  ");
    //             nc[j] -= 1;
    //         } else {
    //             printf("%s\t", "__");
    //         }
    //     }
    //     printf("\n");
    // }
}

int get_idx(char* chs, char c) {
    char* p = strchr(chs, c);
    if (p == NULL) {
        return -1;
    }
    return (int)(p - chs);
}

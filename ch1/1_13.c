#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

#define MAX_WC 10

void main() {
    int c, nc = 0, wc = 0, i, j, aaa = 0;
    int histogram[MAX_WC + 1] = {0};
    bool out = true;
    size_t height = 0, width = 0;
    while (c = getchar()) {
        // printf("\n%d: %c\n", ++aaa, c);
        bool in = !isspace(c) && c != EOF;
        if (in) {
            out = false;
            ++nc;
        } else if (!out) {
            out = true;
            histogram[wc++] = nc;
            height = height < nc ? nc : height;
            nc = 0;
        }

        if (c == EOF || wc >= MAX_WC) {
            width = wc;
            histogram[wc + 1] = '\0';
            break;
        }
    }

    // printf("\nwidth: %lu, height: %lu\n[ ", width, height);
    for (i = 0; i < MAX_WC; ++i) {
        printf("%d ", histogram[i]);
    }
    printf("]\n");

    printf("%s\n", "--- HORIZONTAL ---");

    for (i = 0; histogram[i] != '\0'; ++i) {
        for (j = 0; j < histogram[i]; j++) {
            printf("%s", "|");
        }
        printf("\n");
    }

    printf("%s\n", "--- VERTICAL ---");

    for (i = 0; i < width; ++i) {
        histogram[i] = height - histogram[i];
    }
    for (i = 0; i < height; ++i) {
        for (j = 0; j < width; ++j) {
            // printf("%d", histogram[j]);
            if (histogram[j]) {
                printf("%s ", "  ");
                histogram[j] -= 1;
            } else {
                printf("%s ", "__");
            }
        }
        printf("\n");
    }
}
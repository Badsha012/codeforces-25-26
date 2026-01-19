#include <stdio.h>
#include <string.h>

int main() {
    char s[20];
    scanf("%s", s);

    int len = strlen(s);
    int first_group = len % 3;
    if (first_group == 0)
        first_group = 3;

    // Print first group
    for (int i = 0; i < first_group; i++) {
        printf("%c", s[i]);
    }

    // Print remaining groups with commas
    for (int i = first_group; i < len; i++) {
        if ((i - first_group) % 3 == 0) {
            printf(",");
        }
        printf("%c", s[i]);
    }

    printf("\n");
    return 0;
}

#include <stdio.h>

int main() {
    char s[205];
    int i = 0;

    
    fgets(s, 205, stdin);

    
    while (s[i] != '\0') {
        i++;
    }

    
    for (int j = i - 1; j >= 0; j--) {
        if (s[j] != '\n')   
            printf("%c", s[j]);
    }

    return 0;
}

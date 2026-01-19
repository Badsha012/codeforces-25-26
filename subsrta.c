#include <stdio.h>

int main() {
    int N, M;
    scanf("%d", &N);

    // Sum from 1 to N using Gauss formula
    int sum = N * (N + 1) / 2;

    scanf("%d", &M);

    for (int i = 0; i < M; i++) {
        int x;
        scanf("%d", &x);
        sum -= x;   // subtract given numbers
    }

    printf("%d\n", sum);

    return 0;
}

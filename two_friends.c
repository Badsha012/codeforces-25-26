#include <stdio.h>
#include <math.h>

int main() {
    int N;
    scanf("%d", &N);

    int count = 0;

    for (int i = 1; i * i <= N; i++) {
        if (N % i == 0) {
            count++; // i is a divisor
            if (i != N / i) count++; // N / i is also a divisor
        }
    }

    printf("%d\n", count);
    return 0;
}

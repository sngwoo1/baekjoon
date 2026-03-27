#include <stdio.h>

long long binomial(int n, int k) {
    long long result = 1;

    if (k > n - k)
        k = n - k;  

    for (int i = 0; i < k; i++) {
        result = result * (n - i) / (i + 1);
    }

    return result;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    printf("%lld\n", binomial(n, k));
    return 0;
}
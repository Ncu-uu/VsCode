#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int ans = (n * (n - 1) / 2) % 1000000007;
    printf("%d\n", ans);
    return 0;
}

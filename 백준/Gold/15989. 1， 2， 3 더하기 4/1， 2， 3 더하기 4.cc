#include <stdio.h>
#include <string.h>

int t, n, cache[10010][4];

int calc(int x, int last) {
    if (x == 0) {
        return 1;
    }

    int& ret = cache[x][last];

    if (ret != -1) {
        return ret;
    }

    ret = 0;

    for (int i = last; i <= 3; ++i) {
        if (x - i >= 0) {
            ret += calc(x - i, i);
        }
    }

    return ret;
}

int main() {
    scanf("%d", &t);

    memset(cache, -1, sizeof(cache));

    while (t--) {
        scanf("%d", &n);

        printf("%d\n", calc(n, 1));
    }
}
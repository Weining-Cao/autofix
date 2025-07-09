#include <assert.h>

void foo(int n) {
    int y = 0;
    int x = 1;

    while (x <= n) {
        y = n - x;
        x = x +1;
    }

    if (n > 0) {
        assert (y <= n);
    }
}

int main() {
    foo(5);
    return 0;
}
#include <assert.h>

void foo(int n) {
    int x = 1;
    int y = 0;

    while (x <= n) {
        y = n - x;
        x = x +1;
    }

    if (n > 0) {
      assert (y >= 0);
    }
}

int main() {
    foo(5);
    return 0;
}
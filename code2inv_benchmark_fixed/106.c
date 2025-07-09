#include <assert.h>

void foo(int a, int j, int m) {
    int k = 0;

    while (k < 1) {
        if(m < a) {
            m = a;
        }
        k = k + 1;
    }
    assert(a >= m);
}

int main() {
    foo(1, 0, 2);
    return 0;
}
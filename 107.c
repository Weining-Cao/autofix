#include <assert.h>

void foo(int a, int m) {
    int j = 0;
    int k = 0;

    while ( k < 1) {
        if(m < a) {
            m = a;
        }
        k = k + 1;
    }

    assert(a <= m);
}

int main() {
    foo(1, 2);
    return 0;
}
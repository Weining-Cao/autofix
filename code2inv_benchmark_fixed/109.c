#include <assert.h>

void foo(int a, int m, int c) {
    int j = 0;
    int k = 0;

    while ( k < c) {
        if(m < a) {
            m = a;
        }
        k = k + 1;
    }

    if(c > 0) {
        assert(a <=  m);
    }
}

int main() {
    foo(1, 2, 3);
    return 0;
}
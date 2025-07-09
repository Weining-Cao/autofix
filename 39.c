#include <assert.h>

int unknown() {
    return 0;
}

void assume(int condition) {
    if (!condition) {
        exit(1);
    }
}

void foo(int n) {
    int c = 0;
    assume (n > 0);

    while (unknown()) {
        if(c == n) {
            c = 1;
        }
        else {
            c = c + 1;
        }
    }

    if(c == n) {
        assert( c <= n);
    }
}

int main() {
    foo(5);
    return 0;
}
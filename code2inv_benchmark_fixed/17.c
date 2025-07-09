#include <assert.h>
#include <stdlib.h>
#include <time.h>

int unknown() {
    return rand() % 2;
}

void foo(int n) {
    int x = 1;
    int m = 1;

    while (x < n) {
        if (unknown()) {
            m = x;
        }
        x = x + 1;
    }

    if(n > 1) {
       assert(m < n);
       assert(m >= 1);
    }
}

int main() {
    srand(time(NULL));
    foo(10);
    return 0;
}
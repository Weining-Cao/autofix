#include <assert.h>
#include <stdlib.h>
#include <time.h>

int unknown() {
    return rand() % 2;
}

void foo(int n) {
    int x = 0;
    int m = 0;

    while (x < n) {
        if (unknown()) {
            m = x;
        }
        x = x + 1;
    }

    if(n > 0) {
       assert (m >= 0);
    }
}

int main() {
    srand(time(NULL));
    foo(10);
    return 0;
}
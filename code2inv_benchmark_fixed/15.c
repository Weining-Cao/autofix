#include <assert.h>
#include <stdbool.h>

bool unknown() {
    return true;
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
       assert(m < n);
    }
}

int main() {
    foo(5);
    return 0;
}
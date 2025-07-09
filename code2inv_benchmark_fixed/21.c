#include <assert.h>
#include <stdbool.h>

bool unknown() {
    return false;
}

int main()
{
    int x = 1;
    int m = 1;
    int n = 10;

    while (x < n) {
        if (unknown()) {
            m = x;
        }
        x = x + 1;
    }

    if(n > 1) {
       assert (m < n);
    }
}
#include <assert.h>
#include <stdlib.h>
#include <time.h>

int unknown() {
    return rand() % 2;
}

int main()
{
    srand(time(NULL));
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
       assert (m >= 1);
    }
}
#include <assert.h>
#include <stdbool.h>

bool unknown() {
    return false;
}

void foo(int j, int c, int t) {
    int i = 0;
    
    while(unknown()) {
        if(c > 48) {
            if (c < 57) {
                j = i + i;
                t = c - 48;
                i = j + t;
            }
        }
    } 

    assert (i >= 0);
}

int main() {
    foo(0, 50, 0);
    return 0;
}
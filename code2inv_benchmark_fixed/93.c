#include <assert.h>
#include <stdlib.h>
#include <time.h>

int unknown() {
    return rand() % 2;
}

void foo(int n) {
  int i = 0;
  int x = 0;
  int y = 0;
    
  while (i < n) {
    i = i + 1;
    if (unknown()) {
      x  = x + 1;
      y  = y + 2;
    } else {
      x  = x + 2;
      y  = y + 1;
    }
  }
  assert((3 * n) == (x + y));
}

int main() {
    srand(time(NULL));
    foo(5);
    return 0;
}
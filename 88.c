#include <assert.h>
#include <stdlib.h>
#include <time.h>

int unknown() {
    return rand() % 2;
}

void foo(int x) {
  int lock = 0;
  int y = x + 1;
  
  while (x != y) {
    if (unknown()) {
      lock = 1;
      x = y;
    } else {
      lock = 0;
      x = y;
      y = y + 1;
    }
  }
  assert(lock == 1);
}

int main() {
    srand(time(0));
    foo(0);
    return 0;
}
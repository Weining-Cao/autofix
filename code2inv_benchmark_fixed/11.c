#include <assert.h>
#include <stdbool.h>

bool unknown() {
    return false;
}

void foo(int x, int y) {
  while (unknown()) {
    x  = x + 10;
    y  = y + 10;
  }
  if (x == 20) {
    assert(y != 0);
  }
}

int main() {
    foo(0, 0);
    return 0;
}
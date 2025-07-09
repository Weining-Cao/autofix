#include <assert.h>
#include <stdbool.h>

bool unknown() {
    return false;
}

void foo(int x, int y) {
  while (unknown()) {
    x  = x + 2;
    y  = y + 2;
  }
  if (y == 0) {
    assert(x != 4);
  }
}

int main() {
    foo(0, 0);
    return 0;
}
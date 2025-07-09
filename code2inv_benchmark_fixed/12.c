#include <assert.h>
#include <stdbool.h>

bool unknown() {
    return false;
}

void foo(int x, int y) {
  int z1;
  int z2;
  int z3;

  while (unknown()) {
    x = x + 10;
    y = y + 10;
  }
  if (y == 0) {
    assert(x != 20);
  }
}

int main() {
    foo(0, 0);
    return 0;
}
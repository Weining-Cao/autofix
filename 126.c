#include <assert.h>

void foo(int x, int y) {
  int i = x;
  int j = y;

  while (x != 0) {
    x = x - 1;
    y = y - 1;
  }

  if (i == j) {
    assert(y == 0);
  }
}

int main() {
  foo(5, 5);
  return 0;
}
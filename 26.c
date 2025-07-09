#include <assert.h>

void foo(int x, int n) {
  while (x > 1) {
    x = x - 1;
  }
  if (x != 1) {
    assert(n < 0);
  }
}

int main() {
  foo(5, 5);
  return 0;
}
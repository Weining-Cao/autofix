#include <assert.h>

void foo(int n) {
  int x = n;
  while (x > 0) {
    x = x - 1;
  }
  if (x != 0) {
    assert(n < 0);
  }
}

int main() {
  foo(-5);
  return 0;
}
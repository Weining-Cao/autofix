#include <assert.h>

void foo(int n) {
  int x = n;
  while (x > 1) {
    x = x - 1;
  }
  if (n >= 0) {
    assert(x == 1);
  }
}

int main() {
  foo(5);
  return 0;
}
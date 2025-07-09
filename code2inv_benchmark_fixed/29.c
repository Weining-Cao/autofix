#include <assert.h>

void foo(int x, int n) { 
  while (x > 0) {
    x = x - 1;
  }
  if (n >= 0) {
    assert(x == 0);
  }
}

int main() {
  foo(5, 5);
  return 0;
}
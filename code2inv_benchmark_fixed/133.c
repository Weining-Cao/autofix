#include <assert.h>

void foo(int n) {
  int x = 0;

  while (x < n) {
    x = x + 1;
  }
  assert(x == n);
}

int main() {
  foo(5);
  return 0;
}
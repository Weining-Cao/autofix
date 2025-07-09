#include <assert.h>

void foo(int y) {
  int x = 1;
  
  while (x < y) {
    x = x + x;
  }
  assert(x >= 1);
}

int main() {
  foo(5);
  return 0;
}
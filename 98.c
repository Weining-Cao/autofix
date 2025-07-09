#include <assert.h>

void foo(int x) {
  int i = 0;
  int j = 0;
  int y = 2;

  while (i <= x) {
    i  = i + 1;
    j  = j + y;
  }
  if (i != j) {
    assert(y != 1);
  }
}

int main() {
  foo(5);
  return 0;
}
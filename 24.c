#include <assert.h>

void foo(int i, int j) {
  while (j >= i) {
    i = i + 2;
    j = j - 1;
  }
  assert(j == 6);
}

int main() {
  foo(1, 20);
  return 0;
}
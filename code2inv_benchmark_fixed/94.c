#include <assert.h>

void foo(int k, int n) {
  int i = 0;
  int j = 0;
  
  while (i <= n) {
    i = i + 1;
    j = j + i;
  }
  assert(i + j + k > 2*n);
}

int main() {
  foo(1, 5);
  return 0;
}
#include <assert.h>

void foo(int n) {
  int i = 1;
  int sn = 0;
  
  while (i <= n) {
    i = i + 1;
    sn = sn + 1;
  }
  if (sn != 0) {
    assert(sn == n);
  }
}

int main() {
  foo(5);
  return 0;
}
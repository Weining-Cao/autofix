#include <assert.h>

void foo(int n) {
  int i = 1;
  int sn = 0;
  
  while (i <= n) {
    i  = i + 1;
    sn  = sn + 1;
  }
  if(sn != n) {
    assert(sn == 0);
  }
}

int main() {
  foo(5);
  return 0;
}
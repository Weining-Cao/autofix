#include <assert.h>

int unknown() {
    return 0;
}

int main() {
  int sn = 0;
  int x = 0;
  
  while (unknown()) {
    x = x + 1;
    sn = sn + 1;
  }
  if (sn != x) {
    assert(sn == -1);
  }
  return 0;
}
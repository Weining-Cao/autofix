#include <assert.h>
#include <stdbool.h>

bool unknown() {
    return false;
}

int main() {
  int sn = 0;
  int x = 0;
  
  while (unknown()) {
    x  = x + 1;
    sn  = sn + 1;
  }
  if (sn != -1) {
    assert(sn == x);
  }
  return 0;
}
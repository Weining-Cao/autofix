#include <assert.h>
void main() {
  // variable declarations
  int x;
  int y;
  // pre-conditions
  x = 1;
  y = 0;
  // loop body
  while (y < 100000) {
    x  = x + y;
    y  = y + 1;
  }
  // post-condition
  assert(x >= y >= 1);
}

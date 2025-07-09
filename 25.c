#include <assert.h>

void foo(int x) {
  while ((x > 0)) {
    (x  = (x - 1));
  }
  assert( (x == 0) );
}

int main() {
  foo(10000);
  return 0;
}
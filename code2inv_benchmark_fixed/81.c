#include <assert.h>
#include <stdbool.h>

bool unknown() {
    return true;
}

void foo(int x, int y) {
  int i = 0;

  while (unknown()) {
    if ( (i < y) )
    {
    (i  = (i + 1));
    }
  }
  if (i < y) {
    assert(0 <= i);
  }
}

int main() {
    foo(5, 3);
    return 0;
}
#include <assert.h>
#include <stdbool.h>

bool unknown() {
    return false;
}

void foo(int y) {
  int c = 0;
  int z = 36 * y;
  
  while (unknown()) {
    if (c < 36)
    {
      z = z + 1;
      c = c + 1;
    }
  }
  if (c < 36) {
    assert(z >= 0);
  }
}

int main() {
    foo(127);
    return 0;
}
#include <assert.h>
#include <stdbool.h>

bool unknown() {
    return false;
}

void foo(int x, int y) {
  int i = 0;

  while (unknown()) {
    if (i < y)
    {
      i = i + 1;
    }
  }
  if (i >= x) {
    if (0 > i) {
      assert(i >= y);
    }
  }
}

int main() {
    foo(5, 3);
    return 0;
}
#include <assert.h>
#include <stdbool.h>

bool unknown() {
    return true;
}

void foo(int x, int y) {
  int i = 0;
  
  while (unknown()) {
    if (i < y)
    {
      i = i + 1;
    }
  }
  if (i <= y) {
    assert(i <= x);
  }
}

int main() {
    foo(10, 5);
    return 0;
}
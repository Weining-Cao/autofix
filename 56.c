#include <assert.h>
#include <stdbool.h>

bool unknown() {
    return false;
}

void assume(bool condition) {
    if (!condition) {
        exit(1);
    }
}

void foo(int n) {
  int c = 0;
  assume((n > 0));
  
  while (unknown()) {
    if (unknown()) {
      if (c > n) {
        c = c + 1;
      }
    } else {
      if (c == n) {
        c  = 1;
      }
    }
  }
  if (c == n) {
    assert(n <= -1);
  }
}

int main() {
    foo(1);
    return 0;
}
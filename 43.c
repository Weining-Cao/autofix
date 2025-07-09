#include <assert.h>

int unknown() {
    return 0;
}

void assume(int condition) {
    if (!condition) {
        exit(1);
    }
}

void foo(int n) {
  int c = 0;
  assume(n > 0);
  
  while (unknown()) {
    if (unknown()) {
      if (c > n) {
        c  = c + 1;
      }
    } else {
      if (c == n) {
        c  = 1;
      }
    }
  }
  if (c == n) {
    assert(n > -1);
  }
}

int main() {
    foo(5);
    return 0;
}
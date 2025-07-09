#include <assert.h>
#include <stdbool.h>

int unknown() {
    return rand() % 2;
}

void assume(bool condition) {
    if (!condition) {
        exit(1);
    }
}

void foo(int n) {
  int c = 0;
  assume(n > 0);
  
  while (unknown()) {
      if (unknown()) {
        if (c != n) {
          c  = c + 1;
        }
      } else {
        if (c == n) {
          c = 1;
        }
      }
  }
  if (c < 0) {
    if (c > n) {
      assert(c == n);
    }
  }
}

int main() {
    foo(5);
    return 0;
}
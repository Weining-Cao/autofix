#include <assert.h>

int unknown() {
    return 0;
}

int main() {
  int c = 0;

  while (unknown()) {
    if (unknown()) {
      if (c != 40) {
        c  = c + 1;
      }
    } else {
      if (c == 40) {
        c  = 1;
      }
    }
  }
  if (c < 0) {
    if (c > 40) {
      assert( (c == 40) );
    }
  }
}
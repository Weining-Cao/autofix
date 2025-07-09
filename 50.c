#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

bool unknown() {
  srand(time(NULL));
  return rand() % 2;
}

int main() {
  int c = 0;
  
  while (unknown()) {
    if (unknown()) {
      if (c != 4) {
        c = c + 1;
      }
    } else {
      if (c == 4) {
        c = 1;
      }
    }
  }
  if (c != 4) {
    assert(c >= 0);
  }
  return 0;
}
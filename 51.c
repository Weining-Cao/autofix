#include <assert.h>
#include <stdbool.h>

bool unknown() {
    return true;
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
  if (c != 4){
    assert(c <= 4);
  }
  return 0;
}
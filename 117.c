#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

bool unknown() {
  srand(time(NULL));
  return rand() % 2;
}

int main() {
  int sn = 0;
  int x = 0;
  
  while (unknown()) {
    x = x + 1;
    sn = sn + 1;
  }
  if (sn != -1) {
    assert(sn == x);
  }
  return 0;
}
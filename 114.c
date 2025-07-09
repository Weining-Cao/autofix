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
  if(sn != x) {
    assert(sn == -1);
  }
  return 0;
}
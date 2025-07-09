#include <assert.h>

void foo(int y, int z)
{
   int x = 0;

   while(x < 500) {
      x += 1;
      if( z <= y) {
         y = z;
      }
   }

   assert(z >= y);
}

int main()
{
   foo(10, 20);
   return 0;
}
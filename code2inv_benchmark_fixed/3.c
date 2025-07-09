#include <assert.h>

void foo(int y, int z)
{
   int x = 0;

   while (x < 5) {
      x += 1;
      if (z <= y) {
         y = z;
      }
   }

   // post-condition
   assert(z >= y);
}

int main() {
    foo(10, 5);  // 示例调用
    return 0;
}

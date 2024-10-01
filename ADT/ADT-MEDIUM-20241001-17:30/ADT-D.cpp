#include <bits/stdc++.h>

int main() {

   std::int64_t X;
   std::cin >> X;

   if (X%10 == 0) {
      std::cout << X/10 << std::endl;
   }
   else {
      if (X > 0) {
         std::cout << X/10 + 1 << std::endl;
      }
      else {
         std::cout << X/10 << std::endl;
      }
   }


   return 0;
}
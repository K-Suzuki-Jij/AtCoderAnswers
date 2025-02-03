#include <bits/stdc++.h>


int main() {
   std::int64_t a, b, c;
   std::cin >> a >> b >> c;
   
   std::int64_t val = 1;
   for (std::int64_t i = 0; i < b; ++i) {
      val *= c;
      if (val > a) {
         std::cout << "Yes" << std::endl;
         return 0;
      }
   }
   std::cout << "No" << std::endl;
   
   return 0;
}
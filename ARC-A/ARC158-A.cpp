#include <bits/stdc++.h>

int main() {
   std::int64_t T;
   std::cin >> T;
   std::vector<std::int64_t> x1(T), x2(T), x3(T);

   for (std::int64_t i = 0; i < T; ++i) {
      std::cin >> x1[i] >> x2[i] >> x3[i];
   }

   for (std::int64_t i = 0; i < T; ++i) {
      if ((x1[i] + x2[i] + x3[i])%3 == 0) {
         const std::int64_t z = (x1[i] + x2[i] + x3[i])/3;
         if ((z%2 == x1[i]%2) && (z%2 == x2[i]%2) && (z%2 == x3[i]%2)) {
            std::cout << (std::abs(x1[i] - z) + std::abs(x2[i] - z) + std::abs(x3[i] - z))/4 << std::endl;
         }
         else {
            std::cout << -1 << std::endl;
         }
      } 
      else {
         std::cout << -1 << std::endl;
      }
   }

   return 0;
}
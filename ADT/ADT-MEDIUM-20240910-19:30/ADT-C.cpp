#include <bits/stdc++.h>

int main() {
   std::int64_t N;
   std::cin >> N;

   if (N <= 1e+03 - 1) {
      std::cout << N << std::endl;
   }
   else if (N <= 1e+04 - 1) {
      std::cout << 10*(N/10) << std::endl;
   }
   else if (N <= 1e+05 - 1) {
      std::cout << 100*(N/100) << std::endl;
   }
   else if (N <= 1e+06 - 1) {
      std::cout << 1000*(N/1000) << std::endl;
   }
   else if (N <= 1e+07 - 1) {
      std::cout << 10000*(N/10000) << std::endl;
   }
   else if (N <= 1e+08 - 1) {
      std::cout << 100000*(N/100000) << std::endl;
   }
   else {
      std::cout << 1000000*(N/1000000) << std::endl;
   }

   return 0;
}

#include <bits/stdc++.h>

int main() {

   std::int64_t K, A, B;
   std::cin >> K;
   std::cin >> A >> B;

   std::int64_t A_10 = 0;
   std::int64_t B_10 = 0;
   std::int64_t base = 1;
   while (A > 0) {
      A_10 += (A%10)*base;
      base *= K;
      A /= 10;
   }
   base = 1;
   while (B > 0) {
      B_10 += (B%10)*base;
      base *= K;
      B /= 10;
   }
   std::cout << A_10*B_10 << std::endl;

   return 0;
}
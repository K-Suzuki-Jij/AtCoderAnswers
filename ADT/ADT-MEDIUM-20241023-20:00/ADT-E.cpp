#include <bits/stdc++.h>

std::int64_t GetPower(std::int64_t a, std::int64_t t) {
   t = t + (a/5)*3;
   a = a - (a/5)*5;
   while (a > 0) {
      if (t%3 == 0) {
         a = a - 3;
         t = t + 1;
      }
      else {
         a = a - 1;
         t = t + 1;
      }
   }
   return t;
}


int main() {
   std::int64_t N;
   std::cin >> N;

   std::vector<std::int64_t> H(N);

   for (std::int64_t i = 0; i < N; ++i) {
      std::cin >> H[i];
   }

   std::int64_t T = 1;

   for (std::int64_t i = 0; i < N; ++i) {
      T = GetPower(H[i], T);
   }

   std::cout << T - 1 << std::endl;
   return 0;
}

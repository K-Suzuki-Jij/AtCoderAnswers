
#include <bits/stdc++.h>

int main() {

   std::int64_t N;
   std::cin >> N;

   std::vector<std::int64_t> L(N);
   std::vector<std::int64_t> R(N);

   std::int64_t most_min = 0;
   std::int64_t most_max = 0;
   for (std::int64_t i = 0; i < N; ++i) {
      std::cin >> L[i] >> R[i];
      most_min += L[i];
      most_max += R[i];
   }

   if (most_min <= 0 && 0 <= most_max) {
      std::int64_t diff = most_max;
      std::vector<std::int64_t> ans(N);

      bool adjast = true;
      for (std::int64_t i = 0; i < N; ++i) {
         if (adjast) {
            if (diff - (R[i] - L[i]) <= 0) {
               ans[i] = R[i] - diff;
               adjast = false;
            }
            else {
               ans[i] = L[i];
               diff -= (R[i] - L[i]);
            }
         }
         else {
            ans[i] = R[i];
         }
      }

      std::cout << "Yes" << std::endl;
      for (std::int64_t i = 0; i < N; ++i) {
         std::cout << ans[i] << " ";
      }
   }
   else {
      std::cout << "No" << std::endl;
   }

   return 0;
}
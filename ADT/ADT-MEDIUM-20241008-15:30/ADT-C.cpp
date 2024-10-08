#include <bits/stdc++.h>

int main() {

   int M;
   std::cin >> M;

   std::vector<int> D(M);
   std::int32_t sum = 0;
   for (int i = 0; i < M; ++i) {
      std::cin >> D[i];
      sum += D[i];
   }

   std::int32_t middle = (sum + 1)/2;
   std::int32_t current_sum = 0;
   int ans_m = 0;
   int ans_d = 0;
   for (int i = 0; i < M; ++i) {
      for (int j = 0; j < D[i]; ++j) {
         current_sum += 1;
         if (current_sum == middle) {
            ans_m = i+1;
            ans_d = j+1;
            std::cout << ans_m << " " << ans_d << std::endl;
            return 0;
         }
      }
   }

   return 0;
}
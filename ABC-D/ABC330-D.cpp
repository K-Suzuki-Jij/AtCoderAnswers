#include <bits/stdc++.h>

int main() {
   int N;
   std::cin >> N;
   std::vector<std::string> S(N);

   for (int i = 0; i < N; ++i) {
      std::cin >> S[i];
   }

   std::vector<int> r_o(N);
   std::vector<int> d_o(N);
   for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
         if (S[i][j] == 'o') {
            r_o[i]++;
         }
         if (S[j][i] == 'o') {
            d_o[i]++;
         }
      }
   }

   std::int64_t ans = 0;
   for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
         if (S[i][j] == 'o') {
            ans += (r_o[i] - 1)*(d_o[j] - 1);
         }
      }
   }

   std::cout << ans << std::endl;

   return 0;
}
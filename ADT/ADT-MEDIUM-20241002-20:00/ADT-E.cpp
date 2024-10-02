
#include <bits/stdc++.h>

int main() {

   std::int32_t N, M;
   std::cin >> N >> M;

   std::vector<std::string> S(N);

   for (std::int32_t i = 0; i < N; i++) {
      std::cin >> S[i];
   }

   std::vector<std::int32_t> elements(N);
   std::iota(elements.begin(), elements.end(), 0);
   std::vector<std::int32_t> ans;
   for (int bit = 0; bit < (1<<N); ++bit) {
      std::vector<std::int32_t> subset;
      for (int i = 0; i < N; ++i) {
         if (bit & (1<<i)) {
            subset.push_back(elements[i]);
         }
      }

      std::unordered_set<std::int32_t> popcorns;
      for (const auto &i: subset) {
         for (std::int32_t j = 0; j < M; j++) {
            if (S[i][j] == 'o') {
               popcorns.insert(j);
            }
         }
      }
      if (popcorns.size() == M) {
         ans.push_back(subset.size());
      }
   }
   std::sort(ans.begin(), ans.end());

   std::cout << ans[0] << std::endl;

   return 0;
}
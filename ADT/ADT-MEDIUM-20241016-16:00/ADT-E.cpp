#include <bits/stdc++.h>

int main() {
   std::int64_t N;
   std::cin >> N;

   std::vector<std::int64_t> A(N), C(N);

   for (std::int64_t i = 0; i < N; ++i) {
      std::cin >> A[i] >> C[i];
   }

   std::unordered_map<std::int64_t, std::int64_t> mp;
   for (std::int64_t i = 0; i < N; ++i) {
      if (mp.count(C[i]) == 0) {
         mp[C[i]] = A[i];
      }
      else {
         mp[C[i]] = std::min(mp[C[i]], A[i]);
      }
   }

   std::int64_t result = 0;
   for (const auto &it: mp) {
      result = std::max(result, it.second);
   }

   std::cout << result << std::endl;

   return 0;
}
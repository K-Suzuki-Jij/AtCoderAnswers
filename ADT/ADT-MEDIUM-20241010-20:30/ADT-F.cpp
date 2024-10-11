
#include <bits/stdc++.h>

int main() {
   std::int64_t N, W;
   std::cin >> N >> W;

   std::vector<std::int64_t> A(N);
   std::vector<std::int64_t> B(N);
   std::vector<std::pair<std::int64_t, std::int64_t>> value(N);

   for (std::int64_t i = 0; i < N; ++i) {
      std::cin >> A[i] >> B[i];
      value[i].first = A[i];
      value[i].second = B[i];
   }

   std::sort(value.begin(), value.end(), [](const std::pair<std::int64_t, std::int64_t>& a, const std::pair<std::int64_t, std::int64_t>& b) {
      return a.first > b.first;
   });

   std::int64_t sum = 0;
   std::int64_t current_weight = 0;
   for (std::int64_t i = 0; i < N; ++i) {
      if (current_weight + value[i].second <= W) {
         sum += value[i].first*value[i].second;
         current_weight += value[i].second;
      }
      else {
         sum += (W - current_weight)*value[i].first;
         break;
      }
   }

   std::cout << sum << std::endl;
   return 0;
}
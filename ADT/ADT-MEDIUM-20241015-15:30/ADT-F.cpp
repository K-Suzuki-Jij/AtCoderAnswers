#include <bits/stdc++.h>

int main() {

   std::int64_t N;
   std::cin >> N;

   std::vector<std::int64_t> A(N);
   for (std::int64_t i = 0; i < N; ++i) {
      std::cin >> A[i];
   }

   std::sort(A.begin(), A.end());
   std::int64_t sum = std::accumulate(A.begin(), A.end(), std::int64_t(0));
   
   std::vector<std::int64_t> B(N, sum/N);
   for (std::int64_t i = 0; i < sum%N; ++i) {
      B[N - i - 1]++;
   }

   std::int64_t result = 0;
   for (std::int64_t i = 0; i < N; ++i) {
      result += std::abs(A[i] - B[i]);
   }

   std::cout << result/2 << std::endl;

   return 0;
}

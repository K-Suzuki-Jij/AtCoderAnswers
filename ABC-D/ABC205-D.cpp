#include <bits/stdc++.h>

int main() {
   int N, Q;
   std::cin >> N >> Q;

   std::vector<std::int64_t> A(N);
   for (int i = 0; i < N; ++i) {
      std::cin >> A[i];
   }

   std::vector<std::int64_t> K(Q);
   for (int i = 0; i < Q; ++i) {
      std::cin >> K[i];
   }

   std::vector<std::int64_t> under_count(N);
   for (int i = 0; i < N; ++i) {
      under_count[i] = A[i] - (i + 1);
   }

   for (int i = 0; i < Q; ++i) {
      const auto idx = std::lower_bound(under_count.begin(), under_count.end(), K[i]) - under_count.begin();
      if (under_count[N - 1] < K[i]) {
         std::cout << A[N - 1] + (K[i] - under_count[N - 1]) << std::endl;
      }
      else {
         std::cout <<  A[idx] - 1 - (under_count[idx] - K[i]) << std::endl;
      }
   }

   return 0;
}


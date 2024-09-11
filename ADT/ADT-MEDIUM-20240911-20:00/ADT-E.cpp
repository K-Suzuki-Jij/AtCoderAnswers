#include <bits/stdc++.h>

int main() {
   std::int64_t N;
   std::cin >> N;

   std::vector<std::int64_t> A(N), B(N), diff(N);
   std::int64_t sum = 0;
   for (std::int64_t i = 0; i < N; ++i) {
      std::cin >> A[i];
      std::cin >> B[i];
      diff[i] = B[i] - A[i];
      sum += A[i];
   }

   std::cout << sum + *std::max_element(diff.begin(), diff.end()) << std::endl;

   return 0;
}
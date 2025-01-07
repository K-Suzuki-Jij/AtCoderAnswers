#include <bits/stdc++.h>

int main() {

   int N;
   std::cin >> N;

   std::vector<int> A(N);
   for (int i = 0; i < N; ++i) {
      std::cin >> A[i];
   }

   int Q;
   std::cin >> Q;

   std::vector<int> B(Q);
   for (int i = 0; i < Q; ++i) {
      std::cin >> B[i];
   }

   std::sort(A.begin(), A.end());

   for (int i = 0; i < Q; ++i) {
      const auto lower_it = std::lower_bound(A.begin(), A.end(), B[i]);
      if (lower_it == A.end()) {
         std::cout << std::abs(A.back() - B[i]) << std::endl;
      }
      else if (lower_it == A.begin()) {
         std::cout << std::abs(*lower_it - B[i]) << std::endl;
      }
      else {
         const auto lower = *lower_it;
         const auto upper = *(lower_it - 1);
         const auto ans = std::min(std::abs(lower - B[i]), std::abs(upper - B[i]));
         std::cout << ans << std::endl;
      }
   }

   return 0;
}
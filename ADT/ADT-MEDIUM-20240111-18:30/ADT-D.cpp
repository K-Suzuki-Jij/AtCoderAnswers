#include <bits/stdc++.h>

int main() {
   int N, X;
   std::cin >> N >> X;
   std::vector<int> A(N);
   for (int i = 0; i < N-1; ++i) {
      std::cin >> A[i];
   }

   std::vector<int> ans;
   for (int An = 0; An <= 100; An++) {
      A[N-1] = An;
      std::vector<int> new_A = A;
      std::sort(new_A.begin(), new_A.end());
      int sum = 0;
      for (int i = 1; i < N-1; ++i) {
         sum += new_A[i];
      }
      if (sum >= X) {
         ans.push_back(An);
      }
   }

   if (ans.size() == 0) {
      std::cout << -1 << std::endl;
   }
   else {
      std::cout << ans[0] << std::endl;
   }

   return 0;
}
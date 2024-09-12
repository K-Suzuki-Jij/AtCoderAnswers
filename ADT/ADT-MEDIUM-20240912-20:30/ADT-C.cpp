#include <bits/stdc++.h>

int main() {
   int N;
   std::cin >> N;

   std::vector<int> A(N);

   for (int i = 0; i < N; ++i) {
      std::cin >> A[i];
   }

   std::sort(A.begin(), A.end());
   int ans = 0;
   for (int i = 0; i < N - 1; ++i) {
      if (A[i + 1] - A[i] != 1) {
         ans = A[i] + 1;
         break;
      }
   }

   std::cout << ans << std::endl;

   return 0;
}
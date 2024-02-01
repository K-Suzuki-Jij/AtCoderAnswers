#include <bits/stdc++.h>

int main() {
   int N;

   std::cin >> N;

   std::vector<int> A(N);
   std::vector<int> B(N);

   for (int i = 0; i < N; ++i) {
      std::cin >> A[i];
      std::cin >> B[i];
   }

   std::vector<std::vector<int>> ans(N, std::vector<int>(2));
   ans[0][0] = 1;
   ans[0][1] = 1;

   int mod = 998244353;

   for (int i = 1; i < N; ++i) {
      // 表
      if (A[i] != A[i - 1]) {
         ans[i][0] += ans[i - 1][0];
      }
      if (A[i] != B[i - 1]) {
         ans[i][0] += ans[i - 1][1];
      }

      // 裏
      if (B[i] != A[i - 1]) {
         ans[i][1] += ans[i - 1][0];
      }
      if (B[i] != B[i - 1]) {
         ans[i][1] += ans[i - 1][1];
      }

      ans[i][0] %= mod;
      ans[i][1] %= mod;
   }

   std::cout << (ans[N - 1][0] + ans[N - 1][1])%mod << std::endl;

   return 0;
}
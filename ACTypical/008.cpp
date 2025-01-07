#include <bits/stdc++.h>

int main() {
   int N;
   std::string S;
   std::cin >> N >> S;

   std::vector<std::vector<std::int64_t>> dp(N + 1, std::vector<std::int64_t>(8, 0));
   std::string atcoder = "atcoder";
   dp[0][0] = 1;

   for (int i = 0; i < N; ++i) {
      for (int j = 0; j <= 7; ++j) {
         dp[i + 1][j] += dp[i][j];
         dp[i + 1][j] %= 1000000007;
      }
      for (int j = 0; j <= 6; ++j) {
         if (S[i] == atcoder[j]) {
            dp[i + 1][j + 1] += dp[i][j];
            dp[i + 1][j + 1] %= 1000000007;
         }
      }
   }

   std::cout << dp[N][7] << std::endl;

}
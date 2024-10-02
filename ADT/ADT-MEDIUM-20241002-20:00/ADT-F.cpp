
#include <bits/stdc++.h>

bool isSubsetSumDP(const std::vector<int>& vec, int X) {
    int n = vec.size();
    
    // DPテーブルを初期化
    std::vector<std::vector<bool>> dp(n+1, std::vector<bool>(X+1, false));

    // 部分和が0の場合は必ず可能
    for (int i = 0; i <= n; ++i) {
        dp[i][0] = true;
    }

    // DPテーブルを埋めていく
    for (int i = 1; i <= n; ++i) {
        for (int sum = 1; sum <= X; ++sum) {
            // vec[i-1]を含めない場合
            dp[i][sum] = dp[i-1][sum];

            // vec[i-1]を含める場合
            if (vec[i-1] <= sum) {
                dp[i][sum] = dp[i][sum] || dp[i-1][sum - vec[i-1]];
            }
        }
    }

    return dp[n][X];
}

int main() {

   std::int32_t N, X;
   std::cin >> N >> X;

   std::vector<std::int32_t> a(N);
   std::vector<std::int32_t> b(N);
   std::vector<std::int32_t> diff(N);
   std::int32_t b_sum = 0;
   for (std::int32_t i = 0; i < N; i++) {
      std::cin >> a[i] >> b[i];
      b_sum += b[i];
      diff[i] = b[i] - a[i];
   }

   if (b_sum < X) {
      std::cout << "No" << std::endl;
      return 0;
   }
   else {
      if (isSubsetSumDP(diff, b_sum - X)) {
         std::cout << "Yes" << std::endl;
      }
      else {
         std::cout << "No" << std::endl;
      }
   }

   return 0;
}
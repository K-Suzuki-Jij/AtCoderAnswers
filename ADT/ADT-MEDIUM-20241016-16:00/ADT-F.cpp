#include <bits/stdc++.h>

int main() {
   int N;
   std::cin >> N;

   std::vector<std::vector<std::int64_t>> a(N + 1, std::vector<std::int64_t>(10, 0));

   a[2][1] = 2;
   a[2][2] = 3;
   a[2][3] = 3;
   a[2][4] = 3;
   a[2][5] = 3;
   a[2][6] = 3;
   a[2][7] = 3;
   a[2][8] = 3;
   a[2][9] = 2;

   for (int i = 2; i < N; ++i) {
      for (int j = 1; j <= 9; ++j) {
         if (j == 1) {
            a[i + 1][j] = (a[i][j] + a[i][j + 1]) % 998244353;
         }
         else if (j == 9) {
            a[i + 1][j] = (a[i][j - 1] + a[i][j]) % 998244353;
         }
         else {
            a[i + 1][j] = (a[i][j - 1] + a[i][j] + a[i][j + 1]) % 998244353;
         }
      }
   }

   const auto sum = std::accumulate(a[N].begin(), a[N].end(), std::int64_t(0));

   std::cout << sum % 998244353 << std::endl;
   return 0;
}

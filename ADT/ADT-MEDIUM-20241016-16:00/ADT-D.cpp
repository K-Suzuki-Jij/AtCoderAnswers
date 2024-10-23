#include <bits/stdc++.h>

bool CheckPair(const std::vector<int> &rows, std::pair<int, int> p) {
   for (std::size_t i = 0; i < rows.size() - 1; ++i) {
      if (rows[i] == p.first && rows[i + 1] == p.second) {
         return true;
      }
      else if (rows[i] == p.second && rows[i + 1] == p.first) {
         return true;
      }
   }
   return false;
}

int main() {

   int N, M;
   std::cin >> N >> M;

   std::vector<std::vector<int>> a(M, std::vector<int>(N, 0));
   for (int i = 0; i < M; ++i) {
      for (int j = 0; j < N; ++j) {
         std::cin >> a[i][j];
      }
   }

   std::vector<std::pair<int, int>> all_pairs;
   for (int i = 1; i <= N; ++i) {
      for (int j = i + 1; j <= N; ++j) {
         all_pairs.push_back({i, j});
      }
   }

   int ans = 0;
   for (const auto &p: all_pairs) {
      bool nn = false;
      for (int i = 0; i < M; ++i) {
         if (CheckPair(a[i], p)) {
            nn = true;
            break;
         }
      }

      if (!nn) {
         ans++;
      }
   }

   std::cout << ans << std::endl;

   return 0;
}
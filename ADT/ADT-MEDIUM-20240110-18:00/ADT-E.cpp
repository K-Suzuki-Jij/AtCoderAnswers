#include <bits/stdc++.h>

int main() {
   int N;
   std::cin >> N;

   std::vector<int> X(N), Y(N);
   std::unordered_map<int, std::vector<std::pair<int, int>>> y_map;
   for (int i = 0; i < N; ++i) {
      std::cin >> X[i] >> Y[i];
      y_map[Y[i]].push_back({i, X[i]});
   }

   for (auto &it: y_map) {
      std::sort(it.second.begin(), it.second.end(), [](const auto &a, const auto &b) {
         return a.second < b.second;
      });
   }

   std::string S;
   std::cin >> S;

   for (const auto &it: y_map) {
      for (std::int64_t i = 0; i < static_cast<std::int64_t>(it.second.size()) - 1; ++i) {
         const auto x_1 = it.second[i].second;
         const auto x_2 = it.second[i+1].second;
         const auto i_1 = it.second[i].first;
         const auto i_2 = it.second[i+1].first;
         if ((x_1 < x_2) && (S[i_1] == 'R') && (S[i_2] == 'L')) {
            std::cout << "Yes" << std::endl;
            return 0;
         }
         else if ((x_1 > x_2) && (S[i_1] == 'L') && (S[i_2] == 'R')) {
            std::cout << "Yes" << std::endl;
            return 0;
         }
      }
   }

   std::cout << "No" << std::endl;

   return 0;
}
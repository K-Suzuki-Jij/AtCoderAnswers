#include <bits/stdc++.h>

struct PairHash {
   template<class T1, class T2>
   std::size_t operator()(const std::pair<T1, T2> &p) const {
      std::size_t lhs = std::hash<T1>()(p.first), rhs = std::hash<T2>()(p.second);
      return lhs ^ (rhs + 0x9e3779b9 + (lhs << 6) + (lhs >> 2));
   }
};

int main() {
   int N;
   std::cin >> N;

   std::vector<std::pair<int, int>> coo(N);
   std::unordered_set<std::pair<int, int>, PairHash> coordinate_set;
   for (int i = 0; i < N; ++i) {
      std::cin >> coo[i].first;
      std::cin >> coo[i].second;
      coordinate_set.emplace(coo[i]);
   }

   std::int64_t ans = 0;
   for (int i = 0; i < N; ++i) {
      const auto x_1 = coo[i].first;
      const auto y_1 = coo[i].second;
      for (int j = i + 1; j < N; ++j) {
         const auto x_2 = coo[j].first;
         const auto y_2 = coo[j].second;
         if (x_1 != x_2 && y_1 != y_2) {
            if (coordinate_set.count({x_2, y_1}) == 1 && coordinate_set.count({x_1, y_2}) == 1) {
               ans++;
            }
         }
      }
   }

   std::cout << static_cast<std::int64_t>(ans/2) << std::endl;

   return 0;
}
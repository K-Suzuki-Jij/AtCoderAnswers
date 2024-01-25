#include <bits/stdc++.h>

struct PairHash {
   template<class T1, class T2>
   std::size_t operator()(const std::pair<T1, T2> &p) const {
      std::size_t lhs = std::hash<T1>()(p.first), rhs = std::hash<T2>()(p.second);
      return lhs ^ (rhs + 0x9e3779b9 + (lhs << 6) + (lhs >> 2));
   }
};

int main(void) {

   int N;
   std::cin >> N;

   std::vector<std::int64_t> x(N);
   std::vector<std::int64_t> y(N);

   std::unordered_set<std::pair<int, int>, PairHash> magics;

   for (int i = 0; i < N; i++) {
      std::cin >> x[i] >> y[i];
   }

   for (int i = 0; i < N; i++) {
      int x1 = x[i];
      int y1 = y[i];
      for (int j = i+1; j < N; j++) {
         int x2 = x[j];
         int y2 = y[j];
         int gcd = std::gcd(std::abs(x1 - x2), std::abs(y1 - y2));
         if (gcd == 1) {
            magics.insert({x1 - x2, y1 - y2});
            magics.insert({x2 - x1, y2 - y1});
         }
         else {
            int new_x = (x1 - x2)/gcd;
            int new_y = (y1 - y2)/gcd;
            if (magics.count({new_x, new_y}) == 0) {
               magics.insert({new_x, new_y});
            }
            if (magics.count({-new_x, -new_y}) == 0) {
               magics.insert({-new_x, -new_y});
            }
         }
      }
   }

   std::cout << magics.size() << std::endl;

   return 0;
}
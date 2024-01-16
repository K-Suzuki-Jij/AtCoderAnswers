#include <bits/stdc++.h>

struct PairHash {
   template<class T1, class T2>
   std::size_t operator()(const std::pair<T1, T2> &p) const {
      std::size_t lhs = std::hash<T1>()(p.first), rhs = std::hash<T2>()(p.second);
      return lhs ^ (rhs + 0x9e3779b9 + (lhs << 6) + (lhs >> 2));
   }
};

int main() {
   int H, W;
   std::cin >> H >> W;
   std::vector<std::string> G(H);

   for (int i = 0; i < H; ++i) {
      std::cin >> G[i];
   }

   std::unordered_set<std::pair<int, int>, PairHash> visited;
   std::pair<int, int> start = {0, 0};
   visited.emplace(start);

   bool looped = false;
   while (true) {
      if (G[start.first][start.second] == 'U') {
         if (start.first != 0) {
            start.first--;
         }
         else {
            break;
         }
      }
      else if (G[start.first][start.second] == 'D') {
         if (start.first != H - 1) {
            start.first++;
         }
         else {
            break;
         }
      }
      else if (G[start.first][start.second] == 'L') {
         if (start.second != 0) {
            start.second--;
         }
         else {
            break;
         }
      }
      else if (G[start.first][start.second] == 'R') {
         if (start.second != W - 1) {
            start.second++;
         }
         else {
            break;
         }
      }
      if (visited.count(start) == 1) {
         looped = true;
         break;
      }
      else {
         visited.emplace(start);
      }
   }
   
   if (looped) {
      std::cout << -1 << std::endl;
   }
   else {
      std::cout << start.first + 1 << " " << start.second + 1 << std::endl;
   }

   return 0;
}
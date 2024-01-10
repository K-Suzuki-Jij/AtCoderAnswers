#include <bits/stdc++.h>

int main() {
   int H, W;
   std::cin >> H >> W;
   std::vector<std::pair<int, int>> coo;
   for (int i = 0; i < H; ++i) {
      std::string S;
      std::cin >> S;
      for (int j = 0; j < W; ++j) {
         if (S[j] == 'o') {
            coo.push_back(std::make_pair(i, j));
         }
      }
   }

   std::cout << std::abs(coo[1].first - coo[0].first) + std::abs(coo[1].second - coo[0].second) << std::endl;

}
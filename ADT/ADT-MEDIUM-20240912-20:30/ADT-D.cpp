#include <bits/stdc++.h>

int main() {
   int H, W;
   std::cin >> H >> W;

   std::vector<std::vector<int>> B(W, std::vector<int>(H));

   for (int i = 0; i < H; ++i) {
      for (int j = 0; j < W; ++j) {
         int a;
         std::cin >> a;
         B[j][i] = a;
      }
   }

   for (int i = 0; i < W; ++i) {
      for (int j = 0; j < H; ++j) {
         std::cout << B[i][j] << " ";
      }
      std::cout << std::endl;
   }

   return 0;
}
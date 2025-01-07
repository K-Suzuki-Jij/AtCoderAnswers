#include <bits/stdc++.h>

int main() {
   int H, W;
   std::cin >> H >> W;
   
   std::vector<std::vector<int>> A(H, std::vector<int>(W));

   for (int i = 0; i < H; ++i) {
      for (int j = 0; j < W; ++j) {
         std::cin >> A[i][j];
      }
   }

   std::vector<int> r_sum(H, 0);
   std::vector<int> c_sum(W, 0);
   for (int i = 0; i < H; ++i) {
      for (int j = 0; j < W; ++j) {
         r_sum[i] += A[i][j];
         c_sum[j] += A[i][j];
      }
   }

   for (int i = 0; i < H; ++i) {
      for (int j = 0; j < W; ++j) {
         std::cout << r_sum[i] + c_sum[j] - A[i][j] << " ";
      }
      std::cout << std::endl;
   }

  
   return 0;
}
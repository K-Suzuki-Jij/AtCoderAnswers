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

   std::vector<std::string> S(H);
   for (int i = 0; i < H; ++i) {
      std::string temp;
      for (int j = 0; j < W; ++j) {
         if (A[i][j] == 0) {
            temp.push_back('.');
         }
         else {
            temp.push_back('A' + (A[i][j] - 1));
         }
      }
      S[i] = temp;
   }

   for (int i = 0; i < H; ++i) {
      std::cout << S[i] << std::endl;
   }
   

   return 0;
}

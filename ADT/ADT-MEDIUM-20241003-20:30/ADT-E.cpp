
#include <bits/stdc++.h>

void FindAndColor(const std::vector<std::string> &S, int i, int j, std::vector<std::vector<int>> &group_number, int current_group_number, int H, int W) {

   if (S[i][j] == '.') {
      return;
   }

   if (group_number[i][j] != -1) {
      return;
   }
   else {
      group_number[i][j] = current_group_number;
      if (i-1 >= 0) {
         FindAndColor(S, i-1, j, group_number, current_group_number, H, W);
      }
      if (i-1 >= 0 && j-1 >= 0) {
         FindAndColor(S, i-1, j-1, group_number, current_group_number, H, W);
      }
      if (i-1 >= 0 && j+1 < W) {
         FindAndColor(S, i-1, j+1, group_number, current_group_number, H, W);
      }
      if (j-1 >= 0) {
         FindAndColor(S, i, j-1, group_number, current_group_number, H, W);
      }
      if (j-1 >= 0 && i+1 < H) {
         FindAndColor(S, i+1, j-1, group_number, current_group_number, H, W);
      }
      if (i+1 < H) {
         FindAndColor(S, i+1, j, group_number, current_group_number, H, W);
      }
      if (i+1 < H && j+1 < W) {
         FindAndColor(S, i+1, j+1, group_number, current_group_number, H, W);
      }
      if (j+1 < W) {
         FindAndColor(S, i, j+1, group_number, current_group_number, H, W);
      }
   }

}


int main() {

   int H, W;
   std::cin >> H >> W;

   std::vector<std::string> S(H);
   for (int i = 0; i < H; ++i) {
      std::cin >> S[i];
   }

   std::vector<std::vector<int>> group_number(H, std::vector<int>(W, -1));
   std::unordered_set<int> group_set;

   for (int i = 0; i < H; ++i) {
      for (int j = 0; j < W; ++j) {
         if (S[i][j] == '#') {
            if (group_number[i][j] == -1) {
               int current_group_number = group_set.size();
               group_set.insert(current_group_number);
               FindAndColor(S, i, j, group_number, current_group_number, H, W);
            }
         }
      }
   }

   std::cout << group_set.size() << std::endl;

   return 0;
}
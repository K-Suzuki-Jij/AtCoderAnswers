#include <bits/stdc++.h>

int main() {

   int N, M, H, K;
   std::cin >> N >> M >> H >> K;

   std::string S;
   std::cin >> S;

   std::unordered_map<int, std::unordered_set<int>> item_coordinates;
   for (int i = 0; i < M; ++i) {
      int x, y;
      std::cin >> x >> y;
      item_coordinates[x].insert(y);
   }

   int stamina = H;
   int current_x = 0;
   int current_y = 0;

   bool possibility = true;
   for (int i = 0; i < N; ++i) {

      if (S[i] == 'R') {
         current_x++;
      }
      else if (S[i] == 'L') {
         current_x--;
      }
      else if (S[i] == 'U') {
         current_y++;
      }
      else if (S[i] == 'D') {
         current_y--;
      }


      stamina--;
      if (stamina < 0) {
         possibility = false;
         break;
      }      

      if (item_coordinates.count(current_x) > 0 && item_coordinates.at(current_x).count(current_y) > 0) {
         if (stamina < K) {
            stamina = K;
            item_coordinates.at(current_x).erase(current_y);
         }
      }
   }

   if (possibility) {
      std::cout << "Yes" << std::endl;
   }
   else {
      std::cout << "No" << std::endl;
   }

   return 0;
}
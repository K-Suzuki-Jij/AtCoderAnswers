#include <bits/stdc++.h>

void Search(int x, int y, std::vector<std::vector<char>> &c, std::vector<std::vector<int>> &visited) {
   if (x < 0 || x >= c.size() || y < 0 || y >= c[0].size() || c[x][y] == '#' || visited[x][y] == 1) {
      return;
   }

   visited[x][y] = 1;
   Search(x+1, y, c, visited);
   Search(x-1, y, c, visited);
   Search(x, y+1, c, visited);
   Search(x, y-1, c, visited);
}

int main(void) {
   int H, W;
   std::cin >> H >> W;

   std::vector<std::vector<char>> c(H, std::vector<char>(W));
   int start_x=0, start_y=0;
   int goal_x=0, goal_y=0;
   for (int i = 0; i < H; ++i) {
      for (int j = 0; j < W; ++j) {
         std::cin >> c[i][j];
         if (c[i][j] == 's') {
            start_x = i;
            start_y = j;
         }
         if (c[i][j] == 'g') {
            goal_x = i;
            goal_y = j;
         }
      }
   }
   std::vector<std::vector<int>> visited(H, std::vector<int>(W, 0));

   Search(start_x, start_y, c, visited);
   if (visited[goal_x][goal_y] == 1) {
      std::cout << "Yes" << std::endl;
   } else {
      std::cout << "No" << std::endl;
   }

   return 0; 
}

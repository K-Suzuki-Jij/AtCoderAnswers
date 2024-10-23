#include <bits/stdc++.h>

int main() {
   int N;
   std::cin >> N;

   std::string T;
   std::cin >> T;

   int current_x = 0;
   int current_y = 0;
   int current_direction_x = 1;
   int current_direction_y = 0;

   for (const auto s: T) {
      if (s == 'S') {
         current_x += current_direction_x;
         current_y += current_direction_y;
      }
      else {
         std::swap(current_direction_x, current_direction_y);
         current_direction_y *= -1;
      }
   }

   std::cout << current_x << " " << current_y << std::endl;

   return 0;
}

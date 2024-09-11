#include <bits/stdc++.h>

int main() {
   int N;
   std::cin >> N;

   std::vector<int> P(N + 1);

   for (int i = 2; i <= N; ++i) {
      std::cin >> P[i];
   }

   int current_number = N;
   int count = 0;
   while(true) {
      if (current_number == 1) {
         break;
      }
      current_number = P[current_number];
      count++;
   }

   std::cout << count << std::endl;

   return 0;
}
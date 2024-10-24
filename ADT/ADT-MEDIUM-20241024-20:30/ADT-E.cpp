#include <bits/stdc++.h>



int main() {
   int N, K;
   std::cin >> N >> K;

   std::vector<int> P(N);

   for (int i = 0; i < N; ++i) {
      int temp = 0;
      for (int j = 0; j < 3; ++j) {
         int v = 0;
         std::cin >> v;
         temp += v;
      }
      P[i] = temp;
   }

   auto sorted = P;
   std::sort(sorted.begin(), sorted.end(), std::greater<int>());

   for (int i = 0; i < N; ++i) {
      int possible = P[i] + 300;
      const auto it = std::lower_bound(sorted.begin(), sorted.end(), possible, std::greater<int>());
      if (it - sorted.begin() + 1 <= K) {
         std::cout << "Yes" << std::endl;
      }
      else {
         std::cout << "No" << std::endl;
      }
   }   

   return 0;
}

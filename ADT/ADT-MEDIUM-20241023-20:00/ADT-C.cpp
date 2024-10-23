#include <bits/stdc++.h>

int main() {
   int N;
   std::cin >> N;

   std::vector<std::pair<int, int>> coo(N);

   for (int i = 0; i < N; ++i) {
      std::cin >> coo[i].first >> coo[i].second;
   }

   std::vector<int> max_dist(N);

   for (int i = 0; i < N; ++i) {
      std::vector<int> temp(N);
      const auto x1 = coo[i].first;
      const auto y1 = coo[i].second;
      for (int j = 0; j < N; ++j) {
         const auto x2 = coo[j].first;
         const auto y2 = coo[j].second;
         temp[j] = (x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2);
      }
      max_dist[i] = std::distance(temp.begin(), std::max_element(temp.begin(), temp.end())) + 1;
   }

   for (const auto &it: max_dist) {
      std::cout << it << std::endl;
   }

   
   


   return 0;
}

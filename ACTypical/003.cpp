#include <bits/stdc++.h>

void dfs(const int from, const int now, const int dist, const std::vector<std::vector<int>> &G, std::vector<int> &dist_list) {
   dist_list[now] = dist;
   for (const auto &to : G[now]) {
      if (to == from) {
         continue;
      }
      dfs(now, to, dist + 1, G, dist_list);
   }
}


int main() {
   int N;
   std::cin >> N;
   
   std::vector<std::vector<int>> G(N +1);

   for (int i = 0; i < N - 1; ++i) {
      int a, b;
      std::cin >> a >> b;
      G[a].push_back(b);
      G[b].push_back(a);
   }

   std::vector<int> dist(N + 1, 0);
   dfs(-1, 1, 0, G, dist);

   const int idx = std::distance(dist.begin(), std::max_element(dist.begin(), dist.end()));
   std::fill(dist.begin(), dist.end(), 0);

   dfs(-1, idx, 0, G, dist);

   std::cout << *std::max_element(dist.begin(), dist.end()) + 1 << std::endl;   
   
   return 0;
}
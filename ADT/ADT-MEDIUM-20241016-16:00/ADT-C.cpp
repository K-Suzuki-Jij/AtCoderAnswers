#include <bits/stdc++.h>

int main() {

   int N, M;
   std::cin >> N >> M;

   std::vector<std::vector<int>> adj(N + 1);

   for (int i = 0; i < M; ++i) {
      int u, v;
      std::cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
   }

   for (auto &it: adj) {
      std::sort(it.begin(), it.end());
   }

   for (int i = 1; i <= N; ++i) {
      std::cout << adj[i].size() << " ";
      for (int j = 0; j < adj[i].size(); ++j) {
         std::cout << adj[i][j] << " ";
      }
      std::cout << std::endl;
   }

   return 0;
}
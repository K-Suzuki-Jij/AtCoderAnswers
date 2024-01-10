#include <bits/stdc++.h>

int main() {
   int N, M;
   std::cin >> N >> M;

   std::vector<std::vector<int>> graph(N+1);
   for (int i = 0; i <M; ++i) {
      int a, b;
      std::cin >> a >> b;
      graph[a].push_back(b);
      graph[b].push_back(a);
   }

   for (int i = 1; i <= N; ++i) {
      std::sort(graph[i].begin(), graph[i].end());
   }

   for (int i = 1; i <= N; ++i) {
      std::cout << graph[i].size() << " ";
      for (const auto &it: graph[i]) {
         std::cout << it << " ";
      }
      std::cout << std::endl;
   }
   return 0;
}
#include <bits/stdc++.h>

void dfs(const std::vector<std::vector<int>> &graph, int v, std::vector<int> &seen, std::vector<int> &ans) {
   seen[v] = 1;
   ans.push_back(v);
   for (auto next_v : graph[v]) { 
      if (seen[next_v] == 1) {
         continue;
      }
      dfs(graph, next_v, seen, ans);
      ans.push_back(v);
   }
}

int main() {
   int N;
   std::cin >> N;
   std::vector<std::vector<int>> graph(N+1);
   for (int i = 0; i < N - 1; ++i) {
      int a, b;
      std::cin >> a >> b;
      graph[a].push_back(b);
      graph[b].push_back(a);
   }

   for (int i = 1; i <= N; ++i) {
      std::sort(graph[i].begin(), graph[i].end());
   }

   std::vector<int> seen(N + 1);
   std::vector<int> ans;
   dfs(graph, 1, seen, ans);

   for (std::size_t i = 0; i < ans.size(); ++i) {
      std::cout << ans[i] << " ";
   }
   std::cout << std::endl;

   return 0;
}
#include <bits/stdc++.h>

bool find = false;

void DFS(const std::vector<std::vector<std::int32_t>> &graph, 
         std::vector<bool> &visited, 
         const std::int32_t v, 
         const std::int32_t to, 
         std::vector<std::int32_t> &history
         ) {

   if (!find) {
      history.push_back(v);
   }
   if (v == to) {
      find = true;
   }

   visited[v] = true;
   for (const auto& u : graph[v]) {
      if (!visited[u]) {
         DFS(graph, visited, u, to, history);
      }
   }
   if (!find) {
      history.pop_back();
   }
}

int main() {

   std::int32_t N, X, Y;
   std::cin >> N >> X >> Y;

   std::vector<std::vector<std::int32_t>> graph(N + 1);
   for (std::int32_t i = 0; i < N - 1; i++) {
      std::int32_t a, b;
      std::cin >> a >> b;
      graph[a].push_back(b);
      graph[b].push_back(a);
   }

   std::vector<bool> visited(N + 1, false);
   std::vector<std::int32_t> history;
   DFS(graph, visited, X, Y, history);

   for (const auto& v : history) {
      std::cout << v << " ";
   }

   return 0;
}
#include <bits/stdc++.h>

void Rec(int v, const std::vector<std::vector<int>> &graph, int &count, std::vector<bool> &visited) {
    visited[v] = true;  // このノードを訪問済みにする
    count++;
    for (int u : graph[v]) {
        if (!visited[u]) {  // まだ訪問していないノードだけ再帰
            Rec(u, graph, count, visited);
        }
    }
}

int main() {
    int N;
    std::cin >> N;

    std::vector<std::vector<int>> graph(N);

    for (int i = 0; i < N - 1; ++i) {
        int u, v;
        std::cin >> u >> v;
        u--;  // 0-indexed に変換
        v--;  // 0-indexed に変換
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    if (graph[0].size() == 1) {
        std::cout << 1 << std::endl;
        return 0;
    }

    std::vector<int> count_list;
    for (const auto &v : graph[0]) {
        std::vector<bool> visited(N, false);
        visited[0] = true;
        int c = 0;
        Rec(v, graph, c, visited);
        count_list.push_back(N - c);
    }

    std::cout << *std::min_element(count_list.begin(), count_list.end()) << std::endl;

    return 0;
}
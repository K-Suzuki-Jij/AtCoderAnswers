#include <iostream>
#include <vector>
#include <cassert>

bool dfs(const std::vector<std::vector<int>> &G, int v, std::vector<int> &Ans) {
   const int color = Ans[v]; //頂点 v は塗られている前提
   for (const auto &e: G[v]) {
      //頂点 e が塗られてないら塗って探索する
      if (Ans[e] == 0) {
         Ans[e] = -color;
         dfs(G, e, Ans);
      }
      else if (Ans[e] == color) {
         return false;
      }
   }
   return true;
}

int main(void) {
   int N, M;
   std::cin >> N >> M;
   std::vector<int> A(M), B(M);
   for (int i = 0; i < M; ++i) {
      std::cin >> A[i];
   }
   for (int i = 0; i < M; ++i) {
      std::cin >> B[i];
   }

   std::vector<std::vector<int>> G(N + 1);
   for (int i = 0; i < M; ++i) {
      G[A[i]].push_back(B[i]);
      G[B[i]].push_back(A[i]);
   }

   std::vector<int> Ans(N + 1);
   Ans[1] = +1;
   for (int i = 1; i < N + 1; ++i) {
      if (Ans[i] == 0) {
         Ans[i] = +1;
      }
      bool ans = dfs(G, i, Ans);
      if (!ans) {
         std::cout << "No" << std::endl;
         return 0;
      }
   }

   std::cout << "Yes" << std::endl;
   return 0;

}
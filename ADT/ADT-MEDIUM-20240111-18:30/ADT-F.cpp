#include <bits/stdc++.h>

int main() {
   int N;
   std::cin >> N;

   std::vector<int> A(3*N + 1);
   std::vector<std::vector<int>> b(N+1);
   for (int i = 1; i <= 3*N; ++i) {
      std::cin >> A[i];
      b[A[i]].push_back(i);  
   }

   std::vector<std::pair<int, int>> ans;
   for (int i = 0; i < N; ++i) {
      ans.push_back({b[i+1][1], i+1});
   }

   std::sort(ans.begin(), ans.end());

   for (int i = 0; i < N; ++i) {
      std::cout << ans[i].second << " ";
   }
   std::cout << std::endl;

   return 0;
}
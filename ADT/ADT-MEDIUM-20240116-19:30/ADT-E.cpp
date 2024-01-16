#include <bits/stdc++.h>

int main() {
   int N, Q;
   std::cin >> N >> Q;
   std::unordered_map<int, std::unordered_set<int>> adjacency_list;
   std::vector<std::string> ans; 

   for (int i = 0; i < Q; ++i) {
      int T, A, B;
      std::cin >> T >> A >> B;
      if (T == 1) {
         adjacency_list[A].emplace(B);
      }
      else if (T == 2) {
         adjacency_list[A].erase(B);
      }
      else if (T == 3) {
         if (adjacency_list.count(A) == 1 && 
            adjacency_list.count(B) == 1 &&
            adjacency_list.at(A).count(B) == 1 &&
            adjacency_list.at(B).count(A) == 1
            ) {
               ans.push_back("Yes");
         }
         else {
            ans.push_back("No");
         }
      }
   }

   for (int i = 0; i < ans.size(); ++i) {
      std::cout << ans[i] << std::endl;
   }

   return 0;
}
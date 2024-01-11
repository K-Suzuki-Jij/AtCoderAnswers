#include <bits/stdc++.h>

int main() {
   int N, M;
   std::cin >> N >> M;

   std::vector<std::string> S(N);
   for (int i = 0; i < N; ++i) {
      std::cin >> S[i];
   }

   std::unordered_set<std::string> T;
   for (int i = 0; i < M; ++i) {
      std::string tt;
      std::cin >> tt;
      T.emplace(tt);
   }

   for (int i = 0; i < N; ++i) {
      if (T.count(S[i]) > 0) {
         std::cout << "Yes" << std::endl;
      }
      else {
         std::cout << "No" << std::endl;
      }
   }


   return 0;
}
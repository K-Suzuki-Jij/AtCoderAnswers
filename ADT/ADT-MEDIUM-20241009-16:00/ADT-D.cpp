
#include <bits/stdc++.h>

int main() {
   std::string S;
   std::cin >> S;

   std::unordered_set<std::string> subset;
   for (int i = 0; i < S.size(); ++i) {
      for (int j = 1; j <= S.size() - i; ++j) {
         subset.insert(S.substr(i, j));
      }
   }

   std::cout << subset.size() << std::endl;

   return 0;
}
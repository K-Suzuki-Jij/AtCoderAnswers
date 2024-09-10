#include <bits/stdc++.h>

int main() {
   std::int64_t N;
   std::cin >> N;

   std::unordered_set<std::string> set;
   
   for (std::int64_t i = 0; i < N; ++i) {
      std::string s;
      std::cin >> s;
      const bool flag1 = set.count(s) == 0;
      std::reverse(s.begin(), s.end());
      const bool flag2 = set.count(s) == 0;
      if (flag1 && flag2) {
         set.insert(s);
      }
   }

   std::cout << set.size() << std::endl;
   
   return 0;
}
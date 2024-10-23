#include <bits/stdc++.h>

int main() {
   std::string S;
   std::cin >> S;

   std::unordered_map<char, std::int64_t> count;
   for (const auto s: S) {
      count[s]++;
   }

   std::int64_t ans = (S.size()*(S.size() - 1))/2;

   bool duplicate = false;
   for (const auto &it: count) {
      ans -= (it.second*(it.second - 1))/2;
      if (it.second > 1) {
         duplicate = true;
      }
   }

   if (duplicate) {
      ans++;
   }

   std::cout << ans << std::endl;

   return 0;
}

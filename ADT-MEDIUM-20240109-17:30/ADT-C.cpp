#include <bits/stdc++.h>

int main() {
   int N;
   std::cin >> N;

   std::unordered_map<std::string, int> num;

   for (int i = 0; i < N; ++i) {
      std::string S;
      std::cin >> S;
      num[S]++;
   }

   int max_num = 0;
   std::string ans = "";
   for (const auto &it: num) {
      if (max_num < it.second) {
         max_num = it.second;
         ans = it.first;
      }
   }

   std::cout << ans << std::endl;
}
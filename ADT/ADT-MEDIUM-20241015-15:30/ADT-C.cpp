#include <bits/stdc++.h>

int main() {

   std::string S;
   std::cin >> S;

   std::vector<std::string> all_s;
   for (std::size_t i = 0; i < S.size(); ++i) {
      all_s.push_back(S.substr(i) + S.substr(0, i));
   }

   const auto s_min = std::min_element(all_s.begin(), all_s.end());
   const auto s_max = std::max_element(all_s.begin(), all_s.end());

   std::cout << *s_min << std::endl;
   std::cout << *s_max << std::endl;

   return 0;
}
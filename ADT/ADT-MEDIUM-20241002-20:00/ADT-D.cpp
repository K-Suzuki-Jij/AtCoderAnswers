
#include <bits/stdc++.h>

int main() {

   std::string S;
   std::cin >> S;

   bool include_lower = false;
   bool include_upper = false;
   bool all_different = true;
   std::unordered_set<char> appeared_chars;
   
   for (std::size_t i = 0; i < S.size(); i++) {
      if (std::islower(S[i])) {
         include_lower = true;
      }
      if (std::isupper(S[i])) {
         include_upper = true;
      }
      if (appeared_chars.count(S[i]) > 0) {
         all_different = false;
      }
      else {
         appeared_chars.insert(S[i]);
      }
   }
   
   if (include_lower && include_upper && all_different) {
      std::cout << "Yes" << std::endl;
   }
   else {
      std::cout << "No" << std::endl;
   }

   return 0;
}
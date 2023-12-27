#include <iostream>
#include <vector>
#include <string>


int main(void) {
   std::string S;
   std::cin >> S;
   
   std::vector<char> ans;
   for (std::size_t i = 0; i < S.size(); ++i) {
      ans.push_back(S[i]);
      if (ans.size() >= 3) {
         if (ans[ans.size() - 1] == 'C' && ans[ans.size() - 2] == 'B' && ans[ans.size() - 3] == 'A') {
            ans.pop_back();
            ans.pop_back();
            ans.pop_back();
         }
      }
   }

   for (std::size_t i = 0; i < ans.size(); ++i) {
      std::cout << ans[i];
   }
   std::cout << std::endl;

   return 0;
}
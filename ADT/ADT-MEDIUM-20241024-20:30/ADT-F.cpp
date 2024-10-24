#include <bits/stdc++.h>

int main() {
   std::int64_t K;
   std::cin >> K;

   std::vector<int> ans;

   while(K > 0) {
      if (K % 2 == 0) {
         ans.push_back(0);
      }
      else {
         ans.push_back(2);
         K--;
      }
      K /= 2;
   }   

   for (int i = static_cast<int>(ans.size())  - 1; i >= 0; --i) {
      std::cout << ans[i];
   }

   std::cout << std::endl;

   return 0;
}

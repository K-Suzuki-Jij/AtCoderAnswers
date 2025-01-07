#include <bits/stdc++.h>

bool Check(const std::vector<char> &s) {
   int l = 0;
   int r = 0;
   for (std::size_t i = 0; i < s.size(); i++) {
      if (s[i] == '(') {
         l++;
      } 
      else {
         r++;
      }
      if (r > l) {
         return false;
      }
   }
   if (r != l) {
      return false;
   }

   return true;
}

int main() {
   int N;
   std::cin >> N;
   
   std::vector<std::vector<char>> ans;
   for (int bit = 0; bit < (1 << N); bit++) {
      int x = bit;
      std::vector<char> s;
      for (int i = 0; i < N; i++) {
         if (x % 2) {
            s.push_back('(');
         } else {
            s.push_back(')');
         }
         x /= 2;
      }
      if (Check(s)) {
         ans.push_back(s);
      }
   }

   std::sort(ans.begin(), ans.end());

   for (const auto &s : ans) {
      for (int i = 0; i < s.size(); i++) {
         std::cout << s[i];
      }
      std::cout << std::endl;
   }



   
   return 0;
}
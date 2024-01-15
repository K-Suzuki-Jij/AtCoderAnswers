#include <bits/stdc++.h>

int main() {
   std::string S;
   std::cin >> S;

   std::deque<char> T;
   int reverse_counter = 0;
   for (std::size_t i = 0; i < S.size(); ++i) {
      if (S[i] == 'R') {
         reverse_counter++;
      }
      else {
         if (reverse_counter%2 == 0) {
            T.push_back(S[i]);
         }
         else {
            T.push_front(S[i]);
         }
      }
   }

   std::string ans;
   std::int64_t size = static_cast<std::int64_t>(T.size());
   if (reverse_counter%2 == 0) {
      for (std::int64_t i = 0; i < size; ++i) {
         if (ans.size() > 0 && ans.back() == T[i]) {
            ans.pop_back();
         }
         else {
            ans.push_back(T[i]);
         }
      }
   }
   else {
      for (std::int64_t i = size - 1; i >= 0; --i) {
         if (ans.size() > 0 && ans.back() == T[i]) {
            ans.pop_back();
         }
         else {
            ans.push_back(T[i]);
         }
      }
   }
   
   std::cout << ans << std::endl;


}
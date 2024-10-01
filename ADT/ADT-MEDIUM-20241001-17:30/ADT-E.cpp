#include <bits/stdc++.h>

int ToNum(const char c) {
   return c - 'A' + 1;
}

int main() {

   std::string S;
   std::cin >> S;

   std::int64_t ans = 0;
   std::int64_t power = 1;
   for (int i = S.size() - 1; i >= 0; i--) {
      ans += ToNum(S[i]) * power;
      power *= 26;
   }
   std::cout << ans << std::endl;

   return 0;
}
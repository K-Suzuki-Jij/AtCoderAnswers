#include <bits/stdc++.h>

int main() {
   int L, R;
   std::cin >> L >> R;

   std::string S;
   std::cin >> S;

   std::string T;
   for (int i = 0; i < S.size(); ++i) {
      if (i < L - 1 || i >= R) {
         T.push_back(S[i]);
      }
      else {
         T.push_back(S[R - 1 - i + L - 1]);
      }
   }

   std::cout << T << std::endl;

   return 0;
}

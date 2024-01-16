#include <bits/stdc++.h>

int main() {

   int L, R;
   std::string S;

   std::cin >> L >> R;
   std::cin >> S;

   L = L - 1;
   R = R - 1;

   for (int i = 0; i < L; i++) {
      std::cout << S[i];
   }
   for (int i = R; i >= L; i--) {
      std::cout << S[i];
   }
   for (int i = R+1; i < S.size(); i++) {
      std::cout << S[i];
   }
   std::cout << std::endl;
   return 0;
}
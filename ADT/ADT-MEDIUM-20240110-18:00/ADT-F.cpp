#include <bits/stdc++.h>

int main() {
   int N, Q;
   std::cin >> N >> Q;
   
   std::string S;
   std::cin >> S;

   int start = 0;
   for (int i = 0; i < Q; ++i) {
      int num, x;
      std::cin >> num >> x;
      if (num == 1) {
         start += x;
         start %= N;
      }
      else if (num == 2) {
         if (x - start - 1 < 0) {
            x += N;
         }
         std::cout << S[(x - start - 1)%N] << std::endl;
      }
   }

   return 0;
}
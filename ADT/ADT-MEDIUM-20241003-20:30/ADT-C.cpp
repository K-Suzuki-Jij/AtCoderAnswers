#include <bits/stdc++.h>

int main() {

   int N, A, B;
   std::cin >> N >> A >> B;

   for (int a = 0; a < A*N; ++a) {
      for (int b = 0; b < B*N; ++b) {
         if ((a/A + b/B)%2 == 0) {
            std::cout << ".";
         }
         else {
            std::cout << "#";
         }
      }
      std::cout << std::endl;
   }
   return 0;
}
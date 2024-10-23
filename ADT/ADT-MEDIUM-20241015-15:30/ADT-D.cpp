#include <bits/stdc++.h>

int main() {

   std::int64_t N;
   std::cin >> N;

   std::int64_t num_zeros = 0;

   while (N > 0) {
      if (N%2 == 0) {
         ++num_zeros;
      }
      else {
         break;
      }
      N /= 2;
   }

   std::cout << num_zeros << std::endl;
   
   return 0;
}
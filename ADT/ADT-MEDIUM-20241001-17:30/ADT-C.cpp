#include <bits/stdc++.h>

int main() {

   std::int32_t N;
   std::cin >> N;

   std::vector<std::int32_t> A(N);
   for (std::int32_t i = 0; i < N; i++) {
      std::cin >> A[i];
   }

   std::int32_t ans = 0;
   while(true){
      std::sort(A.begin(), A.end(), [](int a, int b) {
         return a > b;
      });
      if (A[0] > 0 && A[1] > 0) {
         A[0]--;
         A[1]--;
         ans++;
      }
      else {
         break;
      }
   }

   std::cout << ans << std::endl;

   return 0;
}
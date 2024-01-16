#include <bits/stdc++.h>

int main() {
   int N;
   std::cin >> N;

   std::vector<int> A(N);
   for (int i = 0; i < A.size(); ++i) {
      std::cin >> A[i];
   }

   int ans = 0;
   for (int i = 0; i <= 2001; ++i) {
      bool not_included = true;
      for (int j = 0; j < N; ++j) {  
         if (A[j] == i) {
            not_included = false;
            break;
         }
      }
      if (not_included) {
         ans = i;
         break;
      }
   }

   std::cout << ans << std::endl;
   return 0;
}
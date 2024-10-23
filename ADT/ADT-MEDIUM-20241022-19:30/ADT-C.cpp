#include <bits/stdc++.h>

int main() {
   int N;
   std::cin >> N;

   std::unordered_set<int> A;
   for (int i = 0; i < N; ++i) {
      int a;
      std::cin >> a;
      A.insert(a);
   }

   int ans = 0;
   for (int i = 0; i <= N + 1; ++i) {
      if (A.count(i) == 0) {
         ans = i;
         break;
      }
   }

   std::cout << ans << std::endl;


   return 0;
}

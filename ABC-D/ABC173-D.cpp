#include <bits/stdc++.h>

int main() {
   int N;
   std::cin >> N;

   std::vector<int> A(N);
   for (int i = 0; i < N; ++i) {
      std::cin >> A[i];
   }

   std::sort(A.rbegin(), A.rend());

   std::int64_t sum = A[0];

   for (int i = 2; i < N; ++i) {
      sum += A[i/2];
   }    

   std::cout << sum << std::endl;


   return 0;
}
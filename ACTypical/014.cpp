#include <bits/stdc++.h>


int main() {

   int N;
   std::cin >> N;

   std::vector<int> A(N);
   for (int i = 0; i < N; i++) {
      std::cin >> A[i];
   }
   std::vector<int> B(N);
   for (int i = 0; i < N; i++) {
      std::cin >> B[i];
   } 

   std::sort(A.begin(), A.end());
   std::sort(B.begin(), B.end());

   std::int64_t sum = 0;
   for (int i = 0; i < N; i++) {
      sum += std::abs(A[i] - B[i]);
   }

   std::cout << sum << std::endl;

   return 0;
}
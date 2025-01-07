#include <bits/stdc++.h>

bool IsItPossibleToBeMinValue(const int v, int K, const std::vector<int> &A, const int N) {
   int sum = 0;
   K++;
   for (int i = 0; i <= N; i++) {
      if (A[i] - sum >= v) {
         sum = A[i];
         K--;
      }
   }
   return K <= 0;
}


int main() {
   int N, L, K;
   std::cin >> N >> L;
   std::cin >> K;

   std::vector<int> A(N + 1);

   for (int i = 0; i < N; i++) {
      std::cin >> A[i];
   }
   A[N] = L;

   int max_pice = (L + K)/(K + 1) + 1;
   int min_pice = 0;
   while (max_pice - min_pice > 1) {
      int mid = (max_pice + min_pice) / 2;
      const auto c = IsItPossibleToBeMinValue(mid, K, A, N);
      if (c) {
         min_pice = mid;
      } else {
         max_pice = mid;
      }
   }

   std::cout << min_pice << std::endl;
   
   return 0;
}
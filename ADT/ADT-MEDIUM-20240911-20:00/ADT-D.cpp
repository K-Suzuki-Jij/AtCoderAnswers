#include <bits/stdc++.h>

int main() {
   int N, K, Q;
   std::cin >> N >> K >> Q;
   std::vector<int> A(K), L(Q);

   for (int i = 0; i < K; ++i) {
      std::cin >> A[i];
   }

   for (int i = 0; i < Q; ++i) {
      std::cin >> L[i];
   }

   std::vector<int> coo_status(N + 1);
   std::vector<int> positions(K);
   for (int i = 0; i < K; ++i) {
      coo_status[A[i]] = 1;
      positions[i] = A[i];
   }

   for (int i = 0; i < Q; ++i) {
      if (positions[L[i] - 1] == N) {
         continue;
      }
      else if (coo_status[positions[L[i] - 1] + 1] == 0) {
         coo_status[positions[L[i] - 1]] = 0;
         coo_status[positions[L[i] - 1] + 1] = 1;
         positions[L[i] - 1]++;
      }
   }

   for (int i = 0; i < K; ++i) {
      std::cout << positions[i] << " ";
   }
   std::cout << std::endl;

   return 0;
}
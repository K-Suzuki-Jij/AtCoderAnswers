
#include <bits/stdc++.h>

int main() {
   int N, M;
   std::cin >> N >> M;
   std::vector<int> A(M);

   for (int i = 0; i < M; ++i) {
      std::cin >> A[i];
   }

   std::vector<std::vector<int>> X(N, std::vector<int>(M));
   for (int i = 0; i < N; ++i) {
      for (int j = 0; j < M; ++j) {
         std::cin >> X[i][j];
      }
   }

   std::vector<int> energy(M);
   for (int i = 0; i < M; ++i) {
      for (int j = 0; j < N; ++j) {
         energy[i] += X[j][i];
      }
   }

   bool achive = true;
   for (int i = 0; i < M; ++i) {
      if (energy[i] < A[i]) {
         achive = false;
         break;
      }
   }

   if (achive) {
      std::cout << "Yes" << std::endl;
   }
   else {
      std::cout << "No" << std::endl;
   }

   return 0;
}
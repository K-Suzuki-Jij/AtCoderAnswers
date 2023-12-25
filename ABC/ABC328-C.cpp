#include <iostream>
#include <string>
#include <vector>

int main(void) {
   int N, Q;
   std::cin >> N >> Q;

   std::string S;
   std::cin >> S;

   std::vector<int> L(Q);
   std::vector<int> R(Q);
   for (int i = 0; i < Q; ++i) {
      std::cin >> L[i] >> R[i];
   }

   std::vector<int> A(N);
   A[0] = 0;
   for (int i = 0; i < N - 1; ++i) {
      if (S[i] == S[i + 1]) {
         A[i + 1]++;
      }
   }
   for (int i = 0; i < N - 1; ++i) {
      A[i + 1] += A[i];
   }

   for (int i = 0; i < Q; ++i) {
      std::cout << A[R[i] - 1] - A[L[i] - 1] << std::endl;
   }
   
   return 0;
}
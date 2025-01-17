#include <bits/stdc++.h>

int main() {
   int N;
   std::cin >> N;

   std::vector<int> C(N);
   std::vector<int> P(N);
   for (int i = 0; i < N; ++i) {
      std::cin >> C[i] >> P[i];
   }

   int Q;
   std::cin >> Q;

   std::vector<int> L(Q);
   std::vector<int> R(Q);
   for (int i = 0; i < Q; ++i) {
      std::cin >> L[i] >> R[i];
   } 

   std::vector<int> sum_1(N + 1);
   std::vector<int> sum_2(N + 1);

   for (int i = 0; i < N; ++i) {
      const std::int32_t point_1 = (C[i] == 1) ? P[i] : 0;
      const std::int32_t point_2 = (C[i] == 2) ? P[i] : 0;
      sum_1[i + 1] = sum_1[i] + point_1;
      sum_2[i + 1] = sum_2[i] + point_2;
   }

   for (int i = 0; i < Q; ++i) {
      std::cout << sum_1[R[i]] - sum_1[L[i] - 1] << " " << sum_2[R[i]] - sum_2[L[i] - 1] << std::endl;
   }



   return 0;
}

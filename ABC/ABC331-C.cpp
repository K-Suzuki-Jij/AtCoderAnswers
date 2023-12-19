#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <unordered_map>
#include <algorithm>

int main(void) {
   
   int N;
   std::cin >> N;
   std::int64_t sum = 0;

   std::vector<int> A(N);
   for (int i = 0; i < N; ++i) {
      std::cin >> A[i];
      sum += A[i];
   }

   std::vector<int> B = A;
   std::sort(A.begin(), A.end());
   std::unordered_map<std::int64_t, std::int64_t> sum_A;

   std::int64_t temp_sum = 0;
   for (int i = 0; i < N - 1; ++i) {
      if (A[i] != A[i + 1]) {
         temp_sum += A[i];
         sum_A[A[i]] = sum - temp_sum;
      }
      else {
         temp_sum += A[i];
      }
   }

   for (int i = 0; i < N; ++i) {
      std::cout << sum_A[B[i]] << " ";
   }
   std::cout << std::endl;

   return 0;

}
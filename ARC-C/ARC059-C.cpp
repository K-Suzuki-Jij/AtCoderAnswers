#include <bits/stdc++.h>

int main() {
   int N; 
   std::cin >> N;

   std::vector<std::int64_t> a(N);
   double sum = 0.0;
   for (int i = 0; i < N; ++i) {
      std::cin >> a[i];
      sum += a[i];
   }
   std::int64_t x_1 = std::ceil(sum/N);
   std::int64_t x_2 = std::floor(sum/N);
   std::int64_t ans_1 = 0;
   std::int64_t ans_2 = 0;
   for (int i = 0; i < N; ++i) {
      ans_1 += (a[i] - x_1)*(a[i] - x_1);
      ans_2 += (a[i] - x_2)*(a[i] - x_2);
   }
   
   std::cout << std::min(ans_1, ans_2) << std::endl;

   return 0;
}
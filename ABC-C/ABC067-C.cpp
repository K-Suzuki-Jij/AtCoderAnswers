#include <bits/stdc++.h>

int main(void) {

   int N;
   std::cin >> N;

   std::vector<std::int64_t> a(N);

   std::int64_t sum = 0;
   for (int i = 0; i < N; i++) {
      std::cin >> a[i];
      sum += a[i];
   }

   std::int64_t x = a[0];
   std::int64_t y = sum - a[0];
   std::vector<std::int64_t> diff(N-1);
   for (int i = 0; i < N-1; i++) {
      diff[i] = std::abs(x - y);
      x += a[i+1];
      y -= a[i+1];
   }

   std::cout << *std::min_element(diff.begin(), diff.end()) << std::endl;


   return 0;
}
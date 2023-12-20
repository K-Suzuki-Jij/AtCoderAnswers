#include <iostream>
#include <cmath>
#include <algorithm>

std::int64_t MIN(std::int64_t D, std::int64_t y) {
   const std::int64_t x_1 = std::floor(std::sqrt(D - y*y));
   const std::int64_t x_2 = std::ceil(std::sqrt(D - y*y));
   return std::min(
      std::abs(x_1*x_1 + y*y - D),
      std::abs(x_2*x_2 + y*y - D)
   );
}

int main(void) {
   std::int64_t D;
   std::cin >> D;

   std::int64_t max_y = std::ceil(std::sqrt(D));
   std::int64_t ans = std::numeric_limits<std::int64_t>::max();
   for (std::int64_t y = 0; y <= max_y; ++y) {
      ans = std::min(ans, MIN(D, y));
   }
   std::cout << ans << std::endl;

   return 0;
} 
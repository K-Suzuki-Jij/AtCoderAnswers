#include <bits/stdc++.h>

int main() {
   int K;
   std::cin >> K;

   std::vector<std::int64_t> ff;

   for (int bit = 2; bit < (1 << 10); ++bit) {
      std::int64_t num = 0;
      std::vector<int> f;
      for (int i = 0; i < 10; ++i) {
         if (bit & (1 << i)) {
            f.push_back(i);
         }
      }
      std::sort(f.begin(), f.end());
      for (int i = 0; i < f.size(); ++i) {
         num += f[i]*std::pow(10, i);
      }
      ff.push_back(num);
   }

   // for (int i = 0; i < (1 << 10) - 2; ++i) {
   //    std::cout << ff[i] << std::endl;
   // }

   std::sort(ff.begin(), ff.end());

   std::cout << ff[K-1] << std::endl;

   return 0;
}
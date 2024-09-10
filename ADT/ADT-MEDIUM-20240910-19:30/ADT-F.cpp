#include <bits/stdc++.h>

int main() {
   std::int64_t N;
   std::cin >> N;
   std::vector<std::string> S(N);

   for (std::int64_t i = 0; i < N; ++i) {
      std::cin >> S[i];
   }

   std::vector<int> time_vec(10, 0);
   for (int i = 0; i < 10; ++i) {
      std::vector<int> temp(10, 0);
      for (int j = 0; j < N; ++j) {
         for (int k = 0; k < 10; ++k) {
            if (S[j][k] - '0' == i) {
               temp[k]++;
            }
         }
      }
      std::vector<int> temp_time(10, 0);
      for (int j = 0; j < 10; ++j) {
         temp_time[j] = j + (temp[j] - 1)*10;
      }
      time_vec[i] = *std::max_element(temp_time.begin(), temp_time.end());
   }


   std::cout << *std::min_element(time_vec.begin(), time_vec.end()) << std::endl;

   return 0;
}
#include <bits/stdc++.h>

int main() {
   int N;
   std::cin >> N;

   std::vector<int> j_list;
   for (int j = 1; j <= 9; ++j) {
      if (N % j == 0) {
         j_list.push_back(j);
      }
   }

   for (int i = 0; i <= N; ++i) {
      int flag = 0;
      for (int j = 1; j <=9; ++j) {
         if ((N%j == 0) && (i%(N/j) == 0)) {
            std::cout << j;
            flag = 1;
            break;
         }
      }
      if (flag == 0) {
         std::cout << "-";
      }
   }
   std::cout << std::endl;
   return 0;

}
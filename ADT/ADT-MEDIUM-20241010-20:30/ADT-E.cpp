
#include <bits/stdc++.h>

int main() {

   std::int64_t N, M;
   std::cin >> N >> M;
   std::vector<std::vector<std::int64_t>> B(N+1, std::vector<std::int64_t>(M+1));

   for (std::int64_t i = 1; i <= N; ++i) {
      for (std::int64_t j = 1; j <= M; ++j) {
         std::cin >> B[i][j];
      }
   }

   bool col_is_subset = true;
   for (std::int64_t i = 1; i <= N; ++i) {
      for (std::int64_t j = 1; j < M; ++j) {
         if (B[i][j + 1] - B[i][j] != 1) {
            col_is_subset = false;
            break;
         }
      }
      if (!col_is_subset) {
         break;
      }
   }

   bool row_is_subset = true;
   for (std::int64_t j = 1; j <= M; ++j) {
      for (std::int64_t i = 1; i < N; ++i) {
         if (B[i + 1][j] - B[i][j] != 7) {
            row_is_subset = false;
            break;
         }
      }
      if (!row_is_subset) {
         break;
      }
   }

   bool check_boundary = true;
   for (std::int64_t i = 1; i <= N; ++i) {
      for (std::int64_t j = 1; j <= M; ++j) {
         if (B[i][j]%7 == 0 && j != M) {
            check_boundary = false;
            break;
         }
      }
      if (!check_boundary) {
         break;
      }
   }

   if (col_is_subset && row_is_subset && check_boundary) {
      std::cout << "Yes" << std::endl;
   } 
   else {
      std::cout << "No" << std::endl;
   }



   return 0;
}

#include <bits/stdc++.h>

bool Check(const std::vector<int> &cols, const std::vector<int> &c, const std::vector<int> &coo_list) {
   if (coo_list[cols[0]] < coo_list[cols[2]] && coo_list[cols[1]] < coo_list[cols[2]]) {
      if (c[cols[0]] == c[cols[1]] && c[cols[1]] != c[cols[2]]) {
         return false;
      }
   }
   if (coo_list[cols[0]] < coo_list[cols[1]] && coo_list[cols[2]] < coo_list[cols[1]]) {
      if (c[cols[0]] == c[cols[2]] && c[cols[2]] != c[cols[1]]) {
         return false;
      }
   }
   if (coo_list[cols[1]] < coo_list[cols[0]] && coo_list[cols[2]] < coo_list[cols[0]]) {
      if (c[cols[1]] == c[cols[2]] && c[cols[2]] != c[cols[0]]) {
         return false;
      }
   }
   return true;
}


int main() {

   std::vector<int> c(9);
   for (int i = 0; i < 9; ++i) {
      std::cin >> c[i];
   }

   std::vector<int> coo_list = {0,1,2,3,4,5,6,7,8};

   std::vector<int> row0 = {0,1,2};
   std::vector<int> row1 = {3,4,5};
   std::vector<int> row2 = {6,7,8};

   std::vector<int> col0 = {0,3,6};
   std::vector<int> col1 = {1,4,7};
   std::vector<int> col2 = {2,5,8};

   std::vector<int> diag0 = {0,4,8};
   std::vector<int> diag1 = {2,4,6};

   std::vector<std::vector<int>> all_rows = {row0, row1, row2, col0, col1, col2, diag0, diag1};
   std::int64_t disappointed = 0;
   std::int64_t all = 0;
   do {
      all++;
      for (const auto &row : all_rows) {
         if (!Check(row, c, coo_list)) {
            disappointed++;
            break;
         }
      }
   } while (std::next_permutation(coo_list.begin(), coo_list.end()));

   std::cout << std::fixed << std::setprecision(15);
   std::cout << static_cast<double>(all - disappointed)/all << std::endl;

   return 0;
}
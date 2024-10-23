#include <bits/stdc++.h>

bool isSame(const std::vector<std::vector<int>> &A, const std::vector<std::vector<int>> &B) {
   if (A.size() == B.size() && A[0].size() == B[0].size()) {
      for (int i = 0; i < A.size(); ++i) {
         for (int j = 0; j < A[0].size(); ++j) {
            if (A[i][j] != B[i][j]) {
               return false;
            }
         }
      }
   }
   else {
      return false;
   }
   return true;
}

void Combinations(const std::vector<int>& vec, int n, std::vector<int>& combination, 
                  std::vector<std::unordered_set<int>>& all_combinations, int index) {
   if (combination.size() == n) {
      std::unordered_set<int> combination_set(combination.begin(), combination.end());
      all_combinations.push_back(combination_set);
      return;
   }

   for (int i = index; i < vec.size(); ++i) {
      combination.push_back(vec[i]);
      Combinations(vec, n, combination, all_combinations, i + 1);
      combination.pop_back();
   }
}

std::vector<std::vector<int>> MakeErasedMat(const std::vector<std::vector<int>> &A, 
                                             const std::unordered_set<int> &erase_rows, 
                                             const std::unordered_set<int> &erase_columns) {
   int row = A.size() - erase_rows.size();
   int column = A[0].size() - erase_columns.size();
   std::vector<std::vector<int>> erased_mat(row, std::vector<int>(column));
   
   int temp_row = 0;
   for (int i = 0; i < A.size(); ++i) {
      if (erase_rows.count(i) == 0) {
         int temp_column = 0;
         for (int j = 0; j < A[0].size(); ++j) {
            if (erase_columns.count(j) == 0) {
               erased_mat[temp_row][temp_column] = A[i][j];
               temp_column++;
            }
         }
         temp_row++;
      }
   }
   return erased_mat;
}


int main() {
   int H1, W1;
   std::cin >> H1 >> W1;
   
   std::vector<std::vector<int>> A(H1, std::vector<int>(W1));
   for (int i = 0; i < H1; ++i) {
      for (int j = 0; j < W1; ++j) {
         std::cin >> A[i][j];
      }
   }

   int H2, W2;
   std::cin >> H2 >> W2;

   std::vector<std::vector<int>> B(H2, std::vector<int>(W2));
   for (int i = 0; i < H2; ++i) {
      for (int j = 0; j < W2; ++j) {
         std::cin >> B[i][j];
      }
   }

   std::vector<int> row_list(H1);
   std::vector<int> column_list(W1);

   std::iota(row_list.begin(), row_list.end(), 0);
   std::iota(column_list.begin(), column_list.end(), 0);

   std::vector<std::unordered_set<int>> erase_rows;
   std::vector<std::unordered_set<int>> erase_columns;

   std::vector<int> temp1;
   Combinations(row_list, H1 - H2, temp1, erase_rows, 0);
   std::vector<int> temp2;
   Combinations(column_list, W1 - W2, temp2, erase_columns, 0);

   for (std::size_t i = 0; i < erase_rows.size(); ++i) {
      for (std::size_t j = 0; j < erase_columns.size(); ++j) {
         if (isSame(MakeErasedMat(A, erase_rows[i], erase_columns[j]), B)) {
            std::cout << "Yes" << std::endl;
            return 0;
         }
      }

   }

   std::cout << "No" << std::endl;

   return 0;
}

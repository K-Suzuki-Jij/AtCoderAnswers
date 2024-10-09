#include <bits/stdc++.h>

int main() {

   int N;
   std::cin >> N;

   std::vector<int> A(N);
   std::vector<char> S(N);
   
   for (int i = 0; i < N; ++i) {
      std::cin >> A[i] >> S[i];
   }
   
   int tired_count = 0;
   int left_position = 0;
   int right_position = 0;
   for (int i = 0; i < N; ++i) {
      if (S[i] == 'L') {
         if (left_position == 0) {
            left_position = A[i];
         }
         else {
            tired_count += std::abs(A[i] - left_position);
            left_position = A[i];
         }
      }
      else {
         if (right_position == 0) {
            right_position = A[i];
         }
         else {
            tired_count += std::abs(A[i] - right_position);
            right_position = A[i];
         }
      }
   }

   std::cout << tired_count << std::endl;


   return 0;
}
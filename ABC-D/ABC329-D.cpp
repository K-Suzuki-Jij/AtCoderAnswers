#include <iostream>
#include <vector>
#include <utility>

int main(void) {
   int N, M;
   std::cin >> N >> M;

   std::vector<int> A(M);
   for (int i = 0; i < M; ++i) {
      std::cin >> A[i];
   }

   std::vector<int> Point(N);
   std::pair<int, int> ans;
   Point[A[0]]++;
   ans.first = A[0];
   ans.second = Point[A[0]];
   std::cout << ans.first << std::endl;

   for (int i = 1; i < M; ++i) {
      Point[A[i]]++;
      // 今入った票が、すでに当選者だった場合
      if (ans.first == A[i]) {
         std::cout << ans.first << std::endl;
         ans.second = Point[A[i]];
      }
      else {
         // 今入った票が、現在の当選者よりも多かった場合
         if (ans.second < Point[A[i]]) {
            ans.first = A[i];
            ans.second = Point[A[i]];
            std::cout << ans.first << std::endl;
         }
         // 今入った票が、現在の最多得票者と同じ票数だった場合
         else if (ans.second == Point[A[i]]) {
            // その票が入った人の番号が当選者よりも小さい場合
            if (A[i] < ans.first) {
               ans.first = A[i];
               ans.second = Point[A[i]];
               std::cout << ans.first << std::endl;
            }
            else {
               std::cout << ans.first << std::endl;
               ans.second = Point[A[i]];
            }
         }
         // 今入った票が、現在の最多得票者よりも少なかった場合
         else {
            std::cout << ans.first << std::endl;
         }
      }
   }

   return 0;
}
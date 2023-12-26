#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

int main(void) {

   int N;
   std::cin >> N;

   std::string S;
   std::cin >> S;

   // 文字列の切れ目を探す
   std::vector<int> boundary;
   boundary.push_back(0);
   for (int i = 0; i < N - 1; ++i) {
      if (S[i] != S[i + 1]) {
         boundary.push_back(i + 1);
      }
   }
   boundary.push_back(N);

   // 文字列の切れ目ごとに最大の連続文字数を求める
   std::unordered_map<char, int> max_sequential;
   for (std::size_t i = 0; i < boundary.size() - 1; ++i) {
      int count = boundary[i + 1] - boundary[i];
      max_sequential[S[boundary[i]]] = std::max(max_sequential[S[boundary[i]]], count);
   }

   // 最大連続文字数の合計を求める
   int count = 0;
   for (auto& e : max_sequential) {
      count += e.second;
   }

   std::cout << count << std::endl;

   return 0;
}
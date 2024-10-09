
#include <bits/stdc++.h>

void combine(const std::vector<std::vector<int>>& arrays, std::vector<int>& result, int depth, int K) {
    // 最後まで到達した場合、結果を出力
    if (depth == arrays.size()) {
         int sum = 0;
         for (int num : result) {
            sum += num;
         }

         if (sum%K == 0) {
            for (int num : result) {
               std::cout << num << " ";
            }
            std::cout << std::endl;
         }

        return;
    }

    // 現在の数列の各要素を順番に選択し、次のレベルに進む
    for (int i = 0; i < arrays[depth].size(); ++i) {
        result[depth] = arrays[depth][i]; // 現在の数列から1つ選択
        combine(arrays, result, depth + 1, K); // 次のレベルへ
    }
}

int main() {
   int N, K;
   std::cin >> N >> K;

   std::vector<int> R(N);
   std::vector<std::vector<int>> comb(N);
   
   for (int i = 0; i < N; ++i) {
      std::cin >> R[i];
      comb[i].resize(R[i]);
      std::iota(comb[i].begin(), comb[i].end(), 1);
   }

   std::vector<int> result(N);
   combine(comb, result, 0, K);



   return 0;
}
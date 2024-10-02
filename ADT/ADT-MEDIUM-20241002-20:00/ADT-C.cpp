#include <bits/stdc++.h>

int main() {

   std::int64_t N;
   std::cin >> N;

   std::vector<std::int64_t> A(N);
   std::unordered_map<std::int64_t, std::int64_t> map(N);
   for (std::int64_t i = 0; i < N; i++) {
      std::cin >> A[i];
      map[A[i]] = i;
   }

   std::sort(A.begin(), A.end());

   std::cout << map[A[N-2]] + 1 << std::endl;
   return 0;
}
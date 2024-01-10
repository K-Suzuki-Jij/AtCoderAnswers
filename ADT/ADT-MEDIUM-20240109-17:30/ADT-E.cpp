#include <bits/stdc++.h>

int main() {
   std::string X;
   std::cin >> X;

   std::vector<int> convert(X.size());
   for (std::size_t i = 0; i < X.size(); ++i) {
      int position = X[i] - 'a';
      convert[position] = i;
   }

   int N;
   std::cin >> N;

   std::vector<std::string> S(N);
   for (int i = 0; i < N; ++i) {
      std::string ss;
      std::cin >> ss;
      for (const auto &s: ss) {
         int position = s - 'a';
         S[i].push_back(char('a' + convert[position]));
      }
   }

   std::sort(S.begin(), S.end());

   for (const auto &s: S) {
      for (const auto &c: s) {
         int position = c - 'a';
         std::cout << X[position];
      }
      std::cout << std::endl;
   }

   return 0;
}
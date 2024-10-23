#include <bits/stdc++.h>

int main() {
   int N;
   std::cin >> N;

   std::vector<std::string> S(N);
   int max_len = 0;
   for (int i = 0; i < N; ++i) {
      std::cin >> S[i];
      max_len = std::max(max_len, (int)S[i].size());
   }

   std::vector<std::string> T(max_len);
   for (int i = 0; i < max_len; ++i) {
      std::string temp;
      for (int j = N - 1; j >= 0; --j) {
         if (S[j].size() > i) {
            temp.push_back(S[j][i]);
         }
         else {
            temp.push_back('*');
         }
      }
      T[i] = temp;
   }

   bool match = false;
   while (!match) {
      match = true;
      for (int i = 0; i < max_len; ++i) {
         if (T[i].back() == '*') {
            T[i].pop_back();
            match = false;
         }
      }
   }
   
   for (int i = 0; i < max_len; ++i) {
      std::cout << T[i] << std::endl;
   }


   return 0;
}

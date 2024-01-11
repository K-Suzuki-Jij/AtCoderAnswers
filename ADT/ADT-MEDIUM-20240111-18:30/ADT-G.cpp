#include <bits/stdc++.h>

int main() {

   int X, Y, Z;
   std::cin >> X >> Y >> Z;

   std::string S;
   std::cin >> S;

   std::int64_t size = static_cast<std::int64_t>(S.size());
   std::vector<std::vector<std::int64_t>> ans(size, std::vector<std::int64_t>(2));

   if (S[0] == 'a') {
      ans[0][0] = X;
      ans[0][1] = Z + Y;
   }
   else {
      ans[0][0] = Y;
      ans[0][1] = Z + X;
   }

   for (std::int64_t i = 1; i < size; ++i) {
      if (S[i] == 'a') {
         // To off
         ans[i][0] = std::min(ans[i - 1][0] + X, ans[i - 1][1] + Z + X);
         // To on
         ans[i][1] = std::min(ans[i - 1][0] + Z + Y, ans[i - 1][1] + Y);
      }
      else {
         // To off
         ans[i][0] = std::min(ans[i - 1][0] + Y, ans[i - 1][1] + Z + Y);
         // To on
         ans[i][1] = std::min(ans[i - 1][0] + Z + X, ans[i - 1][1] + X);
      }
   }

   std::cout << std::min(ans[size-1][0], ans[size-1][1]) << std::endl;

   return 0;
}
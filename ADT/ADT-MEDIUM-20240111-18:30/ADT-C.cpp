#include <bits/stdc++.h>

int main() {

   std::unordered_set<std::string> set = {
      "ABC", "ARC", "AGC", "AHC"
   };

   std::string S1, S2, S3;
   std::cin >> S1 >> S2 >> S3;

   set.erase(S1);
   set.erase(S2);
   set.erase(S3);
   std::cout << *set.begin() << std::endl;

   return 0;
}
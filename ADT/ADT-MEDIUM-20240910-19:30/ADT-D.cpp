#include <bits/stdc++.h>

int main() {
   std::unordered_set<std::string> contest_set = {"ABC", "ARC", "AGC", "AHC"};
   std::string s1, s2, s3;
   std::cin >> s1 >> s2 >> s3;
   contest_set.erase(s1);
   contest_set.erase(s2);
   contest_set.erase(s3);
   std::cout << *contest_set.begin() << std::endl;
   return 0;
}
#include <bits/stdc++.h>


int main () {

   int N;
   std::cin >> N;

   int A, B, C;
   std::cin >> A >> B >> C;

   std::vector<int> l;

   const int max = 9999;
   for (int a = 0; a <= max; ++a) {
      if (A * a > N) {
         break;
      }
      for (int b = 0; b <= max; ++b) {
         const int remain = N - A * a - B * b;
         if (remain < 0) {
            break;
         }
         if (remain % C == 0) {
            l.push_back(a + b + remain/C);
         }
      }
   }

   std::cout << *std::min_element(l.begin(), l.end()) << std::endl;
   
}
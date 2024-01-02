#include <bits/stdc++.h>

int main() {
   const long double PI = 3.1415926535897932384626433832795028841971;
   int a, b, x;
   std::cin >> a >> b >> x;

   std::cout << std::fixed;
   std::cout << std::setprecision(15);
   if (2*x < a*a*b) {
      long double top = a*b*b;
      long double bottom = 2*x;
      std::cout << 180*std::atan(top/bottom)/PI << std::endl;
   }
   else {
      long double top = 2*a*a*b - 2*x;
      long double bottom = a*a*a;
      std::cout << 180*std::atan(top/bottom)/PI << std::endl;
   }

   return 0;
}
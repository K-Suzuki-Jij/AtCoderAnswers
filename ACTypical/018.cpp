#include <bits/stdc++.h>

long double PI = 3.14159265358979;
std::pair<double, double> get_coo_from_time(const double e, const double total, const double L) {
   const double theta = 2 * PI * e / static_cast<double>(total);
   const double y = -0.5*L*sin(theta);
   const double z = 0.5*L - 0.5*L*cos(theta);
   return std::make_pair(y, z);
}

int main () {

   double T;
   std::cin >> T;

   double L, X, Y;
   std::cin >> L >> X >> Y;

   int Q;
   std::cin >> Q;

   
   std::vector<double> ans;
   for (int i = 0; i < Q; ++i) {
      double E;
      std::cin >> E;
      const auto [y, z] = get_coo_from_time(E, T, L);
      const double theta = atan2(z, sqrt(X*X + (Y-y)*(Y-y)));
      ans.push_back(theta * 180.0 / PI);
   }

   std::cout << std::fixed << std::setprecision(12);
   for (const auto& a : ans) {
      std::cout << a << std::endl;
   }

   return 0;
}
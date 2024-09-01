#include <bits/stdc++.h>

int main() {

   int N, K;
   std::cin >> N >> K;
   std::vector<std::pair<int, int>> P(N);

   for (int i = 0; i < N; ++i) {
      std::cin >> P[i].first;
      P[i].second = i;
   }

   std::sort(P.begin(), P.end());

   std::set<int> s;

   for (int i = 0; i < K; ++i) {
      s.insert(P[i].second);
   }

   int ans = *s.rbegin() - *s.begin();

   for (int i = 0; i < N - K; ++i) {
      s.erase(P[i].second);
      s.insert(P[i + K].second);
      ans = std::min(ans, *s.rbegin() - *s.begin());
   }

   std::cout << ans << std::endl;

}
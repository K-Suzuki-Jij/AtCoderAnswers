#include <bits/stdc++.h>

int main() {
   int N, K;
   std::cin >> N >> K;

   int R, S, P;
   std::cin >> R >> S >> P;
   std::string T;
   std::cin >> T;

   std::unordered_map<std::int64_t, std::pair<char, char>> hist;

   int ans = 0;
   for (std::size_t i = 0; i < T.size(); ++i) {
      if (T[i] == 'r') {
         if (hist.count(i - K) > 0) {
            if (hist.at(i - K).first == 'p' && hist.at(i - K).second == 'p') {
               hist[i].first = 'r';
               hist[i].second = 's';
            }
            else {
               ans += P;
               hist[i].first = 'p';
               hist[i].second = 'p';
            }
         }
         else {
            ans += P;
            hist[i].first = 'p';
            hist[i].second = 'p';
         }
      }
      else if (T[i] == 's') {
         if (hist.count(i - K) > 0) {
            if (hist.at(i - K).first == 'r' && hist.at(i - K).second == 'r') {
               hist[i].first = 's';
               hist[i].second = 'p';
            }
            else {
               ans += R;
               hist[i].first = 'r';
               hist[i].second = 'r';
            }
         }
         else {
            ans += R;
            hist[i].first = 'r';
            hist[i].second = 'r';
         }
      }
      else {
         if (hist.count(i - K) > 0) {
            if (hist.at(i - K).first == 's' && hist.at(i - K).second == 's') {
               hist[i].first = 'p';
               hist[i].second = 'r';
            }
            else {
               ans += S;
               hist[i].first = 's';
               hist[i].second = 's';
            }
         }  
         else {
            ans += S;
            hist[i].first = 's';
            hist[i].second = 's';
         }
      }
   }

   std::cout << ans << std::endl;

   return 0;
}
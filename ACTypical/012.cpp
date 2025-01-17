#include <bits/stdc++.h>

struct PairHash {
   template <class T1, class T2>
   std::size_t operator()(const std::pair<T1, T2> &p) const {
      const std::size_t lhs = std::hash<T1>()(p.first);
      const std::size_t rhs = std::hash<T2>()(p.second);
      return lhs ^ (rhs + 0x9e3779b9 + (lhs << 6) + (lhs >> 2));
   }
};

struct UnionFind {
   
   UnionFind(int H, int W) {
      for (int i = 0; i < H; ++i) {
         for (int j = 0; j < W; ++j) {
            parent[{i, j}] = {i, j};
         }
      }
   }

   std::pair<int, int> root(const std::pair<int, int> &p) {
      if (parent.at(p) == p) {
         return p;
      }
      else {
         return parent.at(p) = root(parent.at(p));
      }
   }

   void unite(std::pair<int, int> p, std::pair<int, int> q) {
      p = root(p);
      q = root(q);
      if (p == q) {
         return;
      }
      parent.at(p) = q;
   } 

   bool same(const std::pair<int, int> &p, const std::pair<int, int> &q) {
      return root(p) == root(q);
   }

   std::unordered_map<std::pair<int, int>, std::pair<int, int>, PairHash> parent;
};




int main() {
   int H, W;
   std::cin >> H >> W;
   int Q;
   std::cin >> Q;
   
   // 0 -> white, 1 -> red
   std::vector<std::string> ans_list;
   std::vector<std::vector<int>> grid(H, std::vector<int>(W, 0)); 
   UnionFind union_find(H, W);

   for (int i = 0; i < Q; ++i) {
      int t;
      std::cin >> t;
      if (t == 1) {
         int r, c;
         std::cin >> r >> c;
         r--; c--;
         grid[r][c] = 1;
         if (r - 1 >= 0 && grid[r - 1][c] == 1) {
            union_find.unite({r, c}, {r - 1, c});
         }
         if (r + 1 < H && grid[r + 1][c] == 1) {
            union_find.unite({r, c}, {r + 1, c});
         }
         if (c - 1 >= 0 && grid[r][c - 1] == 1) {
            union_find.unite({r, c}, {r, c - 1});
         }
         if (c + 1 < W && grid[r][c + 1] == 1) {
            union_find.unite({r, c}, {r, c + 1});
         }
      }
      else {
         int ra, ca, rb, cb;
         std::cin >> ra >> ca >> rb >> cb;
         ra--; ca--; rb--; cb--;
         if (grid[ra][ca] == 0 || grid[rb][cb] == 0) {
            ans_list.push_back("No");
            continue;
         }
         if (union_find.same({ra, ca}, {rb, cb})) {
            ans_list.push_back("Yes");
         }
         else {
            ans_list.push_back("No");
         }
      }
   }

   for (std::size_t i = 0; i < ans_list.size(); ++i) {
      std::cout << ans_list[i] << std::endl;
   }

   return 0;
}
# 3577.[统计计算机解锁顺序排列数](https://leetcode.cn/problems/count-the-number-of-computer-unlocking-permutations/)

```c++
class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        int n = complexity.size();
        if (*min_element(complexity.begin() + 1, complexity.end()) <= complexity[0]) {
            return 0;
        }

        int mod = 1000000007;
        int ans = 1;
        for (int i = 2; i < n; ++i) {
            ans = static_cast<long long>(ans) * i % mod;
        }
        return ans;
    }
};
```

# 3583.[统计特殊三元组](https://leetcode.cn/problems/count-special-triplets/)

```c++
class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        const int MOD = 1000000007;
        long long count=0;
        unordered_map<int,int> mp;
        for (auto i:nums)mp[i]++;
        unordered_map<int,int> now_mp;
        for (auto i:nums){

            long long left = now_mp[i*2];
            now_mp[i]++;
            long long right = mp[i*2]-now_mp[i*2];
            count+=left*right;
            count%=MOD;
        }
        return count;
    }
};
```



# 994.[腐烂的橘子](https://leetcode.cn/problems/rotting-oranges/)

```c++
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> q;
        int fresh = 0;

        // 初始化：将所有腐烂橘子入队，并统计新鲜橘子
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 2) {
                    q.emplace(i, j);
                } else if (grid[i][j] == 1) {
                    ++fresh;
                }
            }
        }

        // 如果没有新鲜橘子，直接返回 0
        if (fresh == 0) return 0;

        // 四个方向
        vector<pair<int, int>> dirs = {{-1,0}, {1,0}, {0,-1}, {0,1}};
        int minutes = 0;

        while (!q.empty() && fresh > 0) {
            int size = q.size(); 
            for (int k = 0; k < size; ++k) {
                auto [i, j] = q.front(); q.pop();
                for (auto& d : dirs) {
                    int ni = i + d.first, nj = j + d.second;
                    if (ni >= 0 && ni < m && nj >= 0 && nj < n && grid[ni][nj] == 1) {
                        grid[ni][nj] = 2;
                        --fresh;
                        q.emplace(ni, nj);
                    }
                }
            }
            ++minutes;
        }

        return fresh == 0 ? minutes : -1;
    }
};
```



# 1925.[统计平方和三元组的数目](https://leetcode.cn/problems/count-square-sum-triples/)

```c++
class Solution {
public:
    int countTriples(int n) {
        int count = 0;
        int x = n;
        for (int i=1;i<=x;i++) {
            for (int j=1;j<=x;j++) {
                double x = sqrt(i*i+j*j);
                if (x<=n&&abs(x-round(x))<0.000001) {
                    count++;
                }
            }
        }
        return count;
    }
};
```


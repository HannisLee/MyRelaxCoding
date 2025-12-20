# [944. 删列造序](https://leetcode.cn/problems/delete-columns-to-make-sorted/)

```c++
class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n - 1; j++) {
                if (strs[j][i] > strs[j + 1][i]) {
                    count++;
                    break;
                }
            }
        }
        return count;
    }
};
```

# [3606.优惠券校验器](https://leetcode.cn/problems/coupon-code-validator/)

```c++
class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        vector<string> validCodes;
        vector<pair<int, string>> temp; // (priority, code)

        unordered_map<string, int> prio = {
            {"electronics", 0},
            {"grocery", 1},
            {"pharmacy", 2},
            {"restaurant", 3}
        };

        for (int i = 0; i < code.size(); i++) {
            if (code[i].empty()) continue;

            bool valid = true;
            for (char c : code[i]) {
                if (!isalnum(c) && c != '_') {
                    valid = false;
                    break;
                }
            }
            if (!valid) continue;

            if (prio.count(businessLine[i]) == 0) continue;
            if (!isActive[i]) continue;

            temp.push_back({prio[businessLine[i]], code[i]});
        }

        sort(temp.begin(), temp.end(), [](const auto& a, const auto& b) {
            if (a.first != b.first) 
                return a.first < b.first; // 按业务线优先级
            return a.second < b.second;   // 同业务线下按字典序
        });

        vector<string> res;
        for (auto& p : temp) res.push_back(p.second);
        return res;
    }
};
```

# [290.单词规律](https://leetcode.cn/problems/word-pattern/)

```c++
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> mp1; // 用来存储字符到单词的映射
        unordered_map<string, char> mp2; // 用来存储单词到字符的映射
        int idx = 0;
        int last = 0;
        s.push_back(' '); // 给字符串末尾加一个空格，方便处理最后一个单词
        
        for (int i = 0; i < s.size(); i++) {
            if (isalpha(s[i])) {
                continue;
            }
            else {
                string temp = s.substr(last, i - last); 
                if (mp1.count(pattern[idx])) {
                    if (mp1[pattern[idx]] != temp) {
                        return false; 
                    }
                } else {
                    mp1[pattern[idx]] = temp; 
                }

                if (mp2.count(temp)) {
                    if (mp2[temp] != pattern[idx]) {
                        return false; 
                    }
                } else {
                    mp2[temp] = pattern[idx]; 
                }

                last = i + 1; 
                idx++; 
            }
        }
        
        
        return idx == pattern.size();
    }
};

```

# [3531.统计被覆盖的建筑](https://leetcode.cn/problems/count-covered-buildings/)

```c++
class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        
        vector<pair<int, int>> line(n+1, {n, -1});   // [min_y, max_y] for each row x
        vector<pair<int, int>> list(n+1, {n, -1});   // [min_x, max_x] for each col y

        for (auto& b : buildings) {
            int x = b[0], y = b[1];
            line[x].first = min(line[x].first, y);
            line[x].second = max(line[x].second, y);
            list[y].first = min(list[y].first, x);  
            list[y].second = max(list[y].second, x); 
        }

        int count = 0;
        for (auto& b : buildings) {
            int x = b[0], y = b[1];
            
            bool hasLeftRight = (line[x].first < y) && (line[x].second > y);
            
            bool hasUpDown = (list[y].first < x) && (list[y].second > x);
            if (hasLeftRight && hasUpDown) {
                count++;
            }
        }
        return count;
    }
};
```



# [3577.统计计算机解锁顺序排列数](https://leetcode.cn/problems/count-the-number-of-computer-unlocking-permutations/)

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

# [3583.统计特殊三元组](https://leetcode.cn/problems/count-special-triplets/)

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



# [994.腐烂的橘子](https://leetcode.cn/problems/rotting-oranges/)

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



# [1925.统计平方和三元组的数目](https://leetcode.cn/problems/count-square-sum-triples/)

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


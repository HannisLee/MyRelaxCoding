#include <bits/stdc++.h>
using namespace std;

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
                string temp = s.substr(last, i - last); // 提取当前的单词
                if (mp1.count(pattern[idx])) {
                    if (mp1[pattern[idx]] != temp) {
                        return false; // 如果字符对应的单词不匹配，返回 false
                    }
                } else {
                    mp1[pattern[idx]] = temp; // 正向映射
                }

                // 反向映射检查
                if (mp2.count(temp)) {
                    if (mp2[temp] != pattern[idx]) {
                        return false; // 如果单词对应的字符不匹配，返回 false
                    }
                } else {
                    mp2[temp] = pattern[idx]; // 反向映射
                }

                last = i + 1; // 更新下一个单词的起始位置
                idx++; // 移动到下一个字符
            }
        }

        // 如果处理完所有单词后，idx 与 pattern 的长度一致，则返回 true
        return idx == pattern.size();
    }
};



int main() {
    Solution s;

    vector<vector<int>> gg={{1,3},{3,2},{3,3},{3,5},{5,3}};
    cout<<s.wordPattern("abba","dog dog dog dog")<<endl;



    return 0;
}
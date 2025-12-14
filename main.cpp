#include <bits/stdc++.h>
using namespace std;

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

int main() {
    Solution s;

    vector<string> vec1={"GROCERY15","ELECTRONICS_50","DISCOUNT10"};
    vector<string> vec2={"grocery","electronics","invalid"};
    vector<bool> vec3 = {false,true,true};
    cout<<s.validateCoupons(vec1,vec2,vec3)<<endl;



    return 0;
}
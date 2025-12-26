#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        vector<int> pre(n + 1, 0);
        vector<int> suf(n + 1, 0);

        for (int i = 0; i < n; ++i) {
            pre[i + 1] = pre[i] + (customers[i] == 'N');
        }
        for (int i = n - 1; i >= 0; --i) {
            suf[i] = suf[i + 1] + (customers[i] == 'Y');
        }

        int minPenalty = INT_MAX;
        int bestHour = 0;
        for (int i = 0; i <= n; ++i) {
            int penalty = pre[i] + suf[i];
            if (penalty < minPenalty) {
                minPenalty = penalty;
                bestHour = i;
            }
        }
        return bestHour;
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
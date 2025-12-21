#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();
        int count = 0;
        int flag1=0;
        for (int i = 0; i < m; i++) {
            flag1=0;
            for (int j = 0; j < n - 1; j++) {
                if (strs[j][i] > strs[j + 1][i]) {
                    count++;
                    flag1=1;
                    break;
                }
            }
            if (flag1==0){
                return count;
            }
        }
        return count;
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
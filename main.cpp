#include <bits/stdc++.h>
using namespace std;

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

int main() {

    vector<vector<int>> gg={{2,1,1},{1,1,0},{0,1,1}};
    Solution s;
    cout<<s.orangesRotting(gg)<<endl;



    return 0;
}
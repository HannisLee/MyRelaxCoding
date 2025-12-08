#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> g;
    int m,n;
    int count=0;
    int flag_fresh = 0;
    void rout(int i,int j) {
        if (i<0||j<0||i>=m||j>=n) {
            return;
        }
        if (g[i][j]==1){
            g[i][j]=2;
            count++;
        }
    }
    int orangesRotting(vector<vector<int>>& grid) {
        g=grid;
        m =grid.size();
        n = grid[0].size();
        int round=0;
        int old=1;
        while (count!=old) {
            old =count;
            round++;
            flag_fresh=0;
            for (int i=0;i<m;i++) {
                for (int j=0;j<n;j++) {
                    if (g[i][j]==1) {
                        flag_fresh=1;
                    }
                    else if (g[i][j]==2) {
                        rout(i-1,j);
                        rout(i+1,j);
                        rout(i,j-1);
                        rout(i,j+1);
                    }
                }
            }
        }
        if (flag_fresh)return -1;
        else return round;
    }
};


int main() {

    vector<vector<int>> gg={{2,1,1},{1,1,0},{0,1,1}};
    Solution s;
    cout<<s.orangesRotting(gg)<<endl;



    return 0;
}
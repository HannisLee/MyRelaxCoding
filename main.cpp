#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {

        vector<pair<int, int>> line(n+1, {n, -1});
        vector<pair<int, int>> list(n+1, {n, -1});

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
int main() {
    Solution s;

    vector<vector<int>> gg={{1,3},{3,2},{3,3},{3,5},{5,3}};
    cout<<s.countCoveredBuildings(5,gg)<<endl;



    return 0;
}
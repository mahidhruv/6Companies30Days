class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int row = dungeon.size(), col = dungeon[0].size();
        vector<int> dpNeedHP(col + 1, 1e5);
        dpNeedHP[col - 1] = dpNeedHP[col] = 1;
        for (int i = row - 1; i >= 0; --i) {
            vector<int> temp(col + 1, 1e5);
            for (int j = col - 1; j >= 0; --j) {
                int minHP = -dungeon[i][j] + min(temp[j + 1], dpNeedHP[j]);
                temp[j] = minHP <= 0 ? 1 : minHP;
            }
            dpNeedHP = temp;
        }
        return dpNeedHP[0];
    }
};
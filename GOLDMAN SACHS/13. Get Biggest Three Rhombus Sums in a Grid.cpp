class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int  row = grid.size(), col = grid[0].size();

        // using set<int> takes much less memory, but is 3x slower
        priority_queue<int> pq;

        // size 0 Rhombus shapes
        for (auto& r : grid) {
            for (auto& c : r) pq.push(c);
        }

        // // size k Rhombus shapes
        for (int k = 1; k < min(row, col); ++k) {
            for (int i = 0; i + 2 * k < row; ++i) {
                for (int j = 0; j + 2 * k < col; ++j) {
                    int sum = 0;

                    // collecting data along 4 lines
                    for (int m = 0; m < k; ++m) {
                        sum += grid[i + k - m][j + m]; // left->up
                        sum += grid[i + m][j + k + m]; // top->right
                        sum += grid[i + k + m][j + 2 * k - m]; //right->down
                        sum += grid[i + 2 * k - m][j + k - m]; // bottom->left
                    }
                    pq.push(sum);
                }
            }
        }

        // formatting the answer 
        vector<int> ret;
        while (pq.empty() == false) {
            if (ret.empty() == true || ret.back() != pq.top()) {
                ret.push_back(pq.top());
            }
            if (ret.size() == 3) return ret;
            pq.pop();
        }
        return ret;
    }
};
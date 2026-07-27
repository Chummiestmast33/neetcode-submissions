class Solution {
   public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix[0].size();
        for (vector<int> row : matrix) {
            int l = 0;
            int r = n - 1;
            if (row[0] <= target && row[n - 1] >= target) {
                int m = 0;
                while (l <= r) {
                    m = l + (r - l) / 2;
                    if (row[m] == target) {
                        return true;
                    } else if (row[m] < target) {
                        l = m + 1;
                    } else {
                        r = m - 1;
                    }
                }
            }
        }
        return false;
    }
};

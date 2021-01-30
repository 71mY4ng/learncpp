#include <iostream>
#include <vector>

using namespace std;

/**
 * https://leetcode-cn.com/problems/search-a-2d-matrix-ii/
 * 
 * https://leetcode-cn.com/problems/er-wei-shu-zu-zhong-de-cha-zhao-lcof/
 * 
 */
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {

        if (matrix.empty() || matrix[0].empty())
            return false;

        vector<vector<bool>> m(matrix.size(), vector<bool>(matrix[0].size(), 0));
        return traversal(matrix, 0, 0, target, m);
    }

    bool traversal(vector<vector<int>> &matrix, int col, int row,
                   int target, vector<vector<bool>> &memo)
    {
        if (col >= matrix.size() || row >= matrix[0].size() || memo[col][row])
        {
            return false;
        }

        for (int i = col; i < matrix.size(); i++)
        {
            for (int j = row; j < matrix[i].size(); j++)
            {
                printf("i: %d, j: %d, v: %d\n", i, j, matrix[i][j]);
                memo[i][j] = true;

                if (matrix[i][j] == target) return true;
                
                if (matrix[i][j] < target) {
                    
                    if (traversal(matrix, i + 1, j, target, memo)
                        || traversal(matrix, i, j + 1, target, memo))
                    {
                        return true;
                    }
                }

                return false;
            }
        }
        
        return false;
    }
};



int main()
{

    vector<vector<int>> vec{
        {-1, 3}
    };

    cout << Solution().findNumberIn2DArray(vec, 3);

    return 0;
}
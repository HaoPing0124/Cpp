/*
题意：
    给定一个整体升序的二维矩阵 matrix，
    判断 target 是否存在于矩阵中。

思路：
    将二维矩阵看成长度为 n × m 的一维升序数组。

    使用二分查找寻找最后一个小于等于 target 的位置。

    left 表示最后一个小于等于 target 的位置；
    right 表示第一个严格大于 target 的位置。

    循环结束后，如果 left 是合法下标，
    并且对应元素等于 target，则说明目标值存在。

时间复杂度：O(log(n × m))
空间复杂度：O(1)
*/

#include "Algorithm_150.h"

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        if (matrix.empty() || matrix[0].empty())
        {
            return false;
        }

        int n = matrix.size();
        int m = matrix[0].size();

        int left = -1;
        int right = n * m;

        while (left + 1 < right)
        {
            int mid = left + (right - left) / 2;

            int row = mid / m;
            int col = mid % m;

            if (matrix[row][col] <= target)
            {
                left = mid;
            }
            else
            {
                right = mid;
            }
        }

        return left >= 0 &&
               matrix[left / m][left % m] == target;
    }
};
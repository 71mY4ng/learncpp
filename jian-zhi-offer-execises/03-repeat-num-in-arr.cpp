#include <iostream>
#include <vector>
#include <map>
#include <array>

using namespace std;

/**
 * https://leetcode-cn.com/problems/shu-zu-zhong-zhong-fu-de-shu-zi-lcof/
 * 
 */
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        
        map<int, int> m;
        
        for (auto &&num : nums)
        {
            m[num]++;
            
            if (m[num] > 1) {
                cout << num;
                return num;
            }
        }
        
        return 0;
    }

    int findRepeatNumberWithArr(vector<int>& nums) {
        const uint32_t size = 10e4;
        int arr[size];
        
        for (auto &&num : nums)
        {
            arr[num]++;
            if (arr[num] > 1) {
                cout << num;
                return num;
            }
        }
        
        return 0;
    }
};

int main() {
    Solution s;
    
    vector<int> vec{0, 1, 2, 3, 4, 11, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    s.findRepeatNumberWithArr(vec);
}
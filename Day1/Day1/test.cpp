#include <climits>
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param schedule int整型vector<vector<>>
     * @return bool布尔型
     */
    bool hostschedule(vector<vector<int> >& schedule) {
        int ret = INT_MIN;
        for (auto& t : schedule)
        {
            int num = t[t.size() - 1];
            if (ret > num) return false;
            ret = num;
        }
        return true;
    }
};

// 这个方法不行，可能是乱序



#include <climits>
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param schedule int整型vector<vector<>>
     * @return bool布尔型
     */
    bool hostschedule(vector<vector<int> >& schedule) {
        std::sort(schedule.begin(), schedule.end(), [](const std::vector<int>& a, const std::vector<int>& b)
            {
                return a.back() < b.back(); // 排序依据是每个活动的结束时间
            }
        );
        int ret = INT_MIN;
        for (auto& t : schedule)
        {
            int num = t.front();
            if (ret > num) return false;
            ret = t.back();
        }
        return true;
    }
};

// 难点 lambda 表达式 解决乱序问题


class Solution {
public:
    int triangleNumber(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        int ret = 0, n = nums.size() - 1;
        while (n >= 2)
        {
            int left = 0, right = n - 1;
            while (left < right)
            {
                if (nums[left] + nums[right] > nums[n]) ret += right - left, right--;
                else left++;
            }
            n--;
        }
        return ret;
    }
};

class Solution {
public:
    int triangleNumber(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        int ret = 0, n = nums.size() - 1;
        while (n >= 2)
        {
            int left = 0, right = n - 1;
            while (left < right)
            {
                if (nums[left] + nums[right] > nums[n]) ret += right - left, right--;
                // 由于已经排序了，只需要判断 nums[left] + nums[right] > nums[n] 即可
                else left++;
            }
            n--;
        }
        return ret;
    }
};

// 双指针 有效三角形的个数
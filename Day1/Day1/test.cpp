#include <climits>
class Solution {
public:
    /**
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     *
     *
     * @param schedule int����vector<vector<>>
     * @return bool������
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

// ����������У�����������



#include <climits>
class Solution {
public:
    /**
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     *
     *
     * @param schedule int����vector<vector<>>
     * @return bool������
     */
    bool hostschedule(vector<vector<int> >& schedule) {
        std::sort(schedule.begin(), schedule.end(), [](const std::vector<int>& a, const std::vector<int>& b)
            {
                return a.back() < b.back(); // ����������ÿ����Ľ���ʱ��
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

// �ѵ� lambda ����ʽ �����������


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
                // �����Ѿ������ˣ�ֻ��Ҫ�ж� nums[left] + nums[right] > nums[n] ����
                else left++;
            }
            n--;
        }
        return ret;
    }
};

// ˫ָ�� ��Ч�����εĸ���
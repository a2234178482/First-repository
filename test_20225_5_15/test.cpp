#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int dest = -1;
        int cur = 0;
        int n = arr.size();
        while (cur < n)
        {
            if (arr[cur] != 0)
            {
                dest++;
            }
            else
            {
                dest += 2;
            }
            if (dest >= n - 1)
                break;
            cur++;
        }
        if (dest == n)
        {
            arr[n - 1] = 0;
            cur--, dest -= 2;
        }
        while (cur >= 0)
        {
            if (arr[cur] == 0)
            {
                arr[dest--] = 0;
                arr[dest--] = 0;
                cur--;
            }
            else {
                arr[dest--] = arr[cur--];
            }
        }
    }
};

class Solution
{
public:
    int Bigsum(int n)
    {
        int sum = 0;
        while (n)
        {
            int t = n % 10;
            sum += t * t;
            n = n / 10;
        }
    }
    bool Happy_num(int n)
    {
        int slow = n;
        int fast = n;
        while (slow != fast)
        {
            slow = Bigsum(slow);
            fast = Bigsum(Bigsum(fast));
        }
        return slow == 1;
    }
};
class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea = 0;
        int cur = 0, dest = height.size() - 1;
        while (cur != dest)
        {
            int area = (dest - cur) * min(height[cur], height[dest]);
            maxArea = max(maxArea, area);
            if (height[cur] < height[dest])
            {
                cur++;
            }
            else
            {
                dest--;
            }
        }
        return maxArea;
    }
};
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int n = nums.size();
        int count = 0;
        for (int i = n - 1; i >= 2; i--)
        {
            int left = 0;
            int right = i - 1;
            while (left != right)
            {
                if (nums[left] + nums[right] > nums[i])
                {
                    count += right - left;
                    right--;
                }
                else
                {
                    left++;
                }
            }
        }
        return count;
    }
};
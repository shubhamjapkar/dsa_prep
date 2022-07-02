#include <bits/stdc++.h>
using namespace std;

// we need to find array which gives us high value 

int maxSubArray(vector<int> &nums)
{
    int max_val = nums[0];
    int next_val = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        next_val += nums[i];

        max_val = max(max_val, next_val);

        if (next_val < 0)
            next_val = 0;
    }

    return max_val;
}

int main()
{
}
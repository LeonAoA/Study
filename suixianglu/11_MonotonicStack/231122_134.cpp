#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <climits>
#include <stack>
#include <algorithm>

using namespace std;


/*
思路：
将gas和cost相减，得到数组arr1，累加arr1，若大于0则继续，并记录起点
若小于0，则重新计算；
同时还要记录最小的负数，因为最大的整数累加小于最小累加负数，也不可能到达终点。
*/

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int positive_max = 0;
        int negitive_min = 0;
        int positive_index = 0;
        int negitive_index = 0;
        int sub_sum = 0;
        int positive = 0;
        int negitive = 0;

        gas.insert(gas.end(), gas.begin(),gas.end());
        cost.insert(cost.end(), cost.begin(),cost.end());
        int len = gas.size();

        for(int i = 0; i < len; i++)
        {
            sub_sum = (gas[i] - cost[i]);
            positive += sub_sum;
            negitive += sub_sum;

            if(positive >  positive_max) 
            {
                positive_max = positive; //实时记录最大的整数
            }
            if(negitive <  negitive_min) 
            {
                negitive_min = negitive; //实时记录最大的整数
            }

            if(sub_sum < 0)
            {   
                positive = 0;
                positive_index = i;
            }
            if(sub_sum >= 0)
            {
                negitive = 0;
                negitive_index = i;
            }
        }
        if(positive_max + negitive_min < 0)
        {
            return -1;
        }
        else if(positive_index + 1 > len/2 )
        {
            return positive_index/2 + 1;
        }
        else 
        {
            return positive_index + 1;
        }
    }
};

int main() {

    vector<int> nums = {4, 2, 3};
    Solution sol;

    int sum = sol.canCompleteCircuit(nums, 1);
    cout << "sum =" << sum << endl;


    system("pause");
    return 0;
}



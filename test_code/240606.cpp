#include <iostream>
#include <vector>
#include <algorithm>
// #include <cmath>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        size_t size = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;

        for(int i = 0; i < size; i++){
            if(nums[i] > target && nums[i] >= 0){
                break;
            }
            if(i > 0 && nums[i] == nums[i-1]){  // 第一个数去重
                continue;
            }
            for(int j = i+1; j < size; j++){
                if(j > i+1 && nums[j] == nums[j-1]){   // 第二个数去重
                    continue;
                }
                if(nums[i] + nums[j] > target && nums[j] >= 0){
                    break;
                }
                int left = j+1;  // int left = j+2;
                int right = size-1;
                while(left < size && right > 0 && left < right){
                    if(nums[i] + nums[j] > target - nums[left] - nums[right]){
                        right--;
                        continue;  // 
                    }else if(nums[i] + nums[j] < target - nums[left] - nums[right]){
                        left++;
                        continue;  // 
                    }else{
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});
                    }
                    while(right > 0 && nums[right] == nums[right-1]){
                        right--;
                    }
                    while(left < size && nums[left] == nums[left+1]){
                        left++;
                    }
                    left++;
                    right--;
                }
            }
        }
        return result;
    }
};

int main(){
    int c,n;
    
    vector<int> nums = {0,0,0,0};
    int target = 0;
    Solution sol;
    sol.fourSum(nums, target);
    // printf("%d", dp[c]);
    system("pause");
    return 0;
}
// #include <bits/stdc++.h>

// using namespace std;

// class Solution {
// public:
//     int sum;
//     int count;
//     void backTracking(vector<int>& nums, int target, int depth){
//         if(depth == nums.size()){
//             if(sum == target) count++;
//             return;
//         }
//         for(int i = 0; i < 2; i++){
//             if(i == 0){
//                 sum += nums[depth];
//                 backTracking(nums, target, depth++);
//                 sum -= nums[depth];
//             }else{
//                 sum -= nums[depth];
//                 backTracking(nums, target, depth++);
//                 sum += nums[depth];
//             }
//         }
//     }

//     int findTargetSumWays(vector<int>& nums, int target) {
//         sum = 0;
//         count = 0;

//         backTracking(nums, target, 0);

//         return count;
//     }
// };


// int main(){

//     vector<int> nums = {1,1,1,1,1};
//     int target = 3;
//     Solution sol;

//     sol.findTargetSumWays(nums, 3);

//     system("pause");
//     return 0;
// }



/*

int main(){
    vector<int> vec1 = {1, 2, 3};
    vector<int> vec2;

    vec2 = std::vector<int>(vec1.begin(), vec1.begin() + 2);

    for (const auto& p : vec2) {
        // std::cout << "{" << p.first << ", " << p.second << "} ";
        std::cout << p << " ";

    }
    std::cout << std::endl;

    system("pause");
    return 0;
}


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};






*/






























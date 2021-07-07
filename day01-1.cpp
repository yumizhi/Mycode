#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>result(2);
        for(int i = 0;i<nums.size();i++){
            for(int j = i+1;j<nums.size();j++){
                if(nums[i]+nums[j] == target){
                    result.push_back(i);
                    result.push_back(j);
                    return result;
                }
            }
        }
        return result;
    }
};
int main(){
     Solution t;
     vector<int> nums ={1,2,3,4,5,6,7,8,9};
     vector<int>res = t.twoSum(nums,10);
     for(int i = 0;i<res.size();i++)cout<<res[i]<<" ";
}
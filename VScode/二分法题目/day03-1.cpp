#include<iostream>
#include<vector>
using namespace std;

// Leetcode 34
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size() == 0)return {-1,-1};
        int left = 0;int right = nums.size() - 1;
        int min = -1;int max = -1;
        int middle;
        while(left <= right){
            middle = (left + right) / 2;
            if(nums[middle] < target){
                left = middle + 1;
            }
            else if(nums[middle] > target){
                right = middle - 1;
            }
            else{
                if(min == -1)min = middle;
                else if(middle <= min){
                    if(( middle == 0)||(middle > 0 &&nums[middle - 1] != target) ){min = middle;break;}
                    else{
                        right = middle - 1 ;
                    }
                }
                
                
            }
        }
        if(min == -1)return {-1,-1};
        left = min;right = nums.size() -1;

        while(left <= right){
            middle = (left + right) / 2;
            if(nums[middle] < target){
                left = middle + 1;
            }
            else if(nums[middle] > target){
                right = middle - 1;
            }
            else{
                if(max == -1)max = middle;

                else if(middle >= max) {
                    if((middle == nums.size() - 1 )||(middle < nums.size()-1 &&nums[middle + 1] != target) ){max = middle;break;}
                    else{
                        left = middle + 1;
                    }
                }
            }
        }
        return {min,max};
    }
};


int main(){
    Solution t;
    vector<int>example = {2,2};
    vector<int> res = t.searchRange(example,2);
    return 0;
}
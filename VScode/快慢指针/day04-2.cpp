#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        int num = 0;
        for(int i = 0;i<len;i++){
            if(i == 0 || nums[i] != nums[i - 1])nums[num++] = nums[i];
        }
        return num;
    }
};

int main()
{
    Solution t;
    vector<int>example = {1,2,3};
    t.removeDuplicates(example);
    return 0;
}
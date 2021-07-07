#include<iostream>
#include<vector>
using namespace std;


// class Solution {
// public:
//     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//         //二分法
//         //奇数个数中位数大于（m+n-1）/2个数，偶数为大于（m+n）/2个
//         int leftnum = 0; int rightnum = 0;
//         int lindex1 = 0; int lindex2 = 0;
//         int rindex1 = nums1.size()-1; int rindex2 = nums2.size()-1;
//         double mid1 = 0; double mid2 = 0; double res = 0;

//         int bignum = (rindex1 + rindex2) / 2  + 1;  

//         while(true){
//             if(leftnum == bignum&& rightnum == bignum)break;
//             int len1 = (rindex1 - lindex1 ) + 1;
//             int len2 = (rindex2 - lindex2 ) + 1;
//             if(len1 % 2 == 1)mid1 = nums1[(len1-1)/2];

//             else{ mid1 = nums1[len1/2]+nums1[len1/2 - 1]; mid1 = mid1/2;}

//             if(len2 % 2 == 1)mid2 = nums2[(len2-1)/2];
//             else{mid2 = nums2[len2/2] + nums2[len2/2-1]; mid2 = mid2 /2 ;}

//             if(mid1 <= mid2){
//                 res = mid2;

//             }

            
//         }
//     }
// };

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }
        
        int m = nums1.size();
        int n = nums2.size();
        int left = 0, right = m;
        // median1：前一部分的最大值
        // median2：后一部分的最小值
        int median1 = 0, median2 = 0;

        while (left <= right) {
            // 前一部分包含 nums1[0 .. i-1] 和 nums2[0 .. j-1]
            // 后一部分包含 nums1[i .. m-1] 和 nums2[j .. n-1]
            int i = (left + right) / 2;
            int j = (m + n + 1) / 2 - i;

            // nums_im1, nums_i, nums_jm1, nums_j 分别表示 nums1[i-1], nums1[i], nums2[j-1], nums2[j]
            int nums_im1 = (i == 0 ? INT_MIN : nums1[i - 1]);
            int nums_i = (i == m ? INT_MAX : nums1[i]);
            int nums_jm1 = (j == 0 ? INT_MIN : nums2[j - 1]);
            int nums_j = (j == n ? INT_MAX : nums2[j]);

            if (nums_im1 <= nums_j) {
                median1 = max(nums_im1, nums_jm1);
                median2 = min(nums_i, nums_j);
                left = i + 1;
            } else {
                right = i - 1;
            }
        }

        return (m + n) % 2 == 0 ? (median1 + median2) / 2.0 : median1;
    }
};

int main(){
    vector<int> nums1 = {};
    vector<int> nums2 = {};
    Solution t;
    cout << t.findMedianSortedArrays(nums1,nums2);
    cout<<endl;
    return 0;
}
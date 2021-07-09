#include<iostream>
#include<math.h>
using namespace std;

// int mySqrt(int x) {
//         int left = 0;int right = x;
//         int middle;
//         while(left <= right){
//             middle = (left + right) / 2;
//             if(pow(middle,2) == x)return middle;
//             if(pow(middle,2) < x && pow(middle + 1, 2) > x)
//             {
//                 return middle;
//             }
//             else if(pow(middle,2) < x && pow(middle + 1, 2) == x){
//                 return middle + 1;
//             }
//             else if(pow(middle + 1, 2) <x){
//                 left = middle;
//             }
//             else if(pow(middle,2) > x){
//                 right = middle;
//             }
//         }
//         return middle;
//     }

// Leetcode 69
class Solution {
public:
    int mySqrt(int x){
        if(x == 0)return x;
        int k = 1;
        while(pow(k,2) < x){
            k = k*2;
        }
        int left = k/2;int right = k;
        int middle;
        while(left <= right){
            middle = (left + right) / 2;
            if(pow(middle,2) == x)break;
            if(pow(middle, 2) < x){
                left = middle + 1;
            }
            else if(pow(middle,2) > x){
                right = middle - 1;
            }
        }
        if(pow(middle,2) > x)return middle -1;
        return middle;
    }
};


int main(){
    Solution t;
    cout<<t.mySqrt(1);
    return 0;
}
#include<iostream>
#include<math.h>
using namespace std;


class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num == 0)return true;
        int k = 1;
        while(pow(k,2) <= num){
            if(pow(k,2) == num)return true;
            k = k*2;
        }
        int left = k/2;int right = k;
        int middle;
        while(left <= right){
            middle = (left + right) / 2;
            
            if(pow(middle,2) == num)return true;
            if(pow(middle, 2) < num){
                left = middle + 1;
            }
            else if(pow(middle,2) > num){
                right = middle - 1;
            }
        }
        return false;
    }
};

int main(){
    Solution t;
    cout<< t.isPerfectSquare(14);
    return 0;
}
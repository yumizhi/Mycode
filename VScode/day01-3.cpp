#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s=="")return 0;
        int max = 0;
        int* dp = new int[s.size()];//dp[i]表示前i个字符不含重复字符最长字串长度
        //转移方程
        //不重复dp[i] = dp[i-1]+1
        //否则dp[i] = 1
        dp[0] = 1;
        for(int i = 1;i<s.size();i++){
            int flag = 1;
            for(int j = i - dp[i-1];j<i;j++){
                if(s[i] == s[j]){
                    flag = 0;
                    dp[i] = i-j;
                    break;
                }
            }
            if(flag){
                dp[i] = dp[i-1]+1;
            }
            if(dp[i]>max)max = dp[i];
        }
        if(dp[s.size()-1]>max)max = dp[s.size()-1];
        return max;
    }
};


int main(){
    Solution t;
    string s = "dvdf";
    cout<<t.lengthOfLongestSubstring(s);
    return 0;
}
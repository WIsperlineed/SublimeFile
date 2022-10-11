

//Dynamic Programming 

核心是递归问题，使用空间换时间，

1.状态表示：f[],
2.状态转移方程：
3.边界表示
4.状态转移计算
5.优化算法

lc 139. 单词拆分


class Solution {
public:
    
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size()+1, false);
        unordered_set<string> m(wordDict.begin(), wordDict.end());
        dp[0] = true;
        //获取最长字符串长度
        int maxWordLength = 0;
        for (int i = 0; i < wordDict.size(); ++i){
            maxWordLength = std::max(maxWordLength, (int)wordDict[i].size());
        }
        for (int i = 1; i <= s.size(); ++i){
        for (int j = std::max(i-maxWordLength, 0); j < i; ++j){
            if (dp[j] && m.find(s.substr(j, i-j)) != m.end()){//从j开始，到i的字符串子串是否在wordDict中
                dp[i] = true;
                break;
            }
        }
    }
    return dp[s.size()];   
    }
}




45. 跳跃游戏 II

class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int>f(n);
        for(int i=1,j=0;i<n;i++)
        {
            while(j+nums[j]<i)//当前位置的可达位置
                j++;//j保持最大可以到达距离
            f[i]=f[j]+1;
        }  
        return f[n-1];
    }
};
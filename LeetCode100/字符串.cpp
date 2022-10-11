



class Solution {
public:
    bool isPalindrome(string s) {
        if(!s.size())return 1;
        string ans;
        for(int i=0;i<s.size();i++){
            if(s[i]<='9'&&s[i]>='0')
                ans+=s[i];
            if(tolower(s[i])<='z'&&tolower(s[i])>='a')
                ans+=tolower(s[i]);
        }
        for(int i=0,j=ans.size()-1;i<=j;){
            if(ans[i]!=ans[j])
                return false;
            else{
                i++;
                j--;
            }
        }
        return true;
    }
};
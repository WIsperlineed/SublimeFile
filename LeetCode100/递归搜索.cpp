 





39. 组合总和 tab: tab：搜索，递归

class Solution {
public:
	vector<vector<int>>res;
	vector<int>path;
   vector<vector<int>> combinationSum(vector<int>& ca, int ta) {
  	  dfs(ca,0,ta);
   }

   void dfs(vector<int>& x,int u,int target){
   		if(target==0){
   			res.push_back(path);
   			return;
   		}

   		if(u==x.size()){
   			return;
   		}


   		for(int i=0;x[u]*i<=target;i++){
   			dfs(x,u+1,target-x[u]*i);
   			path.push_back(x[u]);
   		}

   		for(int i=0;x[u]*i<=target;i++){
   			path.pop();
   		}
   }
};



17. 电话号码的字母组合 tab：搜索，递归

class Solution {
public:
      unordered_map<char, string>hash;

    string path = "";
    vector<string>res;
    
    vector<string> letterCombinations(string d) {
        int n = d.size();
        if(d.empty())return {};
        hash['2'] = "abc";
        hash['3'] = "def";
        hash['4'] = "ghi";
        hash['5'] = "jkl";
        hash['6'] = "mno";
        hash['7'] = "pqrs";
        hash['8'] = "tuv";
        hash['9'] = "wxyz";
        dfs(d, 0, n);
        return res;
    }

    void dfs(string d, int u, int x) {//u:0-n
        if (u == x) {
            res.push_back(path);
            return;
        }
        for (int i = 0; i < hash[d[u]].size(); i++) {
            path.push_back(hash[d[u]][i]);
            dfs(d, u + 1, x);
            path.pop_back();
        }
    
    }
};










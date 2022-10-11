

//双指针滑动窗口

56. 合并区间
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& num) {
       int n=num.size();
        vector<vector<int>>res;
       if(num.empty())return num;
        sort(num.begin(),num.end());
        int l=num[0][0],r=num[0][1];
        for(int i=1;i<num.size();i++){
            if(num[i][0]>r){
                res.push_back({l,r});
                l=num[i][0];
                r=num[i][1];
            }else
                r=max(num[i][1],r);
        }
        res.push_back({l,r});//最后一步需要更新
        return res;
    }
};
//57. 插入区间
class Solution {
    

    
public:
    vector<vector<int>> insert(vector<vector<int>>& a, vector<int>& b){
        if(a.empty())return {b};
        vector<vector<int>> res;
        sort(a.begin(),a.end());
        int xl=b[0],xr=b[1];
        
        for(int i=0;i<a.size();i++){
            int l=a[i][0],r=a[i][1];
            if(xl>r){
                res.push_back({l,r});
            }else
            {
                if(xr<l)
                    res.push_back({l,r});
                else{
                    xl=min(l,xl);
                    xr=max(r,xr);
                }
            }
        }
        res.push_back({xl,xr});
        sort(res.begin(),res.end());
        return res;
    }
};


//三数之和


 class Solution {

public:
    
    
    // a+b+c=0-->a+b=-c//abc中一个可以为0，三个可以为0
    //1若都不为0，则考虑a+b=-c
    //2若为0，则考虑a+b=0
    
    
 vector<vector<int>> threeSum(vector<int>& a) {
    int n=a.size();
    vector<vector<int>>res;
     
     sort(a.begin(),a.end());//n log n
     
     int pre=-1;
     
     for(int i=0; i<n; i++){
         
         
         if(pre !=-1&&a[i]==a[pre])continue;
         
         
         int l=i+1,r=n-1;
         while(l<r){
             int sum=a[i]+a[l]+a[r];
             
             if(sum==0){
                 res.push_back({a[i],a[l],a[r]});
                 int v=a[l];
                 while(l<r&&a[l]==v)l++;
             }else if(sum<0){
                 l++;
             }else{
                 r--;
             }
             
         }
         pre=i;
     }
    
     return res;
}
    
};



两数之和
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int,int>heap;
        for(int i=0;i<nums.size();i++){
            int x=target-nums[i];
            if(heap.count(x))return {heap[x],i};//如果之前有该元素，返回
             heap[nums[i]]=i;//没有的话 元素 对 索引 哈希
        }        
        return {};
    }
}; 


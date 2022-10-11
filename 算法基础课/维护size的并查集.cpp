

#include<iostream>
#include<string>

using namespace std;

const int N=100100;


int n,m,p[N],cnt[N];

int find(int x)//查询函数
{
	if(p[x]!=x)p[x]=find(p[x]);

	return p[x];
}


/*

三种查询：
1.C a b，在点 a 和点 b 之间连一条边，a 和 b 可能相等；
2.Q1 a b，询问点 a 和点 b 是否在同一个连通块中，a 和 b 可能相等；
3.Q2 a，询问点 a 所在连通块中点的数量

*/



int main()
{
	cin>>n>>m;

	for(int i=1;i<=n;i++)//初始化
	{
		p[i]=i;
		cnt[i]=1;
	}

	for(int i=0;i<m;i++)
	{	
		string ss;
		int a, b;
		cin>>ss;

		if(ss=="C")
		{
			cin>>a>>b;
			if(find(a)!=find(b))//要确保a b不在同一个集合内才可以合并
			{
			    cnt[find(b)] += cnt[find(a)];
    		    p[find(a)] = find(b);
			}
		}else if(ss=="Q1")
		{
			cin>>a>>b;
			if(find(a)==find(b))cout<<"Yes"<<endl;
			else cout<<"No"<<endl;
		}else{
			cin>>a;
			cout<<cnt[find(a)]<<endl;
		}
	}
}


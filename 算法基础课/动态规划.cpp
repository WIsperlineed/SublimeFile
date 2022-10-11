

//Dynamic Programming 

核心是递归问题，使用空间换时间，

1.状态表示：f[],
2.状态转移方程：
3.边界表示
4.状态转移计算
5.优化算法




1.01背包问题：

#include<iostream>
#include<algorithm>

const int N=10010;
int n,m;//n个物品，背包体积是m

int v[N],w[N];
int f[N];

int main()
{

	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>v[i]>>w[i];
	}

	for(int i=1;i<n;i++)
		for(int j=m,j>=v[i];j--)
			f[j]=max(f[j],f[j-v[i]]+w[i]);

	return 0;
}



2.完全背包问题


#include<iostream>
using namespace std;
const int N = 1010;
int f[N];
int v[N],w[N];
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i = 1 ; i <= n ;i ++)
    {
        cin>>v[i]>>w[i];
    }

    for(int i = 1 ; i<=n ;i++)
    for(int j = v[i] ; j<=m ;j++)
    {
            f[j] = max(f[j],f[j-v[i]]+w[i]);    
    }
    cout<<f[m]<<endl;
}



3.多重背包问题 I



int main()
{
    int n,m;
    cin>>n>>m;
    for(int i = 1 ; i <= n ;i ++)
    {
        cin>>v[i]>>w[i]>>s[i];
    }

   
    for(int i = 1 ; i<=n ;i++)
    for(int j = 0 ; j<=m ;j++)
    {
        for(int k = 0 ; k*v[i]<=j&&(k<s[i]) ; k++)
            f[i][j] = max(f[i][j],f[i-1][j-k*v[i]]+k*w[i]);
    }

    cout<<f[n][m]<<endl;
}




bool row[9][9], col[9][9], cell[3][3][9];

    void solveSudoku(vector<vector<char>>& board) {
        memset(row, 0, sizeof row);
        memset(col, 0, sizeof col);
        memset(cell, 0, sizeof cell);

        for (int i = 0; i < 9; i ++ )
            for (int j = 0; j < 9; j ++ )
                if (board[i][j] != '.') {
                    int t = board[i][j] - '1';
                    row[i][t] = col[j][t] = cell[i / 3][j / 3][t] = true;
                }

        dfs(board, 0, 0);
    }

    bool dfs(vector<vector<char>>& board, int x, int y) {
        if (y == 9) x ++, y = 0;
        if (x == 9) return true;

        if (board[x][y] != '.') return dfs(board, x, y + 1);
        for (int i = 0; i < 9; i ++ )
            if (!row[x][i] && !col[y][i] && !cell[x / 3][y / 3][i]) {
                board[x][y] = '1' + i;
                row[x][i] = col[y][i] = cell[x / 3][y / 3][i] = true;
                if (dfs(board, x, y + 1)) return true;
                board[x][y] = '.';
                row[x][i] = col[y][i] = cell[x / 3][y / 3][i] = false;
            }

        return false;
    }




#include <iostream>
#include <stack>
using namespace std;

string mp = "+-*/)]}";
// 当前运算符与符号栈的栈顶运算符做优先级比较，如果当前优先级高，则不做运算压入栈中，相同进行运算
bool cmp(char c1, char c2)
{
    if (c1 =='(') {
        return false;
    } else if((c1=='+' || c1=='-') && (c2=='*' || c2=='/')){
        return false;
    }
    return true;
}

void doCal(stack<double> &st, stack<char> &so)
{
    double b = st.top();
    st.pop();
    double a = st.top();
    st.pop();
    int op = so.top();
    so.pop();
    if(op == '+') a = a+b;
    else if(op == '-') a = a-b;
    else if(op == '*') a = a*b;
    else if(op == '/') a = a/b;
    st.push(a);
    return ;
}

int main()
{
    string s;
    while(getline(cin, s))
    {
        stack<double> st;
        stack<char> so;
        so.push('(');
        s += ')';
        bool nextIsOp = false;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i]=='{' || s[i]=='[' || s[i]=='(') {
                so.push('(');
            } else if(s[i]==')' || s[i]==']' || s[i]=='}') {
                while(so.top() != '(') doCal(st, so);
                so.pop();
            } else if (nextIsOp) {
                while(cmp(so.top(), s[i])) doCal(st, so);
                so.push(s[i]);
                nextIsOp = false;
            } else {
                int j = i;
                if(s[j] == '-' || s[j] == '+') i++;
                while(mp.find(s[i]) == mp.npos) i++;
                string t = s.substr(j, i-j);
                st.push((double)stoi(t));
                i--;
                nextIsOp = true;
            }
        }
        cout << st.top() << endl;
    }
    return 0;
}
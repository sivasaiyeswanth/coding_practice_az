// Iahub is very proud of his recent discovery, propagating trees. Right now, he invented a new tree, called xor-tree. 
//After this new revolutionary discovery, he invented a game for kids which uses xor-trees.

// The game is played on a tree having n nodes, numbered from 1 to n. Each node i has an initial value initi, which is either 0 or 1. The root of the tree is node 1.

// One can perform several (possibly, zero) operations on the tree during the game. The only available type of operation is to pick a node x. Right after someone has picked node x, 
//the value of node x flips, the values of sons of x remain the same, the values of sons of sons of x flips, the values of sons of sons of sons of x remain the same and so on.

// The goal of the game is to get each node i to have value goali, which can also be only 0 or 1. You need to reach the goal of the game by using minimum number of operations.

// Input
// The first line contains an integer n (1 ≤ n ≤ 105). Each of the next n - 1 lines contains two integers ui and vi (1 ≤ ui, vi ≤ n; ui ≠ vi) meaning there is an edge between nodes ui and vi.

// The next line contains n integer numbers, the i-th of them corresponds to initi (initi is either 0 or 1). The following line also contains n integer numbers, the i-th number corresponds to goali (goali is either 0 or 1).

// Output
// In the first line output an integer number cnt, representing the minimal number of operations you perform. Each of the next cnt lines should contain an integer xi, representing that you pick a node xi.

#include <bits/stdc++.h>
using namespace std;
 
vector<int> b,c,vis,ans;
vector<vector<int> > a;

void printvec(vector<int> a){
    for(int i=0;i<a.size();i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
void dfs(int x, int n, int m)
{
	vis[x] = 1;
    cout<<"ele: "<<x<<" "<<endl;
    cout<<b[x]<<" "<<m<<" "<<c[x]<<endl;
	if((b[x]+m-c[x])%2)
	{
		ans.push_back(x+1);
		m++;
        cout<<" hi: "<<m<<endl;
	}
	for(int i=0; i<a[x].size(); i++)
		if(!vis[a[x][i]])
			dfs(a[x][i],m,n);
}
 
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
#endif
	int n,x,y;
	cin>>n;
	a.resize(n);
	b.resize(n);
	c.resize(n);
	vis.resize(n);
	for(int i=0; i<n-1; i++)
	{
		cin>>x>>y;
		x--; y--;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	for(int i=0; i<n; i++)
		cin>>b[i];
	for(int i=0; i<n; i++)
		cin>>c[i];
	dfs(0,0,0);
	cout<<ans.size()<<endl;
    printvec(ans);
	for(int i=0; i<ans.size(); i++)
		cout<<ans[i]<<endl;
	return 0;
}
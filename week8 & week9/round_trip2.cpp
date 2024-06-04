#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i, n) for (i = 0; i < n; i++)
#define Fo(i, k, n) for (i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define int long long
#define pb push_back
#define mp make_pair
#define PI 3.1415926535897932384626
#define mod 1000000007
#define endl "\n"
typedef pair<int, int> pii;
typedef pair<int, int> pl;
typedef vector<int> vi;
typedef vector<int> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
vector<vector<int>> v;
vector<int> vis;
vector<int> parent;


void printvec(vector<int> a){
    for(int i=0;i<a.size();i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
bool cycle=false;
void dfs(int i){
    vis[i]=2;
    
    for(auto it:v[i]){
        
        if(vis[it]==1){
            dfs(it);
        }
        else if(vis[it]==2){
            cycle=true;
        }
    }
    vis[i]=3;
}
void solve(){
    int n,m;
    cin>>n>>m;
    v.resize(n+1);
    
    vis.assign(n+1,1);
    //memset(vis,1,sizeof(vis));
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        v[x].pb(y);
        
    }
    cycle=false;
    for(int i=1;i<=n;i++){
        if(vis[i]==1){
            dfs(i);
        }
    }
    if(cycle==false){
        cout<<"No"<<endl;
    }
    else cout<<"Yes"<<endl;
    v.clear();
    vis.clear();
}
int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N=100;
    int t=1;
    
    cin>>t;
    
    while (t--)
    {
        
        solve();
    }
    return 0;
}
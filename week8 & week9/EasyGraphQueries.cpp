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
vector<vector<int>> g;
vector<int> vis;
vector<int> col;
map<int,int> nodes_having_col;
void printvec(vector<int> a){
    for(int i=0;i<a.size();i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

void dfs(int node,int color){
    if(vis[node]){
        return;
    }
    col[node]=color;
    nodes_having_col[color]++;
    vis[node]=1;
    for(int i=0;i<g[node].size();i++){
        dfs(g[node][i],color);
    }
}

void solve(){
    int n,m,q;
    cin>>n>>m>>q;
    g.resize(n+1);
    vis.resize(n+1);
    col.resize(n+1);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }
    int coli=0;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs(i,coli);
            coli++;
        }
    }

    while(q--){
        int w;
        cin>>w;
        if(w==1){
            int x;
            cin>>x;
            cout<<nodes_having_col[col[x]]<<endl;
        }
        else{
            int x,y;
            cin>>x>>y;
            if(col[x]==col[y]){
                cout<<"YES"<<endl;
            }
            else cout<<"NO"<<endl;

        }
    }

    

    
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
    int t;
    t=1;
    //cin>>t;
    
    while (t--)
    {
        
        solve();
    }
    return 0;
}
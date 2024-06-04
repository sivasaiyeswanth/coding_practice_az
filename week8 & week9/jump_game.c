//if we want to find positive cycle--
//negative the costs so positive cycle becomes 
//negative and we can find it
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
void printvec(vector<int> a){
    for(int i=0;i<a.size();i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
vector<int> v,dist,vis;
vector<vector<pair<int,int>>> g;
map<int,vector<int>> m;
int n,a,b;
void dijkshtra(int src){
     priority_queue<pair<int,int>> q;
     q.push({0,src});
     dist[src]=0;
    while(!q.empty()){
        auto sc=q.top();
        q.pop();
        int cost=-sc.first;
        int node=sc.second;
        if(vis[node]) continue;
        vis[node]=1;
        for(int i=0;i<g[node].size();i++){
            int nnode=g[node][i].second;
            int ncost=g[node][i].first;
            if(!vis[nnode] && dist[nnode]>dist[node]+ncost){
                dist[nnode]=dist[node]+ncost;
                q.push({-dist[nnode],nnode});
            }
        }

        
   }
}
void solve(){
    
    cin>>n>>a>>b;
    v.resize(n+1);
    
    
    for(int i=1;i<=n;i++){
        cin>>v[i];
        m[v[i]].pb(i);
    }
    // for(auto it:m){
    //     cout<<it.first<<endl;
    //     for(int val:it.second){
    //         cout<<val<<endl;
    //     }
    // }
    g.resize(n+m.size()+1);
    vis.assign(n+m.size()+1,0);
    dist.assign(n+m.size()+1,1e18);
    for(int i=1;i<n;i++){
        g[i].pb({b,i+1});
        g[i+1].pb({b,i});
    }
    int d=n+1;
    for(auto it:m){
        for(auto its:it.second){
            g[d].pb({0,its});
            g[its].pb({a,d});
        }
        d++;
    }
    // for(int i=0;i<g.size();i++){
    //     cout<<"hi"<<endl;
    //     for(int j=0;j<g[i].size();j++){
    //         cout<<g[i][j].first<<" "<<g[i][j].second<<endl;
    //     }
    // }
    int src;
    cin>>src;
    dijkshtra(src);
    for(int i=1;i<=n;i++){
      
        cout<<dist[i]<<" ";
    }
    cout<<endl;
    

    
    
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
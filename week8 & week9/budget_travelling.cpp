
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
int capacity;
vector<int> petrolcost,ct;
vector<vector<pair<int,int>>> g;
int vis[100005][110];
int dist[100005][110];
int n,m;
void dijkshtra(int sc){
    for(int i=0;i<n+5;i++){
        for(int j=0;j<capacity+5;j++){
            vis[i][j]=0;
            dist[i][j]=1e9;
        }
    }
    priority_queue<pair<int,pair<int,int>>> q; //cost,node,capacity
    q.push({0,{sc,0}});
    dist[sc][0]=0;
    while(!q.empty()){
        auto p=q.top();
        int cost=-p.first;
        int node=p.second.first;
        int pt=p.second.second;
        q.pop();
        if(vis[node][pt]) continue;
        vis[node][pt]=1;
    
    
            
        if(pt<capacity && cost+petrolcost[node]<dist[node][pt+1]){
            dist[node][pt+1]=cost+petrolcost[node];
            q.push({-dist[node][pt+1],{node,pt+1}});
                
        }

        for(auto it:g[node]){
            int nnode=it.first;
            int ndist=it.second;
            if(ndist<=pt && dist[nnode][pt-ndist]>cost){
                dist[nnode][pt-ndist]=cost;
                //cout<<"hi: "<<nnode<<" "<<ndist<<" "<<ct[nnode]<<endl;
                q.push({-dist[nnode][pt-ndist],{nnode,pt-ndist}});
            }
        }
       
    }
   

}
void solve(){

    cin>>n>>m;
    g.resize(n+1);
    petrolcost.resize(n+1);
    ct.assign(n+1,1e18);
    for(int i=0;i<m;i++){
        int u,v,d;
        cin>>u>>v>>d;
        g[u].pb({v,d});
        g[v].pb({u,d});
    }
    for(int i=1;i<=n;i++){
        cin>>petrolcost[i];
    }
    int sc,dc;
    cin>>sc>>dc>>capacity;
    dijkshtra(sc);
     int mini = 1e9;
    
    for (int i = 0; i <= capacity; i++)
    {
        mini = min(mini, dist[dc][i]);
    }
    cout<<mini<<endl;
    
    
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
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
int n,m;
vector<vector<pair<int,int>>> out_edges,in_edges;
vector<int> dist;
int ans;
void zobfs(int sc){
    dist[sc]=0;
    deque<int> q;
    q.push_back(sc);
    while(!q.empty()){
        int s=q.front();
        q.pop_front();
        for(auto it:out_edges[s]){
            int node=it.first;
            int cost=it.second;
            
            
            if(dist[node]>(dist[s]+cost)){
                
                dist[node]=(dist[s]+cost);
                if(cost==0){
                    q.push_front(node);
                }
                else q.push_back(node);
            } 
        }
    }

}
void solve(){
    map<pair<int,int>,int> ma;
    cin>>n>>m;
    out_edges.clear();
    dist.clear();
    out_edges.resize(n+1);
    in_edges.resize(n+1);
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        if(x!=y && ma[{x,y}]!=1){
            out_edges[x].pb({y,0});
            out_edges[y].pb({x,1});
            ma[{x,y}]++;
        }
    }
    dist.assign(n+1,1e9);
    zobfs(1);
    if(dist[n]==1e9){
        cout<<"-1"<<endl;
    }
    else{
        cout<<dist[n]<<endl;
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
    //t=1;
    cin>>t;
    
    while (t--)
    {
        
        solve();
    }
    return 0;
}
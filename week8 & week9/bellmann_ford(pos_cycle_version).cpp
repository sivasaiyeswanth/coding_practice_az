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
int n,m;
vector<vpii> g;
vector<int> dist;
vector<int> vis;
int dx[]={1,-1,0,  printvec(dist);0};
int dy[]={0,0,-1,1};
int ans;
struct edge{
    int a,b,c;
};
void solve(){
    
    cin>>n>>m;
    struct edge E[m];
    
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        E[i].a=a;
        E[i].b=b;
        E[i].c=-c;
    }
    dist.assign(n+1,1e18);
    ans=-1e18;
    dist[1]=0;
    for(int i=0;i<n;i++){
        for(int i=0;i<m;i++){
             int u=E[i].a;
             int v=E[i].b;
             int w=E[i].c;
             
             dist[v]=min(dist[v],(dist[u]+w));
        }
    }
    bool negative=false;

    for(int i=0;i<m;i++){
            int a=E[i].a;
            int b=E[i].b;
            int c=E[i].c;
            if(dist[b]>dist[a]+c){
                negative=true;
                break;
            }
    }
  
    if(negative){
        cout<<"-1"<<endl;
    }
    else cout<<-dist[n]<<endl;
    
    
    
   

    
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
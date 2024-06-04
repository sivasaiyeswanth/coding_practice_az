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
vector<vector<int>> vis;
vector<vector<int>> color;
map<int,int> mi;
bool f=true;
int dx[]={-1,1,0,0};
int dy[]={0,0,1,-1};
int n,m;
void printvec(vector<int> a){
    for(int i=0;i<a.size();i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

bool check(int x,int y){
    if(x>=0 && x<n && y>=0 && y<m && g[x][y]!=1){
        return true;
    }
    return false;
}
void bfs(int x,int y,int col){
    queue<pair<int,int>> q;
   
    q.push(make_pair(x,y));
    if(vis[x][y]){
        return;
    }
    vis[x][y]=1;
     color[x][y]=col;
     mi[col]++;
     
      while(!q.empty()){

        pair<int,int> n=q.front();
        //cout<<"hi "<<node<<"for node  "<<n<<endl;
        int a=n.first;
        int b=n.second;
        q.pop();
        
        for(int i=0;i<4;i++){
            int r=a+dx[i];
            int c=b+dy[i];
            if(!check(r,c)) continue;
            if(vis[r][c]) {
                continue;
            }
            q.push(make_pair(r,c));
            vis[r][c]=1;
            //cout<<n<<" "<<"node: "<<it<<"color"<<color[it]<<endl;
            color[r][c]=col;
            mi[col]++;
           }
        
        //cout<<endl;

     }
    //  cout<<q.size()<<endl;

}
void solve(){
    
    cin>>n>>m;
    g.resize(n);
    vis.resize(n);
    color.resize(n);
    vector<pair<int,int>> zeroes;
    for(int i=0;i<n;i++){
        g[i].resize(m);
        vis[i].assign(m,0);
        color[i].assign(m,-1);
        for(int j=0;j<m;j++){
            int t;
            cin>>t;
            //cout<<t<<endl;
            g[i][j]=t;
            if(t==0) zeroes.pb(make_pair(i,j));
        }
        // cout<<"i :"<<i<<endl;
        // for(int j=0;j<m;j++){
        //     cout<<g[i][j] <<" ";
        // }
        //cout<<endl;
        
    }
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cout<<g[i][j] <<" ";
    //     }
    //     cout<<endl;
    // }
   
    int c=0;
    for(int i=0;i<zeroes.size();i++){
        int f=c;
        int x=zeroes[i].first;
        int y=zeroes[i].second;
        if(vis[x][y]==0) {
            bfs(x,y,c);
        }
        c++;
    }
    
    // for(auto it:mi){
    //     cout<<it.first<<" "<<it.second<<endl;
    // }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(g[i][j]==1){
                cout<<"1 ";
            }
            else{
                if(mi[color[i][j]]==1){
                    cout<<"0 ";
                }
                else{
                    cout<<mi[color[i][j]]<<" ";
                }
            }
        }
        cout<<endl;
    }
    mi.clear();
    
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
    
    cin>>t;
    
    while (t--)
    {
        
        solve();
    }
    return 0;
}
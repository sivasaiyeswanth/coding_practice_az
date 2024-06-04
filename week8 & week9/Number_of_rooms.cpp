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
vector<vector<int>> vis;
int n,m;
char building[1001][1001];
int visited[1001][1001];
void printvec(vector<int> a){
    for(int i=0;i<a.size();i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

void dfs(
int x,int y){
    if(x>=0 && x<n && y>=0 && y<m){
        if(building[x][y]=='#' ){
            return;
        }
        if(visited[x][y]==1) return;
        visited[x][y]=1;
        dfs(x+1,y);
        dfs(x,y+1);
        dfs(x,y-1);
        dfs(x-1,y);
    }
    else return;
    
}

void solve(){
    
    cin>>n>>m;
    vector<pair<int,int>> floor;
    
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>building[i][j];
            if(building[i][j]=='.'){
                floor.pb(make_pair(i,j));
            }
            visited[i][j]==0;
        }
    }
    int ans=0;
    int no_of_floors=floor.size();
    for(auto it:floor){
        int x=it.first;
        int y=it.second;
        if(visited[x][y]==0){
            dfs(x,y);
            ans++;
        }
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         cout<<visited[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        // cout<<endl;
        
    }
    cout<<ans<<endl;

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
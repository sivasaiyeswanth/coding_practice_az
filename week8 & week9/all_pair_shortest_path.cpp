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
int dx[]={1,-1,0,0};
int dy[]={0,0,-1,1};
int ans;
vector<vector<int>> dest;
void solve(){
    
    cin>>n;
    dest.resize(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int k;
            cin>>k;
            dest[i].pb(k);
        }
    }
    vector<int> x,ans;
    for(int i=0;i<n;i++){
        int k;
        cin>>k;
        k--;
        x.pb(k);
    }

    
    
    for(int k=n-1;k>=0;k--){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                dest[i][j]=min(dest[i][j],dest[i][x[k]]+dest[x[k]][j]);
            }

        }
        int temp=0;
        for(int p=k;p<n;p++){
            for(int q=k;q<n;q++){
                temp+=dest[x[p]][x[q]];
            }

        }
        ans.pb(temp);

    }
    
    for(int i=n-1;i>=0;i--){
        cout<<ans[i]<<" ";
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
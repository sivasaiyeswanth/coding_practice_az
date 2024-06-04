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
int n;
int v[110];
int dp[110][110];
int rec(int l,int r){
    if(r-l==2){
        return (v[l]*v[r]*v[l+1]);
    }
    
    if(dp[l][r]!=-1) return dp[l][r];

    int ans=1e9;
    
    for(int x=(l+1);x<=(r-1);x++){
        if(x==r-1){
            ans=min(ans,(v[l]*v[r]*v[r-1]+rec(l,r-1)));
        }
        else if(x==l+1){
            ans=min(ans,(v[l]*v[r]*v[l+1]+rec(l+1,r)));
        }
        else{
            ans=min(ans,v[l]*v[r]*v[x]+rec(l,x)+rec(x,r));
        }
    }
    return dp[l][r]=ans;
    
}

void solve(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    memset(dp,-1,sizeof(dp));
    cout<<rec(0,n-1)<<endl;
    
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


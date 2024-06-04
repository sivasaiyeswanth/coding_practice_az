#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i, n) for (i = 0; i < n; i++)
#define Fo(i, k, n) for (i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define int long long
#define deb(x) cout << #x << "=" << x << endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, false, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
#define mod 1000000007
typedef pair<int, int> pii;
typedef pair<int, int> pl;
typedef vector<int> vi;
typedef vector<int> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
int n;
int check(int mid,int k,int a[]){
    int cnt=0;
    for(int i=1;i<n;i++){
        if((a[i]-a[i-1])>mid){
            cnt=cnt+(a[i]-a[i-1]+mid-1)/mid-1;
        }
    }
    if(cnt<=k)return 1;
    else return 0;


}
void solve(){
    int k;
    cin>>n>>k;
    int i,a[n];
    fo(i,n)cin>>a[i];
    int diff=0;
    for(int i=1;i<n;i++){
        diff=max(diff,a[i]-a[i-1]);
    }
    int hi=1e9;
    int lo=1;
    int ans=1e9;
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        
        if(check(mid,k,a)){
            ans=mid;
            hi=mid-1;
        }
        else{
            lo=mid+1;
        }
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
    int t;
    cin >> t;
    
    while (t--)
    {
        solve();
    }
    return 0;
}
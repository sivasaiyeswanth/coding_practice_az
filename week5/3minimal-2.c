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
int n,m;
int check(int mid, vector<int> a, vector<int> b, int k) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cnt = cnt + (upper_bound(b.begin(), b.end(), mid - a[i])-b.begin());

    }
    return cnt>=k;
}
void solve(){
    int k,i,f;
    cin>>n>>m>>k;
    vector<int> a,b;
    int mini=1e9;
    fo(i,n)cin>>f,a.push_back(f),mini=min(mini,a[i]);
    fo(i,m)cin>>f,b.push_back(f);
    if(m>n){
        swap(a,b);
        swap(n,m);
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    int lo=0;
    int hi=1e9;
    int ans=0;
    while(lo<=hi){
        int mid=(lo+hi)/2;
        if(check(mid,a,b,k)){
            hi=mid-1;
            ans=mid;
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
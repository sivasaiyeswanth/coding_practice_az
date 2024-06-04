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

#define clr(x) memset(x, false, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)
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

int MOD= 998244353;
int power(int a, int b, int p) {
    if(b == 0) return 1;
    int t = power(a, b/2, p);
    t = (t * t)%p;
    if(b % 2) return (a * t)%p;
    return t;
}

void solve(){
   int l,r,m;
   cin>>l>>r>>m;
   int k=(r-l+1+m-1)/m;
   int ans=0;
   if((k-2)>0){
    ans=ans+(((k-2)%mod)*((m%mod)*((m+1)%mod)/2)%mod);
   }
   cout<<"k"<<ans<<endl;
   int x=((l%mod+m%mod-1)%mod);
   cout<<"x: "<<x<<endl;
   x=(x*power(m,mod-2,mod))%mod;
    cout<<"x: "<<x<<endl;
    x=(x*(m%mod))%mod;
    cout<<"x: "<<x<<endl;
    x=(x-(l%mod)+mod)%mod;
    cout<<"x: "<<x<<endl;
    if((x)>r){
        ans=ans+((r%mod)*((r+1)%mod))/2;
        ans=ans-((l%mod)*((l+1)%mod))/2;
        cout<<"x>r: "<<ans<<endl;
    }
    else{
        ans=ans+((m%mod)*((m+1)%mod))/2;
        ans=ans-((l%mod)*((l+1)%mod))/2;
        cout<<"x<r: "<<ans<<endl;
    }
    int y=(((r%mod+m%mod-1)%mod)*power(m,mod-2,mod))%mod;
    y=(y*(m-1)%mod)%mod;
    y=((r%mod)-y+mod)%mod;
    cout<<"y: "<<y<<endl;
    if(l<y){
        ans=ans-((m%mod)*((m+1)%mod))/2;
        ans=ans+((r%mod)*((r+1)%mod))/2;
    }
    cout<<"l<y: "<<ans<<endl;
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
    cin>>t;
    while (t--)
    {
        
        solve();
    }
    return 0;
}
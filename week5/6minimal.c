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
int check(int mid,int a[],int n){
    int tail=0;int head=-1;
    int ans=0;
    int sum=0;
    while(tail<n){
        while((head+1<n) && ((sum+a[head+1])<=mid)){
            head++;
            sum=sum+a[head];
        }
        ans=ans+(head-tail+1);
        if(tail<=head){
            sum=sum-a[tail];
            tail++;
        }
        else{
            tail++;
            head=tail-1;
        }
    }
    int tot=(n*(n+1))/2;
    return ans>=(tot+1)/2;
}
void solve(){
   int n;
   cin>>n;
   int a[n];
   int i;
   int sum=0;
   fo(i,n)cin>>a[i],sum+=a[i];
   multiset<int> m;
   int lo=0;
   int hi=sum;
   int ans=1e18;
   while(lo<=hi){
    int mid=(lo+hi)/2;
    
    if(check(mid,a,n)){
        hi=mid-1;
        ans=min(ans,mid);
    }
    else lo=mid+1;

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
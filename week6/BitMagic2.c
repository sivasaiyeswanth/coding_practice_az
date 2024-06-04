#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i, n) for (i = 0; i < n; i++)
#define Fo(i, k, n) for (i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define int long long
#define ll long long
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
typedef pair<int, int> pii;
typedef pair<int, int> pl;
typedef vector<int> vi;
typedef vector<int> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
int msb(ll x) {
    if (x == 0)return -1;
    if (x < 0)return 63; // negative numbers case.
    return (int)__lg(x);
}
int rsb(ll x) {
    if (x == 0)return -1;
    return msb(x ^ (x - 1));
}
ll pow2_div(ll x) {
    if (x == 0)return -1;
    return (1LL << __builtin_ctzll(x)); // 2^(trailing zeroes in bits).
}
ll pow2_n(ll x) {
    if (x <= 1)return 2;
    return (1LL << (64 - __builtin_clzll(x - 1))); // 2^(64 - leading zeroes in bits).
}
void solve(){
   int n;
   cin>>n;
   bitset<64> x(n);
   //1.Output the 64 bit binary representation of number n.
   cout<<x.to_string()<<endl;
   //Output the position of the most significant bit ( MSB ) or the leftmost set bit of n ( 0- indexed ). If n=0, output -1.
   if(n==0){
    cout<<"-1"<<endl;
   }
   else{
    if(n<0)cout<<"63"<<endl;
    else cout<<__lg(n)<<endl;
   }
   //Output the position of the rightmost set bit of n ( 0- indexed ). If n=0, output -1.
   cout<<rsb(n)<<endl;
   //Output 1 if n  is a power of 2 i.e n==2X , x > 0, else output 0.
    
   if((n&(n-1))==0 && n>0){
    
    if(n!=1){
        cout<<"1"<<endl;
    }
    else{
        
        cout<<"0"<<endl;
    }
   }
   else{
        
        cout<<"0"<<endl;
    }

    //5.Output the biggest power of 2, that is the divisor of n. i.e biggest 2K such that n%2K == 0, k ≥ 0. If n=0, output -1. 

    if(n==0){
    cout<<"-1"<<endl;
   }
   else{
     cout<<(1ll<<rsb(n))<<endl;
   }
   //6.Output the smallest power of 2, which is not smaller than n, i.e smallest 2K such that 2K ≥ n, k>0.
   if (n <= 1)cout<<"2"<<endl;
    else cout<<(1ll << (64 - __builtin_clzll(n - 1)))<<endl;
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
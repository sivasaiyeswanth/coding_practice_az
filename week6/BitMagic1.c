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
typedef pair<int, int> pii;
typedef pair<int, int> pl;
typedef vector<int> vi;
typedef vector<int> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;

void solve(){
   bitset<60> x;
   int q;cin>>q;
   while(q--){
    int a;
    cin>>a;
    if(a==1){
        int i;cin>>i;
        bool f=x.test(i);
        if(f==true)cout<<"1"<<endl;
        else cout<<"0"<<endl;
    }
    else if(a==2){
        int i;cin>>i;
        x.set(i);
    }
    else if(a==3){int i;cin>>i;x.reset(i);}
    else if(a==4){int i;cin>>i;x.flip(i);}
    else if(a==5){
        cout<<x.all()<<endl;
    }
    else if(a==6)cout<<x.any()<<endl;
    else if(a==7)cout<<x.none()<<endl;
    else if(a==8) cout<<x.count()<<endl;
    else if(a==9) cout<<x.to_ullong()<<endl;

   }
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
    int t=1;
    //cin >> t;
    
    while (t--)
    {
        solve();
    }
    return 0;
}
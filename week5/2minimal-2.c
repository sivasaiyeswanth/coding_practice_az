
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

int check(int i,int peak,int a[]){
    int lo=0;int hi=peak;
    int ans=-1;
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        
        if(a[mid]<=i){
            
            if(a[mid]==i)ans=mid;
            lo=mid+1;
        }
        else hi=mid-1;
        
    }
    return ans;
}
int check2(int i,int peak,int a[]){
    int lo=peak+1;int hi=n-1;
    int ans=-1;
    while(hi>=lo){
        int mid=lo+(hi-lo)/2;
        if(a[mid]<=i){
            if(a[mid]==i)ans=mid;
            hi=mid-1;
            
        }
        else lo=mid+1;
        
    }
    return ans;
}

void solve(){
    int q;
    cin>>n>>q;
    int a[n],i;
    fo(i,n)cin>>a[i];
    int lo=0;int hi=n-1;
    int peak=0;
    while(lo<=hi){
        int mid=(lo+hi)/2;
        if(a[mid]>a[mid+1]){
            peak=mid;
            hi=mid-1;
        }
        else lo=mid+1;
    }
    while(q--){
        int k;
        cin>>k;
        int p;
        if((p=check(k,peak,a))>=0){
            cout<<p+1<<" ";
        }
        if(peak!=n-1){
        if((p=check2(k,peak,a))>=0){
            cout<<p+1<<" ";
        }
        }
        cout<<"\n";
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
    int t;
    cin >> t;
    
    while (t--)
    {
        solve();
    }
    return 0;
}

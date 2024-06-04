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
int phi[1000001];



void solve(){
   int l,r;
   cin>>l>>r;
   bool chan=false;
   if(l==1){
    chan=true;
    l++;
   }
   int f=sqrt(r);
   int *prime = new int[f + 1];
   for(int i=1;i*i<=r;i++){
    prime[i]=i;
   }
    
   for(int i=2;i*i<=r;i++){
    if(prime[i]==i){
        for(int j=i;j*j<=r;j+=i){
            if(prime[j]==j){
                prime[j]=i;
            }
        }
    }
   }
    // for(int i=0;i*i<=r;i++){
    //     cout<<prime[i]<<" ";
    // }
    // cout<<endl;
   int a[r-l+1];
   for(int i=0;i<r-l+1;i++){
    a[i]=l+i;
   }
//    cout<<"a: "<<endl;
//    for(int i=0;i<r-l+1;i++){
//     cout<<a[i]<<" ";
//    }
   //cout<<endl;
   int cnt=0;
   for(int i=2;i*i<=r;i++){
    if(prime[i]==i){
     for(int j=((l+i-1)/i)*i;j<=r;j+=i){
        //cout<<"i: "<<i<<" "<<"j: "<<j<<endl;
        if(a[j-l]==j){
            
            a[j-l]=i;
           
        }
        
     }
    }
   }
//     cout<<"a: "<<endl;
//    for(int i=0;i<r-l+1;i++){
//     cout<<a[i]<<" ";
//    }
//    cout<<endl;

 for(int i=0;i<r-l+1;i++){
    if(a[i]==l+i){
        cnt++;
    }
   }

   cout<<cnt<<endl;
   for(int i=0;i<r-l+1;i++){
    if(a[i]==l+i){
        cout<<a[i]<<" ";
    }
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
    int t=1;
    
    
    while (t--)
    {
        
        solve();
    }
    return 0;
}
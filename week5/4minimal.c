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

void solve(){
   int n,k,i;
   cin>>n>>k;
   int a[n];
   fo(i,n)cin>>a[i];
   int head=-1,tail=0;
   int cnt=0;
   int ans=0;
   map<int,int> map;
   while(tail<n){
        while(((head+1)<n) && ( (map[a[head+1]]>0) || ((map[a[head+1]]==0)&&(cnt<k) ))){
            head++;
            map[a[head]]++;
            if(map[a[head]]==1){
                cnt++;
                
            }
            
        }
        ans=ans+(head-tail+1);
        // if((head-tail+1)>0){
        //     for(int i=tail;i<=head;i++)cout<<a[i]<<" ";
        //     cout<<endl;
        // }

        if(head>=tail){
            map[a[tail]]--;
            if(map[a[tail]]==0){
                cnt--;
            }
            tail++;
        }
        else{
            tail++;
            map[a[tail]]--;
            if(map[a[tail]]==0){
                cnt--;
            }
            head=tail-1;
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
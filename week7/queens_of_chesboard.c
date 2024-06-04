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
char a[8][8];
int board[8][8];
int ans=0;
int check(int row,int col){
    for(int i=0;i<8;i++){
        if(board[i][col]==1){
            return 0;
        }  
    }
    for(int i=0;i<8;i++){
        if(board[row][i]==1){
            return 0;
        }  
    }
    int p=row,q=col;
    while((((p-1)>=0) && ((q-1)>=0))){
        if(board[p-1][q-1]==1){
            return 0;
        }
        p--;q--;
    }
    p=row,q=col;
    while((((p-1)>=0) && ((q+1)<8))){
        if(board[p-1][q+1]==1){
            return 0;
        }
        p--;q++;
    }
   
    return 1;
}
int s=0;
void rec(int level){
     if(level==8){
        // if(s<=10){
        //     for(int i=0;i<8;i++){
        //         for(int j=0;j<8;j++){
        //             cout<<board[i][j]<<" ";
        //     }
        //     cout<<endl;
        //     }
        // }
        // s++;
        ans++;
        return;
     }
     
     for(int i=0;i<8;i++){
        if(a[level][i]!='*'){
            if(check(level,i)){
               
                board[level][i]=1;
                rec(level+1);
                board[level][i]=0;
            }
        }
     }
     
}
void solve(){
    memset(board,0,sizeof(board));
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            cin>>a[i][j];
        }
    }
    
    rec(0);
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
    //cin>>t;
    t=1;
    while (t--)
    {
        
        solve();
    }
    return 0;
}
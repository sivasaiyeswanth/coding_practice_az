// We establish the relationship between the sub problems and the problem at hand. Let 
// �
// (
// �
// ,
// �
// )
// L(i,j) be the length of the shortest subsequence that is in 
// �
// [
// 1..
// �
// ]
// S[1..i] that is not in 
// �
// [
// 1..
// �
// ]
// T[1..j]. Here we have the following relationship: 
// �
// (
// �
// ,
// �
// )
// =
// L(i,j)=

// If letter 
// �
// [
// �
// ]
// S[i] is nowhere to be found in 
// �
// [
// 1..
// �
// ]
// T[1..j], then 
// �
// (
// �
// ,
// �
// )
// =
// 1
// L(i,j)=1.
// Otherwise, we have two cases: 2.1. 
// �
// [
// �
// ]
// S[i] is in the shortest subsequence. We find 
// �
// k, the most immediate index in 
// �
// [
// 1..
// �
// ]
// T[1..j] where 
// �
// [
// �
// ]
// =
// =
// �
// [
// �
// ]
// T[k]==S[i]. Then 
// �
// (
// �
// ,
// �
// )
// =
// 1
// +
// �
// (
// �
// −
// 1
// ,
// �
// −
// 1
// )
// L(i,j)=1+L(i−1,k−1). 2.2 
// �
// [
// �
// ]
// S[i] is not in the shortest subsequence. Then 
// �
// (
// �
// ,
// �
// )
// =
// �
// (
// �
// −
// 1
// ,
// �
// )
// L(i,j)=L(i−1,j). We pick whichever is lower.
// Time Complexity : 
// �
// (
// �
// 2
// )
// O(N 
// 2
//  ) per test case.
 #include <bits/stdc++.h>
using namespace std;

#define ll int64_t
#define endl '\n'

string s1, s2;
int n, m;
int dp[1001][1001], pre[1001][1001];
int rec(int i, int j) {
    if (i == -1)return 1e9;
    if (j == -1)return 1;
    auto &ans = dp[i][j];
    if (ans != -1)return ans;
    ans = rec(i - 1, j);
    if (pre[i][j] == -1)ans = 1;
    else ans = min(ans, 1 + rec(i - 1, pre[i][j] - 1));
    return ans;
}
void solve() {
    cin >> s1 >> s2;
    n = s1.size(), m = s2.size();
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < n; i++) {
        int p = -1;
        for (int j = 0; j < m; j++) {
            if (s1[i] == s2[j])p = j;
            pre[i][j] = p;
        }
    }
    int ans = rec(n - 1, m - 1);
    if (ans > n)ans = -1;
    cout << ans << endl;
}
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

#ifdef Mastermind_
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    // int i = 1;
    cin >> t;
    while (t--) {
        // cout << "Case #" << i << ": ";
        solve();
        // i++;
    }
    return 0;
}



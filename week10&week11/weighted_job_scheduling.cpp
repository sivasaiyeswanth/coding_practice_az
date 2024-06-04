#include <bits/stdc++.h>
using namespace std;

#define ll int64_t
#define endl '\n'

int n;
vector<array<ll, 3>> v; // { b, a, p }
vector<ll> dp;
int binsearch(int i) {
	int l = 0, r = i - 1, ans = -1;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (v[mid][0] < v[i][1])ans = mid, l = mid + 1;
		else r = mid - 1;
	}
	return ans;
}
void solve() {
	cin >> n;
	v.resize(n, array<ll, 3>());
	for (int i = 0; i < n; i++)cin >> v[i][1] >> v[i][0] >> v[i][2];
	sort(v.begin(), v.end()); // sorting according to ending time.
	dp.resize(n);
	dp[0] = v[0][2];
	for (int i = 1; i < n; i++) {
		dp[i] = dp[i - 1]; // not choosing current job ending at v[i][0].
		int idx = binsearch(i);
		if (idx != -1)dp[i] = max(dp[i], v[i][2] + dp[idx]); // choosing job ending at v[i][0].
		else dp[i] = max(dp[i], v[i][2]); // choosing only current Job.
	}
	cout << dp[n - 1] << endl;
	assert(dp[n-1]>=0);
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
	// cin >> t;
	while (t--) {
		// cout << "Case #" << i << ": ";
		solve();
		// i++;
	}
	return 0;
}

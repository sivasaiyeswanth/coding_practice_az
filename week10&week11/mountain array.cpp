//mountain array : increasing and after all elements decreasing
//front longest increasing subsequence and take lis also fr0om back
//now take whats the minimum elements to remove to make monutaOMarray
//(n-lis[i]+lis0[i]-1)

#include <bits/stdc++.h>
using namespace std;

#define ll int64_t
#define endl '\n'

void printvec(vector<int> a){
    for(int i=0;i<a.size();i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
void solve() {
	int n, ans = 0;
	cin >> n;
	vector<int> nums(n);
	for (int i = 0; i < n; i++)cin >> nums[i];
	vector<int> dp1(n), dp2(n), lis, lds;
	for (int i = 0; i < n; i++) {
		auto it = lower_bound(lis.begin(), lis.end(), nums[i]);
		if (it != lis.end())*it = nums[i], dp1[i] = (it - lis.begin()) + 1;
		else lis.push_back(nums[i]), dp1[i] = lis.size();
	}
	for (int i = n - 1; i >= 0; i--) {
		auto it = lower_bound(lds.begin(), lds.end(), nums[i]);
		if (it != lds.end())*it = nums[i], dp2[i] = it - lds.begin() + 1;
		else lds.push_back(nums[i]), dp2[i] = lds.size();
		if (dp1[i] >= 2 && dp2[i] >= 2)ans = max(ans, dp1[i] + dp2[i] - 1);
        cout<<ans<<endl;
	}
    printvec(lis);
    printvec(dp1);
    printvec(dp2);
	if (ans == 0)cout << -1 << endl;
	else cout << n - ans << endl;
}
int main() {
	ios_base :: sync_with_stdio(0);
	cin.tie(nullptr); cout.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
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

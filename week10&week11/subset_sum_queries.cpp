
#define endl '\n'

const int mx = 1e5 + 10;
int n, q, dp[100][mx], a[100];
bool rec(int i, int sum) {
    if (sum < 0)return 0;
    if (i == -1) {
        if (sum == 0)return 1;
        return 0;
    }
    auto &ans = dp[i][sum];
    if (ans != -1)return ans;
    ans = (rec(i - 1, sum) | rec(i - 1, sum - a[i]));
    return ans;
}
vector<vector<int>> subset_queries(vector<int> &arr, vector<int> &queries) {
    n = arr.size(), q = queries.size();
    for (int i = 0; i < n; i++)a[i] = arr[i];
    memset(dp, -1, sizeof(dp));
    vector<vector<int>> ans;
    for (auto x : queries) {
        if (rec(n - 1, x)) {
            vector<int> t;
            int i = n - 1;
            while (x) {
                if (rec(i-1, x - a[i]))x -= a[i], t.push_back(i);
                i--;
            }
            reverse(t.begin(), t.end());
            ans.push_back(t);
        }
        else {
            ans.push_back({ -1});
        }
    }
    return ans;
}

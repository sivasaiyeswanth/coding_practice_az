#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef vector<ll> vl;

void solve()
{
    ll i, j, n, cnt = 0;
    cin >> n;
    vl A(n), B(n), C(n);
    for (i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    for (i = 0; i < n; i++)
    {
        cin >> B[i];
    }
    for (i = 0; i < n; i++)
    {
        C[i] = A[i] - B[i];
    }
    // since addition is commutative just sort the elements of the array C
    sort(C.begin(), C.end());
    for (i = 0; i < n; i++)
    {
        if (C[i] <= 0)
        {
            // we want to find element Cj which is strictly greater than -Ci
            // Cj>-Ci equivalent to finding a  Cj>=-Ci+1
            if (lower_bound(C.begin(), C.end(), -C[i] + 1ll) - C.begin() != n)
            {
                cnt += n - (lower_bound(C.begin(), C.end(), -C[i] + 1ll) - C.begin());
            }
        }
        else
        {
            cnt += n - (i + 1);
        }
    }
    cout << cnt << endl;
}

int main()
{
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    // #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i, T;

    T = 1;
    cin >> T;

    for (i = 1; i <= T; i++)
    {
        solve();
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int q;
    cin >> q;
    while (q--)
    {
        int n;
        string s;
        cin >> n >> s;
        s = '$' + s;
        vector<int> subset;
        for (int i = 1; i <= n; ++i)
        {
            while (!subset.empty() && s[subset.back()] < s[i])
            {
                subset.pop_back();
            }
            subset.push_back(i);
        }
        int ans = 0;
        int m = (int)subset.size() - 1;
        while (ans <= m && s[subset[ans]] == s[subset[0]])
        {
            ans++;
        }
        ans = m - ans + 1;

        for (int i = 0; i <= m; ++i)
        {
            if (i < m - i)
            {
                swap(s[subset[i]], s[subset[m - i]]);
            }
        }
        for (int i = 2; i <= n; ++i)
        {
            if (s[i] < s[i - 1])
            {
                ans = -1;
                break;
            }
        }
        cout << ans << '\n';
    }
}
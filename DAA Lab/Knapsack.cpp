#include <bits/stdc++.h>
using namespace std;

bool comparison(pair<int, int> a, pair<int, int> b)
{
    double r1 = (double)a.second / a.first;
    double r2 = (double)b.second / b.first;
    return r1 > r2;
}

int main()
{
    int n; // n=4
    cin >> n;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++)
    {
        // weight->8, 10, 5, 9
        // profit->56, 50, 80, 63
        cin >> v[i].first >> v[i].second;
    }

    sort(v.begin(), v.end(), comparison);

    int w; // max weight=25
    cin >> w;

    int ans = 0;

    // weight->8, 10, 5, 9
    // profit->56, 50, 80, 63
    for (int i = 0; i < n; i++)
    {
        if (w >= v[i].first)
        {
            ans += v[i].second;
            w -= v[i].first;
            continue;
        }
        else
        {
            ans += (double)((v[i].second) / (v[i].first)) * w;
            w = 0;
            break;
        }
    }

    cout << ans << endl;
    return 0;
}

/*
4
8 56
10 50
5 80
9 63
25
*/

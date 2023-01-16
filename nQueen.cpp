#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[10][10];
ll n;
bool isSafe(ll i, ll j)
{
    for (ll r = 0; r < n; r++)
    {
        if (dp[r][j] == 1)
            return false;
    }
    ll x = i;
    ll y = j;
    while (x >= 0 && y >= 0)
    {
        if (dp[x][y] == 1)
            return false;
        x--;
        y--;
    }

    // right diagonal
    x = i;
    y = j;
    while (x >= 0 && y < n)
    {
        if (dp[x][y] == 1)
            return false;
        x--;
        y++;
    }
    return true;
}
bool solveNQueen(ll i, ll j)
{
    if (i == n)
    {
        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < n; j++)
            {
                cout << dp[i][j] << " ";
            }
            cout << "\n";
        }
        return true;
    }
    for (ll j = 0; j < n; j++)
    {
        if (isSafe(i,j))
        {
            dp[i][j] = 1;
            bool nextQueen = solveNQueen(i + 1, n);
            if (nextQueen)
                return true;
        }
        dp[i][j] = 0;
    }
    return false;
}
int main()
{
    cin >> n;
    solveNQueen(0, 0);
    return 0;
}
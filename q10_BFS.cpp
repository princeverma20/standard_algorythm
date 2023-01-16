#include <bits/stdc++.h>
using namespace std;
#include <iostream>
typedef long long ll;
const int N = 1e5 + 10;
vector<int> g[N];
int vis[N];
int level[N];

void bfs(int s)
{
    queue<int> q;
    q.push(s);
    vis[s] = 1;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        cout << cur << " ";
        for (int child : g[cur])
        {
            if (!vis[child])
            {
                q.push(child);
                vis[child] = 1;
                // level[child] = level[cur] + 1;
            }
        }
    }
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);

    }
    int t;
    printf("Enter node for start BFS: "); 
    cin >> t;

    bfs(t);

    return 0;
}
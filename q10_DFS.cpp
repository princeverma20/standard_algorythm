#include <bits/stdc++.h>
using namespace std;
#include <iostream>
typedef long long ll;
//***DFS Traversal***
const int N = 1e5 + 10;
vector<int> g[N];
bool vis[N];
int level[N];
int mx=INT_MIN;
void dfs(int v)
{
    // cout << v << " ";
    vis[v] = true;
    for (int child : g[v])
    {  if(!vis[child])
        {level[child]=level[v]+1;
         mx=max(mx,level[child]);
      cout<<"child"<<child<<" "<<level[child]<<" "<<endl;}
        // cout << "par" << v << " ,child" << child << endl;
        if (vis[child])
            continue;
        dfs(child);
    }
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
        g[y].push_back(x);
    }
    int t;
    printf("Enter node for start DFS: ");
    cin >> t;

    dfs(t);
    cout<<"mx"<<mx<<endl;

    return 0;
}
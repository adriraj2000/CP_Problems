//Solution to https://www.spoj.com/problems/SUBMERGE/

#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define rep(i, a, b) for (int i = a; i < b; i++)
#define w(x)  \
    int x;    \
    cin >> x; \
    while (x--)
#define bakchodi                  \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)


vi adj[100005];
bool vis[100005];
int low[100005], disc[100005];
int timer;
set<int> ap;
bool hasBridge;
int n, m;

void dfs(int src, int parent)
{
    low[src] = disc[src] = timer++;
    vis[src] = true;
    int child = 0;

    for (auto el : adj[src])
    {
        if (el == parent)
            continue;
        if (vis[el])
        {
            low[src] = min(low[src], disc[el]);
        }
        else
        {
            dfs(el, src);
            child++;
            low[src] = min(low[src], low[el]);
            if (disc[src] <= low[el] && parent != -1)
            {
                ap.insert(src);
            }
        }
    }
    if (parent == -1 && child > 1)
    {
        ap.insert(src);
    }
}

int32_t main()
{
    while (1)
    {
        cin >> n >> m;
        if (n == 0 && m == 0)
            break;
        rep(i, 1, n + 1)
        {
            adj[i].clear();
            vis[i] = 0;
        }
        ap.clear();
        timer = 1;

        rep(i, 0, m)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        rep(i, 1, n + 1)
        {
            if (!vis[i])
            {
                dfs(i, -1);
            }
        }

        cout << ap.size() << "\n";
    }
}

// int32_t main()
// {
//     bakchodi;
//     int t;
//     // cin >> t;
//     t = 1;
//     while (t--)
//     {
//         code();
//     }
// }

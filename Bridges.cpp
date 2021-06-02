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
vector<pair<int, int>> ans;
bool hasBridge;
 
void bridges(int src, int parent)
{
    low[src] = disc[src] = timer++;
    vis[src] = true;
 
    for (auto el : adj[src])
    {
        if (el == parent)
            continue;
        if (vis[el])
        {
            low[src] = min(low[src], disc[el]);
            if (disc[src] > disc[el])
            {
                ans.push_back({src, el});
            }
        }
        else
        {
            bridges(el, src);
            if (low[el] > disc[src])
            {
                hasBridge = true;
                return;
            }
            ans.push_back({src, el});
            low[src] = min(low[src], low[el]);
        }
    }
}
 
void code()
{
    int n, m;
    cin >> n >> m;
 
    rep(i, 0, m)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
 
    bridges(1, -1);
    if (hasBridge == true)
    {
        cout << 0 << "\n";
    }
    else
    {
        for (auto el : ans)
        {
            cout << el.first << " " << el.second;
            cout << "\n";
        }
    }
}
 
int32_t main()
{
    bakchodi;
    int t;
    // cin >> t;
    t = 1;
    while (t--)
    {
        code();
    }
}

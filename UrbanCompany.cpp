The problem says, You are given a connected undirected graph. It has n nodes and m edges. Each node has some sweetness value that will be given to us.

The game is as follows:

Alice moves first and she may break a node. Each edge connected to this node will vanish.
Bob will pick any connected component(containing all or some nodes)
Alice will pick any remaining connected components if there are any
The game ends in three steps. Both of them want to maximize their score by collecting maximum possible sweetness. They are not trying to minimize each other' score.

Determine the maximum score of Alice and Bob respectively. Assume both plays the game optimally.

Graph nodes index starts from 1. If no connected component left, alice gets 0

Input: number of test cases then n, m and then sweetness of each node and then the edges.

Example:

1

6 7

4 3 7 5 9 2

1 2

2 3

1 3

3 4

4 5

5 6

4 6

For this answer is 11 14

The problem says, You are given a connected undirected graph. It has n nodes and m edges. Each node has some sweetness value that will be given to us.

The game is as follows:

Alice moves first and she may break a node. Each edge connected to this node will vanish.
Bob will pick any connected component(containing all or some nodes)
Alice will pick any remaining connected components if there are any
The game ends in three steps. Both of them want to maximize their score by collecting maximum possible sweetness. They are not trying to minimize each other' score.

Determine the maximum score of Alice and Bob respectively. Assume both plays the game optimally.

Graph nodes index starts from 1. If no connected component left, alice gets 0

Input: number of test cases then n, m and then sweetness of each node and then the edges.

Example:

1

6 7

4 3 7 5 9 2

1 2

2 3

1 3

3 4

4 5

5 6

4 6

For this answer is 11 14
my solution

#include <bits/stdc++.h>
#define M 1000000007
#define inf 1e17 + 1
#define pb push_back
#define forz(i, s, n) for (lli i = s; i < n; i++)
#define fore(i, n, s) for (lli i = n; i >= s; i--)
#define binod                          \
    ios_base ::sync_with_stdio(false); \
    cin.tie(NULL);                     \
    cout.tie(NULL);
using namespace std;
typedef long long int lli;
typedef signed long long int slli;
typedef pair<int, pair<int, int>> pii;

lli dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

bool valid(lli x, lli y, lli n, lli m)
{
    return (x >= 0 and y >= 0 and x < n and y < m);
}

lli timer = 0, n, m,tot = 0, alice = 0, bob = 0;
vector<bool> vis;
vector<lli> sub, tin, low, a;
void dfs(lli i, lli par, vector<vector<lli>> adj)
{
    tin[i] = timer;
    timer++;
    low[i] = tin[i];
    vis[i] = 1;
    sub[i] = a[i];
    lli sw = tot - a[i], ma = 0, children = 0;
    for (auto j : adj[i])
    {
        if (j == par)
            continue;
        low[i] = min(low[i], low[j]);
        if (vis[j])
            continue;
        dfs(j, i, adj);
        low[i] = min(low[i], low[j]);
        sub[i] += sub[j];
        if (low[j] < tin[i])
            continue;
        ma = max(ma, sub[j]);
        sw -= sub[j];
        ++children;
    }
    ma = max(ma, sw);
    if ((par != -1 or children > 1) and alice < tot - ma - a[i])
    {
        alice = tot - ma - a[i];
        bob = ma;
    }
}

int main()
{
    binod;
    cin >> n >> m;
    vis.resize(n, 0);
    tin.resize(n);
    a.resize(n);
    low.resize(n, INT_MAX);
    sub.resize(n, 0);
    forz(i, 0, n)
    {
        cin >> a[i];
        tot += a[i];
    }
    vector<vector<lli>> adj(n);
    forz(i, 0, m)
    {
        lli u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    dfs(0, -1, adj);
    cout << alice << " " << bob << "\n";

    return 0;
}

//https://www.codechef.com/problems/CHEFRRUN/


#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define int long long int
#define pii pair<int, int>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define vi vector<int>
#define mii unordered_map<int, int>
#define MAX 2000002
#define pqb priority_queue<int>
#define pqs priority_queue<int, vi, greater<int>>
#define setbits(x) __builtin_popcount(x)
#define zrobits(x) __builtin_ctz(x)
#define all(x) x.begin(), x.end()
#define ps(x, y) fixed << setprecision(y) << x
#define w(x)  \
    int x;    \
    cin >> x; \
    while (x--)
#define bakchodi                  \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)

vector<bool> primes(100006, true);

int power(int a, int n, int m)
{
    int res = 1;
    while (n)
    {
        if (n % 2)
            res = (res * a) % m;
        n /= 2;
        a = (a * a) % m;
    }
    return res;
}

// int modInverse(int n, int p)
// {
//     return recpow(n, p - 2);
// }

// int nCrModPFermat(int n, int r)
// {
//     if (r == 0)
//         return 1;
//     int fac[n + 1];
//     fac[0] = 1;
//     for (int i = 1; i <= n; i++)
//         fac[i] = fac[i - 1] * i % M;

//     return (fac[n] * modInverse(fac[r], M) % M * modInverse(fac[n - r], M) % M) % M;
// }

vector<int> adj[1000005];
vector<int> tr[1000005]; //transpose
int vis[200003];
vi order, scc;

void dfs(int node)
{
    vis[node] = 1;
    for (auto el : adj[node])
    {
        if (!vis[el])
        {
            dfs(el);
        }
    }
    order.push_back(node);
}

void dfs1(int node)
{
    vis[node] = 1;

    for (int el : tr[node])
        if (vis[el] == 0)
            dfs1(el);
    scc.pb(node);
}

int32_t main()
{
    bakchodi;
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        order.clear();
        int ans = 0;
        rep(i, 0, n + 1)
        {
            adj[i].clear();
            vis[i] = 0;
            tr[i].clear();
        }
        int a[n];
        rep(i, 0, n) cin >> a[i];
        for (int i = 0; i < n; i++)
        {
            adj[i].push_back((i + a[i] + 1) % n);
            tr[(i + a[i] + 1) % n].push_back(i);
        }
        rep(i, 0, n)
        {
            if (vis[i] == 0)
            {
                dfs(i);
            }
        }
        rep(i, 0, n) vis[i] = 0;
        reverse(all(order));
        for (auto el : order)
        {
            if (vis[el] == 0)
            {
                scc.clear();
                dfs1(el);

                if (scc.size() == 1 && scc[0] != adj[scc[0]][0])
                    continue; //Not a self loop
                ans += scc.size();
            }
        }
        cout << ans << "\n";
    }
}

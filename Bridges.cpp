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
 
int recpow(int base, int exp)
{
    int result = 1;
    while (exp > 0)
    {
        if (exp & 1)
            result = ((int)result * base);
        base = ((int)base * base);
        exp >>= 1;
    }
    return result;
}
 
//Euler Totient Function for no of coprimes with n from 1 to n-1
/*int phi(int n) 
            {
                int result = n;
                for (int i = 2; i * i <= n; i++) 
                {
                    if (n % i == 0) 
                    {
                        while (n % i == 0)
                            n /= i;
                        result -= result / i;
                    }
                }
                if (n > 1)
                    result -= result / n;
                return result;
            }*/
 
/*int modInverse(int n, int p)
                        {
                            return recpow(n, p - 2);
                        }
        
                        int nCrModPFermat(int n, int r)
                        {
                            if (r == 0)
                                return 1;
                            int fac[n + 1];
                            fac[0] = 1;
                            for (int i = 1; i <= n; i++)
                                fac[i] = fac[i - 1] * i % M;
        
                            return (fac[n] * modInverse(fac[r], M) % M * modInverse(fac[n - r], M) % M) % M;
                        }*/
 
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
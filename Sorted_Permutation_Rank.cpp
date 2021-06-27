//https://www.interviewbit.com/problems/sorted-permutation-rank/
// An interesting Fenwick tree approach

int n;
vector<int> fac, fen, vis;

int query(int b)
{
    int sum=0;
    while(b!=0)
    {
        sum+=fen[b];
        b-=b&-b;
    }
    return sum;
}

void update(int x, int val)
{
    vis[x] += val;
    while(x<=n)
    {
        fen[x] += val;
        x += x&-x;
    }
}
int Solution::findRank(string A) {
    
    n = (int)A.size();
    
    set<char> s(A.begin(), A.end());
    map<char, int> m;
    int cnt = 1;
    for(auto i: s)
    {
        m[i] = cnt;
        cnt++;
    }
    
    const int mod  = 1000003;
    
    fac.clear(), fen.clear(), vis.clear();
    fac.resize(n+1,1), fen.resize(n+1,0), vis.resize(n+1,1);
    for(int i=1; i<=n; i++) {
        fac[i] = (i*fac[i-1])%mod;
    }
    for(int i=1; i<=n; i++)
        for(int j=i; j>i-(i&-i); j--)
            fen[i] += vis[j];

    int val=1, ans=1;
    for(auto i: A)
    {
        ans = (ans + ((query(m[i]-1) * fac[n-val])%mod))%mod;
        val++;
        update(m[i], -1);
    }
    return ans;
}

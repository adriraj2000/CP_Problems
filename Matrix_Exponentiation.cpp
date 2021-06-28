//https://www.interviewbit.com/problems/find-nth-fibonacci/
// O(logn) Approach

#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;
lli mod = 1e9 + 7;

vector<vector<int>> multiplication(vector<vector<int>> &A, vector<vector<int>> &B)
{
    vector<vector<int>> res(2, vector<int>(2, 0));
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                res[i][j] += (A[i][k] * B[k][j]) % mod;
            }
        }
    }
    return res;
}

vector<vector<int>> matrixExponentiation(vector<vector<int>> &a, int exp)
{
    if (exp == 0)
    {
        vector<vector<int>> res(2, vector<int>(2, 0));
        res[0][0] = res[1][1] = 1;
        return res;
    }

    if (exp == 1)
    {
        return a;
    }

    vector<vector<int>> temp = matrixExponentiation(a, exp / 2);
    vector<vector<int>> mul = multiplication(temp, temp);
    if (exp & 1)
    {
        mul = multiplication(mul, a);
    }
    return mul;
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> a(2, vector<int>(2, 0));
    a[0][0] = a[0][1] = a[1][0] = 1;

    vector<vector<int>> res = matrixExponentiation(a, n - 1);
    // for (int i = 0; i < 2; i++)
    // {
    //     for (int j = 0; j < 2; j++)
    //     {
    //         cout << res[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    cout << a[0][0] << "\n"; // Nth fibonacci
}

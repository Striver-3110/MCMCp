//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// class Solution {
//   public:
//   long long solve(long long a, long long b, long long c, long long n, long long m){
//     //   if( n == 1 || n == 2){
//     //       return 1%m;
//     //   }
//     //   return (a*solve(a,b,c,n-1,m,dp)+b*solve(a,b,c,n-2,m,dp)+c)%m;

//       // initialization
//     //   dp[0] = 1;
//     //   dp[1] = 1;
//     long long first = 1;
//     long long second = 1;
//     long long third = -1;

//       for(int i = 2; i < n; i++){
//         //   dp[i] = (a*dp[i-1]+b*dp[i-2]+c)%m;
//           third = (first*a + second*b + c)%m;
//           first = second;
//           second = third;
//       }
//     //   return dp[n-1]%m;
//     return third == -1 ? 1%m : third%m;

//   }
//     long long genFibNum(long long a, long long b, long long c, long long n, long long m) {
//         // code here
//         // vector<long long>dp(n,-1);
//         // memset(dp,-1,sizeof(dp));
//         return solve(a,b,c,n,m);
//     }
// };

class Solution
{
public:
    vector<vector<long long>> multiply(const vector<vector<long long>> &A, const vector<vector<long long>> &B, long long m)
    {
        int size = A.size();
        vector<vector<long long>> result(size, vector<long long>(size, 0));
        for (int i = 0; i < size; ++i)
        {
            for (int j = 0; j < size; ++j)
            {
                for (int k = 0; k < size; ++k)
                {
                    result[i][j] += A[i][k] * B[k][j];
                    result[i][j] %= m;
                }
            }
        }
        return result;
    }
    long long genFibNum(long long a, long long b, long long c, long long n, long long m)
    {
        if (n <= 2)
            return 1LL % m;
        vector<vector<long long>> mat = {{a, b, 1}, {1, 0, 0}, {0, 0, 1}};
        vector<vector<long long>> res = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
        n -= 2;
        while (n > 0)
        {
            if (n & 1)
                res = multiply(res, mat, m);
            mat = multiply(mat, mat, m);
            n >>= 1;
        }
        return (res[0][0] + res[0][1] + c * res[0][2]) % m;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long a, b, c, n, m;

        cin >> a >> b >> c >> n >> m;

        Solution ob;
        cout << ob.genFibNum(a, b, c, n, m) << endl;
    }
    return 0;
}
// } Driver Code Ends
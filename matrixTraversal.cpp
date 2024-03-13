//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
/*You are required to complete this method */

class Solution
{
public:
    vector<int> matrixDiagonally(vector<vector<int>> &mat)
    {
        int i = 0;
        int j = 0;
        int n = mat.size();

        vector<int> ans(n * n);
        if (n == 1)
        {
            ans[0] = mat[0][0];
            return ans;
        }
        ans[0] = mat[0][0];
        int k = 1;

        while (i < n && j < n)
        {
            if (i == 0 && j != n - 1)
            {
                j++;
                ans[k++] = mat[i][j];
            }
            else
            {
                i++;
                ans[k++] = mat[i][j];
            }
            int f1 = false;
            while (j != -1 && i != n - 1)
            {
                j--;
                if (j == -1)
                    break;
                i++;
                ans[k++] = mat[i][j];
                if (i == n - 1)
                {
                    f1 = true;
                }
            }
            if (!f1)
                j++;
            if (j == 0 && i != n - 1)
            {
                //  j++;
                i++;
                ans[k++] = mat[i][j];
            }
            else
            {
                j++;
                ans[k++] = mat[i][j];
            }
            f1 = false;
            while (i != -1 && j != n - 1)
            {

                i--;
                if (i == -1)
                    break;
                j++;
                ans[k++] = mat[i][j];
                if (j == n - 1)
                {
                    f1 = true;
                }
            }
            if (!f1)
                i++;
        }
        //  ans[k++] = mat[n]
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int n;
        int k = 0;
        // cin>>k;
        cin >> n;
        vector<vector<int>> mat(n, vector<int>(n));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> mat[i][j];
            }
        }
        Solution obj;
        vector<int> ans = obj.matrixDiagonally(mat);
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
    }
}
// } Driver Code Ends
//Qs link - https://www.geeksforgeeks.org/problems/brackets-in-matrix-chain-multiplication1024/1
string matrixChainOrder(const vector<int>& arr) {
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    vector<vector<int>> split(n, vector<int>(n, 0));

    // dp[i][j] will hold the minimum number of scalar multiplications needed to multiply matrices i through j
    // split[i][j] will hold the index where the optimal split occurs for matrices i through j

    for (int len = 2; len < n; ++len) {  // length of the subchain
        for (int i = 0; i < n - len; ++i) {
            int j = i + len;
            dp[i][j] = INT_MAX;

            for (int k = i + 1; k < j; ++k) {
                int q = dp[i][k] + dp[k][j] + arr[i] * arr[k] * arr[j];
                if (q < dp[i][j]) {
                    dp[i][j] = q;
                    split[i][j] = k;
                }
            }
        }
    }

    // Helper function to reconstruct the optimal parenthesized multiplication order
    function<string(int, int)> constructOrder = [&](int i, int j) {
        if (i == j) {
            return string(1, 'A' + i);  // Convert index to letter (A, B, C, ...)
        } else {
            string left = constructOrder(i, split[i][j]);
            string right = constructOrder(split[i][j] + 1, j);
            return "(" + left + right + ")";
        }
    };

    // The answer is the optimal parenthesized multiplication order for matrices 0 to n-2
    return constructOrder(0, n - 2);
}

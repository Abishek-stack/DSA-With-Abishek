class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        const int MOD = 1e9 + 7;

        vector<vector<int>> score(n, vector<int>(n, -1));
        vector<vector<int>> ways(n, vector<int>(n, 0));

        // Start from 'S'
        score[n-1][n-1] = 0;
        ways[n-1][n-1] = 1;

        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {

                if (board[i][j] == 'X') continue;

                if (i == n-1 && j == n-1) continue;

                int maxScore = -1;
                int totalWays = 0;

                // Down (i+1, j)
                if (i + 1 < n && score[i+1][j] != -1) {
                    if (score[i+1][j] > maxScore) {
                        maxScore = score[i+1][j];
                        totalWays = ways[i+1][j];
                    } else if (score[i+1][j] == maxScore) {
                        totalWays = (totalWays + ways[i+1][j]) % MOD;
                    }
                }

                // Right (i, j+1)
                if (j + 1 < n && score[i][j+1] != -1) {
                    if (score[i][j+1] > maxScore) {
                        maxScore = score[i][j+1];
                        totalWays = ways[i][j+1];
                    } else if (score[i][j+1] == maxScore) {
                        totalWays = (totalWays + ways[i][j+1]) % MOD;
                    }
                }

                // Diagonal (i+1, j+1)
                if (i + 1 < n && j + 1 < n && score[i+1][j+1] != -1) {
                    if (score[i+1][j+1] > maxScore) {
                        maxScore = score[i+1][j+1];
                        totalWays = ways[i+1][j+1];
                    } else if (score[i+1][j+1] == maxScore) {
                        totalWays = (totalWays + ways[i+1][j+1]) % MOD;
                    }
                }

                if (maxScore == -1) continue;

                int val = (board[i][j] == 'E') ? 0 : board[i][j] - '0';

                score[i][j] = maxScore + val;
                ways[i][j] = totalWays % MOD;
            }
        }

        if (score[0][0] == -1) return {0, 0};

        return {score[0][0], ways[0][0]};
    }
};
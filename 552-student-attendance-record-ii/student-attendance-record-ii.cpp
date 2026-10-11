class Solution {
public:
    int checkRecord(int n) {
        vector<vector<int>> transitions = {
            {0, 0, 0, 0, 1, 1, 0},
            {1, 1, 1, 0, 0, 0, 0},
            {1, 1, 0, 1, 0, 0, 0},
            {1, 1, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 1, 1, 0},
            {0, 0, 0, 0, 1, 0, 1},
            {0, 0, 0, 0, 1, 0, 0}
        };

        vector<vector<int>> paths_matrix = matrix_power(transitions, n - 1);

        vector<int> initial_state = {1, 1, 1, 0, 0, 0, 0};

        vector<int> final_state(paths_matrix[0].size(), 0);

        for (int i = 0; i < static_cast<int>(paths_matrix[0].size()); ++i) {
            for (int j = 0; j < static_cast<int>(initial_state.size()); ++j) {
                final_state[i] = (final_state[i] + static_cast<long long>(initial_state[j]) * paths_matrix[j][i] % MOD) % MOD;
            }
        }

        int total_paths = static_cast<int>(accumulate(final_state.begin(), final_state.end(), 0LL) % MOD);

        return total_paths;
    }

private:
    const int MOD = 1000000007;

    vector<vector<int>> multiply_matrices(const vector<vector<int>>& A, const vector<vector<int>>& B) const {
        int rows_A = static_cast<int>(A.size()), cols_A = static_cast<int>(A[0].size());
        int rows_B = static_cast<int>(B.size()), cols_B = static_cast<int>(B[0].size());

        vector<vector<int>> result(rows_A, vector<int>(cols_B, 0));

        for (int i = 0; i < rows_A; ++i) {
            for (int j = 0; j < cols_B; ++j) {
                for (int k = 0; k < cols_A; ++k) {
                    result[i][j] = (result[i][j] + static_cast<long long>(A[i][k]) * B[k][j] % MOD) % MOD;
                }
            }
        }

        return result;
    }

    vector<vector<int>> matrix_power(vector<vector<int>> matrix, int n) const {
        int size = static_cast<int>(matrix.size());
        vector<vector<int>> result(size, vector<int>(size, 0));

        for (int i = 0; i < size; ++i) {
            result[i][i] = 1;
        }

        vector<vector<int>> base = matrix;
        while (n > 0) {
            if (n % 2 == 1) {
                result = multiply_matrices(result, base);
            }
            base = multiply_matrices(base, base);
            n /= 2;
        }

        return result;
    }
};
class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int area = 0;
        int n = grid.size();
        vector<int> arr_yz(n,0);
        vector<int> arr_zx(n,0);
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (grid[i][j] > 0){
                    area++;
                    if (arr_yz[i] < grid[i][j]){
                        arr_yz[i] = grid[i][j];
                    }
                    if (arr_zx[j] < grid[i][j]){
                        arr_zx[j] = grid[i][j];
                    }
                }
            }
        }
        for (int i = 0; i < n; i++){
            area += arr_yz[i] + arr_zx[i];
        }
        return area;
    }
};
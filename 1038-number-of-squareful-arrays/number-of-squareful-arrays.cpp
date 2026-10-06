#include <vector>
#include <unordered_map>
#include <cmath>
#include <algorithm>

class Solution {
public:
    int numSquarefulPerms(std::vector<int>& nums) {
        int n = nums.size();
        std::unordered_map<int, int> count;
        for (int num : nums) {
            count[num]++;
        }
        
        // Find unique elements and sort them
        std::vector<int> unique_nums;
        for (auto& pair : count) {
            unique_nums.push_back(pair.first);
        }
        
        // Precompute valid adjacent elements
        std::unordered_map<int, std::vector<int>> graph;
        for (int i = 0; i < unique_nums.size(); ++i) {
            for (int j = 0; j < unique_nums.size(); ++j) {
                long long sum = (long long)unique_nums[i] + unique_nums[j];
                long long r = round(sqrt(sum));
                if (r * r == sum) {
                    graph[unique_nums[i]].push_back(unique_nums[j]);
                }
            }
        }
        
        int total_permutations = 0;
        
        // Backtracking function
        auto backtrack = [&](auto& self, int curr, int remaining) -> void {
            if (remaining == 0) {
                total_permutations++;
                return;
            }
            
            for (int next_num : graph[curr]) {
                if (count[next_num] > 0) {
                    count[next_num]--;
                    self(self, next_num, remaining - 1);
                    count[next_num]++; // Backtrack
                }
            }
        };
        
        for (int num : unique_nums) {
            count[num]--;
            backtrack(backtrack, num, n - 1);
            count[num]++; 
        }
        
        return total_permutations;
    }
};
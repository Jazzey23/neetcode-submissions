class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // 1. Build frequency map
        unordered_map<int, int> frq;
        for (int num : nums) {
            frq[num]++;
        }

        // 2. Use a vector of vectors for buckets (Index = Frequency)
        // Size is nums.size() + 1 because max frequency is nums.size()
        vector<vector<int>> buckets(nums.size() + 1);
        for (const auto& [key, value] : frq) {
            buckets[value].push_back(key);
        }

        // 3. Prepare result vector
        vector<int> returnable;
        returnable.reserve(k); // Optimizes memory allocation

        // 4. Iterate backward to grab most frequent elements
        for (int i = buckets.size() - 1; i >= 0; i--) {
            for (int num : buckets[i]) {
                returnable.push_back(num);
                k--;
                // Break immediately once we have exactly k elements
                if (k == 0) {
                    return returnable; 
                }
            }
        }

        return returnable;
    }
};
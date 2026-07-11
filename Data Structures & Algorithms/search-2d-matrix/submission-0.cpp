class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int low = 0;
        int high;
        int mid;

        for(int i = 0; i < matrix.size(); i++){
                low = 0;
                high = matrix[i].size() -1;
                if(matrix[i][high] < target){
                    continue;
                } 


                while(low <= high){
                    int mid = low + (high - low) / 2;
                    if(matrix[i][mid] == target){
                        return true;
                    }
                    if(matrix[i][mid] > target){
                        high = mid - 1;
                    }else{
                        low = mid + 1;
                    }
                }

            
        }
        return false;
    }
};

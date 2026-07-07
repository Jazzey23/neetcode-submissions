class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i = 0;
        int j = heights.size() - 1;
        int maxSpace = INT_MIN;
   
        while(i < j){
            
            int val = min(heights[j], heights[i]);
            

            int area = val * (j - i);
           
            
            maxSpace = max(maxSpace, area);
          


           if(heights[i] < heights[j]){
                i++;
           }else{
                j--;
           }

        
            
        }
        
        return maxSpace;

        
    }
};

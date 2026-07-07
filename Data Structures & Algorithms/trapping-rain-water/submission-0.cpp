class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;
        int leftMax = height[l];
        int rightMax = height[r];
    
       
        int h = 0;
        while(l < r){

           

            leftMax = max(leftMax, height[l]);
            rightMax = max(rightMax, height[r]);

            if(leftMax < rightMax){
                // LEFT MAX IS LESSER THAN RIGHT SO WE MOVE THIS;
                l++;
                 if(height[l] < leftMax){
                    h += leftMax - height[l];
                }

            }else{
                // RIGHT MAX IS LESSER THAN LEFT SO WE MOVE THIS;
                r--;
                if(height[r] < rightMax){
                    h += rightMax - height[r];
                }
            }

        }

        return h;
        
    }
};

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n=nums.size();
        int i=0;
        int j=0;
        int k=0;
        while(i<n){
            if(nums[i]==val){
                
                i++;
                
            }
            else{
                nums[j]=nums[i];
                k++;
                j++;
                i++;
            }
        }
        return k;
    }
};
class Solution {
public:
    bool f(vector<int>&nums,int n,int p){
        int i=0;
        int c=0;
        while(i<nums.size()-1){
            if(nums[i+1]-nums[i]<=n){
                c++;
                i=i+2;
            }
            else{
                i++;
            }
        }
        return c>=p;
    }
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(),nums.end());
        int l=0;
        int n=nums.size();
        int r=nums[n-1]-nums[0];
        int res=INT_MAX;
        while(l<=r){
            int mid=(l+r)/2;
            if(f(nums,mid,p)){
                res=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }

        }
        return res;
        
    }
};
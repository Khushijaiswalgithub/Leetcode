class Solution {
public:
    // void f(vector<int>& nums,int n,int &s,int ind,int &ans){
    // //     if(ind>=n){
    //         if(s%3==0){
    //             ans=max(ans, s);
    //         }
    //         return;

    //     }
    //     s+=nums[ind];
    //     f(nums,n,s,ind+1,ans);
    //     s-=nums[ind];
    //     f(nums,n,s,ind+1,ans);
    // }
    int maxSumDivThree(vector<int>& nums) {
        
        int n=nums.size();
        int sum=0;
        vector<int>r1;
        vector<int>r2;
        
        for(int i=0;i<n;i++){
           sum+=nums[i];
           if(nums[i]%3==1){
            r1.push_back(nums[i]);
           }
           if(nums[i]%3==2){
            r2.push_back(nums[i]);
           }
        }

        if(sum%3==0) return sum;
        sort(r1.begin(),r1.end());
        sort(r2.begin(),r2.end());
        int s=0;
        if(sum%3==1){

            if(r1.size()>=1) s=max(s,sum-r1[0]);
            if(r2.size()>=2) s=max(s,sum-r2[0]-r2[1]);
        }
        if(sum%3==2){
            if(r2.size()>=1) s=max(s,sum-r2[0]);
            if(r1.size()>=2) s=max(s,sum-r1[0]-r1[1]);
        }
        
        return s;

        
    }
};
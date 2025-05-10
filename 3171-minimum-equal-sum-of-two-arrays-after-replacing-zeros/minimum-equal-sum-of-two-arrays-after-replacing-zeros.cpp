class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1=0;
        long long sum2=0;
        int n1=nums1.size();
        int n2=nums2.size();
        long long c1=0;
        long long c2=0;
        for(int i=0;i<n1;i++){
            if(nums1[i]==0){
                c1++;
                sum1++;
            }
            else{
            sum1+=nums1[i];
            }
        }
        for(int i=0;i<n2;i++){
            if(nums2[i]==0){
                c2++;
                sum2++;
            }
            else{
            sum2+=nums2[i];
            }
        }
        if(sum1>sum2 && c2==0){
            return -1;

        }
        if(sum2>sum1 && c1==0){
            return -1;

        }
        return max(sum1,sum2);




        
    }
};
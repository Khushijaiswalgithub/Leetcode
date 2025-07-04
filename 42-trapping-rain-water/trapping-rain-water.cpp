class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();

        vector<int>lmaxi(n);
        vector<int>rmaxi(n);
        lmaxi[0]=height[0];
        for(int i=1;i<n;i++){
            lmaxi[i]=max(lmaxi[i-1],height[i]);
        }
        rmaxi[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--){
            rmaxi[i]=max(rmaxi[i+1],height[i]);
        }
        vector<int> water(n);
        int sum=0;
        for(int i=0;i<n;i++){
            water[i]=min(lmaxi[i],rmaxi[i])-height[i];
            sum+=water[i];
        }
        return sum;
    }
};
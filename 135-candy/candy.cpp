class Solution {
public:
    int candy(vector<int>& ratings) {
        
        int i=1;
        int n=ratings.size();
        vector<int>left(n,1);
        while(i<n ){
            if(ratings[i]>ratings[i-1]){
                left[i]=left[i-1]+1;
            }
           
            i++;
            
        }
        vector<int>right(n,1);
        i=n-2;
        while(i>=0 ){
            if(ratings[i]>ratings[i+1]){
                right[i]=right[i+1]+1;
            }
            
            i--;
            
        }
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=max(left[i],right[i]);

        }
        return sum;
            
        
    }
};
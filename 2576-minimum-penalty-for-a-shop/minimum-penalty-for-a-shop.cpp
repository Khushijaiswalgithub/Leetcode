class Solution {
public:
    int bestClosingTime(string customers) {
        int n=customers.size();
        int y=0;

        for(auto c:customers){
            if(c=='Y'){
                y++;
            }
            
        }
        int ans=-1;
        int pe=INT_MAX;
        int cy=0;
        int cn=0;
        for(int i=0;i<n;i++){
            int p=0;
            if(customers[i]=='Y'){
                cy++;
                p=y-cy+1+cn;
            }
            else{
                cn++;
                p=y-cy+cn-1;

            }
            if(p<pe){
                ans=i;
                pe=p;

            }

        }
        if(n-y<pe){
            ans=n;
        }
        return ans;
    
        
    }
};
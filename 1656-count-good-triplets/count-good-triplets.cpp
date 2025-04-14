class Solution {
public:
    void subset(int ind,int n,int a,int b,int c,int &count,vector<int>&arr,vector<int>&res){
        
        if(res.size()==3){
            if(abs(res[0]-res[1])<=a && abs(res[1]-res[2])<=b && abs(res[0]-res[2])<=c){
                count++;
            }
            return;
        }
        if(ind>=n){
            return;
        }
        res.push_back(arr[ind]);
        subset(ind+1,n,a,b,c,count,arr,res);
        res.pop_back();
        subset(ind+1,n,a,b,c,count,arr,res);

    }
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int count=0;
        int n=arr.size();
        vector<int>res;
        subset(0,n,a,b,c,count,arr,res);
        return count;
    }
};
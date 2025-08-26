class Solution {
public:
   bool binary (vector<int>arr,int t,int n){
    int l=0;
    int h=n-1;
    while(l<=h){
        int mid=(l+h)/2;
        if(arr[mid]==t) return true;
        else if(arr[mid]>t) h=mid-1;
        else l=mid+1;

    }
    return false;
   }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<n;i++){
            if(matrix[i][0]<=target && target<=matrix[i][m-1]){
                if(binary(matrix[i],target,m)){
                    return true;
                }
            }
        }
        return false;
        
    }
};
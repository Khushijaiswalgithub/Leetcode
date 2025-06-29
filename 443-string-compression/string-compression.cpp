class Solution {
public:
    int compress(vector<char>& chars) {
        int i=0;
        int ind=0;
        int n=chars.size();
        while(i<n){
            char curr=chars[i];
            i++;
            int count=1;
            while(i<n && chars[i]==curr){
                count++;
                i++;
            }
            chars[ind]=curr;
            ind++;
            if(count>1){
                string str=to_string(count);
                for(char &it:str){
                    chars[ind]=it;
                    ind++;
                }
            }
            
            
            
        }
        return ind;
    }
};
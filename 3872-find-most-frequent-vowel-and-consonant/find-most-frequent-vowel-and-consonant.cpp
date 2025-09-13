class Solution {
public:
    int maxFreqSum(string s) {
        int n=s.size();
        vector<int>vec(50,0);
        int maxv=0;
        int maxc=0;
        for(char ch:s){
            if(ch=='a' ||ch=='e' || ch=='i' ||ch=='o' ||ch=='u'){
                vec[ch-'a']++;
                maxv=max(maxv,vec[ch-'a']);
            }
            else{
                vec[ch-'a']++;
                maxc=max(maxc,vec[ch-'a']);
            }
        }
        return maxv+maxc;
        
    }
};
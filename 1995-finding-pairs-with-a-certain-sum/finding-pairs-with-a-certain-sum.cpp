class FindSumPairs {
public:
    unordered_map<int,int>mp;
    unordered_map<int,int>mp1;
    vector<int>n1;
    vector<int>n2;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        for(int i=0;i<nums1.size();i++){
            mp[nums1[i]]++;
        }
        for(int i=0;i<nums2.size();i++){
            mp1[nums2[i]]++;
        }
        n1=nums1;
        n2=nums2;
    }
    
    void add(int index, int val){
        int oldVal = n2[index];
        mp1[oldVal]--;              
        if (mp1[oldVal] == 0) {
            mp1.erase(oldVal);      
        }
        
        n2[index] += val;
        mp1[n2[index]]++;   
    }
    
    int count(int tot) {
        int c=0;
        for(auto it:mp){
            int x=tot-it.first;
            if(mp1.find(x)!=mp1.end()){
                c+=mp[it.first]*mp1[x];
            }
        }
        return c;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */
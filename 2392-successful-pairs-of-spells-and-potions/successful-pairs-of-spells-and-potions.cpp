class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
//         int n=spells.size();
//    int m=potions.size();
//    vector<int>ans(n,0);
//  vector<pair<int,int>>s;
//  for(int i=0;i<n;i++){
//     s.push_back({spells[i],i});

//  }
//  sort(s.rbegin(),s.rend());
//   sort(potions.begin(),potions.end()); 
//  unordered_map<int,int>mp;
  
//     int l=0,r=m-1;
//      for(int i=0;i<n;i++){ 
//         while(l<=r && potions[l]*s[i].first<(int)success){ 
//             l++; 
//          } 
//          ans[s[i].second]=m-l;
//     } 
              
             
//     return ans;
//     }
    int n = spells.size();
    int m = potions.size();

    // keep original indices and sort spells DESC
    vector<pair<int,int>> spells_idx;
    spells_idx.reserve(n);
    for (int i = 0; i < n; ++i) spells_idx.emplace_back(spells[i], i);
    sort(spells_idx.begin(), spells_idx.end(), greater<>()); // sort by spell descending

    sort(potions.begin(), potions.end()); // ascending

    vector<int> ans(n, 0);
    int p = 0; // pointer into potions (moves right)

    for (auto &pr : spells_idx) {
        long long spell = pr.first;
        // advance p while current potion is insufficient
        while (p < m && spell * (long long)potions[p] < success) ++p;
        ans[pr.second] = m - p;
    }

    return ans;
}
};
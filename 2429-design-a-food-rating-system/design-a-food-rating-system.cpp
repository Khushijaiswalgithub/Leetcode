
   struct cmp {
    bool operator()(const pair<int,string> &a, const pair<int,string> &b) const {
        if (a.first != b.first) return a.first > b.first;
        return a.second < b.second;                     
    }
};

class FoodRatings {
public:
    unordered_map<string, int> ftor;              
    unordered_map<string, string> ftoc;          
    unordered_map<string, set<pair<int,string>, cmp>> ctof; 

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for (int i = 0; i < n; i++) {
            ftor[foods[i]] = ratings[i];
            ftoc[foods[i]] = cuisines[i];
            ctof[cuisines[i]].insert({ratings[i], foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        string cuisine = ftoc[food];
        int oldRating = ftor[food];
        ctof[cuisine].erase({oldRating, food});
        ftor[food] = newRating;
        ctof[cuisine].insert({newRating, food});
    }
    
    string highestRated(string cuisine) {
        return ctof[cuisine].begin()->second; 
    }
};


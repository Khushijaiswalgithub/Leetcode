class MovieRentingSystem {
public:
    typedef pair<int,int> p; 
    set<tuple<int,int,int>> rented; 
    unordered_map<int,set<p>> mp;   
    unordered_map<int,set<p>> mp1;  

    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for (auto &it : entries) {
            mp[it[1]].insert({it[2], it[0]});
            mp1[it[1]].insert({it[0], it[2]});
        }
    }

    vector<int> search(int movie) {
        vector<int> ans;
        if (mp.find(movie) != mp.end()) {
            int c = 0;
            for (auto &[price, shop] : mp[movie]) {
                ans.push_back(shop);
                if (++c >= 5) break;
            }
        }
        return ans;
    }

    void rent(int shop, int movie) {
        if (mp.find(movie) != mp.end()) {
            auto it = mp1[movie].lower_bound({shop, INT_MIN});
            int price = it->second;
            mp[movie].erase({price, shop});
           
            rented.insert({price, shop, movie});
        }
    }

    void drop(int shop, int movie) {
        auto it = mp1[movie].lower_bound({shop, INT_MIN});
        int price = it->second;
        mp[movie].insert({price, shop});
        mp1[movie].insert({shop, price});
        rented.erase({price, shop, movie});
    }

    vector<vector<int>> report() {
        vector<vector<int>> ans;
        int c = 0;
        for (auto &[price, shop, movie] : rented) {
            ans.push_back({shop, movie});
            if (++c >= 5) break;
        }
        return ans;
    }
};

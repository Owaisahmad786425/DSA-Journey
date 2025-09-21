class MovieRentingSystem {
    unordered_map<int,set<pair<int,int>>> unrented,rented;
    unordered_map<int,set<pair<int,int>>> mp;
    set<tuple<int,int,int>> store;
public:
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for(auto e:entries){
            int shop=e[0];
            int movie=e[1];
            int price=e[2];
            unrented[movie].insert({price,shop});
            mp[movie].insert({shop,price});
        }
    }
    
    vector<int> search(int movie) {
        vector<int> res;
        int count=0;
        if(unrented.count(movie)){
            for(auto &[price,shop]:unrented[movie]){
                res.push_back(shop);
                count++;
                if(count>=5) break;
            }
        }
        return res;
    }
    
    void rent(int shop, int movie) {
          auto it=mp[movie].lower_bound({shop,INT_MIN});
          int price=it->second;
          unrented[movie].erase({price,shop});
          rented[movie].insert({price,shop});
          store.insert({price, shop, movie});

    }
    
    void drop(int shop, int movie) {
          auto it=mp[movie].lower_bound({shop,INT_MIN});
          int price=it->second;
          rented[movie].erase({price,shop});
          unrented[movie].insert({price,shop});
          store.erase({price, shop, movie});

    }
    
    vector<vector<int>> report() {
        vector<vector<int>> res;
        int count=0;
        for(auto [price,shop,movie]:store){
            res.push_back({shop,movie});
            count++;
            if(count>=5) break;
        }
        return res;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */
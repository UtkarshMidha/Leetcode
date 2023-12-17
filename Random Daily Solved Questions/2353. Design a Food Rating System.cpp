struct cmp {
 bool operator()(const pair<int, string> &b, const pair<int, string> &a) const 
    { 
        if(a.first==b.first)
        {
            return a.second<b.second;
        }
        return a.first>b.first;
    }
};

class FoodRatings {
public:
    map<string, string> mps;
    
    map<string, int> mpr; 
    
    map<string, set<pair<int, string>, cmp>> mapp;
    
    
    
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        
        int size=foods.size();
        
        for(int i=0; i<size; i++)
        {
            mps[foods[i]]=cuisines[i];
            mapp[cuisines[i]].insert({ratings[i], foods[i]});
            mpr[foods[i]]=ratings[i];
        }
    cout<<"done";
    }
    
    void changeRating(string food, int newRating) {
        mapp[mps[food]].erase({mpr[food], food});
        mapp[mps[food]].insert({newRating, food});
        mpr[food]=newRating;
    
    if(newRating<INT_MIN)
        cout<<"1" ;
    }
    
    string highestRated(string cuisine) {
        
        cout<<"over";
        return (*--mapp[cuisine].end()).second;
        cout<<"finish";
        
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        
         auto comp = [](auto a, auto b){
            return ((a[0] == b[0] &&  a[1] < b[1]) ||  a[0] > b[0]);   
        };
        sort(people.begin(), people.end(),comp);
        vector<vector<int>> res; //To store the final array to be returned
        
        for(int i = 0; i < people.size(); i++)
        {
            int idx = people[i][1];
            //Inserting the element at desired position.
            res.insert(res.begin() + idx, people[i]); 
        }
        
        return res;
    }
};

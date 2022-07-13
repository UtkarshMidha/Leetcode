class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int ans=0;
        sort(people.begin(),people.end());
        int i=0,j=people.size()-1;
        while(i<=j){
            if(people[j]==limit){
                j--;
                ans++;
            }
            if(people[i]+people[j]<=limit){
                ans++;
                i++;
                j--;
                
            }
            else{
                ans++;
                j--;
            }
        }
        return ans;
    }
};

class Solution {
private:
    int parent[26];

    int find(int val){
        if(val!=parent[val]) 
            parent[val]=find(parent[val]);
        return parent[val]; 
    }
public:
    bool equationsPossible(vector<string>& equations) {
        for(int i=0;i<26;i++)
            parent[i]=i;
        
        for(string s:equations){
            if(s[1]=='=')
                parent[find(s[0]-'a')]=find(s[3]-'a');
            
        }
        for (string e : equations)
            if (e[1] == '!' && find(e[0] - 'a') == find(e[3] - 'a'))
                return false;
        return true;
    }
};

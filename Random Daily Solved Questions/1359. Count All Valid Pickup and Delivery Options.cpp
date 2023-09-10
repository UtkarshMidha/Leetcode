class Solution {
public:
    int countOrders(int n) {
        long sol=1, MOD = 1e9 + 7;
        
        for(int i=1;i<=n;i++){
            sol=sol*(2*i-1)*i%MOD;
        }
        return sol;
    }
};


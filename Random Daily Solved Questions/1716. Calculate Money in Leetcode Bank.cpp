class Solution {
public:
    int totalMoney(int n) {
        //--------O(N)---------
        if(n<1) return 0;
        int counter=1,sum=0;
        while(n>0){
            for(int i=0;i<7 and n-- > 0 ;++i) 
                sum+=counter+i;
            counter++;
        }
        return sum;
       
    }
};


class Solution {
private:
    int square_nikalne_wala_balak(int n ){
        int sum = 0,temp;
        while(n){
            temp=n%10;
            sum+=temp*temp;
            n/=10;
        }
        return sum ;
    }
    
    
public:
    bool isHappy(int n) {
        int slow,fast;
        slow=fast=n;
        do{
            slow=square_nikalne_wala_balak(slow);
            fast=square_nikalne_wala_balak(fast);
            fast=square_nikalne_wala_balak(fast);
        }while(slow!=fast);
        
        return slow==1;
            
        
    }
};

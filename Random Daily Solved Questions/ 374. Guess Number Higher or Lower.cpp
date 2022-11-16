/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        // BINARY SEARCH
        // int i=1,j=n;
        // while(i<=j){
        //     int mid=i+(j-i)/2;
        //     if(guess(mid)==0) return mid;
        //     else if(guess(mid)==-1) j=mid-1;
        //     else i=mid+1;
        // }
        // return -1;
    
    //TERNARY SEARCH
        int i=1,j=n;
        while(i<=j){
            int m1=i+(j-i)/3;
            int m2=j-(j-i)/3;
            int ans1=guess(m1),ans2=guess(m2);
            if(ans1==0) return m1;
            else if (ans2==0) return m2;
            else if(ans1==-1)
                j=m1-1;
            else if(ans2==1)
                i=m2+1;
            else{
                i=m1+1;
                j=m2-1;
            }
            
        }
    return -1;
    
    
    }
};

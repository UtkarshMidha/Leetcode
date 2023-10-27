class Solution {
public:
    
    //------------------BRUTE FORCE-------------------
    string longestPalindrome(string s) {
        if (s.size() <= 1) // if size is 0 or 1
            return s;  // return string directly
        
        else{
            int max =1; // the max length of palindrome in string
            int f = 0;  // the first index of this max palindrome
            
            for(int i = 0; i< s.size(); i++) //for every element in string
                for (int j= s.size()-1; j>=i; j--) // check if we have the same element
                    if (s[i] == s[j]){  // if two element are same
                        int a = i;      // check if between them is palindrome
                        int b = j;
                        int flag = 1;
                        while(a<=b){    // from the start index i to the end index j
                            if (s[a] == s[b]){ // if the elements between are same
                                a++; b--;           
                            }
                            else{
                                flag = 0; 
                                break;
                            }
                        }
                        if (flag ==1 && max <(j-i+1)){  // if it is palindrome and longer than max
                            max = j-i+1;  // set it to max
                            f = i;
                        }    
                    }
            return s.substr(f,max);
        }
        
    }
};

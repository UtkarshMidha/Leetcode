class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
    //     int i=0;
    //     while(arr[i] < arr[i+1]) {
    //         i++;
    //     }
    //     return i;                   
    int i=0,j=arr.size()-1;
        while(i<j){
            int mid=i+(j-i)/2;
            if(arr[mid]<arr[mid+1])
                i=mid+1;
            else j=mid;
        }
        
    return i;
    
    
    }
        
};

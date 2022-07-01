class Solution {
public:
    int minMoves(vector<int>& nums) {
        return accumulate(nums.begin(), nums.end(), 0)-nums.size()* *min_element(nums.begin(),nums.end());
    }
};
// 0  1  1  2  3  4  8  8  9  9    +9
// 9 10 10  11 12 13 17 17 18 9
    
// 9  9 10  10 11 12 13 17 17 18   +9
// 18 18 19 19 20 21 22 26 26 18
    
// 18 18 18 19 19 20 21 22 26 26   +8
// 26 26 26 27 27 28 29 30 34 26
    
// 26 26 26 26 27 27 28 29 30 34   +8
// 34 34 34 34 35 35 36 37 38 34
    
// 34 34 34 34 34 35 35 36 37 38   +4
// 38 38 38 38 38 39 39 40 41 38
    
// 38 38 38 38 38 38 39 39 40 41   +3
// 41 41 41 41 41 41 42 42 43 41
    
// 41 41 41 41 41 41 41 42 42 43   +2
// 43 43 43 43 43 43 43 44 44 43

// 43 43 43 43 43 43 43 43 44 44   +1
// 44 44 44 44 44 44 44 44 45 44
    
// 44 44 44 44 44 44 44 44 44 45   +1
// 45 45 45 45 45 45 45 45 45 45

//     --------------------
// 2  3  6  9      +7
// 9  10 13 9
    
// 9  9  10  13    +4
// 13 13 14  13
    
// 13 13 13 14     +1
// 14 14 14 14
//     ---------
//let's define sum as the sum of all the numbers,
//before any moves; minNum as the min number int the list; n is the length of the list;

//After, say m moves, we get all the numbers as x , and we will get the following equation

//sum + m * (n - 1) = x * n
//and actually,
//  x = minNum + m
// => sum +mn -m =n*minNum +mn
//=> sum-n*minNum=m

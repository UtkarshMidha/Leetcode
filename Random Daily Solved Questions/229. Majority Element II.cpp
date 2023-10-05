class Solution {
public:
    vector <int> majorityElement(vector <int> &a)
{
    vector <int> result;
    int candOne = -1 , candTwo = -1 , cntOne = 0 , cntTwo = 0;
    for(int &i : a)
    {
        if(candOne == i)
            cntOne++;
        else if(candTwo == i)
            cntTwo++;
        else if(cntOne == 0)
        {
            candOne = i;
            cntOne++;
        }
        else if(cntTwo == 0)
        {
            candTwo = i;
            cntTwo++;
        }
        else
        {
            cntOne--;
            cntTwo--;
        }
    }
    cntOne = 0;
    cntTwo = 0;
    for(int &i : a)
    {
        if(i == candOne)
            cntOne++;
        if(i == candTwo)
            cntTwo++;
    }
    if(cntOne > ((int)a.size()) / 3)
        result.push_back(candOne);
    if(cntTwo > ((int)a.size()) / 3 && candOne!=candTwo )
        result.push_back(candTwo);
    return result;
}
};

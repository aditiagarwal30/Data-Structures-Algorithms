class Solution
{
public:
    int heightChecker(vector<int> &heights)
    {
        vector<int> temp;
        temp = heights;
        sort(temp.begin(), temp.end());
        int c = 0;
        for (int i = 0; i < temp.size(); i++)
        {
            if (temp[i] != heights[i])
                c++;
        }
        return c;
    }
};
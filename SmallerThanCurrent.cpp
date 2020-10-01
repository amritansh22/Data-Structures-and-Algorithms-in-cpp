/* Disclaimer:
This solution does not contain any header file or driver code, this only contains the class 
and the algorithm used in this problem. You're probably learning DS and Algo because you 
want to get into Competitive Programming or crack and interview, you should be acquainted with 
this kind of solution.
TL;DR This is not the complete solution
*/
class Solution
{
public:
    vector<int> smallerNumbersThanCurrent(vector<int> &nums)
    {
        vector<int> ans;
        int freq = 0;
        for (int x : nums)
        {

            for (int y : nums)
            {
                if (y < x)
                {
                    freq++;
                }
            }
            ans.push_back(freq);
            freq = 0;
        }
        return ans;
    }
};
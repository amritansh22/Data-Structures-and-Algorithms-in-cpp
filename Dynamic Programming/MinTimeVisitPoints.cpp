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
    int minTimeToVisitAllPoints(vector<vector<int>> &points)
    {
        int steps = 0;
        for (int i = 0; i < points.size() - 1; i++)
        {
            steps += max(abs(points[i + 1][0] - points[i][0]), abs(points[i + 1][1] - points[i][1]));
        }
        return steps;
    }
};

#include <vector>
#include <string>
#include <stack>

using namespace std;
class Solution
{
public:
    int calc(vector<string> &op)
    {
        stack<int> score;
        int i = 0;

        while (i < op.size())
        {
            if (op[i] == "C")
            {
                // Invalidate the previous score by popping
                if (!score.empty())
                {
                    score.pop();
                }
            }
            else if (op[i] == "D")
            {
                // Double the previous score
                if (!score.empty())
                {
                    score.push(score.top() * 2);
                }
            }
            else if (op[i] == "+")
            {
                // Add the sum of the last two scores
                if (score.size() >= 2)
                {
                    auto first = score.top();
                    score.pop();
                    auto second = first + score.top();
                    score.push(first);
                    score.push(second);
                }
            }
            else
            {
                // Add a new score (convert the string to integer)
                score.push(stoi(op[i]));
            }
            i++;
        }

        // Return the sum of all the scores
        int total = 0;
        while (!score.empty())
        {
            total += score.top();
            score.pop();
        }

        return total;
    }

    int calPoints(vector<string> &operations)
    {

        return calc(operations);
    }
};
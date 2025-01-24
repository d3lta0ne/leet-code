#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    int calc(vector<string> &op)
    {
        vector<int> score;
        int i = 0;

        while (i < op.size())
        {
            if (op[i] == "C")
            {
                // Invalidate the previous score by popping
                if (!score.empty())
                {
                    score.pop_back();
                }
            }
            else if (op[i] == "D")
            {
                // Double the previous score
                if (!score.empty())
                {
                    score.push_back(score.back() * 2);
                }
            }
            else if (op[i] == "+")
            {
                // Add the sum of the last two scores
                if (score.size() >= 2)
                {
                    score.push_back(score[score.size() - 1] + score[score.size() - 2]);
                }
            }
            else
            {
                // Add a new score (convert the string to integer)
                score.push_back(stoi(op[i]));
            }

            // Increment index to process the next operation
            i++;
        }

        // Return the sum of all the scores
        int total = 0;
        for (int sc : score)
        {
            total += sc;
        }

        return total;
    }

    int calPoints(vector<string> &operations)
    {

        return calc(operations);
    }
};
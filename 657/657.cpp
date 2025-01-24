#include <string>
using namespace std;
class Solution
{

public:
    bool judgeCircle(string moves)
    {
        int x, y, i;

        i = 0;

        x = 0;
        y = 0;

        while (moves[i])
        {
            if (moves[i] == 'U')
            {
                y++;
            }
            else if (moves[i] == 'D')
            {
                y--;
            }
            else if (moves[i] == 'L')
            {
                x--;
            }
            else if (moves[i] == 'R')
            {
                x++;
            }
            i++;
        }

        return x == 0 && y == 0;
    }
};
#include <string>
using namespace std;
class Solution
{

public:
    bool judgeCircle(string moves)
    {
        int chk[2]{};
        for (char x : moves)
        {
            if (x == 'R')
            {
                chk[0]++;
            }
            else if (x == 'L')
            {
                chk[0]--;
            }
            else if (x == 'U')
            {
                chk[1]++;
            }
            else if (x == 'D')
            {
                chk[1]--;
            }
            else
            {
                continue;
            }
        }

        for (int ck : chk)
        {
            if (ck != 0)
                return false;
        }

        return true;
    }
};
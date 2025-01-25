#include <string>
#include <iostream>
using namespace std;

class Solution
{
public:
    bool isRobotBounded(string instructions)
    {
        int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        // Initial position is in the center
        int x = 0, y = 0;
        // facing north
        int idx = 0;

        for (char i : instructions)
        {
            if (i == 'L')
                idx = (idx + 3) % 4;
            else if (i == 'R')
                idx = (idx + 1) % 4;
            else
            {
                x += directions[idx][0];
                y += directions[idx][1];
            }
        }

        // after one cycle:

        /*It's a limit cycle trajectory if the robot is back to the center: x = y = 0 or if the robot doesn't face north: idx != 0*/
        return (x == 0 && y == 0) || (idx != 0);
    }
};
#include <string>
#include <iostream>
using namespace std;

class Solution
{
public:
    bool isRobotBounded(string instructions)
    {
        int x = 0;
        int y = 0;
        int direction = 0;
        pair<int, int> movement[] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // Correct the initialization here

        int loop = 2;
        while (loop)
        {
            for (char instruction : instructions)
            {
                if (instruction == 'R')
                    direction = abs(++direction % 4); // Right turn
                else if (instruction == 'L')
                    direction = abs((--direction + 4) % 4); // Left turn (avoid negative direction)
                else if (instruction == 'G')
                {
                    x += movement[direction].first;
                    y += movement[direction].second;
                }
                cout << "Instruction: " << instruction << ", Position: (" << x << ", " << y << "), Direction: " << direction << endl;
            }
            loop--;
        }

        return x == 0 && y == 0;
    }
};
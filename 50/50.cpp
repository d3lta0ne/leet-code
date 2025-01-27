class Solution
{
public:
    double myPow(double x, int n)
    {
        // Edge case for n == 0
        if (n == 0)
            return 1;

        // Edge case for x == 1
        if (x == 1)
            return 1;

        // Handle the case where n is negative
        long long N = n; // Use long long to handle INT_MIN edge case
        if (n < 0)
        {
            x = 1 / x;
            N = -N; // Convert n to positive
        }

        double res = 1;
        while (N > 0)
        {
            if (N % 2 == 1)
            { // If N is odd, multiply the result by x
                res *= x;
            }
            x *= x; // Square x for the next power of 2
            N /= 2; // Divide N by 2
        }

        return res;
    }
};

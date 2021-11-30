#include <iostream>
using namespace std;

// find the squre root of number
/**
 * 1. bruteforce check till n TC: O(n)
 * 2. check till root n only TC: O(sqrt(n))
 * 3. using binary search TC: O(log(n))
 */

// implimantation using binary search till perticular precision
float sqrt_precision(int n, int p)
{
    int start = 0, end = n;
    float root;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (mid * mid == n)
            return mid;

        if (mid * mid > n)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
            root = mid;
        }
    }

    float inc = 0.1;
    for (int i = 0; i < p; i++)
    {
        while (root * root <= n)
        {
            root += inc;
        }
        root -= inc;
        inc /= 10;
    }

    return root;
}
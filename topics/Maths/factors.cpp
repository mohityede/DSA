#include <iostream>
#include <vector>
using namespace std;

/**
 * find the factors of number
 * 1. Bruteforce approach to check divisilblity of number till number. TC: O(n)
 * 2. check the divibility of number till sqrt(n) only and maintain divisor and dividant. TC:O(sqrt(n))
 */

// function with second approach
vector<int> getFactors(int n)
{
    vector<int> ans;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            ans.push_back(i);
            if (i != n / i)
                ans.push_back(n / i);
        }
    }
    return ans;
}

/**
 * Find the HCF of number
 * 1. Bruteforce approach is check each number from lowest to 1 which divisible by both num. TC:O(min(a,b));
 * 2. Using euculian algorithm. TC:O(log(n))
 */

// first approach
int getHCF(int a, int b)
{
    int curr = min(a, b);
    for (int i = curr; i >= 1; i--)
    {
        if (a % i == 0 && b % i == 0)
            return i;
    }
    return 1;
}

// Euclidian algorithm
int euclideAlgo(int a, int b)
{
    if (a == 0)
        return b;
    return euclideAlgo(b % a, a);
}

// LCM bruteforce method TC:O(lcm)
int getLCM(int a, int b)
{
    int curr = max(a, b);
    while (curr % a != 0 || curr % b != 0)
        curr++;
    return curr;
}

// method using gcd TC:O(log(n)) if use euclidian algo
// Property: a*b = GCD(a,b)*LCM(a,b)
int LCM_usingGCD(int a, int b)
{
    return (a * b) / euclideAlgo(a, b);
}
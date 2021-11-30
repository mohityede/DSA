#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

/**
 * function to check number is prime or not
*/
// bruteforce TC: O(n)
bool isPrime(int n)
{
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

// check till root only (optimal approach) TC: O(sqrt(n))
bool isPrime_Optimized(int n)
{
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

/**
 * function to print prime numbers till given number
*/
// bruteforce approach with optimal prime check TC : O(n*sqrt(n))
void printPrime(int n)
{
    for (int i = 2; i <= n; i++)
    {
        if (isPrime_Optimized(i))
            cout << i << " ";
    }
}

// sieve of eratosthenes
// TC : O(n*log(log(n))) SC: O(n)
void sieveOfEratosthenes(int n)
{
    bool temp[n + 1];
    memset(temp, true, sizeof(temp));

    for (int i = 2; i * i <= n; i++)
    {
        if (temp[i])
        {
            int j = i * i;
            while (j <= n)
            {
                temp[j] = false;
                j = j + i;
            }
        }
    }

    for (int i = 2; i <= n; i++)
    {
        if (temp[i])
            cout << i << ",";
    }
}
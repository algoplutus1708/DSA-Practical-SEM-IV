#include <bits/stdc++.h>
using namespace std;

int sum(int freq[], int i, int j)
{
    int s = 0;
    for (int k = i; k <= j; k++)
    {
        s += freq[k];
    }
    return s;
}

int optCost(int freq[], int i, int j)
{

    if (j < i)
    {
        return 0;
    }
    if (j == i)
    {
        return freq[i];
    }

    int fsum = sum(freq, i, j);

    int min = INT_MAX;

    for (int r = i; r <= j; ++r)
    {
        int leftCost = optCost(freq, i, r - 1);

        int rightCost = optCost(freq, r + 1, j);

        int totalCost = leftCost + rightCost;

        if (totalCost < min)
        {
            min = totalCost;
        }
    }

    return min + fsum;
}

int optimalSearchTree(int keys[], int freq[], int n)
{
    return optCost(freq, 0, n - 1);
}

int main()
{
    int keys[] = {10, 20, 30, 40, 50};
    int freq[] = {4, 2, 6, 3, 5};
    int n = sizeof(keys) / sizeof(keys[0]);
    cout << "Cost of Optimal BST is " << optimalSearchTree(keys, freq, n);
    return 0;
}

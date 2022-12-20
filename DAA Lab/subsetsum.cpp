#include <bits/stdc++.h>
using namespace std;
/*
 *Find whether or not there exists any subset
 *  of array  that sum up to targetSum
 */
void subsetsum_Backtracking(vector<int> &Set, int pos, int sum, int tmpsum, int size, bool &found)
{
    if (sum == tmpsum)
        found = true;
    // generate nodes along the breadth
    for (int i = pos; i < size; i++)
    {
        if (tmpsum + Set[i] <= sum)
        {
            tmpsum = tmpsum + Set[i];
            // consider next level node (along depth)
            subsetsum_Backtracking(Set, i + 1, sum, tmpsum, size, found);
            tmpsum = tmpsum - Set[i];
        }
    }
}

int main()
{

    clock_t t;
    t = clock();

    int n;
    cout << "Enter the number of elements in the set" << endl;
    cin >> n;

    vector<int> Set;
    cout << "Enter the values" << endl;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        Set.push_back(x);
    }

    int sum;
    cout << "Enter the value of sum" << endl;
    cin >> sum;

    bool found = false;
    subsetsum_Backtracking(Set, 0, sum, 0, n, found);

    if (found)
    {
        cout << "Subset  found" << endl;
    }
    else
    {
        cout << "Subset not found" << endl;
    }

    t = clock() - t;
    double time_taken = ((double)t) / CLOCKS_PER_SEC; // in seconds

    printf("\nThis probelm took %f seconds to execute \n\n", time_taken);
    return 0;
}
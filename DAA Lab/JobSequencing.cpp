#include <bits/stdc++.h>
using namespace std;

struct Job
{
    char id;
    int dead;
    int profit;
};

bool comparison(Job a, Job b)
{
    return a.profit > b.profit;

}

void printJobScheduling(Job arr[], int n)
{
    // Sort all jobs according to decreasing order of profit
    sort(arr, arr + n, comparison);

    int result[n]; // To store result (Sequence of jobs)
    bool slot[n]={false};  // To keep track of free time slots

    // Initialize all slots to be free
    // Iterate through all given jobs
    for (int i = 0; i < n; i++)
    {
        // Find a free slot for this job (Note that we start
        // from the last possible slot)
        for (int j = min(n, arr[i].dead); j > 0; j--)
        {
            // Free slot found
            if (slot[j] == false)
            {
                result[j] = i;  // Add this job to result
                slot[j] = true; // Make this slot occupied
                break;
            }
        }
    }

    // Print the result
    for (int i = 0; i < n; i++)
        if (slot[i])
            cout << arr[result[i]].id << " ";
}

int main()
{
    Job arr[] = {{'a', 2, 60},
                 {'b', 1, 100},
                 {'c', 3, 20},
                 {'d', 2, 40},
                 {'e', 1, 20}};
    int n=5;
    printJobScheduling(arr, n);
    return 0;
}


/*
({'31',2,60],
('32",1,100],
('33',3,20],

4°,2,401,

$*,1,20))



*/
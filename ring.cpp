#include <iostream>
#include <omp.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    int process[n];
    cout << "Enter the process IDs: ";
    for (int i = 0; i < n; i++)
    {
        cin >> process[i];
    }

    int rank;
    cout << "Enter the rank of this process: ";
    cin >> rank;

    int next = (rank + 1) % n;
    int prev = (rank - 1 + n) % n;

#pragma omp parallel sections
    {
#pragma omp section
        {
            cout << "Process " << rank << " sending message to process " << next << endl;
        }

#pragma omp section
        {
            cout << "Process " << rank << " receiving message from process " << prev << endl;
        }
    }

    return 0;
}
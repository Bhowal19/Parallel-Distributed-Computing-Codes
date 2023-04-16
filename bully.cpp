#include <iostream>
#include <omp.h>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    int process[n];
    cout << "Enter the process IDs: ";
    for (int i = 0; i < n; i++) {
        cin >> process[i];
    }

    int coordinator = n;
    int i;

    #pragma omp parallel for
    for (i = 0; i < n; i++) {
        if (process[i] > process[coordinator - 1]) {
            coordinator = i + 1;
        }
    }

    cout << "Coordinator is " << coordinator << endl;
    return 0;
}
#include <iostream>
#include <cmath>

using namespace std;

void spiralSorrend(const int* matrix, int n, int* spiral)
{
    int sqrtN = sqrt(n);

    for (int i = 0; i < n; i++)
    {
        




    }
}

int main()
{
    // PELDA
    int n;

    cin >> n;

    int sqrtN = sqrt(n);

    int prespiral[n];
    int spiral[n];

    for (int i = 0; i < n; i++) cin >> prespiral[i];

    spiralSorrend(prespiral, n, spiral);

    for (int i = 0; i < sqrtN; i++)
    {
        for (int j = 0; j < sqrtN; j++)
        {
            cout << spiral[i * sqrtN + j] << " ";
        }

        cout << endl;
    }

    return 0;
}
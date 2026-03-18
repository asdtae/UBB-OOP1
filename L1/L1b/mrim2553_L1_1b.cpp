#include <iostream>
#include <cmath>

using namespace std;

void spiralSorrend(const int* matrix, int n, int* spiral)
{
    // https://wbd.ms/share/v2/aHR0cHM6Ly93aGl0ZWJvYXJkLm1pY3Jvc29mdC5jb20vYXBpL3YxLjAvd2hpdGVib2FyZHMvcmVkZWVtLzQzNWM2NDdkOTRmYTQ0M2ZhMWFlMzE3MmY2NWUxNjBlX0JCQTcxNzYyLTEyRTAtNDJFMS1CMzI0LTVCMTMxRjQyNEUzRF9mOTY2MzZkZi04ZmQ3LTQ3YmMtYWM5My1lZDc4M2E2MThiMTc=

    int sqrtN = sqrt(n);

    int felso = 0;
    int also = sqrtN - 1;
    int bal = 0;
    int jobb = sqrtN - 1;

    int k = 0;

    while (felso <= also && bal <= jobb)
    {

        for (int i = bal; i <= jobb; i++, k++)
        {
            spiral[k] = matrix[felso * sqrtN + i];
        }

        felso++;

        for (int i = felso; i <= also; i++, k++)
        {
            spiral[k] = matrix[i * sqrtN + jobb];
        }

        jobb--;

        if (felso <= also)
        {
            for (int i = jobb; i >= bal; i--, k++)
            {
                spiral[k] = matrix[also * sqrtN + i];
            }

            also--;
        }

        if (bal <= jobb)
        {
            for (int i = also; i >= felso; i--, k++)
            {
                spiral[k] = matrix[i * sqrtN + bal];
            }

            bal++;
        }
    }
}

int main()
{
    // PELDA
    int n;

    cin >> n;

    int sqrtN = sqrt(n);

    int preSpiral[n];
    int spiral[n];

    for (int i = 0; i < n; i++) cin >> preSpiral[i];

    spiralSorrend(preSpiral, n, spiral);

    for (int i = 0; i < sqrtN; i++)
    {
        for (int j = 0; j < sqrtN; j++)
        {
            cout << spiral[i * sqrtN + j] << " ";
        }

        cout << endl;
    }

    /*
        n = 25

        IN
            0  1  2  3  4
            10 11 12 13 14
            20 21 22 23 24
            30 31 32 33 34
            40 41 42 43 44

        OUT
            0 1 2 3 4
            14 24 34 44 43
            42 41 40 30 20
            10 11 12 13 23
            33 32 31 21 22

    */

    return 0;
}
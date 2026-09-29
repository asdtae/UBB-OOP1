/*
 *  Mathe Ruben-Jonathan
 *  mrim2553
 *  512/2
 *  feladat_nev
 */
#include <iostream>
#define MAXIM(a,b) (a>b ? (a) : (b))

using namespace std;

class Vector
{
    int *tomb;
    int dim;

public:
    // feltolt konstruktor
    Vector(const int *t, const int d)
    {
        tomb = new int[d];
        dim = d;

        for (int i=0; i<d; i++)
        {
            tomb[i] = t[i];
        }
    }

    // destruktor
    ~Vector()
    {
        delete[] tomb;
    }

    void kiir()
    {
        for (int i = 0; i<dim; i++) cout << tomb[i] << ' ';
        cout << endl;
    }

    int getMaxi()
    {
        int maxi = tomb[0];

        for (int i = 1; i<dim; i++) maxi = MAXIM(maxi,tomb[i]);

        return maxi;
    }

    void scalarMulti()
    {
        // scale by 2

        for (int i = 0; i<dim; i++) tomb[i] *= 2;
    }

    void scalarMulti(const int n)
    {
        for (int i = 0; i<dim; i++) tomb[i] *= n;
    }
};

int main()
{
    int t[5]={38,65,93,32,90};

    Vector v1(t,5);

    v1.kiir();
    v1.scalarMulti(5);
    v1.kiir();

    cout << v1.getMaxi() << endl;

    return 0;
}
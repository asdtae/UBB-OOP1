/*
 *  Mathe Ruben-Jonathan
 *  mrim2553
 *  512/2
 *
 *  Lab2_1_a
 */
#include <iostream>
#include "mrim2553_L2_1a_Inter.h"

using namespace std;

int main()
{
    int a,b;
    cin >> a >> b;

    inter* ab = init(a, b);

    // set(ab,12.36371);

    kiir(ab);

    ab = duplaz(ab);

    kiir(ab);

    felsz(ab);

    return 0;
}
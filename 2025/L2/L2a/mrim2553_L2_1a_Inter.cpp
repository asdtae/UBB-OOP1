#include <iostream>

using namespace std;

struct inter
{
    double* daData;
    int leftB;
    int rightB;
    int delta;
};

int getDelta(int a, int b)
{
    if (a > b) swap(a,b);
    return (b - a) + 1;
}

inter* init(int a, int b)
{
    const int delta = getDelta(a,b);

    inter *p = new inter;

    p->leftB = a;
    p->rightB = b;
    p->delta = delta;

    p->daData = new double[delta];
    for (int i = 0; i<delta; i++) p->daData[i] = 0.0;

    return p;
}

void felsz(inter* p)
{
    if (p != nullptr)
    {
        delete[] p->daData;
        delete p;
    }
}

inter* duplaz(inter *p)
{
    int middle = (p->leftB + p->rightB) / 2;
    int factor = p->rightB - middle;

    inter* q = new inter;

    q->rightB = p->rightB + factor;
    q->leftB = p->leftB - factor;

    //cout << "debug: " << '[' << q->leftB << ',' << q->rightB << ']' << endl;

    q->delta = getDelta(q->leftB,q->rightB);
    q->daData = new double[q->delta];

    for (int i = 0; i < q->delta; i++) q->daData[i] = 0.0;

    int i = factor;
    int j = 0;

    while (i < p->delta + factor)
    {
        q->daData[i] = p->daData[j];

        j++;
        i++;
    }

    felsz(p);
    return q;
}

void kiir(const inter *p)
{
    cout << '[' << p->leftB << ',' << p->rightB << ']' << endl;

    for (int i = 0; i<p->delta; i++) cout << p->daData[i] << ' ';

    cout << endl;
}

// void set(const inter* p, double x)
// {
//     for (int i = 0; i<p->delta; i++) p->daData[i] = x;
// }
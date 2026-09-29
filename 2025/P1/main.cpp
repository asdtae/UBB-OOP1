/*
 *  Mathe Ruben-Jonathan
 *  mrim2553
 *  512/1
 *
 */
#include <iostream>
#include <vector>
#include <exception>

using namespace std;

class NagyEgesz
{
protected:
    int* szamjegyek;
    int n;
    int elojel;

public:
    class NullavalValoOsztas : public exception
    {
    public:
        const char* msc = "Hiba: Nullaval valo osztas!";

        NullavalValoOsztas()
        {
            cerr << msc << endl;
        }
    };

    NagyEgesz(const int elojel, const int n, const int* szamjegyek)
    {
        this->elojel = elojel;
        this->n = n;

        this->szamjegyek = new int[n];

        if (szamjegyek != nullptr)
        {
            for (int i = 0; i < n; i++)
            {
                this->szamjegyek[i] = szamjegyek[i];
            }
        } else
        {
            this->szamjegyek[0] = 0;
        }
    }

    NagyEgesz() : NagyEgesz(0, 1, nullptr){}

    NagyEgesz(const NagyEgesz& t) : NagyEgesz(t.elojel, t.n, t.szamjegyek){}

    NagyEgesz(long long szam)
    {
        if (szam < 0)
        {
            elojel = -1;
            szam *= -1;
        }
        else if (szam > 0) elojel = 1;
        else elojel = 0;

        if (szam != 0)
        {
            vector<int> t;
            makeVecCucc(szam,0,t);

            this->n = t.size();
            this->szamjegyek = new int[t.size()];
            for (int i = 0; i < t.size(); i++) this->szamjegyek[i] = t[i];
        } else
        {
            this->n = 1;
            this->szamjegyek = new int[1];
            this->szamjegyek[0] = 0;
        }
    }

    NagyEgesz(int szam) : NagyEgesz(static_cast<long long>(szam)){};

    ~NagyEgesz()
    {
       delete[] szamjegyek;
    }

    NagyEgesz operator+(const NagyEgesz& t) const
    {
        if (this->elojel == 0) return t;
        if (t.elojel == 0) return *this;

        if (this->elojel == -1 && t.elojel == 1)
        {
            NagyEgesz temp = *this;
            temp.elojel = 1;
            return t - temp;
        }

        if (this->elojel == 1 && t.elojel == -1) {
            NagyEgesz temp = t;
            temp.elojel = 1;
            return *this - temp;
        }

        if (this->elojel == t.elojel)
        {
            const int maxN = this->n > t.n ? this->n+1 : t.n+1;
            int* NewSzamjegyek = new int[maxN];
            for (int i = 0; i < maxN; i++) NewSzamjegyek[i] = 0;

            int i = this->n-1;
            int j = t.n-1;
            int k = maxN-1;

            int m = 0;

            while (i >= 0 || j >= 0 || m > 0)
            {
                NewSzamjegyek[k] = m;

                if (i >= 0)
                {
                    NewSzamjegyek[k] += this->szamjegyek[i];
                    i--;
                }

                if (j >= 0)
                {
                    NewSzamjegyek[k] += t.szamjegyek[j];
                    j--;
                }

                if (NewSzamjegyek[k] > 10)
                {
                    m = NewSzamjegyek[k] / 10;
                    NewSzamjegyek[k] %= 10;
                }

                k--;
            }

            NagyEgesz e;

            e.elojel = this->elojel;
            e.n = maxN - ((k == 0) ? 1 : 0);
            e.szamjegyek = new int[e.n];
            for (int o = 0; o < e.n; o++) e.szamjegyek[o] = NewSzamjegyek[o+((k == 0) ? 1 : 0)];

            delete[] NewSzamjegyek;
            return e;
        }
    }

    NagyEgesz operator-(const NagyEgesz& t) const
    {
        if (this->elojel == 0)
        {
            NagyEgesz temp = t;
            temp.elojel *= -1;
            return temp;
        }
        if (t.elojel == 0) return *this;

        if (this->elojel != t.elojel)
        {
            NagyEgesz temp = t;
            temp.elojel = this->elojel;
            return *this + temp;
        }

        bool aKisebb = (this->n < t.n) ? true : false;
        if (this->n == t.n)
        {
            for (int i = 0; i < this->n; i++)
            {
                if (this->szamjegyek[i] < t.szamjegyek[i])
                {
                    aKisebb = true;
                    break;
                }

                if (this->szamjegyek[i] > t.szamjegyek[i]) break;
            }
        }

        if (aKisebb)
        {
            NagyEgesz e = t - *this;
            e.elojel *= -1;
            return e;
        }

        int* NewSzamjegyek = new int[this->n];

        int i = this->n-1;
        int j = t.n-1;
        int k = this->n-1;
        int m = 0;

        while (i >= 0)
        {
            NewSzamjegyek[k] = this->szamjegyek[i] - m;

            if (j >= 0)
            {
                NewSzamjegyek[k] -= t.szamjegyek[j];
                j--;
            }

            if (NewSzamjegyek[k] < 0)
            {
                m = 1;
                NewSzamjegyek[k] += 10;
            }

            i--;
            k--;
        }

        int o = 0;
        while (o < this->n && NewSzamjegyek[o] == 0) o++;

        if (o == this->n)
        {
            NagyEgesz temp;
            delete[] NewSzamjegyek;
            return temp;
        }

        NagyEgesz e;
        e.elojel = this->elojel;
        e.n = this->n - o;
        e.szamjegyek = new int[e.n];
        for (int x = 0; x < e.n; x++) e.szamjegyek[x] = NewSzamjegyek[x+o];

        delete[] NewSzamjegyek;
        return e;
    }

    NagyEgesz operator*(const NagyEgesz& t) const
    {
        if (this->elojel == 0 || t.elojel == 0) {
            NagyEgesz temp;
            return temp;
        }

        const int newN = this->n + t.n;
        int* NewSzamjegyek = new int[newN]{0};

        for (int i = this->n-1; i >= 0; i--)
        {
            for (int j = t.n-1; j >= 0; j--)
            {
                int e = this->szamjegyek[i] * t.szamjegyek[j];
                const int ePoz = i + j + 1;
                const int mPoz = i + j;
                e += NewSzamjegyek[ePoz];

                NewSzamjegyek[ePoz] = e % 10;
                NewSzamjegyek[mPoz] += e / 10;
            }
        }

        int o = 0;
        while (o < newN && NewSzamjegyek[o] == 0) o++;

        NagyEgesz e;
        e.elojel = this->elojel * t.elojel;
        e.n = newN - o;
        e.szamjegyek = new int[e.n];
        for (int x = 0; x < e.n; x++) e.szamjegyek[x] = NewSzamjegyek[x+o];

        delete[] NewSzamjegyek;
        return e;
    }

    NagyEgesz operator/(const NagyEgesz& t) const
    {
        if (t.elojel == 0) throw NullavalValoOsztas();

        if (this->elojel == 0)
        {
            NagyEgesz temp;
            return temp;
        }

        NagyEgesz absT = t;
        absT.elojel = 1;

        NagyEgesz m;
        m.elojel = 1;

        int* NewSzamjegyek = new int[this->n];
        int k = 0;

        for (int i = 0; i < this->n; i++)
        {
            m = m * 10 + this->szamjegyek[i];
            int h = 0;

            for (int szj = 9; szj >= 0; szj--)
            {
                if (const NagyEgesz prb = m - absT * szj; prb.elojel != -1)
                {
                    h = szj;
                    m = prb;
                    break;
                }
            }

            NewSzamjegyek[k] = h;
            k++;
        }

        int o = 0;
        while (o < this->n && NewSzamjegyek[o] == 0) o++;

        if (o == k)
        {
            NagyEgesz temp;
            delete[] NewSzamjegyek;
            return temp;
        }

        NagyEgesz e;
        e.elojel = this->elojel * t.elojel;
        e.n = k - o;
        e.szamjegyek = new int[e.n];
        for (int x = 0; x < e.n; x++) e.szamjegyek[x] = NewSzamjegyek[x+o];

        delete[] NewSzamjegyek;
        return e;
    }

    NagyEgesz& operator++() {
        *this = *this + 1;
        return *this;
    }

    NagyEgesz operator++(int) {
        NagyEgesz temp = *this;
        ++(*this);
        return temp;
    }

    NagyEgesz& operator--() {
        *this = *this - 1;
        return *this;
    }

    NagyEgesz operator--(int) {
        NagyEgesz temp = *this;
        --(*this);
        return temp;
    }

    NagyEgesz& operator=(const NagyEgesz& t) {
        if (this != &t) {
            delete[] this->szamjegyek;

            this->elojel = t.elojel;
            this->n = t.n;
            this->szamjegyek = new int[this->n];
            for (int i = 0; i < n; i++) {
                this->szamjegyek[i] = t.szamjegyek[i];
            }
        }

        return *this;
    }

    NagyEgesz& operator+=(const NagyEgesz& t) {
        *this = *this + t;
        return *this;
    }

    NagyEgesz& operator-=(const NagyEgesz& t) {
        *this = *this - t;
        return *this;
    }

    NagyEgesz& operator*=(const NagyEgesz& t) {
        *this = *this * t;
        return *this;
    }

    NagyEgesz& operator/=(const NagyEgesz& t) {
        *this = *this / t;
        return *this;
    }

    friend ostream& operator<<(ostream& os, const NagyEgesz& szam);

private:
    static void makeVecCucc(const long long inp, int n, vector<int> &t)
    {
        if (inp == 0)
        {
            t.resize(n,0);
            t[t.size()-n] = inp%10;
            return;
        }

        n++;
        makeVecCucc(inp/10,n,t);
        t[t.size()-n] = inp%10;
    }

};

ostream& operator<<(ostream& os, const NagyEgesz& szam)
{
    if (szam.elojel == -1) {
        os << "-";
    }

    if (szam.elojel == 0) {
        os << 0;
        return os;
    }

    for (int i = 0; i < szam.n; i++) {
        os << szam.szamjegyek[i];
    }

    return os;
}

int main()
{
    try
    {
        NagyEgesz t1 = 5;
        NagyEgesz t2 = 10;
        NagyEgesz t3 = -2;
        NagyEgesz t4 = -20;

        cout << "Test: +" << endl;
        cout << t1 << " + " << t2 << " = " << t1 + t2 << endl;
        cout << t2 << " + " << t3 << " = " << t2 + t3 << endl;
        cout << t3 << " + " << t4 << " = " << t3 + t4 << endl << endl << endl;

        cout << "Test: -" << endl;
        cout << t1 << " - " << t2 << " = " << t1 - t2 << endl;
        cout << t2 << " - " << t3 << " = " << t2 - t3 << endl;
        cout << t3 << " - " << t4 << " = " << t3 - t4 << endl << endl << endl;

        cout << "Test: *" << endl;
        cout << t1 << " * " << t2 << " = " << t1 * t2 << endl;
        cout << t2 << " * " << t3 << " = " << t2 * t3 << endl;
        cout << t3 << " * " << t4 << " = " << t3 * t4 << endl << endl << endl;

        cout << "Test: /" << endl;
        cout << t1 << " / " << t2 << " = " << t1 / t2 << endl;
        cout << t2 << " / " << t3 << " = " << t2 / t3 << endl;
        cout << t3 << " / " << t4 << " = " << t3 / t4 << endl << endl << endl;
        //cout << t3 << " / " << '0' << " = " << t3 / 0 << endl << endl << endl;

        cout << "Test: ++" << endl;
        cout << t1 << " ++ " << " = " << t1++ << endl;
        cout << "++ " << t1 << " = " << ++t1 << endl << endl << endl;

        cout << "Test: --" << endl;
        cout << t1 << " -- " << " = " << t1-- << endl;
        cout << "-- " << t1 << " = " << --t1 << endl << endl << endl;

        cout << "Test: += -= *= /=" << endl;
        cout << t1 << " += " << t2 << " : " << (t1 += t2) << endl;
        cout << t2 << " -= " << t3 << " : " << (t2 -= t3) << endl;
        cout << t3 << " *= " << t4 << " : " << (t3 *= t4) << endl;
        cout << t3 << " /= " << t4 << " : " << (t3 /= t4) << endl << endl << endl;

    } catch (exception& e) {}

    return 0;
}
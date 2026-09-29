/*
 *  Mathe Ruben-Jonathan
 *  mrim2553
 *  512
 */

#include <iostream>

using namespace std;

// a.)
class Konyv {
    char* cim;
    char* szerzo;
    int oldalszam;
    int ev;

public:
    // class HibasAdat : exception {
    // public:
    //     const char* data = "Hibas bemeneti adatok!";
    // };

    Konyv(const char* c, const char* sz, const int osz, const int ev) {
        if (c == nullptr || sz == nullptr || osz <= 0 || ev < 1450 || ev > 2026) throw "Hibas bemeneti adatok!";

        this->cim = new char[strlen(c)];
        this->szerzo = new char[strlen(sz)];
        strcpy(this->cim,c);
        strcpy(this->szerzo,sz);

        this->oldalszam = osz;
        this->ev = ev;
    }

    Konyv(const Konyv &k) {
        this->cim = new char[strlen(k.cim)];
        this->szerzo = new char[strlen(k.szerzo)];
        strcpy(this->cim,k.cim);
        strcpy(this->szerzo,k.szerzo);

        this->oldalszam = k.oldalszam;
        this->ev = k.ev;
    }

    ~Konyv() {
        delete[] this->cim;
        delete[] this->szerzo;
    }

    Konyv& operator=(const Konyv& k) {
        if (this != &k) {
            delete[] this->cim;
            delete[] this->szerzo;

            this->cim = new char[strlen(k.cim)];
            this->szerzo = new char[strlen(k.szerzo)];
            strcpy(this->cim,k.cim);
            strcpy(this->szerzo,k.szerzo);

            this->oldalszam = k.oldalszam;
            this->ev = k.ev;
        }
        return *this;
    }

    bool operator<(const Konyv& k) const {
        return (this->oldalszam < k.oldalszam);
    }

    Konyv& operator+=(const int n) {
        if (n < 0) throw "Hibas bemeneti adatok!";
        this->oldalszam += n;

        return *this;
    }

    friend ostream& operator<<(ostream& o, const Konyv& k) {
        return k.Kiir(o);
    }

    ostream& Kiir(ostream& o) const {
        o << "Cim: " << this->cim << endl
          << "Szerzo: " << this->szerzo << endl
          << "Oldalszam: " << this->oldalszam << endl
          << "Ev: " << this->ev << endl;

        return o;
    }

    int meret() const {
        return this->oldalszam;
    }
};

// b.)
template <class T>
class Tarolo {
    T* elemek;
    int meret;
    int kapacitas;

public:
    Tarolo(const int maxCap) {
        if (maxCap <= 0) throw "A maximalis kapacitas nem pozitiv!";
        this->meret = 0;
        this->kapacitas = maxCap;

        // this->elemek = new T[maxCap];
    }

    ~Tarolo() {
        delete[] this->elemek;
    }

    void hozzaad(T& adat) {
        if (this->meret == this->kapacitas-1) throw "A tarolo megtelt!";
        this->elemek[this->meret] = adat;
        ++this->meret;
    }

    T legkisebb() const {
        if (meret == 0) throw "A tarolo ures!";
        // T mini;

        for (int i = 0; i<=this->meret; i++) {
            // if (this->elemek[i] < mini) mini = this->elemek[i];
        }

        // return mini;
    }

    ostream& kiirMind(ostream& o) const {
        for (int i = 0; i<this->meret; i++) o << this->elemek[i] << ' ';
        return o;
    }
};

// c.)
class Konyvtar {
    Tarolo<Konyv> konyvek;

public:
    Konyvtar(const int maxCap) : konyvek(maxCap) {};

    void hozzaadKonyv(Konyv& k) {
        konyvek.hozzaad(k);
    }

    int legrovidebbKonyv() const {
        const Konyv x = konyvek.legkisebb();
        return x.meret();
    }

    ostream& kiir(ostream& o) const {
        /* o << */ konyvek.kiirMind(o);
        return o;
    }
};

int main() {
    Konyv a("Almas kalandok","Almaember",200,2016);
    Konyv b("Befottes kalandok","Bal",23,1694);
    Konyv c("Csupa kalandok","Cirmus",442,2000);
    Konyvtar k(25);

    try {
        k.hozzaadKonyv(a);
        k.hozzaadKonyv(b);
        k.hozzaadKonyv(c);

        // cout << k;
        cout << k.legrovidebbKonyv();

        if (a < b) cout << "eper";

        cout << a << endl;
        a += 15;
        a += -20;
        cout << a << endl;

    } catch (const char* ch) {
        cerr << ch << endl;
    }

    return 0;
}

/*
 *  Mathe Ruben-Jonathan
 *  mrim2553
 *  512/1
 *
 */

#include <iostream>

using namespace std;

class Allat {
protected:
    char* nev;

public:
    explicit Allat(const char* s) {
        nev = new char[strlen(s) + 1];
        strncpy(nev,s,strlen(s) + 1);
    }

    void kiirnev() const {
        cout << nev << endl;
    }

    virtual ~Allat() {
        delete nev;
    }

    virtual void kiadhangot() = 0;
};

class Kutya:public Allat {
protected:
    bool hazorzo;

public:
    Kutya(const char* n, const bool h):Allat(n) {
        hazorzo = h;
    }

    void kiadhangot() override {
        cout << "wuf wuf" << endl;
    }
};

class Macska:public Allat {
protected:
    bool benti;

public:
    Macska(const char* n, const bool b):Allat(n) {
        benti = b;
    }

    void kiadhangot() override {
        cout << "miao miao" << endl;
    }
};

/////////////////////////////////

class Jarmu {
protected:
    string marka;

public:
    Jarmu(const string& m) {
        marka = m;
    }

    virtual void kiir() const {
        cout << marka << endl;
    }

    // virtual ~Jarmu() = 0;
};

class ElektromosJormu:public virtual Jarmu{
protected:
    double akkuKapacitas;

public:
    ElektromosJormu(const string &marka, const double akku):Jarmu(marka) {
        akkuKapacitas = akku;
    }

    void kiir() const override {
        Jarmu::kiir();
        cout << akkuKapacitas << endl;
    }
};

class Auto:public virtual Jarmu {
protected:
    int ajtokSzama;

public:
    Auto(const string &marka, const int ajtok):Jarmu(marka) {
        ajtokSzama = ajtok;
    }

    void kiir() const override {
        Jarmu::kiir();
        cout << ajtokSzama << endl;
    }
};

class ElektromosAuto:public ElektromosJormu, Auto {
protected:
    int toltesSebesseg;

public:
    ElektromosAuto(const string &marka, const int ajtokSzama, const double akku, const int toltes):Jarmu(marka),ElektromosJormu(marka,akku),Auto(marka,ajtokSzama){
        toltesSebesseg = toltes;
    }

    void kiir() const override {
        cout << marka << ' ' << ajtokSzama << ' ' << akkuKapacitas << ' ' << toltesSebesseg << endl;
    }
};

int main() {
    // Kutya k("eper",false);
    // Macska m("alma",true);
    //
    // k.kiadhangot();
    // m.kiadhangot();
    //
    // Allat* allatkert[]{new Kutya("korte",false), new Macska("Garfiel",true), new Kutya("Rex",true)};
    //
    // for (auto& allat:allatkert) {
    //     allat->kiirnev();
    //     allat->kiadhangot();
    //
    //     cout << endl;
    // }

    ElektromosAuto e("nev",4,4000,200);

    e.kiir();

    return 0;
}

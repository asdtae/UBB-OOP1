#include <iostream>

using namespace std;

class Ember {
    string nev;

public:
    Ember() {
        nev = "";
    }

    Ember(const string& s) {
        nev = s;
    }

    friend ostream& operator<<(ostream &os, const Ember &e) {
        os << e.nev;
        return os;
    }

    void Kiir() const {
        cout << nev << endl;
    }
};

class Hazaspar {
    Ember ferj;
    Ember feleseg;

public:
    Hazaspar() = default;

    Hazaspar(const string& ferjNev, const string& felesegNev) : ferj(ferjNev), feleseg(felesegNev){};

    void Kiir() const {
        cout << ferj << endl << feleseg;
    }
};

int main() {
    const Ember p("pistike");
    p.Kiir();

    const Hazaspar h("Jancsi Valaki", "Eszti Valaki");
    Hazaspar h2;
    h.Kiir();

    return 0;
}

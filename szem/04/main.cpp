#include <iostream>

using namespace std;

class Tomeg {
private:
    int mass = 0;

public:
    Tomeg() {
        mass = 0;
    }

    Tomeg(int g, const int mg) {
        if (g < 0 || mg < 0) {
            throw ("Mass cannot be negative.\n");
        }

        mass = g * 1000;
        mass += mg;
    }

    Tomeg(const int i) {
        Tomeg t(0,i); // ez nem megy
    }

    ~Tomeg() {
        mass = 0;
    }

    explicit operator int() const {
        return mass;
    }

    Tomeg operator+(const Tomeg &t) const
    {
        const int sumMass = mass + t.mass;
        Tomeg sumT(0,sumMass);
        return sumT;
    }

    Tomeg& operator++() {
        mass++;
        return *this;
    }

    Tomeg& operator++(const int i) {
        mass += i;
        return *this;
    }

    Tomeg& operator+=(const Tomeg &t) {
        return *this = *this + t;
    }

    Tomeg operator-(const Tomeg &t) const
    {
        const int diffMass = mass - t.mass;
        Tomeg diffT(0,diffMass);
        return diffT;
    }

    void Print() const {
        int g = 0, mg = 0;

        g = mass / 1000;
        mg = mass % (1000 * g);

        cout << "mass: " << g << ',' << mg << 'g' << '\n';
    }
};

int main()
{
    try {
     Tomeg t1(1,191),t2(3,245);
        cout << "Original: " << endl;
        t1.Print();
        t2.Print();
        cout << endl;

        cout << "+=: " << endl;
        (t1+=t1).Print();
        cout << endl;

        cout << "+: " << endl;
        (t1+t2).Print();
        cout << endl;

        cout << "++: " << endl;
        (++t1).Print();
        (t1++).Print();
        cout << endl;

        cout << "-: " << endl;
        (t2-t1).Print();
        cout << endl;

        cout << "tomeg + int: " << endl;
        (t1+4100).Print();
        cout << endl;

        cout << "expicitemite: " << endl;
        cout << static_cast<int>(t1) << 'g';
        cout << endl;

    } catch (const char* err) {
        cerr << err;
    }

    return 0;
}

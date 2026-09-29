/*
    Mathe Ruben-Jonathan
    mrim2553
    512/1

*/
#include <iostream>
#include <vector>

class Rational_numbers {
private:
    long int numerator;     //  p
    long int denominator;   //  q

    static std::vector<long> primeGen(const long int n) {
        std::vector<long int> primes(n+1, 0);
        std::vector<long int> primesS;
        int k = 3;

        if (n >= 2) primes[0] = 2;
        if (n >= 3) primes[1] = 3;
        if (n >= 5) primes[2] = 5;

        for (long int i = 7; i<n; i++) {
            if ((i+1)%6==0 || (i-1)%6==0) {
                bool isPrime = true;
                int j = 0;

                while (j<i && primes[j] != 0) {
                    if (i%primes[j] == 0) {
                        isPrime = false;
                        break;
                    }

                    j++;
                }

                if (isPrime) {
                    primes[k] = i;
                    k++;
                }

                std::cout << std::endl;
            }
        }

        for (long prime : primes) {
            if (prime != 0) primesS.push_back(prime);
        }

        return primesS;
    }

    void Simplify() {
        std::vector<long> primes;

        if (numerator < denominator) primes = primeGen(numerator);
        else primes = primeGen(denominator);

        for (const long prime : primes) {
            if (numerator%prime==0 && denominator%prime==0) {
                numerator /= prime;
                denominator /= prime;
            }
        }
    }

    static void Simplify(Rational_numbers r) {
        std::vector<long> primes;

        if (r.numerator < r.denominator) primes = primeGen(r.numerator);
        else primes = primeGen(r.denominator);

        for (const long prime : primes) {
            if (r.numerator%prime==0 && r.denominator%prime==0) {
                r.numerator /= prime;
                r.denominator /= prime;
            }
        }
    }

public:
    Rational_numbers() {
        numerator = 0;
        denominator = 1;
    }

    Rational_numbers(long int p, long int q) {
        if (q == 0) {
            throw "Denominator cannot be 0.";
        }

        numerator = p;
        denominator = q;

        if (numerator < 0 && denominator < 0) {
            numerator *= -1;
            denominator *= -1;
        }

        Simplify();
    }

    Rational_numbers operator+(const Rational_numbers r2) const {
        Rational_numbers result;

        result.numerator = numerator + r2.numerator;
        result.denominator = denominator + r2.denominator;

        return result;
    }

    void operator+=(Rational_numbers r2) {
        numerator += r2.numerator;
        denominator += r2.denominator;
    }

    Rational_numbers operator*(const Rational_numbers r2) const {
        Rational_numbers result;

        result.numerator = numerator * r2.numerator;
        result.denominator = denominator * r2.denominator;

        Simplify(result);

        return result;
    }

    void operator*=(const Rational_numbers r2) {
        numerator = numerator * r2.numerator;
        denominator = denominator * r2.denominator;

        Simplify();
    }

    void Print() const {
        std::cout << numerator << '/' << denominator << std::endl;
    }
};

class Time {
private:
    int hour = 0;
    int minutes = 0;
    int seconds = 0;

    static bool CheckContains(const int h, const int m, const int s) {
        if (h<0 || m<0 || s<0) {
            return false;
        }

        return true;
    }

public:
    Time() = default;

    Time(int h, int m, int s) {
        if (CheckContains(h,m,s)) {
            if (s>=60) {
                m += s / 60;
                s %= 60;
            }

            if (m>=60) {
                h += m / 60;
                m %= 60;
            }

            hour = h;
            minutes = m;
            seconds = s;
        }
        else {
            throw "Time cannot be negative.";
        }
    }

    Time operator++() const {
        Time newTime;

        newTime.hour = hour;
        newTime.minutes = minutes;
        newTime.seconds = seconds + 1;

        return newTime;
    }

    Time operator++(const int t) const {
        Time newTime;

        newTime.hour = hour;
        newTime.minutes = minutes;
        newTime.seconds = seconds + 1;

        return newTime;
    }

    void Print() const {
        if (hour == 0 ) std::cout << "00";
        else std::cout << hour;

        std::cout << ':';

        if (minutes == 0 ) std::cout << "00";
        else std::cout << minutes;

        std::cout << ':';

        if (seconds == 0 ) std::cout << "00";
        else std::cout << seconds;

        std::cout << std::endl;
    }

};

int main()
{
    try {
        Rational_numbers r1, r2(2,6);
        Time t1, t2(22,33,78);

        // r1.Print();
        // r2.Print();

        t1.Print();
        t2.Print();

        (t2++).Print();
        (++t2).Print();

    } catch (const char* err) {
        std::cerr << err << std::endl;
    }

    return 0;
}

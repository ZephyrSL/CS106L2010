#include <iostream>

using namespace std;

class RationalNumber
{
    public:
        RationalNumber(int num = 0, int denom = 1) :
            numerator(num), denominator(denom) {}
        
        double getValue() const {
            return double(numerator) / denominator;
        }

        void setNumerator(int value) {
            numerator = value;
        }

        void setDenominator(int value) {
            denominator = value;
        }

        bool operator < (const RationalNumber& other) const {
            return this->getValue() < other.getValue();
        }

        bool operator > (const RationalNumber& other) const {
            return other.getValue() < this->getValue();
        }

        bool operator == (const RationalNumber& other) const {
            return ( !( (*this) < other ) && !( other < (*this) ));
        }

        bool operator >= (const RationalNumber& other) const {
            return !((*this) < other);
        }

        bool operator <= (const RationalNumber& other) const {
            return !( other < (*this));
        }

        bool operator != (const RationalNumber& other) const {
            return ( (*this) < other || other < (*this) );    
        }


    private:
        int numerator, denominator;
};

class RealNumber
{
    public:
        RealNumber(double real=0.0) : 
            realnumber(real) {}

        RealNumber(const RationalNumber& instance) {
            realnumber=instance.getValue();
        }
        
        double getValue() const {
            return realnumber;
        }

        void setRealNumber(double value) {
            realnumber=value;
        }

    private:
        double realnumber;
};

int main(void) 
{
    RationalNumber piApprox_ration(355, 113);
    RationalNumber piInt(3);
    RealNumber piApprox_real(piApprox_ration);
    cout << piApprox_ration.getValue() << endl;
    cout << piApprox_real.getValue() << endl;
    cout << "The operation output" << endl;
    cout << (piApprox_ration < piInt) << " " << (piApprox_ration <= piInt) << " "
         << (piApprox_ration == piInt) << " " << (piApprox_ration != piInt) << " "
         << (piApprox_ration >= piInt) << " " << (piApprox_ration > piInt) << endl;
    
    return 0;
}

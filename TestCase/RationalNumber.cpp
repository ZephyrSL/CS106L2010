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
    RealNumber piApprox_real(piApprox_ration);
    cout << piApprox_ration.getValue() << endl;
    cout << piApprox_real.getValue() << endl;
    
    return 0;
}

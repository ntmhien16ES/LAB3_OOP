#include <iostream>
#include <string>
#include <cmath>
using namespace std;
class complex
{
private :
    float real, image;
public:
    complex()
    {
        this->real = this->image = 0;
    }
    //complex()
    complex(const complex& that)
    {
        this->real = that.real;
        this->image = that.image;
    }
    complex operator=(const complex&);
    complex operator+(const complex&);
    complex operator-(const complex&);
    bool operator==(const complex&);
    complex operator*(const complex&);
    void display(void);
    friend ostream &operator<<(ostream&, const complex &);
    friend istream &operator>>(istream&, complex &);
};
#include <iostream>
#include "complex.h"
using namespace std;

int main()
{
    complex a;
    cin>>a;
    cout<<a;
    return 0;
}
complex complex::operator=(const complex& that)
{
    this->real = that.real;
    this->image = that.image;
}
complex complex::operator+(const complex& that)
{
    complex tmpComplex;
    tmpComplex.real = this->real+ that.real;
    tmpComplex.image = this->real + that.real;
    return tmpComplex;
}
complex complex::operator-(const complex& that)
{
    complex tmp;
    tmp.real = this->real - that.real;
    tmp.real = this->image - that.image;
    return tmp;
}
bool complex::operator==(const complex& that)
{
    return (this->real == that.real) && (this->image == that.image);
}
complex complex::operator*(const complex& that)
{
    complex tmp;
    tmp.real = (this->real)*(that.real) - (this->image)*(that.image);
    tmp.image = (this->real)*(that.image) + (this->image)*(that.real);
    return tmp;
}
void complex::display(void)
{

}
ostream &operator<<(ostream& out, const complex &that)
{
    out<<that.real<<" + j"<<that.image;
    return out;
}
istream &operator>>(istream& in, complex & that)
{
    string tmp ;
    cin>>tmp;
    float realPart, imagePart;
    int plusPos = tmp.find_first_of('+');
    realPart = tmp[0] - '0';
    int ireal;
    for(ireal = 1; (ireal < plusPos) && (tmp[ireal] != '.') ; ireal++)
    {
        realPart = realPart*10 + (tmp[ireal] - '0');
    }
    for(int j = ireal+1; j < plusPos ; j++)
    {
        static int count = 1;
        realPart = realPart + ((tmp[j] - '0')/pow(10,count++));
    }
    that.real = realPart;
    imagePart = tmp[plusPos+2] - '0';
    int iimage;
    for(iimage = plusPos + 3 ; iimage < tmp.size() && (tmp[iimage] != '.'); iimage ++)
    {
        imagePart = imagePart*10 + (tmp[iimage] - '0');
    }
    for(int j = iimage +1 ; j < tmp.size(); j++)
    {
        static int count = 1;
        imagePart = imagePart + ((tmp[j] - '0')/pow(10,count++));
    }
    that.image = imagePart;
    return in;
}

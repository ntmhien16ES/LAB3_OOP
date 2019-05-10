#include <iostream>
#include <conio.h>
using namespace std;
class Real
{
private:
	float value;
public:
	Real(float v = 0)
	{
		value = v;
	}
	Real operator+(const Real& that)
	{
		Real tmp;
		tmp.value = this->value + that.value;
		return tmp;
	}
	void display()
	{
		cout << value;
	}
};
main()
{
	Real A(6.5);
	Real B(3.5);
	Real C = A + B;
	C.display();
	return 0;
}

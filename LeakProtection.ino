#include "View.h"

//#include <Vector.h>

//class C
//{
//public:
//	C(const int& size) :
//		mVector(size)
//	{}
//	Vector<int> mVector;
//
//private:
//};

void setup() 
{
	Serial.begin(115200);
	//Element e = Element();
	//e.push_back('a');
	//Serial.println(e.View());

	//C c(0);
	//c.mVector.push_back('a');
	//Serial.println(c.mVector.size());
}

void loop() 
{
	View::Instanse().Loop();
}

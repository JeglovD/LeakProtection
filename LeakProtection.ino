#include "Leak.h"
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

//ViewElementIcon view_element_icon;

void setup() 
{
	Serial.begin(115200);
	//Element e = Element();
	//e.push_back('a');
	//Serial.println(e.View());

	//C c(0);
	//c.mVector.push_back('a');
	//Serial.println(c.mVector.size());

	//view_element_icon.Push_back(char(34));
	//view_element_icon.Push_back(char(35));
	//View::Instanse().ViewElementSet(&view_element_icon);
}

void loop() 
{
	Leak::Instanse().Loop();
	View::Instanse().Loop();
}

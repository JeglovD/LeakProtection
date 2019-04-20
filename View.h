#pragma once

#include <Vector.h>

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

class Element
{
public:
	Element();
	String View() const;

//private:
//	Vector<char> mVector = Vector<char>(0);
};

class Elements:public Vector<Element>
{
public:
	Elements() {}
	String View() const
	{
		String result("");
		for (int i = 0; i < size(); ++i)
			result += (*this)[i].View();
		return result;
	}
};

//class Display
//{
//public:
//	~Display();
//	static Display& Instanse();
//	void Loop();
//
//private:
//	Display();
//	Display(const Display&);
//	Display& operator=(Display&);
//
//	Adafruit_SSD1306 mDisplay;
//	static const int DISPLAY_ARRAY_SIZE = 5;
//	Elements* mArray[DISPLAY_ARRAY_SIZE] = {};
//};


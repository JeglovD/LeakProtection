#pragma once

#include <Vector.h>

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

//class Element
//{
//public:
//	Element();
//	String View() const;
//
////private:
////	Vector<char> mVector = Vector<char>(0);
//};
//
//class Elements:public Vector<Element>
//{
//public:
//	Elements() {}
//	String View() const
//	{
//		String result("");
//		for (int i = 0; i < size(); ++i)
//			result += (*this)[i].View();
//		return result;
//	}
//};

class Mode
{
public:
	virtual void Loop() = 0;

protected:
	Mode() {};
	Mode(const Mode&);
	Mode& operator=(Mode&);
};

class ModeSafe :public Mode
{
public:
	void Loop() override;
	static Mode& Instanse() { static ModeSafe mode_safe; return mode_safe; }

private:
	ModeSafe();
	ModeSafe(const ModeSafe&);
	ModeSafe& operator=(ModeSafe&);

	double mX, mY, mDX, mDY;
};

class View
{
public:
	~View() {};
	static View& Instanse() { static View view; return view; };
	void Loop() { Mode().Loop(); };

private:
	View();
	View(const View&);
	View& operator=(View&);

	Mode& Mode() { return ModeSafe::Instanse(); }

	Adafruit_SSD1306 mDisplay;
	//static const int DISPLAY_ARRAY_SIZE = 5;
	//Elements* mArray[DISPLAY_ARRAY_SIZE] = {};

	friend ModeSafe;
};


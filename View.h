#pragma once

#include <Vector.h>

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

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

class ViewElement :public Vector<String>
{
public:
	ViewElement();
	String View() const;
};

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

class View :public Vector<ViewElement>
{
public:
	~View();
	static View& Instanse() { static View view; return view; };
	void Loop() { Mode().Loop(); };
	//void Clear();
	//View& operator<<(const ViewElement& view_element);

private:
	View();
	View(const View&);
	View& operator=(View&);
	Mode& Mode() { return ModeSafe::Instanse(); }

	Adafruit_SSD1306 mDisplay;
	//Vector<Vector<int>>* mPViewElements;

	friend ModeSafe;
};


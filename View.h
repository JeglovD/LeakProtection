#pragma once

#include <Vector.h>

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

class ViewElement
{
public:
	ViewElement();
	String View() const;

protected:
	String mElementsArray[2];
	Vector<String> mElements;
};

class ViewElementIcon :public ViewElement
{
public:
	ViewElementIcon() {};
	void Push_back(const char& c);
	void Clear();
};

class ViewElementTimer :public ViewElement
{
public:
	ViewElementTimer();
	void Loop();

private:
	byte mSecond, mMinute, mHour, mDay, mMonth;
	unsigned long mMillis;
};

class ViewMode
{
public:
	virtual void Loop() = 0;

protected:
	ViewMode() {};
	ViewMode(const ViewMode&);
	ViewMode& operator=(ViewMode&);
};

class ViewModeSafe :public ViewMode
{
public:
	void Loop() override;
	static ViewMode& Instanse() { static ViewModeSafe view_mode_safe; return view_mode_safe; }

private:
	ViewModeSafe();
	ViewModeSafe(const ViewModeSafe&);
	ViewModeSafe& operator=(ViewModeSafe&);

	double mX, mY, mDX, mDY;
};

class ViewModeNormal :public ViewMode
{
public:
	void Loop() override;
	static ViewMode& Instanse() { static ViewModeNormal view_mode_normal; return view_mode_normal; }

private:
	ViewModeNormal() {};
	ViewModeNormal(const ViewModeNormal&);
	ViewModeNormal& operator=(ViewModeNormal&);
};

class View
{
public:
	~View() {};
	static View& Instanse() { static View view; return view; };
	void ViewElementSet(const ViewElement* p_view_element);
	void ViewElementClear();
	const ViewElement* ViewElementGet() const;
	void Loop() { ViewMode().Loop(); };

private:
	// ---------------------------------------------
	// methods
	// ---------------------------------------------
	View();
	View(const View&);
	View& operator=(View&);
	ViewMode& ViewMode();

	// ---------------------------------------------
	// variables
	// ---------------------------------------------
	Adafruit_SSD1306 mDisplay;
	ViewElement* mPViewElement;

	// ---------------------------------------------
	// friends
	// ---------------------------------------------
	friend ViewModeNormal;
	friend ViewModeSafe;
};


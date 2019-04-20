#include "View.h"
#include <Wire.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels
// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)

//Element::Element()
//{}
//
//String Element::View() const
//{
//	//return size() ? String((*this)[0]) : "";
//	//return String(size());
//	return "";
//}

//Display& Display::Instanse()
//{
//	static Display display = Display();
//	return display;
//}

ModeSafe::ModeSafe():
	mX(0),
	mY(0),
	mDX(1.01),
	mDY(1)
{
}

void ModeSafe::Loop()
{
	View::Instanse().mDisplay.clearDisplay();
	View::Instanse().mDisplay.drawPixel(mX, mY, WHITE);
	View::Instanse().mDisplay.display();
	int x_test(mX + mDX);
	if (x_test<0 || x_test>View::Instanse().mDisplay.width())
		mDX = -mDX;
	int y_test(mY + mDY);
	if (y_test<0 || y_test>View::Instanse().mDisplay.height())
		mDY = -mDY;
	mX += mDX;
	mY += mDY;
}

View::View():
	mDisplay(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET)
	//,
	//mPViewElements(new Vector<ViewElement>)
{
	// SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
	// Address 0x3C for 128x32
	while (!mDisplay.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {};
}

View::~View()
{
	//delete mPViewElements;
}

//void View::Clear()
//{
//	delete mPViewElements;
//	mPViewElements = new Vector<ViewElement>;
//}

//View& View::operator<<(const ViewElement& view_element)
//{
//	mPViewElements->push_back();
//	return *this;
//}
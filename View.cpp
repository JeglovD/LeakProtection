#include "View.h"
#include "Fonts/FontLeakProtection.h"
#include <Wire.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels
// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)

ViewElement::ViewElement()
{
	mElements.setStorage(mElementsArray);
}

String ViewElement::View() const
{
	if (!mElements.size())
		return "";
	return mElements[(millis() / 500) % mElements.size()];
}

void ViewElementIcon::Push_back(const char& c)
{
	mElements.push_back(String(c));
}

void ViewElementIcon::Clear()
{
	mElements.clear();
}

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

ViewModeSafe::ViewModeSafe():
	mX(0),
	mY(0),
	mDX(1.01),
	mDY(1)
{}

void ViewModeSafe::Loop()
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

void ViewModeNormal::Loop()
{
	View::Instanse().mDisplay.clearDisplay();
	if (View::Instanse().mPViewElement)
	{
		View::Instanse().mDisplay.setFont(&Roboto_Thin_36);
		View::Instanse().mDisplay.setTextColor(WHITE);
		View::Instanse().mDisplay.setTextSize(1);
		View::Instanse().mDisplay.setCursor(0, 32);
		View::Instanse().mDisplay.print(View::Instanse().mPViewElement->View());
	}
	View::Instanse().mDisplay.display();
}

View::View() :
	mDisplay(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET),
	mPViewElement(nullptr)
{
	// SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
	// Address 0x3C for 128x32
	while (!mDisplay.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {};
}

void View::ViewElementSet(const ViewElement* p_view_element)
{
	mPViewElement = p_view_element;
}

void View::ViewElementClear()
{
	mPViewElement = nullptr;
}

ViewMode& View::ViewMode()
{ 
	//return ViewModeNormal::Instanse();
	return ViewModeSafe::Instanse();
}

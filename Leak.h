#pragma once

#include "View.h"

class Leak
{
public:
	static Leak& Instanse() { static Leak leak; return leak; }
	void Loop();

private:
	// --------------------------------------------------
	// methods
	// --------------------------------------------------
	Leak();
	Leak(const Leak&);
	Leak& operator=(Leak&);

	// --------------------------------------------------
	// variables
	// --------------------------------------------------
	ViewElementIcon mViewElementIcon;
	ViewElementTimer mViewElementTimer;
};

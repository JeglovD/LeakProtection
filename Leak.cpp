#include "Leak.h"

Leak::Leak()
{
	mViewElementIcon.Push_back(char(61));
}

void Leak::Loop()
{
	//if (View::Instanse().ViewElementGet() != &mViewElementIcon)
	//	View::Instanse().ViewElementSet(&mViewElementIcon);
	if (View::Instanse().ViewElementGet() != &mViewElementTimer)
		View::Instanse().ViewElementSet(&mViewElementTimer);

	mViewElementTimer.Loop();
}
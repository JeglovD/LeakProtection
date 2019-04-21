#include "Leak.h"

Leak::Leak()
{
	mViewElementIcon.Push_back(char(65));
}

void Leak::Loop()
{
	if (View::Instanse().ViewElementGet() != &mViewElementIcon)
	{
		View::Instanse().ViewElementSet(&mViewElementIcon);
		mViewElementIcon.ViewElementNextSet(&mViewElementTimer);
	}
	mViewElementTimer.Loop();
}
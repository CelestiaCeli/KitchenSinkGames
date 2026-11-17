#pragma once
#ifndef __VISUAL_OBJECT__
#define __VISUAL_OBJECT__

#include "object.h"
#include "window.h"

class VisualObject : public Object
{
	protected:
		Window* focusedWindow;
	public:
		VisualObject(Window* _focusedWindow)
		{
			focusedWindow = _focusedWindow;
		}
};

#endif

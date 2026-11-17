#pragma once
#ifndef __BACKGROUND_H__
#define __BACKGROUND_H__


#include "ext/glfw-src/deps/glad/gl.h"
#include "ext/glfw-src/include/GLFW/glfw3.h"

#include "visualobject.h"
#include "Vector3.h"
#include "window.h"

class Background : public VisualObject
{
	protected:
    bool button_pressed = false;
    const float colorModifier = 1.0;
    float previousColor;
		const float CHANGE_AMT = 0.1;
		struct Vector3 currColor = { 0, 0, 0 };
	public:
		bool IInit() override;
		bool IUpdate() override;
		bool IRender() override;
		using VisualObject::VisualObject;
};
#endif

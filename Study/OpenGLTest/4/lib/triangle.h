#pragma once
#ifndef __SHAPE_H__
#define __SHAPE_H__

#include "ext/glfw-src/deps/glad/gl.h"
#include "ext/glfw-src/include/GLFW/glfw3.h"
#include "shader.h"
#include "object.h"
#include "Vector3.h"
#include <list>

class Shape : public Object
{
	private:
		std::list<Vector3> cords;
		int GetArraySize();
		void SetVertex(std::list<Vector3> _cords);
	public:
		Shader shader;
		bool IRender() override;
		bool IUpdate() override;
		bool IInit() override;
		Shape(std::list<Vector3> _cords) {}
		~Shape();
};

#endif

#include "../lib/triangle.h"

void Shape::SetVertex(std::list<Vector3> _cords)
{
	cords = _cords;
}

bool Shape::IInit()
{
  shader.CompileShader();
	return true;
}

bool Shape::IRender()
{
	return true;
}

bool Shape::IUpdate()
{
	return true;
}

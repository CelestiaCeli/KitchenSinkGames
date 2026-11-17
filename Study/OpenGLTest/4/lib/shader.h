#pragma once
#ifndef SHADER_H
#define SHADER_H

#include "ext/glfw-src/deps/glad/gl.h"
#include "log.h"
#include "filereader.h"
#include "object.h"
#include "Vector3.h"

#include <string>
#include <fstream>
#include <sstream>
#include <list>
#include <iostream>

class Shader : public Object
{
	private:
		unsigned int vertex;
		unsigned int fragment;
		unsigned int geometry;
		unsigned int tesselation;

		unsigned int VBO;
		unsigned int VAO;
		unsigned int EBO;

		int success;
		char infoLog[512];

		std::list<Vector3> data;

		void CompileVertex(const char* _vShaderCode);
		void CompileFragment(const char* _fShaderCode);
		void CompileGeometry(const char* _gShaderCode);
		void CompileTesselator(const char* _tShaderCode);
		void RenderConstructor();

		FileReader fileReader;
	public:
		unsigned int ID;

		void CompileShader(const char* vShaderCode, const char* fShaderCode, const char* gShaderCode, const char* tShaderCode);
		void CompileShader(const char* vShaderCode, const char* fShaderCode, const char* gShaderCode);
		void CompileShader(const char* vShaderCode, const char* fShaderCode);
		void CompileShader();


		std::string vertexPath;
		std::string fragmentPath;
		std::string geometryPath;
		std::string tesselatorPath;

		bool Recompile() { return true; }
		Shader() {}
		Shader(const char* _vertexPath, const char* _fragmentPath)
		{
			vertexPath = _vertexPath;
			fragmentPath = _fragmentPath;
		}

		void SetBool(const std::string &name, bool value) const;
		void SetInt(const std::string &name, int value) const;
		void SetFloat(const std::string &name, float value) const;
};

#endif

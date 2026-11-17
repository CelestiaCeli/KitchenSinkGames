#include "../lib/shader.h"

void Shader::CompileFragment(const char* _fShaderCode)
{
  std::string fShaderCode = fileReader.ReadFile(_fShaderCode);
	fragment = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragment, 1, &fShaderCode.c_str(), NULL);
	glCompileShader(fragment);

	glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		Logger::GetInstance().Log(LogType::WARNING, LogContent::SHADER_FRAGMENT);
	}
}

void Shader::CompileShader(const char* vShaderCode, const char* fShaderCode, const char* gShaderCode, const char* tShaderCode)
{
	CompileVertex(vShaderCode);
	CompileFragment(fShaderCode);
	CompileGeometry(gShaderCode);
	CompileTesselator(tShaderCode);
}

void Shader::CompileShader(const char* vShaderCode, const char* fShaderCode)
{
	CompileVertex(vShaderCode);
	CompileFragment(fShaderCode);
}

void Shader::CompileShader(const char* vShaderCode, const char* fShaderCode, const char* gShaderCode)
{
	CompileVertex(vShaderCode);
	CompileFragment(fShaderCode);
	CompileGeometry(gShaderCode);
}

void Shader::CompileShader()
{
  std::printf("%s\n", vertexPath.c_str());
	if (fileReader.ValidFile(vertexPath.c_str()) && fileReader.ValidFile(fragmentPath.c_str()))
	{
		if (fileReader.ValidFile(geometryPath.c_str()))
		{
			if (fileReader.ValidFile(tesselatorPath.c_str()))
			{
        CompileShader(vertexPath.c_str(), fragmentPath.c_str(), geometryPath.c_str(), tesselatorPath.c_str());
				return;
			}
      CompileShader(vertexPath.c_str(), fragmentPath.c_str(), geometryPath.c_str());
			return;
		}
    CompileShader(vertexPath.c_str(), fragmentPath.c_str());
		return;
	}
	Logger::GetInstance().Log(LogType::WARNING, LogContent::SHADER_VERTEX);
	return;
}

void Shader::CompileVertex(const char* vShaderCode)
{
	vertex = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertex, 1, &vShaderCode, NULL);
	glCompileShader(vertex);

	glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		Logger::GetInstance().Log(LogType::WARNING, LogContent::SHADER_VERTEX);
	}
}

void Shader::CompileGeometry(const char* gShaderCode)
{
	geometry = 0;
}

void Shader::CompileTesselator(const char* tShaderCode)
{
	tesselation = 0;
}

void Shader::SetBool(const std::string &name, bool value) const
{
	glUniform1i(glGetUniformLocation(ID, name.c_str()), (int)value);
}

void Shader::SetFloat(const std::string &name, float value) const
{
	glUniform1i(glGetUniformLocation(ID, name.c_str()), value);
}

void Shader::SetInt(const std::string &name, int value) const
{
glUniform1f(glGetUniformLocation(ID, name.c_str()), value);
}

void Shader::RenderConstructor()
{
	GLuint shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertex);
	glAttachShader(shaderProgram, fragment);
	glLinkProgram(shaderProgram);

	int success;
	char infoLog[512];

	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::LINKING_FAILED\n" << infoLog << std::endl;
	}

  glUseProgram(shaderProgram);

	glDeleteShader(vertex);
	glDeleteShader(fragment);

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);
	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);


	for(int currIndex = 0; currIndex < data.size(); currIndex++)
	{
		//glVertexAttribPointer(i, 3, GL_FLOAT, GL_FALSE, , (void*) :sizeof(float))
	}

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	//return shaderProgram;
}


#include "../lib/Render.h"

	unsigned int indices[] = {
		0, 1, 3,
		1, 2, 3
	};

	GLfloat triangle[] =
	{
		0.5f, 0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		-0.5f, -0.5f, 0.0f,
	};

void Renderer::framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0,0,width,height);
}

bool Renderer::CreateGLFWWindow(GLFWwindow* window)
{
	//if (window == NULL)
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return false;
	}
	else 
	{
		std::cout << "Created GLFW window" << std::endl;
		return true;
	}
}

bool Renderer::CompileShaders()
{
	GLfloat vertices = InputAssembler();

	unsigned int vertexOutput = VertexShader();
	unsigned int tesselatorOutput = Tesselator();
	unsigned int geometryOutput = GeometryShader();
	unsigned int fragmentOutput = FragmentShader();
	
	/* Render Construction */
	unsigned int renderOutput = RenderConstructor(vertexOutput, tesselatorOutput, geometryOutput, fragmentOutput, vertices);
	return true;
}

InitInfo Renderer::Init(InitInfo initInfo)
{
	window = glfwCreateWindow(WINDOW_HEIGHT, WINDOW_WIDTH, "LearnOpenGL", NULL, NULL);

	if(window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		initInfo.initStatus = false;
		initInfo.errorCode = -1;
	}
	else
	{
		if (!CreateGLFWWindow(window))	{ return initInfo; }
		initInfo.window = window;

		glfwMakeContextCurrent(window);
		if (!gladLoadGL(glfwGetProcAddress)) { return initInfo; }

		std::cout << "Viewport Established" << std::endl; 
		glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

		initInfo.initStatus = true;

		if (CompileShaders())
		{
			initInfo.initStatus = true;
		}
		else
		{
			initInfo.initStatus = false;
			initInfo.errorCode = -1;
		}
	}

	return initInfo;
}

bool Renderer::Render(GLFWwindow* window)
{
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	glUseProgram(shaderProgram);
	glBindVertexArray(VAO);

	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

	glfwSwapBuffers(window);
	return true;
}

unsigned int Renderer::RenderConstructor(
		unsigned int vertexOutput, 
		unsigned int tesselatorOutput, 
		unsigned int geometryOutput, 
		unsigned int fragmentOutput,
		GLfloat vertices)
{
	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexOutput);
	glAttachShader(shaderProgram, fragmentOutput);
	glLinkProgram(shaderProgram);

	int success;
	char infoLog[512];

	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::LINKING_FAILED\n" << infoLog << std::endl;
	}

	glDeleteShader(vertexOutput);
	glDeleteShader(fragmentOutput);

	unsigned EBO;

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);
	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(triangle), triangle, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	return shaderProgram;
}

unsigned int Renderer::GeometryShader()
{
	return 0;
}

unsigned int Renderer::Tesselator()
{
	return 0;
}

GLfloat Renderer::InputAssembler()
{
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(triangle), triangle, GL_STATIC_DRAW);

	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, 3);

	return *triangle;
}

unsigned int Renderer::VertexShader()
{
	const char *vertexShaderSource = "#version 330 core\n"
		"layout (location = 0) in vec3 aPos;\n"
		"void main()\n"
		"{\n"
		"	gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
		"}\0";
	unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);

	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);


	int success;
	char infoLog[512];
	glCompileShader(vertexShader);
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);

	if (!success)
	{
		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
		return 0;
	}
	else
	{
		return vertexShader;
	}
}

unsigned int Renderer::FragmentShader()
{
	const char *fragmentShaderSource = "#version 330 core\n"
		"out vec4 FragColor;\n"
		"void main()\n"
		"{\n"
		"	FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
		"}\0";
	unsigned int fragmentShader;
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);

	int success;
	char infoLog[512];
	glCompileShader(fragmentShader);

	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
		return 0;
	}
	else
	{
		return fragmentShader;
	}

}

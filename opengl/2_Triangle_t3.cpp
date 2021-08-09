//#include <iostream>
////glew
//#define GLEW_STATIC
//#include <GL/glew.h>
////glfw
//#include <GLFW/glfw3.h>
//
//using namespace std;
//
//void key_callabck(GLFWwindow* window, int key, int scancode, int action, int mode);
//
//const GLuint WIDTH = 800, HEIGHT = 600;
//
////shader
//const GLchar* vertexShaderSource = "#version 330 core\n"
//"layout (location = 0) in vec3 position;\n"
//"void main()\n"
//"{\n"
//"    gl_Position = vec4(position, 1.0f);\n"
//"}";
//const GLchar* fragmentShader1Source = "#version 330 core\n"
//"out vec4 color;\n"
//"void main()\n"
//"{\n"
//"    color = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
//"}";
//const GLchar* fragmentShader2Source = "#version 330 core\n"
//"out vec4 color;\n"
//"void main()\n"
//"{\n"
//"    color = vec4(1.0f, 1.0f, 0.0f, 1.0f);\n"
//"}";
//
//int main()
//{
//	glfwInit();
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
//
//	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "LearnOpenGL", nullptr, nullptr);
//	glfwMakeContextCurrent(window);
//	glfwSetKeyCallback(window, key_callabck);
//
//	glewExperimental = GL_TRUE;
//	glewInit();
//
//	int width, height;
//	glfwGetFramebufferSize(window, &width, &height);
//	glViewport(0, 0, width, height);
//
//	GLint success;
//	GLchar infoLog[512];
//
//	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
//	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
//	glCompileShader(vertexShader);
//	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
//	if (!success)
//	{
//		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
//		clog << "error::shader::vertex compile failed\n" << infoLog << endl;
//	}
//	GLuint fragmentShaderOrange = glCreateShader(GL_FRAGMENT_SHADER);
//	glShaderSource(fragmentShaderOrange, 1, &fragmentShader1Source, NULL);
//	glCompileShader(fragmentShaderOrange);
//	glGetShaderiv(fragmentShaderOrange, GL_COMPILE_STATUS, &success);
//	if (!success)
//	{
//		glGetShaderInfoLog(fragmentShaderOrange, 512, NULL, infoLog);
//		clog << "error::shader::fragment compile failed\n" << infoLog << endl;
//	}
//	GLuint fragmentShaderYellow = glCreateShader(GL_FRAGMENT_SHADER);
//	glShaderSource(fragmentShaderYellow, 1, &fragmentShader2Source, NULL);
//	glCompileShader(fragmentShaderYellow);
//	glGetShaderiv(fragmentShaderYellow, GL_COMPILE_STATUS, &success);
//	if (!success)
//	{
//		glGetShaderInfoLog(fragmentShaderYellow, 512, NULL, infoLog);
//		clog << "error::shader::fragment compile failed\n" << infoLog << endl;
//	}
//	GLuint shaderProgramOrange = glCreateProgram();
//	glAttachShader(shaderProgramOrange, vertexShader);
//	glAttachShader(shaderProgramOrange, fragmentShaderOrange);
//	glLinkProgram(shaderProgramOrange);
//	glGetProgramiv(shaderProgramOrange, GL_LINK_STATUS, &success);
//	if (!success)
//	{
//		glGetProgramInfoLog(shaderProgramOrange, 512, NULL, infoLog);
//		clog << "error::shader::program orange linking failed\n" << infoLog << endl;
//	}
//	GLuint shaderProgramYellow = glCreateProgram();
//	glAttachShader(shaderProgramYellow, vertexShader);
//	glAttachShader(shaderProgramYellow, fragmentShaderYellow);
//	glLinkProgram(shaderProgramYellow);
//	glGetProgramiv(shaderProgramYellow, GL_LINK_STATUS, &success);
//	if (!success)
//	{
//		glGetProgramInfoLog(shaderProgramYellow, 512, NULL, infoLog);
//		clog << "error::shader::program yellow linking failed\n" << infoLog << endl;
//	}
//
//	GLfloat firstTriangle[] = {
//		-0.9f, -0.5f, 0.0f,
//		-0.0f, -0.5f, 0.0f,
//		-0.45f, 0.5f, 0.0f,
//	};
//	GLfloat secondTriangle[] = {
//		0.0f, -0.5f, 0.0f,
//		0.9f, -0.5f, 0.0f,
//		0.45f, 0.5f, 0.0f,
//	};
//
//	GLuint vaos[2], vbos[2];
//	glGenVertexArrays(2, vaos);
//	glGenBuffers(2, vbos);
//
//	glBindVertexArray(vaos[0]);
//	glBindBuffer(GL_ARRAY_BUFFER, vbos[0]);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(firstTriangle), firstTriangle, GL_STATIC_DRAW);
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
//	glEnableVertexAttribArray(0);
//	glBindVertexArray(0);
//
//	glBindVertexArray(vaos[1]);
//	glBindBuffer(GL_ARRAY_BUFFER, vbos[1]);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(secondTriangle), secondTriangle, GL_STATIC_DRAW);
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (GLvoid*)0);// Because the vertex data is tightly packed we can also specify 0 as the vertex attribute's stride to let OpenGL figure it out.// Because the vertex data is tightly packed we can also specify 0 as the vertex attribute's stride to let OpenGL figure it out.
//	glEnableVertexAttribArray(0);
//	glBindVertexArray(0);
//
//	while (!glfwWindowShouldClose(window))
//	{
//		glfwPollEvents();
//		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//		glClear(GL_COLOR_BUFFER_BIT);
//
//		glUseProgram(shaderProgramOrange);
//		glBindVertexArray(vaos[0]);
//		glDrawArrays(GL_TRIANGLES, 0, 3);
//		//glBindVertexArray(0);
//
//		glUseProgram(shaderProgramYellow);
//		glBindVertexArray(vaos[1]);
//		glDrawArrays(GL_TRIANGLES, 0, 3);
//
//		glBindVertexArray(0);
//
//		glfwSwapBuffers(window);
//	}
//
//	glDeleteVertexArrays(2, vaos);
//	glDeleteBuffers(2, vbos);
//
//	glfwTerminate();
//
//	return 0;
//}
//
//void key_callabck(GLFWwindow* window, int key, int scancode, int action, int mode)
//{
//	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
//		glfwSetWindowShouldClose(window, GL_TRUE);
//}
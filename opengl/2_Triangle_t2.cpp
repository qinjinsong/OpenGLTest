//#include <iostream>
//
////glew
//#define GLEW_STATIC
//#include <GL/glew.h>
//
////glfw
//#include <GLFW/glfw3.h>
//
//using namespace std;
//
//void key_callback(GLFWwindow* window, int key, int scancode, int acion, int mode);
//
//const GLuint WIDTH = 800, HEIGHT = 600;
//
//const GLchar* vertexShaderSource = "#version 330 core\n"
//"layout (location = 0) in vec3 position;\n"
//"void main()\n"
//"{\n"
//"    gl_Position = vec4(position, 1.0f);\n"
//"}";
//const GLchar* fragmentShaderSource = "#version 330 core\n"
//"out vec4 color;\n"
//"void main()\n"
//"{\n"
//"    color = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
//"}";
//
//int main(int argc, char** argv[])
//{
//	glfwInit();
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//	glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);
//
//	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "LearnOpenGL", nullptr, nullptr);
//	glfwMakeContextCurrent(window);
//
//	glfwSetKeyCallback(window, key_callback);
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
//		clog << "error::shader::vertex::compilation_failed\n" << infoLog << endl;
//	}
//	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
//	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
//	glCompileShader(fragmentShader);
//	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
//	if (!success)
//	{
//		glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
//		clog << "error::shader::fragment::compilation_failed\n" << infoLog << endl;
//	}
//	GLuint shaderProgram = glCreateProgram();
//	glAttachShader(shaderProgram, vertexShader);
//	glAttachShader(shaderProgram, fragmentShader);
//	glLinkProgram(shaderProgram);
//	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
//	if (!success)
//	{
//		glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
//		clog << "error::shader::program::linking_failed\n" << infoLog << endl;
//	}
//	glDeleteShader(vertexShader);
//	glDeleteShader(fragmentShader);
//
//	GLfloat firstTriangle[] = {
//		-0.9f, -0.5f, 0.0f,
//		0.0f, -0.5f, 0.0f,
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
//	//1th
//	glBindVertexArray(vaos[0]);
//	glBindBuffer(GL_ARRAY_BUFFER, vbos[0]);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(firstTriangle), firstTriangle, GL_STATIC_DRAW);
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
//	glEnableVertexAttribArray(0);
//	glBindVertexArray(0);
//	//2th
//	glBindVertexArray(vaos[1]);
//	glBindBuffer(GL_ARRAY_BUFFER, vbos[1]);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(secondTriangle), secondTriangle, GL_STATIC_DRAW);
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (GLvoid*)0);
//	glEnableVertexAttribArray(0);
//	glBindVertexArray(0);
//
//	while (!glfwWindowShouldClose(window))
//	{
//		glfwPollEvents();
//
//		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//		glClear(GL_COLOR_BUFFER_BIT);
//
//		glUseProgram(shaderProgram);
//		glBindVertexArray(vaos[0]);
//		glDrawArrays(GL_TRIANGLES, 0, 3);
//		glBindVertexArray(vaos[1]);
//		glDrawArrays(GL_TRIANGLES, 0, 3);
//		glBindVertexArray(0);
//
//		glfwSwapBuffers(window);
//	}
//	glDeleteVertexArrays(2, vaos);
//	glDeleteBuffers(2, vbos);
//
//	glfwTerminate();
//
//	return 0;
//}
//
//void key_callback(GLFWwindow* window, int key, int scancode, int acion, int mode)
//{
//	if (key == GLFW_KEY_ESCAPE && acion == GLFW_PRESS)
//		glfwSetWindowShouldClose(window, GL_TRUE);
//}
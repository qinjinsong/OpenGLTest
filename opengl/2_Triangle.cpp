//#include<iostream>
//
////glew
//#define GLEW_STATIC
//#include <GL/glew.h>
//
////glfw
//#include<GLFW\glfw3.h>
//
//using namespace std;
//
//void key_callabck(GLFWwindow* window, int key, int scancode, int action, int mode);
//
//const GLuint WIDTH = 800, HEIGHT = 600;
//
////"layout (location = 0) in vec3 position;\n"
//const GLchar* vertexShaderSource = "#version 330 core\n"
//"in vec3 position;\n"
//"in vec3 color;\n"
//"out vec3 srcCol;\n"
//"void main()\n"
//"{\n"
//"gl_Position = vec4(position.x, position.y, position.z, 1.0);\n"
//"srcCol = color;\n"
//"}\0";
//
//const GLchar* fragmentShaderSource = "#version 330 core\n"
//"in vec3 srcCol;\n"
//"out vec4 color;\n"
//"void main()\n"
//"{\n"
//"color = vec4(srcCol, 1.0f);\n"
//"}\0";
//
//void Log(string msg)
//{
//	cout << msg << endl;
//}
//
//int main(int argc, char** argv[])
//{
//	glfwInit();//初始化
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);//配置GLFW
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);//配置GLFW
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
//
//	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "LearnOpenGL", nullptr, nullptr);
//	if (window == nullptr)
//	{
//		Log("Failed to create GLFW window");
//		glfwTerminate();
//		return -1;
//	}
//	glfwMakeContextCurrent(window);
//
//	glfwSetKeyCallback(window, key_callabck);
//	glewExperimental = GL_TRUE;
//	glewInit();
//
//	int width, height;
//	glfwGetFramebufferSize(window, &width, &height);
//	glViewport(0, 0, width, height);
//
//	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
//	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
//	glCompileShader(vertexShader);
//
//	GLint success;
//	GLchar infoLog[512];
//	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
//	if (!success)
//	{
//		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
//		cout << "error::shader::vertex::compilation_failed\n" << infoLog << endl;
//	}
//
//	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
//	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
//	glCompileShader(fragmentShader);
//	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
//	if (!success)
//	{
//		glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
//		cout << "error::shader::fragment::compilation_failed\n" << infoLog << endl;
//	}
//
//	GLuint shaderProgram = glCreateProgram();
//	glAttachShader(shaderProgram, vertexShader);
//	glAttachShader(shaderProgram, fragmentShader);
//	glLinkProgram(shaderProgram);
//	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
//	if (!success)
//	{
//		glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
//		cout << "error::shader::program::linking_failed\n" << infoLog << endl;
//	}
//
//	glDeleteShader(vertexShader);
//	glDeleteShader(fragmentShader);
//
//	// [-1.0f, 1.0f]
//	// ==> 1
//	//GLfloat vertices[] = {
//	//    -1.0f, -1.0f, 0.0f, //left
//	//    0.5f, -0.5f, 0.0f, //right
//	//    0.0f, 0.5f, 0.0f, //top
//	//};
//
//	// ==> 2
//	//GLfloat vertices[] = {
//	//	// 第一个三角形
//	//	0.5f, 0.5f, 0.0f,   // 右上角
//	//	0.5f, -0.5f, 0.0f,  // 右下角
//	//	-0.5f, 0.5f, 0.0f,  // 左上角
//	//	// 第二个三角形
//	//	0.5f, -0.5f, 0.0f,  // 右下角
//	//	-0.5f, -0.5f, 0.0f, // 左下角
//	//	-0.5f, 0.5f, 0.0f   // 左上角
//	//};
//
//	// ==> 3
//	GLfloat vertices[] = {
//		0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f,// red
//		0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,// green
//		-0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,// red
//		-0.5f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f,//blue
//	};
//	GLuint indices[] = {
//		0, 1, 3,
//		1, 2, 3,
//	};
//
//	GLuint VBO, VAO, EBO;
//	glGenVertexArrays(1, &VAO);
//	glGenBuffers(1, &VBO);
//	glGenBuffers(1, &EBO);
//
//	glBindVertexArray(VAO);
//	glBindBuffer(GL_ARRAY_BUFFER, VBO);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW); //GL_STATIC_DRAW, GL_DYNAMIC_DRAW, GL_STREAM_DRAW 
//
//	//==> 3
//	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
//	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STREAM_DRAW);
//
//	GLint posAttrib = glGetAttribLocation(shaderProgram, "position");
//	glEnableVertexAttribArray(posAttrib);
//	glVertexAttribPointer(posAttrib, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (GLvoid*)0);
//
//	GLint colAttrib = glGetAttribLocation(shaderProgram, "color");
//	glEnableVertexAttribArray(colAttrib);
//	glVertexAttribPointer(colAttrib, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (GLvoid*)(3 * sizeof(float)));
//
//	//glVertexAttribPointer(0, 6, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
//
//	glEnableVertexAttribArray(0);
//	glEnableVertexAttribArray(1);
//
//	glBindBuffer(GL_ARRAY_BUFFER, 0);
//
//	glBindVertexArray(0);
//
//	//game loop
//	while (!glfwWindowShouldClose(window))
//	{
//		glfwPollEvents();
//
//		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//		glClear(GL_COLOR_BUFFER_BIT);
//
//		glUseProgram(shaderProgram);
//		glBindVertexArray(VAO);
//
//		//glDrawArrays(GL_POINTS, 0, 3);
//		//glDrawArrays(GL_LINE_STRIP, 0, 3);
//
//		// ==> 1
//		//glDrawArrays(GL_TRIANGLES, 0, 3);
//
//		// ==> 2
//		//glDrawArrays(GL_TRIANGLES, 0, 6);
//
//		// ==> 3
//		//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); //线框模式(Wireframe Mode)
//		//glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
//		//glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
//		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
//
//		glBindVertexArray(0);
//
//		glfwSwapBuffers(window);
//	}
//
//	glDeleteVertexArrays(1, &VAO);
//	glDeleteBuffers(1, &VBO);
//	glDeleteBuffers(1, &EBO);
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
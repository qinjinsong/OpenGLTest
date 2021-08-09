////glew
//#define GLEW_STATIC
//#include <GL/glew.h>
////glfw
//#include <GLFW/glfw3.h>
////glm mathemtics
//#include <glm/glm.hpp>
//#include <glm/gtc/matrix_transform.hpp>
//#include <glm/gtc/type_ptr.hpp>
//
//#include "Shader.h"
//
//GLuint WIDTH = 800, HEIGHT = 600;
//
//void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
//
//int main()
//{
//	glfwInit();
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
//
//	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "LearnOpengGL", nullptr, nullptr);
//	glfwMakeContextCurrent(window);
//
//	glfwSetKeyCallback(window, key_callback);
//
//	glewExperimental = GL_TRUE;
//	glewInit();
//
//	glViewport(0, 0, WIDTH, HEIGHT);
//
//	Shader shader("glsl/vInstancing.glsl", "glsl/fInstancing.glsl");
//	
//	glm::vec2 translations[100];
//	int index = 0;
//	GLfloat offset = 0.1f;
//	for (GLint y=-10; y < 10; y += 2)
//	{
//		for (GLint x = -10; x < 10; x += 2)
//		{
//			glm::vec2 translation;
//			translation.x = (GLfloat)x / 10.0f + offset;
//			translation.y = (GLfloat)y / 10.0f + offset;
//			translations[index++] = translation;
//		}
//	}
//
//	GLuint instanceVbo;
//	glGenBuffers(1, &instanceVbo);
//	glBindBuffer(GL_ARRAY_BUFFER, instanceVbo);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec2) * 100, &translations[0], GL_STATIC_DRAW);
//	glBindBuffer(GL_ARRAY_BUFFER, 0);
//
//	GLfloat quadVertices[] = {
//		// Positions   // Colors
//		-0.05f,  0.05f,  1.0f, 0.0f, 0.0f,
//		 0.05f, -0.05f,  0.0f, 1.0f, 0.0f,
//		-0.05f, -0.05f,  0.0f, 0.0f, 1.0f,
//
//		-0.05f,  0.05f,  1.0f, 0.0f, 0.0f,
//		 0.05f, -0.05f,  0.0f, 1.0f, 0.0f,
//		 0.05f,  0.05f,  0.0f, 1.0f, 1.0f
//	};
//
//	GLuint quadVao, quadVbo;
//	glGenVertexArrays(1, &quadVao);
//	glGenBuffers(1, &quadVbo);
//	glBindVertexArray(quadVao);
//	glBindBuffer(GL_ARRAY_BUFFER, quadVbo);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(quadVertices), quadVertices, GL_STATIC_DRAW);
//	glEnableVertexAttribArray(0);
//	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)0);
//	glEnableVertexAttribArray(1);
//	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)(2 * sizeof(GLfloat)));
//
//	//set instance data
//	glEnableVertexAttribArray(2);
//	glBindBuffer(GL_ARRAY_BUFFER, instanceVbo);
//	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), (GLvoid*)0);
//	glBindBuffer(GL_ARRAY_BUFFER, 0);
//	glVertexAttribDivisor(2, 1);
//	glBindVertexArray(0);
//
//	while (!glfwWindowShouldClose(window))
//	{
//		glfwPollEvents();
//		glClearColor(0.03f, 0.03f, 0.03f, 1.0f);
//		glClear(GL_COLOR_BUFFER_BIT);
//
//		shader.Use();
//		glBindVertexArray(quadVao);
//		glDrawArraysInstanced(GL_TRIANGLES, 0, 6, 100);
//		glBindVertexArray(0);
//
//		glfwSwapBuffers(window);
//	}
//
//	glDeleteBuffers(1, &instanceVbo);
//	glDeleteVertexArrays(1, &quadVao);
//	glDeleteBuffers(1, &quadVbo);
//
//	glfwTerminate();
//
//	return 0;
//}
//
//void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
//{
//	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
//		glfwSetWindowShouldClose(window, GL_TRUE);
//}
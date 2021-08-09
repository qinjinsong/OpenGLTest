//#include <iostream>
//#include <cmath>
////glew
//#define GLEW_STATIC
//#include <GL/glew.h>
////glfw
//#include <GLFW/glfw3.h>
////other libs
//#include <SOIL.h>
////glm mathematics
//#include <glm/glm.hpp>
//#include <glm/gtc/matrix_transform.hpp>
//#include <glm/gtc/type_ptr.hpp>
////other includes
//#include "Shader.h"
//#include "Camera.h"
//
//void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
//void mouse_callback(GLFWwindow* window, double xpos, double ypos);
//void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
//void do_movement();
//
//const GLuint WIDTH = 800, HEIGHT = 600;
//
//Camera camera(glm::vec3(0.0f, 0.0f, 5.0f));
//GLfloat lastX = WIDTH / 2;
//GLfloat lastY = HEIGHT / 2;
//bool keys[1024];
//glm::vec3 lightPos(1.2f, 1.0f, 2.0);
//GLfloat deltatime = 0.0f;
//GLfloat lastFrame = 0.0f;
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
//
//	glfwSetKeyCallback(window, key_callback);
//	glfwSetCursorPosCallback(window, mouse_callback);
//	glfwSetScrollCallback(window, scroll_callback);
//
//	//glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
//
//	glewExperimental = GL_TRUE;
//	glewInit();
//
//	glViewport(0, 0, WIDTH, HEIGHT);
//
//	glEnable(GL_DEPTH_TEST);
//
//	Shader lightingShader("glsl/vLighting.glsl", "glsl/fLighting.glsl");
//	Shader lampShader("glsl/vLamp.glsl", "glsl/fLamp.glsl");
//
//	GLfloat vertices[] = {
//		-0.5f, -0.5f, -0.5f,
//		 0.5f, -0.5f, -0.5f,
//		 0.5f,  0.5f, -0.5f,
//		 0.5f,  0.5f, -0.5f,
//		-0.5f,  0.5f, -0.5f,
//		-0.5f, -0.5f, -0.5f,
//
//		-0.5f, -0.5f,  0.5f,
//		 0.5f, -0.5f,  0.5f,
//		 0.5f,  0.5f,  0.5f,
//		 0.5f,  0.5f,  0.5f,
//		-0.5f,  0.5f,  0.5f,
//		-0.5f, -0.5f,  0.5f,
//
//		-0.5f,  0.5f,  0.5f,
//		-0.5f,  0.5f, -0.5f,
//		-0.5f, -0.5f, -0.5f,
//		-0.5f, -0.5f, -0.5f,
//		-0.5f, -0.5f,  0.5f,
//		-0.5f,  0.5f,  0.5f,
//
//		 0.5f,  0.5f,  0.5f,
//		 0.5f,  0.5f, -0.5f,
//		 0.5f, -0.5f, -0.5f,
//		 0.5f, -0.5f, -0.5f,
//		 0.5f, -0.5f,  0.5f,
//		 0.5f,  0.5f,  0.5f,
//
//		-0.5f, -0.5f, -0.5f,
//		 0.5f, -0.5f, -0.5f,
//		 0.5f, -0.5f,  0.5f,
//		 0.5f, -0.5f,  0.5f,
//		-0.5f, -0.5f,  0.5f,
//		-0.5f, -0.5f, -0.5f,
//
//		-0.5f,  0.5f, -0.5f,
//		 0.5f,  0.5f, -0.5f,
//		 0.5f,  0.5f,  0.5f,
//		 0.5f,  0.5f,  0.5f,
//		-0.5f,  0.5f,  0.5f,
//		-0.5f,  0.5f, -0.5f
//	};
//
//	//container
//	GLuint vbo, containerVao;
//	glGenVertexArrays(1, &containerVao);
//	glGenBuffers(1, &vbo);
//
//	glBindVertexArray(containerVao);
//	glBindBuffer(GL_ARRAY_BUFFER, vbo);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
//	glEnableVertexAttribArray(0);
//
//	glBindVertexArray(0);
//
//	//light (VBO stays the same. After all, the vertices are the same for the light object (also a 3D cube))
//	GLuint lightVao;
//	glGenVertexArrays(1, &lightVao);
//
//	glBindVertexArray(lightVao);
//	glBindBuffer(GL_ARRAY_BUFFER, vbo);
//
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
//	glEnableVertexAttribArray(0);
//
//	glBindVertexArray(0);
//
//	while (!glfwWindowShouldClose(window))
//	{
//		GLfloat curFrame = glfwGetTime();
//		deltatime = curFrame - lastFrame;
//		lastFrame = curFrame;
//
//		glfwPollEvents();
//		do_movement();
//
//		glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
//		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//		lightingShader.Use();
//
//		GLint objectColorLoc = glGetUniformLocation(lightingShader.program, "objectColor");
//		GLint lightColorLoc = glGetUniformLocation(lightingShader.program, "lightColor");
//		glUniform3f(objectColorLoc, 1.0f, 0.5f, 0.31f);
//		//glUniform3f(lightColorLoc, 1.0f, 0.5f, 1.0f);
//		glUniform3f(lightColorLoc, 1.0f, 1.0f, 1.0f);
//		//glUniform3f(lightColorLoc, 0.0f, 1.0f, 0.0f);
//		//glUniform3f(lightColorLoc, 0.33f, 0.42f, 0.18f);
//
//		glm::mat4 view;
//		view = camera.GetViewMatrix();
//		glm::mat4 projection = glm::perspective(camera.zoom, (GLfloat)WIDTH / (GLfloat)HEIGHT, 0.1f, 100.0f);
//
//		GLint modelLoc = glGetUniformLocation(lightingShader.program, "model");
//		GLint viewLoc = glGetUniformLocation(lightingShader.program, "view");
//		GLint projLoc = glGetUniformLocation(lightingShader.program, "projection");
//		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
//		glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));
//
//		glBindVertexArray(containerVao);
//		glm::mat4 model;
//		model = glm::rotate(model, glm::radians(45.0f), glm::vec3(0.0f, 1.0f, 0.0f));
//		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//		glDrawArrays(GL_TRIANGLES, 0, 36);
//		glBindVertexArray(0);
//
//
//		lampShader.Use();
//		modelLoc = glGetUniformLocation(lampShader.program, "model");
//		viewLoc = glGetUniformLocation(lampShader.program, "view");
//		projLoc = glGetUniformLocation(lampShader.program, "projection");
//		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
//		glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));
//		model = glm::mat4();
//		model = glm::translate(model, lightPos);
//		model = glm::scale(model, glm::vec3(0.2f));
//		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//
//		glBindVertexArray(lightVao);
//		glDrawArrays(GL_TRIANGLES, 0, 36);
//		glBindVertexArray(0);
//
//		glfwSwapBuffers(window);
//	}
//
//	glDeleteVertexArrays(1, &containerVao);
//	glDeleteBuffers(1, &vbo);
//	glDeleteVertexArrays(1, &lightVao);
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
//
//	if (key >= 0 && key < 1024)
//	{
//		if (action == GLFW_PRESS)
//			keys[key] = true;
//		else if (action == GLFW_RELEASE)
//			keys[key] = false;
//	}
//}
//
//void do_movement()
//{
//	if (keys[GLFW_KEY_W] || keys[GLFW_KEY_UP])
//		camera.KeyboardMove(FORWARD, deltatime);
//	if (keys[GLFW_KEY_S] || keys[GLFW_KEY_DOWN])
//		camera.KeyboardMove(BACKWARD, deltatime);
//	if (keys[GLFW_KEY_A] || keys[GLFW_KEY_LEFT])
//		camera.KeyboardMove(LEFT, deltatime);
//	if (keys[GLFW_KEY_D] || keys[GLFW_KEY_RIGHT])
//		camera.KeyboardMove(RIGHT, deltatime);
//}
//
//bool firstMouse = true;
//void mouse_callback(GLFWwindow* window, double xpos, double ypos)
//{
//	if (firstMouse)
//	{
//		lastX = xpos;
//		lastY = ypos;
//		firstMouse = false;
//	}
//
//	GLfloat xoffset = xpos - lastX;
//	GLfloat yoffset = lastY - ypos;
//	lastX = xpos;
//	lastY = ypos;
//
//	camera.MouseMove(xoffset, yoffset);
//}
//
//void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
//{
//	camera.MouseScroll(yoffset);
//}
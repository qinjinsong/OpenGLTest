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
//using namespace std;
//
//void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
//void do_movement();
//void mouse_callback(GLFWwindow* window, double xpos, double ypos);
//void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
//
//const GLuint WIDTH = 800, HEIGHT = 600;
//
//Camera camera(glm::vec3(0.0f, 0.0f, 3.0f));
//bool keys[1024];
//GLfloat deltatime = 0.0f;
//GLfloat lastFrame = 0.0f;
//GLfloat lastX = WIDTH / 2.0f;
//GLfloat lastY = HEIGHT / 2.0f;
//bool firstMouse = true;
//
//void main()
//{
//	glfwInit();
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
//
//	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "LearnOpenGL", nullptr, nullptr);
//	glfwMakeContextCurrent(window);
//	glfwSetKeyCallback(window, key_callback);
//	glfwSetCursorPosCallback(window, mouse_callback);
//	glfwSetScrollCallback(window, scroll_callback);
//
//	glewExperimental = GL_TRUE;
//	glewInit();
//
//	glViewport(0, 0, WIDTH, HEIGHT);
//
//	glEnable(GL_DEPTH_TEST);
//
//	Shader ourShader("glsl/vDefault.glsl", "glsl/fDefault.glsl");
//
//	GLfloat vertices[] = {
//		-0.5f, -0.5f, -0.5f,   1.0f,0.0f,0.0f,   0.0f, 0.0f,
//		 0.5f, -0.5f, -0.5f,   0.0f,1.0f,0.0f,   1.0f, 0.0f,
//		 0.5f,  0.5f, -0.5f,   0.0f,0.0f,1.0f,   1.0f, 1.0f,
//		 0.5f,  0.5f, -0.5f,   1.0f,1.0f,0.0f,   1.0f, 1.0f,
//		-0.5f,  0.5f, -0.5f,   0.0f,1.0f,1.0f,   0.0f, 1.0f,
//		-0.5f, -0.5f, -0.5f,   1.0f,0.0f,1.0f,   0.0f, 0.0f,
//
//		-0.5f, -0.5f,  0.5f,   1.0f,0.0f,0.0f,   0.0f, 0.0f,
//		 0.5f, -0.5f,  0.5f,   0.0f,1.0f,0.0f,   1.0f, 0.0f,
//		 0.5f,  0.5f,  0.5f,   0.0f,0.0f,1.0f,   1.0f, 1.0f,
//		 0.5f,  0.5f,  0.5f,   1.0f,1.0f,0.0f,   1.0f, 1.0f,
//		-0.5f,  0.5f,  0.5f,   0.0f,1.0f,1.0f,   0.0f, 1.0f,
//		-0.5f, -0.5f,  0.5f,   1.0f,0.0f,1.0f,   0.0f, 0.0f,
//
//		-0.5f,  0.5f,  0.5f,   1.0f,0.0f,0.0f,   1.0f, 0.0f,
//		-0.5f,  0.5f, -0.5f,   0.0f,1.0f,0.0f,   1.0f, 1.0f,
//		-0.5f, -0.5f, -0.5f,   0.0f,0.0f,1.0f,   0.0f, 1.0f,
//		-0.5f, -0.5f, -0.5f,   1.0f,1.0f,0.0f,   0.0f, 1.0f,
//		-0.5f, -0.5f,  0.5f,   0.0f,1.0f,1.0f,   0.0f, 0.0f,
//		-0.5f,  0.5f,  0.5f,   1.0f,0.0f,1.0f,   1.0f, 0.0f,
//
//		 0.5f,  0.5f,  0.5f,   1.0f,0.0f,0.0f,   1.0f, 0.0f,
//		 0.5f,  0.5f, -0.5f,   0.0f,1.0f,0.0f,   1.0f, 1.0f,
//		 0.5f, -0.5f, -0.5f,   0.0f,0.0f,1.0f,   0.0f, 1.0f,
//		 0.5f, -0.5f, -0.5f,   1.0f,1.0f,0.0f,   0.0f, 1.0f,
//		 0.5f, -0.5f,  0.5f,   0.0f,1.0f,1.0f,   0.0f, 0.0f,
//		 0.5f,  0.5f,  0.5f,   1.0f,0.0f,1.0f,   1.0f, 0.0f,
//
//		-0.5f, -0.5f, -0.5f,   1.0f,0.0f,0.0f,   0.0f, 1.0f,
//		 0.5f, -0.5f, -0.5f,   0.0f,1.0f,0.0f,   1.0f, 1.0f,
//		 0.5f, -0.5f,  0.5f,   0.0f,0.0f,1.0f,   1.0f, 0.0f,
//		 0.5f, -0.5f,  0.5f,   1.0f,1.0f,0.0f,   1.0f, 0.0f,
//		-0.5f, -0.5f,  0.5f,   0.0f,1.0f,1.0f,   0.0f, 0.0f,
//		-0.5f, -0.5f, -0.5f,   1.0f,0.0f,1.0f,   0.0f, 1.0f,
//
//		-0.5f,  0.5f, -0.5f,   1.0f,0.0f,0.0f,   0.0f, 1.0f,
//		 0.5f,  0.5f, -0.5f,   0.0f,1.0f,0.0f,   1.0f, 1.0f,
//		 0.5f,  0.5f,  0.5f,   0.0f,0.0f,1.0f,   1.0f, 0.0f,
//		 0.5f,  0.5f,  0.5f,   1.0f,1.0f,0.0f,   1.0f, 0.0f,
//		-0.5f,  0.5f,  0.5f,   0.0f,1.0f,1.0f,   0.0f, 0.0f,
//		-0.5f,  0.5f, -0.5f,   1.0f,0.0f,1.0f,   0.0f, 1.0f
//	};
//	glm::vec3 cubePositins[] = {
//		glm::vec3(0.0f, 0.0f, 0.0f),
//		glm::vec3(2.0f, 5.0f, -15.0f),
//		glm::vec3(-1.5f, -2.2f, -2.5f),
//		glm::vec3(-3.8f, -2.0f, -12.3f),
//		glm::vec3(2.4f, -0.4f, -3.5f),
//		glm::vec3(-1.7f, 3.0f, -7.5f),
//		glm::vec3(1.5f, -2.0f, -2.5f),
//		glm::vec3(1.5f, 0.2f, -1.5f),
//		glm::vec3(-1.3f, 1.0f, -1.5f),
//		glm::vec3(-2.3f, 2.0f, -3.5f),
//	};
//
//	GLuint vao, vbo;
//	glGenVertexArrays(1, &vao);
//	glGenBuffers(1, &vbo);
//
//	glBindVertexArray(vao);
//	glBindBuffer(GL_ARRAY_BUFFER, vbo);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)0);
//	glEnableVertexAttribArray(0);
//	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
//	glEnableVertexAttribArray(1);
//	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));
//	glEnableVertexAttribArray(2);
//
//	glBindVertexArray(0);//unbind vao
//
//	GLuint texture0, texture1;
//	//texture0
//	glGenTextures(1, &texture0);
//	glBindTexture(GL_TEXTURE_2D, texture0);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//	int width, height;
//	unsigned char* image = SOIL_load_image("texture/container.jpg", &width, &height, 0, SOIL_LOAD_RGB);
//	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
//	SOIL_free_image_data(image);
//	glBindTexture(GL_TEXTURE_2D, 0);
//	//texture1
//	glGenTextures(1, &texture1);
//	glBindTexture(GL_TEXTURE_2D, texture1);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//	image = SOIL_load_image("texture/awesomeface.png", &width, &height, 0, SOIL_LOAD_RGB);
//	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
//	glGenerateMipmap(GL_TEXTURE_2D);
//	SOIL_free_image_data(image);
//	glBindTexture(GL_TEXTURE_2D, 0);
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
//		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//		glActiveTexture(GL_TEXTURE0);
//		glBindTexture(GL_TEXTURE_2D, texture0);
//		glUniform1i(glGetUniformLocation(ourShader.program, "ourTexture0"), 0);
//		glActiveTexture(GL_TEXTURE1);
//		glBindTexture(GL_TEXTURE_2D, texture1);
//		glUniform1i(glGetUniformLocation(ourShader.program, "ourTexture1"), 1);
//
//		ourShader.Use();
//
//		//view transformation
//		glm::mat4 view;
//		//GLfloat radius = 10.0f;
//		//GLfloat camX = sin(glfwGetTime()) * radius;
//		//GLfloat camZ = cos(glfwGetTime()) * radius;
//		//view = glm::lookAt(glm::vec3(camX, 0, camZ), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
//		view = camera.GetViewMatrix();
//		ourShader.SetMat4("view", view);
//		//projection
//		glm::mat4 projection;
//		projection = glm::perspective(camera.zoom, (GLfloat)WIDTH / (GLfloat)HEIGHT, 0.1f, 100.0f);
//		ourShader.SetMat4("projection", projection);
//
//		glBindVertexArray(vao);
//		int len = sizeof(cubePositins) / sizeof(cubePositins[0]);
//		for (GLuint i = 0; i < len; i++)
//		{
//			glm::mat4 model;
//			model = glm::translate(model, cubePositins[i]);
//			GLfloat angle = 20.0f * i;
//			if (i % 3 == 0)
//				angle = glfwGetTime() * 75.0f;
//			model = glm::rotate(model, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));
//			ourShader.SetMat4("model", model);
//
//			glDrawArrays(GL_TRIANGLES, 0, 36);
//		}
//		glBindVertexArray(0);
//
//		glfwSwapBuffers(window);
//	}
//	glDeleteVertexArrays(1, &vao);
//	glDeleteBuffers(1, &vbo);
//
//	glfwTerminate();
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
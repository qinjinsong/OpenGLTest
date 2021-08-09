//#include <iostream>
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
//
//using namespace std;
//
//void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
//
//const GLuint WIDTH = 800, HEIGHT = 600;
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
//	glfwSetKeyCallback(window, key_callback);
//
//	glewExperimental = GL_TRUE;
//	glewInit();
//
//	glViewport(0, 0, WIDTH, HEIGHT);
//
//	//setup opengl options
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
//	glBindVertexArray(0); //unbind vao
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
//	glGenerateMipmap(GL_TEXTURE_2D);
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
//		glfwPollEvents();
//		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//		//glClear(GL_COLOR_BUFFER_BIT);
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
//		glm::mat4 model, view, projection;
//		model = glm::rotate(model, (GLfloat)glfwGetTime(), glm::vec3(0.5f, 1.0f, 0.0f));
//		view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
//		projection = glm::perspective(45.0f, (GLfloat)WIDTH / (GLfloat)HEIGHT, 0.1f, 100.0f);
//		GLint modelLoc, viewLoc, projLoc;
//		modelLoc = glGetUniformLocation(ourShader.program, "model");
//		viewLoc = glGetUniformLocation(ourShader.program, "view");
//		projLoc = glGetUniformLocation(ourShader.program, "projection");
//		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
//		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
//		glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));
//
//		glBindVertexArray(vao);
//		glDrawArrays(GL_TRIANGLES, 0, 36);
//		glBindVertexArray(0);
//
//		glfwSwapBuffers(window);
//	}
//	glDeleteVertexArrays(1, &vao);
//	glDeleteBuffers(1, &vbo);
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
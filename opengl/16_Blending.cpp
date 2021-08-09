//#include <string>
////glew
//#define	GLEW_STATIC
//#include <GL/glew.h>
////glfw
//#include <GLFW/glfw3.h>
////glm mathemtics
//#include <glm/glm.hpp>
//#include <glm/gtc/matrix_transform.hpp>
//#include <glm/gtc/type_ptr.hpp>
////other libs
//#include <SOIL.h>
//
//#include "Shader.h"
//#include "Camera.h"
//
//void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
//void mouse_callback(GLFWwindow* window, double xpos, double ypos);
//void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
//void do_movement();
//GLuint loadTexture(const GLchar* path, GLboolean alpha = false);
//
//const GLuint WIDTH = 800, HEIGHT = 600;
//
//Camera camera(glm::vec3(0.0f, 0.0f, 3.0f));
//GLfloat lastX = WIDTH / 2.0;
//GLfloat lastY = HEIGHT / 2.0;
//bool keys[1024];
//
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
//	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "LearnOpengGL", nullptr, nullptr);
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
//	Shader shader("glsl/vBlending.glsl", "glsl/fBlending.glsl");
//
//	GLfloat cubeVertices[] = {
//		// Positions          // Texture Coords
//		-0.5f, -0.5f, -0.5f,  0.0f,  0.0f,
//		 0.5f, -0.5f, -0.5f,  1.0f,  0.0f,
//		 0.5f,  0.5f, -0.5f,  1.0f,  1.0f,
//		 0.5f,  0.5f, -0.5f,  1.0f,  1.0f,
//		-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,
//		-0.5f, -0.5f, -0.5f,  0.0f,  0.0f,
//
//		-0.5f, -0.5f,  0.5f,  0.0f,  0.0f,
//		 0.5f, -0.5f,  0.5f,  1.0f,  0.0f,
//		 0.5f,  0.5f,  0.5f,  1.0f,  1.0f,
//		 0.5f,  0.5f,  0.5f,  1.0f,  1.0f,
//		-0.5f,  0.5f,  0.5f,  0.0f,  1.0f,
//		-0.5f, -0.5f,  0.5f,  0.0f,  0.0f,
//
//		-0.5f,  0.5f,  0.5f,  1.0f,  0.0f,
//		-0.5f,  0.5f, -0.5f,  1.0f,  1.0f,
//		-0.5f, -0.5f, -0.5f,  0.0f,  1.0f,
//		-0.5f, -0.5f, -0.5f,  0.0f,  1.0f,
//		-0.5f, -0.5f,  0.5f,  0.0f,  0.0f,
//		-0.5f,  0.5f,  0.5f,  1.0f,  0.0f,
//
//		 0.5f,  0.5f,  0.5f,  1.0f,  0.0f,
//		 0.5f,  0.5f, -0.5f,  1.0f,  1.0f,
//		 0.5f, -0.5f, -0.5f,  0.0f,  1.0f,
//		 0.5f, -0.5f, -0.5f,  0.0f,  1.0f,
//		 0.5f, -0.5f,  0.5f,  0.0f,  0.0f,
//		 0.5f,  0.5f,  0.5f,  1.0f,  0.0f,
//
//		-0.5f, -0.5f, -0.5f,  0.0f,  1.0f,
//		 0.5f, -0.5f, -0.5f,  1.0f,  1.0f,
//		 0.5f, -0.5f,  0.5f,  1.0f,  0.0f,
//		 0.5f, -0.5f,  0.5f,  1.0f,  0.0f,
//		-0.5f, -0.5f,  0.5f,  0.0f,  0.0f,
//		-0.5f, -0.5f, -0.5f,  0.0f,  1.0f,
//
//		-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,
//		 0.5f,  0.5f, -0.5f,  1.0f,  1.0f,
//		 0.5f,  0.5f,  0.5f,  1.0f,  0.0f,
//		 0.5f,  0.5f,  0.5f,  1.0f,  0.0f,
//		-0.5f,  0.5f,  0.5f,  0.0f,  0.0f,
//		-0.5f,  0.5f, -0.5f,  0.0f,  1.0f
//	};
//	GLfloat planeVertices[] = {
//		// Positions          // Texture Coords (note we set these higher than 1 that together with GL_REPEAT as texture wrapping mode will cause the floor texture to repeat)
//		 5.0f, -0.5f,  5.0f,  2.0f,  0.0f,
//		-5.0f, -0.5f,  5.0f,  0.0f,  0.0f,
//		-5.0f, -0.5f, -5.0f,  0.0f,  2.0f,
//
//		 5.0f, -0.5f,  5.0f,  2.0f,  0.0f,
//		-5.0f, -0.5f, -5.0f,  0.0f,  2.0f,
//		 5.0f, -0.5f, -5.0f,  2.0f,  2.0f
//	};
//	GLfloat transparentVertices[] = {
//		// Positions         // Texture Coords (swapped y coordinates because texture is flipped upside down)
//		0.0f,  0.5f,  0.0f,  0.0f,  1.0f,
//		0.0f, -0.5f,  0.0f,  0.0f,  0.0f,
//		1.0f, -0.5f,  0.0f,  1.0f,  0.0f,
//
//		0.0f,  0.5f,  0.0f,  0.0f,  1.0f,
//		1.0f, -0.5f,  0.0f,  1.0f,  0.0f,
//		1.0f,  0.5f,  0.0f,  1.0f,  1.0f
//	};
//
//	GLuint cubeVao, cubeVbo;
//	glGenVertexArrays(1, &cubeVao);
//	glGenBuffers(1, &cubeVbo);
//	glBindVertexArray(cubeVao);
//	glBindBuffer(GL_ARRAY_BUFFER, cubeVbo);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(cubeVertices), &cubeVertices, GL_STATIC_DRAW);
//	glEnableVertexAttribArray(0);
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)0);
//	glEnableVertexAttribArray(1);
//	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
//	glBindVertexArray(0);
//
//	GLuint planeVao, planeVbo;
//	glGenVertexArrays(1, &planeVao);
//	glGenBuffers(1, &planeVbo);
//	glBindVertexArray(planeVao);
//	glBindBuffer(GL_ARRAY_BUFFER, planeVbo);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(planeVertices), &planeVertices, GL_STATIC_DRAW);
//	glEnableVertexAttribArray(0);
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)0);
//	glEnableVertexAttribArray(1);
//	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
//	glBindVertexArray(0);
//
//	GLuint transparentVao, transparentVbo;
//	glGenVertexArrays(1, &transparentVao);
//	glGenBuffers(1, &transparentVbo);
//	glBindVertexArray(transparentVao);
//	glBindBuffer(GL_ARRAY_BUFFER, transparentVbo);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(transparentVertices), &transparentVertices, GL_STATIC_DRAW);
//	glEnableVertexAttribArray(0);
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)0);
//	glEnableVertexAttribArray(1);
//	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
//	glBindVertexArray(0);
//
//	GLuint cubeTexture = loadTexture("texture/cube.jpeg");
//	GLuint floorTexture = loadTexture("texture/floor.jpg");
//	GLuint grassTexture = loadTexture("texture/grass.png", true);
//
//	vector<glm::vec3> vegetation;
//	vegetation.push_back(glm::vec3(-1.5f, 0.0f, -0.48f));
//	vegetation.push_back(glm::vec3(1.5f, 0.0f, 0.51f));
//	vegetation.push_back(glm::vec3(0.0f, 0.0f, 0.7f));
//	vegetation.push_back(glm::vec3(-0.3f, 0.0f, -2.3f));
//	vegetation.push_back(glm::vec3(0.5f, 0.0f, -0.6f));
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
//
//		shader.Use();
//		glm::mat4 view = camera.GetViewMatrix();
//		glm::mat4 projection = glm::perspective(camera.zoom, (GLfloat)WIDTH / (GLfloat)HEIGHT, 0.1f, 100.0f);
//		shader.SetMat4("view", view);
//		shader.SetMat4("projection", projection);
//
//		//cube
//		glActiveTexture(GL_TEXTURE0);
//		glBindTexture(GL_TEXTURE_2D, cubeTexture);
//		shader.SetInt("texture1", 0);
//		glBindVertexArray(cubeVao);
//		glm::mat4 model;
//		model = glm::translate(model, glm::vec3(-1.0f, 0.0f, -1.0f));
//		shader.SetMat4("model", model);
//		glDrawArrays(GL_TRIANGLES, 0, 36);
//		model = glm::mat4();
//		model = glm::translate(model, glm::vec3(2.0f, 0.0f, 0.0f));
//		shader.SetMat4("model", model);
//		glDrawArrays(GL_TRIANGLES, 0, 36);
//
//		//floor
//		glBindTexture(GL_TEXTURE_2D, floorTexture);
//		glBindVertexArray(planeVao);
//		model = glm::mat4();
//		shader.SetMat4("model", model);
//		glDrawArrays(GL_TRIANGLES, 0, 6);
//
//		//vegetation
//		glBindVertexArray(transparentVao);
//		glBindTexture(GL_TEXTURE_2D, grassTexture);
//		for (GLuint i=0; i < vegetation.size(); i++)
//		{
//			model = glm::mat4();
//			model = glm::translate(model, vegetation[i]);
//			shader.SetMat4("model", model);
//			glDrawArrays(GL_TRIANGLES, 0, 6);
//		}
//		glBindVertexArray(0);
//
//		glfwSwapBuffers(window);
//	}
//
//	glDeleteVertexArrays(1, &cubeVao);
//	glDeleteBuffers(1, &cubeVbo);
//	glDeleteVertexArrays(1, &planeVao);
//	glDeleteBuffers(1, &planeVbo);
//	glDeleteVertexArrays(1, &transparentVao);
//	glDeleteBuffers(1, &transparentVbo);
//	glfwTerminate();
//
//	return 0;
//}
//
//GLuint loadTexture(const GLchar* path, GLboolean alpha)
//{
//	GLuint textureId;
//	glGenTextures(1, &textureId);
//	int width, height;
//	unsigned char* image = SOIL_load_image(path, &width, &height, 0, alpha ? SOIL_LOAD_RGBA : SOIL_LOAD_RGB);
//	glBindTexture(GL_TEXTURE_2D, textureId);
//	glTexImage2D(GL_TEXTURE_2D, 0, alpha ? GL_RGBA : GL_RGB, width, height, 0, alpha ? GL_RGBA : GL_RGB, GL_UNSIGNED_BYTE, image);
//	glGenerateMipmap(GL_TEXTURE_2D);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, alpha ? GL_CLAMP_TO_EDGE : GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, alpha ? GL_CLAMP_TO_EDGE : GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//	glBindTexture(GL_TEXTURE_2D, 0);
//	SOIL_free_image_data(image);
//	return textureId;
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
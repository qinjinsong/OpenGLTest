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
//Camera camera(glm::vec3(0.0f, 0.0f, 3.0f));
//GLfloat lastX = WIDTH / 2.0;
//GLfloat lastY = HEIGHT / 2.0;
//bool keys[1024];
//
////glm::vec3 lightPos(1.2f, 1.0f, 2.0f);
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
//	Shader lightingShader("glsl/vLighting.glsl", "glsl/fLighting.glsl");
//	Shader lampShader("glsl/vLamp.glsl", "glsl/fLamp.glsl");
//
//	GLfloat vertices[] = {
//		// Positions          // Normals           // Texture Coords
//		-0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f,  0.0f,
//		 0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f,  0.0f,
//		 0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f,  1.0f,
//		 0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f,  1.0f,
//		-0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f,  1.0f,
//		-0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f,  0.0f,
//
//		-0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f,  0.0f,
//		 0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f,  0.0f,
//		 0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f,  1.0f,
//		 0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f,  1.0f,
//		-0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f,  1.0f,
//		-0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f,  0.0f,
//
//		-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f,  0.0f,
//		-0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  1.0f,  1.0f,
//		-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
//		-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
//		-0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  0.0f,  0.0f,
//		-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f,  0.0f,
//
//		 0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f,  0.0f,
//		 0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  1.0f,  1.0f,
//		 0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
//		 0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
//		 0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  0.0f,  0.0f,
//		 0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f,  0.0f,
//
//		-0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f,  1.0f,
//		 0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  1.0f,  1.0f,
//		 0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f,  0.0f,
//		 0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f,  0.0f,
//		-0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  0.0f,  0.0f,
//		-0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f,  1.0f,
//
//		-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f,  1.0f,
//		 0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  1.0f,  1.0f,
//		 0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f,  0.0f,
//		 0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f,  0.0f,
//		-0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  0.0f,  0.0f,
//		-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f,  1.0f
//	};
//	glm::vec3 cubePositions[] = {
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
//	glm::vec3 pointLightPositions[] = {
//		glm::vec3(0.7f,  0.2f,  2.0f),
//		glm::vec3(2.3f, -3.3f, 4.0f),
//		glm::vec3(-4.0f,  2.0f, 12.0f),
//		glm::vec3(0.0f,  0.0f, -3.0f)
//	};
//
//	GLuint vbo, containerVao;
//	glGenVertexArrays(1, &containerVao);
//	glGenBuffers(1, &vbo);
//
//	glBindBuffer(GL_ARRAY_BUFFER, vbo);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//
//	glBindVertexArray(containerVao);
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)0);
//	glEnableVertexAttribArray(0);
//	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
//	glEnableVertexAttribArray(1);
//	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));
//	glEnableVertexAttribArray(2);
//	glBindVertexArray(0);
//
//	GLuint lightVao;
//	glGenVertexArrays(1, &lightVao);
//
//	glBindVertexArray(lightVao);
//	glBindBuffer(GL_ARRAY_BUFFER, vbo);
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)0);
//	glEnableVertexAttribArray(0);
//	glBindVertexArray(0);
//
//	//load texture
//	int width, height;
//	unsigned char* image;
//	image = SOIL_load_image("texture/container2.png", &width, &height, 0, SOIL_LOAD_RGB);
//	GLuint diffuseMap;
//	glGenTextures(1, &diffuseMap);
//	glBindTexture(GL_TEXTURE_2D, diffuseMap);
//	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
//	glGenerateMipmap(GL_TEXTURE_2D);
//	SOIL_free_image_data(image);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST_MIPMAP_NEAREST);
//	glBindTexture(GL_TEXTURE_2D, 0);
//
//	image = SOIL_load_image("texture/container2_specular.png", &width, &height, 0, SOIL_LOAD_RGB);
//	GLuint specularMap;
//	glGenTextures(1, &specularMap);
//	glBindTexture(GL_TEXTURE_2D, specularMap);
//	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
//	glGenerateMipmap(GL_TEXTURE_2D);
//	SOIL_free_image_data(image);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST_MIPMAP_NEAREST);
//	glBindTexture(GL_TEXTURE_2D, 0);
//
//	//set texture uint
//	lightingShader.Use();
//	lightingShader.SetInt("material.diffuse", 0);
//	lightingShader.SetInt("material.specular", 1);
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
//		//lightPos.x = 1.0f + sin(glfwGetTime()) * 2.0f;
//		//lightPos.y = sin(glfwGetTime() / 2.0f) * 1.0f;
//
//		lightingShader.Use();
//		lightingShader.SetFloat3("viewPos", camera.position.x, camera.position.y, camera.position.z);
//		//set material properties
//		lightingShader.SetFloat("material.shininess", 64.0);
//
//		//directional light
//		lightingShader.SetFloat3("dirLight.direction", -0.2f, -1.0f, -0.3f);
//		lightingShader.SetFloat3("dirLight.ambient", 0.05f, 0.05f, 0.05f);
//		lightingShader.SetFloat3("dirLight.diffuse", 0.4f, 0.4f, 0.4f);
//		lightingShader.SetFloat3("dirLight.specular", 0.5f, 0.5f, 0.5f);
//		//point light
//		lightingShader.SetFloat3("pointLights[0].position", pointLightPositions[0].x, pointLightPositions[0].y, pointLightPositions[0].z);
//		lightingShader.SetFloat3("pointLights[0].ambient", 0.05f, 0.05f, 0.05f);
//		lightingShader.SetFloat3("pointLights[0].diffuse", 0.8f, 0.8f, 0.8f);
//		lightingShader.SetFloat3("pointLights[0].specular", 1.0f, 1.0f, 1.0f);
//		lightingShader.SetFloat("pointLights[0].constant", 1.0f);
//		lightingShader.SetFloat("pointLights[0].linear", 0.09f);
//		lightingShader.SetFloat("pointLights[0].quadratic", 0.032f);
//
//		lightingShader.SetFloat3("pointLights[1].position", pointLightPositions[1].x, pointLightPositions[1].y, pointLightPositions[1].z);
//		lightingShader.SetFloat3("pointLights[1].ambient", 0.05f, 0.05f, 0.05f);
//		lightingShader.SetFloat3("pointLights[1].diffuse", 0.8f, 0.8f, 0.8f);
//		lightingShader.SetFloat3("pointLights[1].specular", 1.0f, 1.0f, 1.0f);
//		lightingShader.SetFloat("pointLights[1].constant", 1.0f);
//		lightingShader.SetFloat("pointLights[1].linear", 0.09f);
//		lightingShader.SetFloat("pointLights[1].quadratic", 0.032f);
//
//		lightingShader.SetFloat3("pointLights[2].position", pointLightPositions[2].x, pointLightPositions[2].y, pointLightPositions[2].z);
//		lightingShader.SetFloat3("pointLights[2].ambient", 0.05f, 0.05f, 0.05f);
//		lightingShader.SetFloat3("pointLights[2].diffuse", 0.8f, 0.8f, 0.8f);
//		lightingShader.SetFloat3("pointLights[2].specular", 1.0f, 1.0f, 1.0f);
//		lightingShader.SetFloat("pointLights[2].constant", 1.0f);
//		lightingShader.SetFloat("pointLights[2].linear", 0.09f);
//		lightingShader.SetFloat("pointLights[2].quadratic", 0.032f);
//
//		lightingShader.SetFloat3("pointLights[3].position", pointLightPositions[3].x, pointLightPositions[3].y, pointLightPositions[3].z);
//		lightingShader.SetFloat3("pointLights[3].ambient", 0.05f, 0.05f, 0.05f);
//		lightingShader.SetFloat3("pointLights[3].diffuse", 0.8f, 0.8f, 0.8f);
//		lightingShader.SetFloat3("pointLights[3].specular", 1.0f, 1.0f, 1.0f);
//		lightingShader.SetFloat("pointLights[3].constant", 1.0f);
//		lightingShader.SetFloat("pointLights[3].linear", 0.09f);
//		lightingShader.SetFloat("pointLights[3].quadratic", 0.032f);
//
//		//14_MoreLight_t1
//		lightingShader.SetFloat3("spotLight.position", camera.position.x, camera.position.y, camera.position.z);
//		lightingShader.SetFloat3("spotLight.direction", camera.front.x, camera.front.y, camera.front.z);
//		lightingShader.SetFloat3("spotLight.ambient", 0.0f, 0.0f, 0.0f);
//		lightingShader.SetFloat3("spotLight.diffuse", 1.0f, 1.0f, 1.0f);
//		lightingShader.SetFloat3("spotLight.specular", 1.0f, 1.0f, 1.0f);
//		lightingShader.SetFloat("spotLight.constant", 1.0f);
//		lightingShader.SetFloat("spotLight.linear", 0.09f);
//		lightingShader.SetFloat("spotLight.quadratic", 0.032f);
//		lightingShader.SetFloat("spotLight.cutOff", glm::cos(glm::radians(12.5f)));
//		lightingShader.SetFloat("spotLight.outerCutOff", glm::cos(glm::radians(15.5f)));
//
//		glm::mat4 view;
//		view = camera.GetViewMatrix();
//		lightingShader.SetMat4("view", view);
//		glm::mat4 projection = glm::perspective(camera.zoom, (GLfloat)WIDTH / (GLfloat)HEIGHT, 0.1f, 100.0f);
//		lightingShader.SetMat4("projection", projection);
//
//		//bind diffuse map
//		glActiveTexture(GL_TEXTURE0);
//		glBindTexture(GL_TEXTURE_2D, diffuseMap);
//		glActiveTexture(GL_TEXTURE1);
//		glBindTexture(GL_TEXTURE_2D, specularMap);
//
//		glBindVertexArray(containerVao);
//		int len = sizeof(cubePositions) / sizeof(cubePositions[0]);
//		glm::mat4 model;
//		for (GLuint i = 0; i < len; i++)
//		{
//			model = glm::mat4();
//			model = glm::translate(model, cubePositions[i]);
//			GLfloat angle = (GLfloat)glfwGetTime() * -25;
//			//GLfloat angle = 20.0f * i;
//			model = glm::rotate(model, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));
//			lightingShader.SetMat4("model", model);
//
//			glDrawArrays(GL_TRIANGLES, 0, 36);
//		}
//		glBindVertexArray(0);
//
//		lampShader.Use();
//		lampShader.SetMat4("view", view);
//		lampShader.SetMat4("projection", projection);
//		glBindVertexArray(lightVao);
//		len = sizeof(pointLightPositions) / sizeof(pointLightPositions[0]);
//		for (GLuint i = 0; i < len; i++)
//		{
//			model = glm::mat4();
//			model = glm::translate(model, pointLightPositions[i]);
//			model = glm::scale(model, glm::vec3(0.2f));
//			lampShader.SetMat4("model", model);
//
//			glDrawArrays(GL_TRIANGLES, 0, 36);
//		}
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
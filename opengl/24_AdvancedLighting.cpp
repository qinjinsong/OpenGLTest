//#include <string>
//#include <algorithm>
//using namespace std;
////glew
//#define GLEW_STATIC
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
//#include "Camera.h"
//#include "Shader.h"
//
//GLuint WIDTH = 800, HEIGHT = 600;
//
//void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
//void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
//void mouse_callback(GLFWwindow* window, double xpos, double ypos);
//void do_movement();
//GLuint loadTexture(const GLchar* path, GLboolean alpha = false);
//
//Camera camera(glm::vec3(0.0f, 0.0f, 3.0f));
//bool keys[1024];
//GLfloat lastX = WIDTH / 2;
//GLfloat lastY = HEIGHT / 2;
//bool firstMouse = true;
//GLfloat deltatime = 0.0f;
//GLfloat lastFrame = 0.0f;
//
//GLboolean blinn = true;
////GLboolean blinn = false;
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
//	glDepthFunc(GL_DEPTH_TEST);
//
//	Shader shader("glsl/vAdvancedLighting.glsl", "glsl/fAdvancedLighting.glsl");
//
//	GLfloat planeVertices[] = {
//		// Positions          // Normals         // Texture Coords
//		 8.0f, -0.5f,  8.0f,  0.0f, 1.0f, 0.0f,  5.0f, 0.0f,
//		-8.0f, -0.5f,  8.0f,  0.0f, 1.0f, 0.0f,  0.0f, 0.0f,
//		-8.0f, -0.5f, -8.0f,  0.0f, 1.0f, 0.0f,  0.0f, 5.0f,
//
//		 8.0f, -0.5f,  8.0f,  0.0f, 1.0f, 0.0f,  5.0f, 0.0f,
//		-8.0f, -0.5f, -8.0f,  0.0f, 1.0f, 0.0f,  0.0f, 5.0f,
//		 8.0f, -0.5f, -8.0f,  0.0f, 1.0f, 0.0f,  5.0f, 5.0f
//	};
//
//	GLuint planeVao, planeVbo;
//	glGenVertexArrays(1, &planeVao);
//	glGenBuffers(1, &planeVbo);
//	glBindVertexArray(planeVao);
//	glBindBuffer(GL_ARRAY_BUFFER, planeVbo);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(planeVertices), &planeVertices, GL_STATIC_DRAW);
//	glEnableVertexAttribArray(0);
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)0);
//	glEnableVertexAttribArray(1);
//	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
//	glEnableVertexAttribArray(2);
//	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));
//	glBindVertexArray(0);
//
//	glm::vec3 lightPos(0.0f, 0.0f, 0.0f);
//
//	GLuint floorTexture = loadTexture("texture/floor.jpg");
//
//	std::cout << "blinn: " << (blinn ? "true" : "false") << std::endl;
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
//		shader.Use();
//		glm::mat4 view = camera.GetViewMatrix();
//		glm::mat4 projection = glm::perspective(camera.zoom, (float)WIDTH / (float)HEIGHT, 0.1f, 100.0f);
//		shader.SetMat4("view", view);
//		shader.SetMat4("projection", projection);
//		shader.SetFloat3("lightPos", lightPos.x, lightPos.y, lightPos.z);
//		shader.SetFloat3("viewPos", camera.position.x, camera.position.y, camera.position.z);
//		shader.SetInt("blinn", blinn);
//
//		//floor
//		glBindVertexArray(planeVao);
//		glBindTexture(GL_TEXTURE_2D, floorTexture);
//		glDrawArrays(GL_TRIANGLES, 0, 6);
//		glBindVertexArray(0);
//
//		glfwSwapBuffers(window);
//	}
//
//	glDeleteVertexArrays(1, &planeVao);
//	glDeleteBuffers(1, &planeVbo);
//	glfwTerminate();
//
//	return 0;
//}
//
//GLuint loadTexture(const GLchar* path, GLboolean alpha /* = false */)
//{
//	GLuint textureId;
//	int width, height;
//	unsigned char* image = SOIL_load_image(path, &width, &height, 0, alpha ? SOIL_LOAD_RGBA : SOIL_LOAD_RGB);
//	glGenTextures(1, &textureId);
//	glBindTexture(GL_TEXTURE_2D, textureId);
//	glTexImage2D(GL_TEXTURE_2D, 0, alpha ? GL_RGBA : GL_RGB, width, height, 0, alpha ? GL_RGBA : GL_RGB, GL_UNSIGNED_BYTE, image);
//	glGenerateMipmap(GL_TEXTURE_2D);
//
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, alpha ? GL_CLAMP_TO_EDGE : GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, alpha ? GL_CLAMP_TO_EDGE : GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//
//	glBindTexture(GL_TEXTURE_2D, 0);
//	SOIL_free_image_data(image);
//
//	return textureId;
//}
//
//bool isKeyBStatus = false;
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
//		{
//			keys[key] = false;
//			isKeyBStatus = false;
//		}
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
//
//	if (keys[GLFW_KEY_B] && !isKeyBStatus)
//	{
//		blinn = !blinn;
//		isKeyBStatus = true;
//	}
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
//
//
//
//
//
//
////// Std. Includes
////#include <string>
////
////// GLEW
////#define GLEW_STATIC
////#include <GL/glew.h>
////
////// GLFW
////#include <GLFW/glfw3.h>
////
////// GL includes
////#include "Camera.h"
////#include "Shader.h"
////
////// GLM Mathemtics
////#include <glm/glm.hpp>
////#include <glm/gtc/matrix_transform.hpp>
////#include <glm/gtc/type_ptr.hpp>
////
////// Other Libs
////#include <SOIL.h>
////
////// Properties
////const GLuint SCR_WIDTH = 800, SCR_HEIGHT = 600;
////
////// Function prototypes
////void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
////void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
////void mouse_callback(GLFWwindow* window, double xpos, double ypos);
////void Do_Movement();
////GLuint loadTexture(const GLchar* path);
////
////// Camera
////Camera camera(glm::vec3(0.0f, 0.0f, 3.0f));
////
////// Delta
////GLfloat deltaTime = 0.0f;
////GLfloat lastFrame = 0.0f;
////
////// Options
////GLboolean blinn = false;
////
////// The MAIN function, from here we start our application and run our Game loop
////int main()
////{
////	// Init GLFW
////	glfwInit();
////	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
////	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
////	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
////	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
////
////	GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", nullptr, nullptr); // Windowed
////	glfwMakeContextCurrent(window);
////
////	// Set the required callback functions
////	glfwSetKeyCallback(window, key_callback);
////	glfwSetCursorPosCallback(window, mouse_callback);
////	glfwSetScrollCallback(window, scroll_callback);
////
////	// Options
////	//glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
////
////	// Initialize GLEW to setup the OpenGL Function pointers
////	glewExperimental = GL_TRUE;
////	glewInit();
////
////	// Define the viewport dimensions
////	glViewport(0, 0, SCR_WIDTH, SCR_HEIGHT);
////
////	// Setup some OpenGL options
////	glEnable(GL_DEPTH_TEST);
////	// glDepthFunc(GL_ALWAYS); // Set to always pass the depth test (same effect as glDisable(GL_DEPTH_TEST))
////
////	// Setup and compile our shaders
////	Shader shader("glsl/vAdvancedLighting.glsl", "glsl/fAdvancedLighting.glsl");
////
////	GLfloat planeVertices[] = {
////		// Positions          // Normals         // Texture Coords
////		 8.0f, -0.5f,  8.0f,  0.0f, 1.0f, 0.0f,  5.0f, 0.0f,
////		-8.0f, -0.5f,  8.0f,  0.0f, 1.0f, 0.0f,  0.0f, 0.0f,
////		-8.0f, -0.5f, -8.0f,  0.0f, 1.0f, 0.0f,  0.0f, 5.0f,
////
////		 8.0f, -0.5f,  8.0f,  0.0f, 1.0f, 0.0f,  5.0f, 0.0f,
////		-8.0f, -0.5f, -8.0f,  0.0f, 1.0f, 0.0f,  0.0f, 5.0f,
////		 8.0f, -0.5f, -8.0f,  0.0f, 1.0f, 0.0f,  5.0f, 5.0f
////	};
////	// Setup plane VAO
////	GLuint planeVAO, planeVBO;
////	glGenVertexArrays(1, &planeVAO);
////	glGenBuffers(1, &planeVBO);
////	glBindVertexArray(planeVAO);
////	glBindBuffer(GL_ARRAY_BUFFER, planeVBO);
////	glBufferData(GL_ARRAY_BUFFER, sizeof(planeVertices), &planeVertices, GL_STATIC_DRAW);
////	glEnableVertexAttribArray(0);
////	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)0);
////	glEnableVertexAttribArray(1);
////	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
////	glEnableVertexAttribArray(2);
////	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));
////	glBindVertexArray(0);
////
////	// Light source
////	glm::vec3 lightPos(0.0f, 0.0f, 0.0f);
////
////	// Load textures
////	GLuint floorTexture = loadTexture("texture/floor.jpg");
////
////	// Game loop
////	while (!glfwWindowShouldClose(window))
////	{
////		// Set frame time
////		GLfloat currentFrame = glfwGetTime();
////		deltaTime = currentFrame - lastFrame;
////		lastFrame = currentFrame;
////
////		// Check and call events
////		glfwPollEvents();
////		Do_Movement();
////
////		// Clear the colorbuffer
////		glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
////		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
////
////		// Draw objects
////		shader.Use();
////		glm::mat4 view = camera.GetViewMatrix();
////		glm::mat4 projection = glm::perspective(camera.zoom, (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
////		glUniformMatrix4fv(glGetUniformLocation(shader.program, "view"), 1, GL_FALSE, glm::value_ptr(view));
////		glUniformMatrix4fv(glGetUniformLocation(shader.program, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
////		// Set light uniforms
////		glUniform3fv(glGetUniformLocation(shader.program, "lightPos"), 1, &lightPos[0]);
////		glUniform3fv(glGetUniformLocation(shader.program, "viewPos"), 1, &camera.position[0]);
////		glUniform1i(glGetUniformLocation(shader.program, "blinn"), blinn);
////		// Floor
////		glBindVertexArray(planeVAO);
////		glBindTexture(GL_TEXTURE_2D, floorTexture);
////		glDrawArrays(GL_TRIANGLES, 0, 6);
////		glBindVertexArray(0);
////
////		std::cout << (blinn ? "true" : "false") << std::endl;
////
////		// Swap the buffers
////		glfwSwapBuffers(window);
////	}
////
////	glfwTerminate();
////	return 0;
////}
////
////// This function loads a texture from file. Note: texture loading functions like these are usually 
////// managed by a 'Resource Manager' that manages all resources (like textures, models, audio). 
////// For learning purposes we'll just define it as a utility function.
////GLuint loadTexture(const GLchar* path)
////{
////	// Generate texture ID and load texture data 
////	GLuint textureID;
////	glGenTextures(1, &textureID);
////	int width, height;
////	unsigned char* image = SOIL_load_image(path, &width, &height, 0, SOIL_LOAD_RGB);
////	// Assign texture to ID
////	glBindTexture(GL_TEXTURE_2D, textureID);
////	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
////	glGenerateMipmap(GL_TEXTURE_2D);
////
////	// Parameters
////	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
////	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
////	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
////	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
////	glBindTexture(GL_TEXTURE_2D, 0);
////	SOIL_free_image_data(image);
////	return textureID;
////
////}
////
////bool keys[1024];
////bool keysPressed[1024];
////// Moves/alters the camera positions based on user input
////void Do_Movement()
////{
////	// Camera controls
////	if (keys[GLFW_KEY_W])
////		camera.KeyboardMove(FORWARD, deltaTime);
////	if (keys[GLFW_KEY_S])
////		camera.KeyboardMove(BACKWARD, deltaTime);
////	if (keys[GLFW_KEY_A])
////		camera.KeyboardMove(LEFT, deltaTime);
////	if (keys[GLFW_KEY_D])
////		camera.KeyboardMove(RIGHT, deltaTime);
////
////	if (keys[GLFW_KEY_B] && !keysPressed[GLFW_KEY_B])
////	{
////		blinn = !blinn;
////		keysPressed[GLFW_KEY_B] = true;
////	}
////}
////
////GLfloat lastX = 400, lastY = 300;
////bool firstMouse = true;
////// Is called whenever a key is pressed/released via GLFW
////void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
////{
////	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
////		glfwSetWindowShouldClose(window, GL_TRUE);
////
////	if (key >= 0 && key <= 1024)
////	{
////		if (action == GLFW_PRESS)
////			keys[key] = true;
////		else if (action == GLFW_RELEASE)
////		{
////			keys[key] = false;
////			keysPressed[key] = false;
////		}
////	}
////}
////
////void mouse_callback(GLFWwindow* window, double xpos, double ypos)
////{
////	if (firstMouse)
////	{
////		lastX = xpos;
////		lastY = ypos;
////		firstMouse = false;
////	}
////
////	GLfloat xoffset = xpos - lastX;
////	GLfloat yoffset = lastY - ypos;
////
////	lastX = xpos;
////	lastY = ypos;
////
////	camera.MouseMove(xoffset, yoffset);
////}
////
////void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
////{
////	camera.MouseScroll(yoffset);
////}
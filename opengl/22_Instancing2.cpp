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
//#include "Model.h"
//
//GLuint WIDTH = 800, HEIGHT = 600;
//
//void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
//void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
//void mouse_callback(GLFWwindow* window, double xpos, double ypos);
//void do_movement();
//
//Camera camera(glm::vec3(0.0f, 0.0f, 3.0f));
//bool keys[1024];
//GLfloat lastX = WIDTH / 2, lastY = HEIGHT / 2;
//bool firstMouse = true;
//
//GLfloat deltatime = 0.0f;
//GLfloat lastFrame = 0.0;
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
//	//Shader shader("glsl/vInstancing.glsl", "glsl/fInstancing.glsl");
//	Shader shader("glsl/vPlanet.glsl", "glsl/fPlanet.glsl");
//
//	Model rock("model/rock/rock.obj", "rock.png");
//	Model planet("model/planet/planet.obj", "mars.png");
//	//Model planet("model/backpack/backpack.obj");
//
//	shader.Use();
//	glm::mat4 projection = glm::perspective(camera.zoom, (float)WIDTH / (float)HEIGHT, 0.1f, 100.0f);
//	shader.SetMat4("projection", projection);
//
//	GLuint amount = 1000;
//	glm::mat4* modelMatrices = new glm::mat4[amount];
//	srand(glfwGetTime());
//	GLfloat radius = 50.0;
//	GLfloat offset = 2.5f;
//	for (GLuint i=0; i < amount; i++)
//	{
//		glm::mat4 model;
//		GLfloat angle = (GLfloat)i / (GLfloat)amount * 360.0f;
//		GLfloat displacement = (rand() % (GLint)(2 * offset * 100)) / 100.0f - offset;
//		GLfloat x = sin(angle) * radius + displacement;
//		displacement = (rand() % (GLint)(2 * offset * 100)) / 100.0f - offset;
//		GLfloat y = displacement * 0.4f;
//		displacement = (rand() % (GLint)(2 * offset * 100)) / 100.0f - offset;
//		GLfloat z = cos(angle) * radius + displacement;
//		model = glm::translate(model, glm::vec3(x, y, z));
//
//		GLfloat scale = (rand() % 20) / 100.0f + 0.05;
//		model = glm::scale(model, glm::vec3(scale));
//
//		GLfloat rotAngle = (rand() % 360);
//		model = glm::rotate(model, glm::radians(rotAngle), glm::vec3(0.4f, 0.6f, 0.6f));
//
//		modelMatrices[i] = model;
//	}
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
//		shader.SetMat4("view", camera.GetViewMatrix());
//
//		//draw planet
//		glm::mat4 model;
//		model = glm::translate(model, glm::vec3(0.5f, 0.0f, -3.0f));
//		model = glm::scale(model, glm::vec3(0.5f));
//		shader.SetMat4("model", model);
//		planet.Draw(shader);
//
//		//draw meteorites
//		for (GLuint i = 0; i < amount; i++)
//		{
//			shader.SetMat4("model", modelMatrices[i]);
//			rock.Draw(shader);
//		}
//
//		glfwSwapBuffers(window);
//	}
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
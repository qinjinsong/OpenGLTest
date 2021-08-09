////glew
//#define	GLEW_STATIC
//#include <GL/glew.h>
////glfw
//#include <GLFW/glfw3.h>
////glm mathemtics
//#include <glm/glm.hpp>
//#include <glm/gtc/matrix_transform.hpp>
//#include <glm/gtc/type_ptr.hpp>
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
//Camera camera(glm::vec3(0.0f, 0.0f, 155.0f));
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
//	Shader planetShader("glsl/vPlanet.glsl", "glsl/fPlanet.glsl");
//	Shader instanceShader("glsl/vAsteroids.glsl", "glsl/fAsteroids.glsl");
//
//	Model rock("model/rock/rock.obj", "rock.png");
//	Model planet("model/planet/planet.obj", "mars.png");
//	//Model planet("model/backpack/backpack.obj");
//
//	planetShader.Use();
//	glm::mat4 projection = glm::perspective(camera.zoom, (float)WIDTH / (float)HEIGHT, 1.0f, 10000.0f);
//	planetShader.SetMat4("projection", projection);
//
//	instanceShader.Use();
//	instanceShader.SetMat4("projection", projection);
//
//	GLuint amount = 100000;
//	glm::mat4* modelMatrices;
//	modelMatrices = new glm::mat4[amount];
//	srand(glfwGetTime()); // initialize random seed	
//	GLfloat radius = 150.0f;
//	GLfloat offset = 25.0f;
//	for (GLuint i = 0; i < amount; i++)
//	{
//		glm::mat4 model;
//		// 1. Translation: Randomly displace along circle with radius 'radius' in range [-offset, offset]
//		GLfloat angle = (GLfloat)i / (GLfloat)amount * 360.0f;
//		GLfloat displacement = (rand() % (GLint)(2 * offset * 100)) / 100.0f - offset;
//		GLfloat x = sin(angle) * radius + displacement;
//		displacement = (rand() % (GLint)(2 * offset * 100)) / 100.0f - offset;
//		GLfloat y = -2.5f + displacement * 0.4f; // Keep height of asteroid field smaller compared to width of x and z
//		displacement = (rand() % (GLint)(2 * offset * 100)) / 100.0f - offset;
//		GLfloat z = cos(angle) * radius + displacement;
//		model = glm::translate(model, glm::vec3(x, y, z));
//
//		// 2. Scale: Scale between 0.05 and 0.25f
//		GLfloat scale = (rand() % 20) / 100.0f + 0.05;
//		model = glm::scale(model, glm::vec3(scale));
//
//		// 3. Rotation: add random rotation around a (semi)randomly picked rotation axis vector
//		GLfloat rotAngle = (rand() % 360);
//		model = glm::rotate(model, glm::radians(rotAngle), glm::vec3(0.4f, 0.6f, 0.8f));
//
//		// 4. Now add to list of matrices
//		modelMatrices[i] = model;
//	}
//
//	GLuint buffer;
//	glGenBuffers(1, &buffer);
//	glBindBuffer(GL_ARRAY_BUFFER, buffer);
//	glBufferData(GL_ARRAY_BUFFER, amount * sizeof(glm::mat4), &modelMatrices[0], GL_STATIC_DRAW);
//
//	for (GLuint i=0; i < rock.meshes.size(); i++)
//	{
//		GLuint vao = rock.meshes[i].vao;
//		glBindVertexArray(vao);
//
//		glEnableVertexAttribArray(3);
//		glVertexAttribPointer(3, 4, GL_FLOAT, GL_FALSE, sizeof(glm::mat4), (GLvoid*)0);
//		glEnableVertexAttribArray(4);
//		glVertexAttribPointer(4, 4, GL_FLOAT, GL_FALSE, sizeof(glm::mat4), (GLvoid*)(sizeof(glm::vec4)));
//		glEnableVertexAttribArray(5);
//		glVertexAttribPointer(5, 4, GL_FLOAT, GL_FALSE, sizeof(glm::mat4), (GLvoid*)(2 * sizeof(glm::vec4)));
//		glEnableVertexAttribArray(6);
//		glVertexAttribPointer(6, 4, GL_FLOAT, GL_FALSE, sizeof(glm::mat4), (GLvoid*)(3 * sizeof(glm::vec4)));
//
//		glVertexAttribDivisor(3, 1);
//		glVertexAttribDivisor(4, 1);
//		glVertexAttribDivisor(5, 1);
//		glVertexAttribDivisor(6, 1);
//
//		glBindVertexArray(0);
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
//		glm::mat4 view = camera.GetViewMatrix();
//
//		planetShader.Use();
//		planetShader.SetMat4("view", view);
//		instanceShader.Use();
//		instanceShader.SetMat4("view", view);
//
//		//draw planet
//		planetShader.Use();
//		glm::mat4 model;
//		model = glm::translate(model, glm::vec3(0.0f, -5.0f, 0.0f));
//		model = glm::scale(model, glm::vec3(10.0f));
//		planetShader.SetMat4("model", model);
//		planet.Draw(planetShader);
//
//		instanceShader.Use();
//		glBindTexture(GL_TEXTURE_2D, rock.textures_loaded[0].id);
//		for (GLuint i=0; i< rock.meshes.size(); i++)
//		{
//			glBindVertexArray(rock.meshes[i].vao);
//			glDrawElementsInstanced(GL_TRIANGLES, rock.meshes[i].indices.size(), GL_UNSIGNED_INT, 0, amount);
//			glBindVertexArray(0);
//		}
//
//		glfwSwapBuffers(window);
//	}
//
//	delete[] modelMatrices;
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
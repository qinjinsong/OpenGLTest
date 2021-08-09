////glew
//#define  GLEW_STATIC
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
//GLuint WIDTH = 800, HEIGHT = 600;
//
//void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
//void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
//void mouse_callback(GLFWwindow* window, double xpos, double ypos);
//void do_movement();
//GLuint loadTexture(const GLchar* path, GLboolean alpha = false);
//void renderScene(Shader &shader);
//void renderCube();
//void renderQuad();
//
//Camera camera(glm::vec3(0.0f, 0.0f, 3.0f));
//bool keys[1024];
//GLfloat lastX = WIDTH / 2, lastY = HEIGHT / 2;
//bool firstMouse = true;
//
//GLfloat deltatime = 0.0f;
//GLfloat lastFrame = 0.0;
//
//GLuint woodTexture;
//GLuint planeVao;
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
//	Shader shader("glsl/vShadowMapping.glsl", "glsl/fShadowMapping.glsl");
//	Shader simpleDepthShader("glsl/vShadowMappingDepth.glsl", "glsl/fShadowMappingDepth.glsl");
//	Shader debugDepthShader("glsl/vDebugQuad.glsl", "glsl/fDebugQuad.glsl");
//
//	shader.Use();
//	shader.SetInt("diffuseTexture", 0);
//	shader.SetInt("shadowMap", 1);
//
//	GLfloat planeVertices[] = {
//		// Positions          // Normals         // Texture Coords
//		25.0f, -0.5f, 25.0f, 0.0f, 1.0f, 0.0f, 25.0f, 0.0f,
//		-25.0f, -0.5f, -25.0f, 0.0f, 1.0f, 0.0f, 0.0f, 25.0f,
//		-25.0f, -0.5f, 25.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f,
//
//		25.0f, -0.5f, 25.0f, 0.0f, 1.0f, 0.0f, 25.0f, 0.0f,
//		25.0f, -0.5f, -25.0f, 0.0f, 1.0f, 0.0f, 25.0f, 25.0f,
//		-25.0f, -0.5f, -25.0f, 0.0f, 1.0f, 0.0f, 0.0f, 25.0f
//	};
//
//	//setup plane vao
//	GLuint planeVbo;
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
//	glm::vec3 lightPos(-2.0f, 4.0f, -1.0f);
//
//	woodTexture = loadTexture("texture/container.jpg");
//
//	const GLuint SHADOW_WIDTH = 1024, SHADOW_HEIGHT = 1024;
//	GLuint depthMapFbo;
//	glGenFramebuffers(1, &depthMapFbo);
//	//create depth texture
//	GLuint depthMap;
//	glGenTextures(1, &depthMap);
//	glBindTexture(GL_TEXTURE_2D, depthMap);
//	glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT, SHADOW_WIDTH, SHADOW_HEIGHT, 0, GL_DEPTH_COMPONENT, GL_FLOAT, NULL);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
//	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
//	GLfloat borderColor[] = { 1.0,1.0, 1.0, 1.0 };
//	glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, borderColor);
//
//	glBindFramebuffer(GL_FRAMEBUFFER, depthMapFbo);
//	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, depthMap, 0);
//	glDrawBuffer(GL_NONE);
//	glDrawBuffer(GL_NONE);
//	glBindFramebuffer(GL_FRAMEBUFFER, 0);
//
//	glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
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
//		//change light position
//		lightPos.x = sin(glfwGetTime()) * 3.0f;
//		lightPos.z = cos(glfwGetTime()) * 2.0f;
//		lightPos.y = 5.0 + cos(glfwGetTime()) * 1.0f;
//
//		//render depth of scene to texture
//		glm::mat4 lightProjection, lightView;
//		glm::mat4 lightSpaceMatrix;
//		GLfloat near_plane = 1.0f, far_plane = 7.5f;
//		lightProjection = glm::ortho(-10.0f, 10.0f, -10.0f, 10.0f, near_plane, far_plane);
//		lightView = glm::lookAt(lightPos, glm::vec3(0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
//		lightSpaceMatrix = lightProjection * lightView;
//		//now render scene from light's point of view
//		simpleDepthShader.Use();
//		simpleDepthShader.SetMat4("lightSpaceMatrix", lightSpaceMatrix);
//		glViewport(0, 0, SHADOW_WIDTH, SHADOW_HEIGHT);
//		glBindFramebuffer(GL_FRAMEBUFFER, depthMapFbo);
//		glClear(GL_DEPTH_BUFFER_BIT);
//		renderScene(simpleDepthShader);
//		glBindFramebuffer(GL_FRAMEBUFFER, 0);
//
//		//render scene as normal
//		glViewport(0, 0, WIDTH, HEIGHT);
//		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//		shader.Use();
//		glm::mat4 projection = glm::perspective(camera.zoom, (float)WIDTH / (float)HEIGHT, 0.1f, 100.0f);
//		glm::mat4 view = camera.GetViewMatrix();
//		shader.SetMat4("projection", projection);
//		shader.SetMat4("view", view);
//		shader.SetFloat3("lightPos", lightPos.x, lightPos.y, lightPos.z);
//		shader.SetFloat3("viewPos", camera.position.x, camera.position.y, camera.position.z);
//		shader.SetMat4("lightSpaceMatrix", lightSpaceMatrix);
//		glActiveTexture(GL_TEXTURE0);
//		glBindTexture(GL_TEXTURE_2D, woodTexture);
//		glActiveTexture(GL_TEXTURE1);
//		glBindTexture(GL_TEXTURE_2D, depthMap);
//		renderScene(shader);
//
//		//visualize depth map by rendering it to plane
//		//debugDepthShader.Use();
//		//debugDepthShader.SetFloat("near_plane", near_plane);
//		//debugDepthShader.SetFloat("far_plane", far_plane);
//		//glActiveTexture(GL_TEXTURE0);
//		//glBindTexture(GL_TEXTURE_2D, depthMap);
//		//renderQuad();
//
//		glfwSwapBuffers(window);
//	}
//
//	glDeleteFramebuffers(1, &depthMapFbo);
//	glDeleteTextures(1, &depthMap);
//	glDeleteTextures(1, &woodTexture);
//	glDeleteVertexArrays(1, &planeVao);
//	glDeleteBuffers(1, &planeVbo);
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
//void renderScene(Shader& shader)
//{
//	//floor
//	glm::mat4 model;
//	shader.SetMat4("model", model);
//	glBindVertexArray(planeVao);
//	glDrawArrays(GL_TRIANGLES, 0, 6);
//	glBindVertexArray(0);
//	//cubes
//	model = glm::mat4();
//	model = glm::translate(model, glm::vec3(-0.1f, 1.5f, 0.0f));
//	model = glm::rotate(model, (float)glm::radians(60.0f * glfwGetTime()), glm::vec3(1.0, 0.0, 0.0));
//	shader.SetMat4("model", model);
//	renderCube();
//	model = glm::mat4();
//	model = glm::translate(model, glm::vec3(0.0f, -0.3f, 0.0f));
//	shader.SetMat4("model", model);
//	renderCube();
//	model = glm::mat4();
//	model = glm::translate(model, glm::vec3(-1.1f, 1.0f, 0.0f));
//	model = glm::rotate(model, glm::radians(60.0f), glm::vec3(1.0, 0.0, 1.0));
//	model = glm::scale(model, glm::vec3(0.5));
//	shader.SetMat4("model", model);
//	renderCube();
//}
//
//GLuint quadVao, quadVbo;
//void renderQuad()
//{
//	if (quadVao == 0)
//	{
//		GLfloat quadVertices[] = {
//			// Positions        // Texture Coords
//			-1.0f,  1.0f, 0.0f,  0.0f, 1.0f,
//			-1.0f, -1.0f, 0.0f,  0.0f, 0.0f,
//			 1.0f,  1.0f, 0.0f,  1.0f, 1.0f,
//			 1.0f, -1.0f, 0.0f,  1.0f, 0.0f,
//		};
//
//		glGenVertexArrays(1, &quadVao);
//		glGenBuffers(1, &quadVbo);
//		glBindVertexArray(quadVao);
//		glBindBuffer(GL_ARRAY_BUFFER, quadVbo);
//		glBufferData(GL_ARRAY_BUFFER, sizeof(quadVertices), &quadVertices, GL_STATIC_DRAW);
//		glEnableVertexAttribArray(0);
//		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)0);
//		glEnableVertexAttribArray(1);
//		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
//	}
//
//	glBindVertexArray(quadVao);
//	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
//	glBindVertexArray(0);
//}
//
//GLuint cubeVao, cubeVbo;
//void renderCube()
//{
//	if (cubeVao == 0)
//	{
//		GLfloat vertices[] = {
//			// Back face
//			-0.5f, -0.5f, -0.5f, 0.0f, 0.0f, -1.0f, 0.0f, 0.0f, // Bottom-left
//			0.5f, 0.5f, -0.5f, 0.0f, 0.0f, -1.0f, 1.0f, 1.0f, // top-right
//			0.5f, -0.5f, -0.5f, 0.0f, 0.0f, -1.0f, 1.0f, 0.0f, // bottom-right         
//			0.5f, 0.5f, -0.5f, 0.0f, 0.0f, -1.0f, 1.0f, 1.0f,  // top-right
//			-0.5f, -0.5f, -0.5f, 0.0f, 0.0f, -1.0f, 0.0f, 0.0f,  // bottom-left
//			-0.5f, 0.5f, -0.5f, 0.0f, 0.0f, -1.0f, 0.0f, 1.0f,// top-left
//			// Front face
//			-0.5f, -0.5f, 0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, // bottom-left
//			0.5f, -0.5f, 0.5f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f,  // bottom-right
//			0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f,  // top-right
//			0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, // top-right
//			-0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f,  // top-left
//			-0.5f, -0.5f, 0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f,  // bottom-left
//			// Left face
//			-0.5f, 0.5f, 0.5f, -1.0f, 0.0f, 0.0f, 1.0f, 0.0f, // top-right
//			-0.5f, 0.5f, -0.5f, -1.0f, 0.0f, 0.0f, 1.0f, 1.0f, // top-left
//			-0.5f, -0.5f, -0.5f, -1.0f, 0.0f, 0.0f, 0.0f, 1.0f,  // bottom-left
//			-0.5f, -0.5f, -0.5f, -1.0f, 0.0f, 0.0f, 0.0f, 1.0f, // bottom-left
//			-0.5f, -0.5f, 0.5f, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f,  // bottom-right
//			-0.5f, 0.5f, 0.5f, -1.0f, 0.0f, 0.0f, 1.0f, 0.0f, // top-right
//			// Right face
//			0.5f, 0.5f, 0.5f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, // top-left
//			0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f, // bottom-right
//			0.5f, 0.5f, -0.5f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f, // top-right         
//			0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f,  // bottom-right
//			0.5f, 0.5f, 0.5f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f,  // top-left
//			0.5f, -0.5f, 0.5f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, // bottom-left     
//			// Bottom face
//			-0.5f, -0.5f, -0.5f, 0.0f, -1.0f, 0.0f, 0.0f, 1.0f, // top-right
//			0.5f, -0.5f, -0.5f, 0.0f, -1.0f, 0.0f, 1.0f, 1.0f, // top-left
//			0.5f, -0.5f, 0.5f, 0.0f, -1.0f, 0.0f, 1.0f, 0.0f,// bottom-left
//			0.5f, -0.5f, 0.5f, 0.0f, -1.0f, 0.0f, 1.0f, 0.0f, // bottom-left
//			-0.5f, -0.5f, 0.5f, 0.0f, -1.0f, 0.0f, 0.0f, 0.0f, // bottom-right
//			-0.5f, -0.5f, -0.5f, 0.0f, -1.0f, 0.0f, 0.0f, 1.0f, // top-right
//			// Top face
//			-0.5f, 0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f,// top-left
//			0.5f, 0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, // bottom-right
//			0.5f, 0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f, // top-right     
//			0.5f, 0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, // bottom-right
//			-0.5f, 0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f,// top-left
//			-0.5f, 0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f // bottom-left        
//		};
//
//		glGenVertexArrays(1, &cubeVao);
//		glGenBuffers(1, &cubeVbo);
//		glBindBuffer(GL_ARRAY_BUFFER, cubeVbo);
//		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//		glBindVertexArray(cubeVao);
//		glEnableVertexAttribArray(0);
//		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)0);
//		glEnableVertexAttribArray(1);
//		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
//		glEnableVertexAttribArray(2);
//		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));
//		glBindBuffer(GL_ARRAY_BUFFER, 0);
//		glBindVertexArray(0);
//	}
//
//	glBindVertexArray(cubeVao);
//	glDrawArrays(GL_TRIANGLES, 0, 36);
//	glBindVertexArray(0);
//}
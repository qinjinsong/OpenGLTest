//#include <string>
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
////gl includes
//#include "Shader.h"
//#include "Camera.h"
//
//
//void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
//void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
//void mouse_callback(GLFWwindow* window, double xpos, double ypos);
//void do_movement();
//GLuint loadTexture(const GLchar* path, GLboolean alpha = false);
//void renderScene(Shader shader);
//void renderQuad();
//void renderCube();
//
//const GLuint WIDTH = 800, HEIGHT = 600;
//Camera camera(glm::vec3(0.0f, 0.0f, 3.0f));
//bool keys[1024];
//GLfloat lastX = WIDTH / 2, lastY = HEIGHT / 2;
//bool firstMouse = true;
//
//GLfloat deltatime = 0.0f;
//GLfloat lastFrame = 0.0;
//
//GLboolean bloom = true;
//GLfloat exposure = 0.1f;
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
//	glGetError();
//	
//	glViewport(0, 0, WIDTH, HEIGHT);
//	
//	glEnable(GL_DEPTH_TEST);
//	
//	Shader shader("glsl/vBloom.glsl", "glsl/fBloom.glsl");
//	Shader shaderLight("glsl/vBloom.glsl", "glsl/fLightBox.glsl");
//	Shader shaderBlur("glsl/vBlur.glsl", "glsl/fBlur.glsl");
//	Shader shaderBloomFinal("glsl/vBloomFinal.glsl", "glsl/fBloomFinal.glsl");
//
//	GLuint woodTexture = loadTexture("texture/wood.png");
//	GLuint containerTexture = loadTexture("texture/container2.png");
//
//	//configure floating point framebuffers
//	GLuint hdrFbo;
//	glGenFramebuffers(1, &hdrFbo);
//	glBindFramebuffer(GL_FRAMEBUFFER, hdrFbo);
//	//create 2 floating point color buffers
//	GLuint colorBuffers[2];
//	glGenTextures(2, colorBuffers);
//	for (int i=0; i<2; i++)
//	{
//		glBindTexture(GL_TEXTURE_2D, colorBuffers[i]);
//		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA16F, WIDTH, HEIGHT, 0, GL_RGBA, GL_FLOAT, NULL);
//		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
//		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
//		//attach texture to framebuffer
//		glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0 + i, GL_TEXTURE_2D, colorBuffers[i], 0);
//	}
//	//create and attach depth buffer (renderbuffer)
//	GLuint depthRbo;
//	glGenRenderbuffers(1, &depthRbo);
//	glBindRenderbuffer(GL_RENDERBUFFER, depthRbo);
//	glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT, WIDTH, HEIGHT);
//	glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, depthRbo);
//	GLuint attachments[2] = {GL_COLOR_ATTACHMENT0, GL_COLOR_ATTACHMENT1};
//	glDrawBuffers(2, attachments);
//	if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
//		printf("1, framebuffer not complete...");
//	glBindFramebuffer(GL_FRAMEBUFFER, 0);
//
//	//ping-pong-framebuffer for bluring
//	GLuint pingpongFbo[2];
//	GLuint pingpongColorbuffers[2];
//	glGenFramebuffers(2, pingpongFbo);
//	glGenTextures(2, pingpongColorbuffers);
//	for (int i=0; i<2; i++)
//	{
//		glBindFramebuffer(GL_FRAMEBUFFER, pingpongFbo[i]);
//		glBindTexture(GL_TEXTURE_2D, pingpongColorbuffers[i]);
//		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA16F, WIDTH, HEIGHT, 0, GL_RGBA, GL_FLOAT, NULL);
//		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
//		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
//		glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, pingpongColorbuffers[i], 0);
//		if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
//			printf("2, framebuffer not complete...");
//	}
//
//	//lighting info
//	vector<glm::vec3> lightPositions;
//	lightPositions.push_back(glm::vec3(0.0f, 0.5f, 1.5f));
//	lightPositions.push_back(glm::vec3(-4.0f, 0.5f, -3.0f));
//	lightPositions.push_back(glm::vec3(3.0f, 0.5f, 1.0f));
//	lightPositions.push_back(glm::vec3(-.8f, 2.4f, -1.0f));
//	// colors
//	vector<glm::vec3> lightColors;
//	lightColors.push_back(glm::vec3(5.0f, 5.0f, 5.0f));
//	lightColors.push_back(glm::vec3(10.0f, 0.0f, 0.0f));
//	lightColors.push_back(glm::vec3(0.0f, 0.0f, 15.0f));
//	lightColors.push_back(glm::vec3(0.0f, 5.0f, 0.0f));
//
//	shader.Use();
//	shader.SetInt("diffuseTexture", 0);
//	shaderBlur.Use();
//	shaderBlur.SetInt("image", 0);
//	shaderBloomFinal.Use();
//	shaderBloomFinal.SetInt("scene", 0);
//	shaderBloomFinal.SetInt("bloomBlur", 1);
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
//		//render scene into floating point framebuffer
//		glBindFramebuffer(GL_FRAMEBUFFER, hdrFbo);
//		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//		glm::mat4 projection = glm::perspective(camera.zoom, (float)WIDTH / (float)HEIGHT, 0.1f, 100.0f);
//		glm::mat4 view = camera.GetViewMatrix();
//		glm::mat4 model = glm::mat4(1.0f);
//		shader.Use();
//		shader.SetMat4("projection", projection);
//		shader.SetMat4("view", view);
//		glActiveTexture(GL_TEXTURE0);
//		glBindTexture(GL_TEXTURE_2D, woodTexture);
//		//set lighting uniform
//		for (int i = 0; i < lightPositions.size(); i++)
//		{
//			string name = "lights[" + to_string(i) + "].Position";
//			shader.SetVec3(name.c_str(), lightPositions[i]);
//			name = "lights[" + to_string(i) + "].Color";
//			shader.SetVec3(name.c_str(), lightColors[i]);
//		}
//		shader.SetVec3("viewPos", camera.position);
//
//		//create one large cube that acts as the floor
//		model = glm::mat4(1.0f);
//		model = glm::translate(model, glm::vec3(0.0f, -1.0f, 0.0f));
//		model = glm::scale(model, glm::vec3(12.5f, 0.5f, 12.5f));
//		shader.SetMat4("model", model);
//		renderCube();
//
//		//then create multiple cubes as the scenery
//		glBindTexture(GL_TEXTURE_2D, containerTexture);
//		model = glm::mat4(1.0f);
//		model = glm::translate(model, glm::vec3(0.0f, 1.5f, 0.0));
//		model = glm::scale(model, glm::vec3(0.5f));
//		shader.SetMat4("model", model);
//		renderCube();
//
//		model = glm::mat4(1.0f);
//		model = glm::translate(model, glm::vec3(2.0f, 0.0f, 1.0));
//		model = glm::scale(model, glm::vec3(0.5f));
//		shader.SetMat4("model", model);
//		renderCube();
//
//		model = glm::mat4(1.0f);
//		model = glm::translate(model, glm::vec3(-1.0f, -1.0f, 2.0));
//		model = glm::rotate(model, glm::radians(60.0f), glm::normalize(glm::vec3(1.0, 0.0, 1.0)));
//		shader.SetMat4("model", model);
//		renderCube();
//
//		model = glm::mat4(1.0f);
//		model = glm::translate(model, glm::vec3(0.0f, 2.7f, 4.0));
//		model = glm::rotate(model, glm::radians(23.0f), glm::normalize(glm::vec3(1.0, 0.0, 1.0)));
//		model = glm::scale(model, glm::vec3(1.25));
//		shader.SetMat4("model", model);
//		renderCube();
//
//		model = glm::mat4(1.0f);
//		model = glm::translate(model, glm::vec3(-2.0f, 1.0f, -3.0));
//		model = glm::rotate(model, glm::radians(124.0f), glm::normalize(glm::vec3(1.0, 0.0, 1.0)));
//		shader.SetMat4("model", model);
//		renderCube();
//
//		model = glm::mat4(1.0f);
//		model = glm::translate(model, glm::vec3(-3.0f, 0.0f, 0.0));
//		model = glm::scale(model, glm::vec3(0.5f));
//		shader.SetMat4("model", model);
//		renderCube();
//
//		//finally show all the light sources as bright cubes
//		shaderLight.Use();
//		shaderLight.SetMat4("projection", projection);
//		shaderLight.SetMat4("view", view);
//		for (int i=0; i<lightPositions.size(); i++)
//		{
//			model = glm::mat4(1.0f);
//			model = glm::translate(model, glm::vec3(lightPositions[i]));
//			model = glm::scale(model, glm::vec3(0.25f));
//			shaderLight.SetMat4("model", model);
//			shaderLight.SetVec3("lightColor", lightColors[i]);
//			renderCube();
//		}
//		glBindFramebuffer(GL_FRAMEBUFFER, 0);
//
//		//blur bright fragment with two-pass caussin Blur
//		bool horizontal = true, first_iteration = true;
//		GLuint amount = 10;
//		shaderBlur.Use();
//		for (GLuint i = 0; i < amount; i++)
//		{
//			glBindFramebuffer(GL_FRAMEBUFFER, pingpongColorbuffers[horizontal]);
//			shaderBlur.SetInt("horizontal", horizontal);
//			glBindTexture(GL_TEXTURE_2D, first_iteration ? colorBuffers[1] : pingpongColorbuffers[!horizontal]);
//			renderQuad();
//			horizontal = !horizontal;
//			if (first_iteration)
//				first_iteration = false;
//		}
//		glBindFramebuffer(GL_FRAMEBUFFER, 0);
//
//		//now render floating point color buffer to 2d quad tonemap HDR colors to default framebuffer's (clamped) color range
//		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//		shaderBloomFinal.Use();
//		glActiveTexture(GL_TEXTURE0);
//		glBindTexture(GL_TEXTURE_2D, colorBuffers[0]);
//		glActiveTexture(GL_TEXTURE1);
//		glBindTexture(GL_TEXTURE_2D, pingpongColorbuffers[!horizontal]);
//		shaderBloomFinal.SetInt("bloom", bloom);
//		shaderBloomFinal.SetFloat("exposure", exposure);
//		renderQuad();
//
//		//std::cout << "bloom: " << (bloom ? "on" : "off") << "| exposure: " << exposure << std::endl;
//
//		glfwSwapBuffers(window);
//	}
//
//	glfwTerminate();
//	return 0;
//}
//
//bool isKeySpaceStatus = false;
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
//			isKeySpaceStatus = false;
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
//	if (keys[GLFW_KEY_B] && !isKeySpaceStatus)
//	{
//		isKeySpaceStatus = true;
//		bloom = !bloom;
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
//GLuint quadVao, quadVbo;
//void renderQuad()
//{
//	if (quadVao == 0)
//	{
//		GLfloat quadVertices[] = {
//			// Positions        // Texture Coords
//			-1.0f, 1.0f, 0.0f, 0.0f, 1.0f,
//			-1.0f, -1.0f, 0.0f, 0.0f, 0.0f,
//			1.0f, 1.0f, 0.0f, 1.0f, 1.0f,
//			1.0f, -1.0f, 0.0f, 1.0f, 0.0f,
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
//	glDrawArrays(GL_TRIANGLE_STRIP, 0, 5);
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
//		glGenVertexArrays(1, &cubeVao);
//		glGenBuffers(1, &cubeVbo);
//		// Fill buffer
//		glBindBuffer(GL_ARRAY_BUFFER, cubeVbo);
//		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//		// Link vertex attributes
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
//	// Render Cube
//	glBindVertexArray(cubeVao);
//	glDrawArrays(GL_TRIANGLES, 0, 36);
//	glBindVertexArray(0);
//}
//
//#define glCheckError() glCheckError_(__FILE__, __LINE__)
//GLenum glCheckError_(const char* file, int line)
//{
//	GLenum errorCode;
//	while ((errorCode = glGetError()) != GL_NO_ERROR)
//	{
//		std::string error;
//		switch (errorCode)
//		{
//		case GL_INVALID_ENUM:                  error = "INVALID_ENUM"; break;
//		case GL_INVALID_VALUE:                 error = "INVALID_VALUE"; break;
//		case GL_INVALID_OPERATION:             error = "INVALID_OPERATION"; break;
//		case GL_STACK_OVERFLOW:                error = "STACK_OVERFLOW"; break;
//		case GL_STACK_UNDERFLOW:               error = "STACK_UNDERFLOW"; break;
//		case GL_OUT_OF_MEMORY:                 error = "OUT_OF_MEMORY"; break;
//		case GL_INVALID_FRAMEBUFFER_OPERATION: error = "INVALID_FRAMEBUFFER_OPERATION"; break;
//		}
//		std::cout << error << " | " << file << " (" << line << ")" << std::endl;
//	}
//	return errorCode;
//}
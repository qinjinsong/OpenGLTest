//#include <iostream>
//
//#define GLEW_STATIC
//#include <GL/glew.h>
//#include <GLFW/glfw3.h>
//
//#include "Shader.h"
//#include "Camera.h"
//
//#include <SOIL.h>
//
//#include <glm/glm.hpp>
//#include <glm/gtc/matrix_transform.hpp>
//#include <glm/gtc/type_ptr.hpp>
//#include <vector>
//
////检测窗口变化的回调函数
//void framebuffer_size_callback(GLFWwindow* window, int width, int height);
////鼠标移动镜头
//void mouse_callback(GLFWwindow* window, double xpos, double ypos);
////滚轮缩放
//void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
////检测输入
//void processInput(GLFWwindow* window);
////导入图
//GLuint loadTexture(const GLchar* path, GLboolean alpha = false);
////渲染场景
//void RenderScene(const Shader* shader);
//void RenderCube();
//
//// settings
//const unsigned int SCR_WIDTH = 800;
//const unsigned int SCR_HEIGHT = 600;
//
//
//#pragma region Camera Declare
////建立camera
//glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, -3.0f);
//Camera camera(cameraPos);
//#pragma endregion
//
//#pragma region Input Declare
////移动用
//float deltaTime = 0.0f; // 当前帧与上一帧的时间差
//float lastFrame = 0.0f; // 上一帧的时间
//
//void processInput(GLFWwindow* window) {
//	//看是不是按下esc键 然后退出
//	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
//		glfwSetWindowShouldClose(window, true);
//	}
//
//	//camera前后左右根据镜头方向移动
//	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
//		camera.KeyboardMove(FORWARD, deltaTime);
//	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
//		camera.KeyboardMove(BACKWARD, deltaTime);
//	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
//		camera.KeyboardMove(LEFT, deltaTime);
//	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
//		camera.KeyboardMove(RIGHT, deltaTime);
//}
//float lastX;
//float lastY;
//bool firstMouse = true;
//
//unsigned int planeVAO;
//
////鼠标控制镜头方向
//void mouse_callback(GLFWwindow* window, double xpos, double ypos) {
//	if (firstMouse == true)
//	{
//		lastX = xpos;
//		lastY = ypos;
//		firstMouse = false;
//	}
//	float deltaX, deltaY;
//	float sensitivity = 0.05f;
//
//	deltaX = (xpos - lastX) * sensitivity;
//	deltaY = (ypos - lastY) * sensitivity;
//
//	lastX = xpos;
//	lastY = ypos;
//
//	camera.MouseMove(deltaX, deltaY);
//
//};
////缩放
//float fov = 45.0f;
//
//void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
//{
//	if (fov >= 1.0f && fov <= 45.0f)
//		fov -= yoffset;
//	if (fov <= 1.0f)
//		fov = 1.0f;
//	if (fov >= 45.0f)
//		fov = 45.0f;
//}
//
//#pragma endregion
//
//
//
//int main() {
//
//#pragma region Open a Window
//	glfwInit();
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//
//	// Open GLFW Window
//	GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "My OpenGL Game", NULL, NULL);
//	if (window == NULL)
//	{
//		printf("Open window failed.");
//		glfwTerminate();
//		return -1;
//	}
//	glfwMakeContextCurrent(window);
//	// 关闭鼠标显示
//	//glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
//	// 回调函数监听鼠标
//	glfwSetCursorPosCallback(window, mouse_callback);
//
//	// 回调函数监听滚轮
//	glfwSetScrollCallback(window, scroll_callback);
//
//	// 每当窗口改变大小就会启动
//	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
//
//
//	// Init GLEW
//	glewExperimental = true;
//	if (glewInit() != GLEW_OK)
//	{
//		printf("Init GLEW failed.");
//		glfwTerminate();
//		return -1;
//	}
//
//	glEnable(GL_DEPTH_TEST);
//	glEnable(GL_CULL_FACE);
//	GLboolean shadows = true;
//	GLuint woodTexture;
//	GLuint planeVAO;
//#pragma endregion
//
//#pragma region Init Shader Program
//	// 所需要的shader
//	Shader* shader = new Shader("glsl/v_point_shadows.glsl", "glsl/f_point_shadows.glsl");
//	Shader* simpleDepthShader = new Shader("glsl/v_point_shadows_depth.glsl", "glsl/f_point_shadows_depth.glsl", "glsl/g_point_shadows_depth.glsl");
//#pragma endregion
//
//	// 设置材质
//	shader->Use();
//	glUniform1i(glGetUniformLocation(shader->program, "diffuseTexture"), 0);
//	glUniform1i(glGetUniformLocation(shader->program, "depthMap"), 1);
//	woodTexture = loadTexture("texture/floor.jpg");
//
//	// 宣告光源
//	glm::vec3 lightPos(0.0f, 0.0f, 0.0f);
//
//
//	// 设置深度贴图的FBO
//	GLuint depthMapFBO;
//	glGenFramebuffers(1, &depthMapFBO);
//	// 创建深度贴图
//	GLuint depthCubemap;
//	glGenTextures(1, &depthCubemap);
//	glBindTexture(GL_TEXTURE_CUBE_MAP, depthCubemap);
//	const GLuint SHADOW_WIDTH = 1024, SHADOW_HEIGHT = 1024;
//	for (GLuint i = 0; i < 6; ++i)
//		glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, GL_DEPTH_COMPONENT, SHADOW_WIDTH, SHADOW_HEIGHT, 0, GL_DEPTH_COMPONENT, GL_FLOAT, NULL);
//	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
//	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
//	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
//	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
//	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
//	// 把立方体贴图附加成帧缓冲的深度附件
//	glBindFramebuffer(GL_FRAMEBUFFER, depthMapFBO);
//	glFramebufferTexture(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, depthCubemap, 0);
//	glDrawBuffer(GL_NONE);
//	glReadBuffer(GL_NONE);
//	if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
//		std::cout << "Framebuffer not complete!" << std::endl;
//	glBindFramebuffer(GL_FRAMEBUFFER, 0);
//
//	// 渲染循环
//
//	while (!glfwWindowShouldClose(window))
//	{
//		// 显示相关的数据
//		float currentFrame = glfwGetTime();
//		deltaTime = currentFrame - lastFrame;
//		lastFrame = currentFrame;
//
//		// 检测输入
//
//		processInput(window);
//
//
//		// 0. 创建六个面光空间变换的矩阵
//		GLfloat aspect = (GLfloat)SHADOW_WIDTH / (GLfloat)SHADOW_HEIGHT;
//		GLfloat near = 1.0f;
//		GLfloat far = 25.0f;
//		glm::mat4 shadowProj = glm::perspective(glm::radians(90.0f), aspect, near, far);
//		std::vector<glm::mat4> shadowTransforms;
//		shadowTransforms.push_back(shadowProj * glm::lookAt(lightPos, lightPos + glm::vec3(1.0, 0.0, 0.0), glm::vec3(0.0, -1.0, 0.0)));
//		shadowTransforms.push_back(shadowProj * glm::lookAt(lightPos, lightPos + glm::vec3(-1.0, 0.0, 0.0), glm::vec3(0.0, -1.0, 0.0)));
//		shadowTransforms.push_back(shadowProj * glm::lookAt(lightPos, lightPos + glm::vec3(0.0, 1.0, 0.0), glm::vec3(0.0, 0.0, -1.0)));
//		shadowTransforms.push_back(shadowProj * glm::lookAt(lightPos, lightPos + glm::vec3(0.0, -1.0, 0.0), glm::vec3(0.0, 0.0, -1.0)));
//		shadowTransforms.push_back(shadowProj * glm::lookAt(lightPos, lightPos + glm::vec3(0.0, 0.0, 1.0), glm::vec3(0.0, -1.0, 0.0)));
//		shadowTransforms.push_back(shadowProj * glm::lookAt(lightPos, lightPos + glm::vec3(0.0, 0.0, -1.0), glm::vec3(0.0, -1.0, 0.0)));
//
//		// 1. Render scene to depth cubemap
//		glViewport(0, 0, SHADOW_WIDTH, SHADOW_HEIGHT);
//		glBindFramebuffer(GL_FRAMEBUFFER, depthMapFBO);
//		glClear(GL_DEPTH_BUFFER_BIT);
//		simpleDepthShader->Use();
//		for (GLuint i = 0; i < 6; ++i)
//			glUniformMatrix4fv(glGetUniformLocation(simpleDepthShader->program, ("shadowMatrices[" + std::to_string(i) + "]").c_str()), 1, GL_FALSE, glm::value_ptr(shadowTransforms[i]));
//		glUniform1f(glGetUniformLocation(simpleDepthShader->program, "far_plane"), far);
//		glUniform3f(glGetUniformLocation(simpleDepthShader->program, "lightPos"), lightPos.x, lightPos.y, lightPos.z);
//		RenderScene(simpleDepthShader);
//		glBindFramebuffer(GL_FRAMEBUFFER, 0);
//
//		// 2. Render scene as normal 
//		glViewport(0, 0, SCR_WIDTH, SCR_HEIGHT);
//		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//		shader->Use();
//		glm::mat4 projection = glm::perspective(glm::radians(fov), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
//		glm::mat4 view = camera.GetViewMatrix();
//
//		glUniformMatrix4fv(glGetUniformLocation(shader->program, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
//		glUniformMatrix4fv(glGetUniformLocation(shader->program, "view"), 1, GL_FALSE, glm::value_ptr(view));
//		// Set light uniforms
//		glUniform3f(glGetUniformLocation(shader->program, "lightPos"), lightPos.x, lightPos.y, lightPos.z);
//
//		glUniform3f(glGetUniformLocation(shader->program, "viewPos"), camera.position.x, camera.position.y, camera.position.z);
//
//		glUniform1i(glGetUniformLocation(shader->program, "shadows"), shadows);
//		glUniform1f(glGetUniformLocation(shader->program, "far_plane"), far);
//		glActiveTexture(GL_TEXTURE0);
//		glBindTexture(GL_TEXTURE_2D, woodTexture);
//		glActiveTexture(GL_TEXTURE1);
//		glBindTexture(GL_TEXTURE_CUBE_MAP, depthCubemap);
//		RenderScene(shader);
//
//		// Swap the buffers
//		glfwSwapBuffers(window);
//		glfwPollEvents();
//	}
//
//	glfwTerminate();
//	return 0;
//}
//
//
//void RenderScene(const Shader* shader)
//{
//	// Room cube
//	glm::mat4 model;
//	model = glm::scale(model, glm::vec3(14.0));
//	glUniformMatrix4fv(glGetUniformLocation(shader->program, "model"), 1, GL_FALSE, glm::value_ptr(model));
//	glDisable(GL_CULL_FACE); // Note that we disable culling here since we render 'inside' the cube instead of the usual 'outside' which throws off the normal culling methods.
//	glUniform1i(glGetUniformLocation(shader->program, "reverse_normals"), 1); // A small little hack to invert normals when drawing cube from the inside so lighting still works.
//	RenderCube();
//	glUniform1i(glGetUniformLocation(shader->program, "reverse_normals"), 0); // And of course disable it
//	glEnable(GL_CULL_FACE);
//	// Cubes
//	model = glm::mat4();
//	model = glm::translate(model, glm::vec3(3.0f, 2.0f, 0));
//	glUniformMatrix4fv(glGetUniformLocation(shader->program, "model"), 1, GL_FALSE, glm::value_ptr(model));
//	RenderCube();
//	model = glm::mat4();
//	model = glm::translate(model, glm::vec3(-3.0f, -2.0f, 0));
//	glUniformMatrix4fv(glGetUniformLocation(shader->program, "model"), 1, GL_FALSE, glm::value_ptr(model));
//	RenderCube();
//	model = glm::mat4();
//	model = glm::translate(model, glm::vec3(3.0f, 0, 2.0f));
//	glUniformMatrix4fv(glGetUniformLocation(shader->program, "model"), 1, GL_FALSE, glm::value_ptr(model));
//	RenderCube();
//	model = glm::mat4();
//	model = glm::translate(model, glm::vec3(-3.0f, 0, -2.0f));
//	glUniformMatrix4fv(glGetUniformLocation(shader->program, "model"), 1, GL_FALSE, glm::value_ptr(model));
//	RenderCube();
//	model = glm::mat4();
//	model = glm::translate(model, glm::vec3(0, -2.0f, -3.0f));
//	glUniformMatrix4fv(glGetUniformLocation(shader->program, "model"), 1, GL_FALSE, glm::value_ptr(model));
//	RenderCube();
//	model = glm::mat4();
//	model = glm::translate(model, glm::vec3(0, 2.0f, 3.0f));
//	glUniformMatrix4fv(glGetUniformLocation(shader->program, "model"), 1, GL_FALSE, glm::value_ptr(model));
//	RenderCube();
//}
//
//// RenderCube() Renders a 1x1 3D cube in NDC.
//GLuint cubeVAO = 0;
//GLuint cubeVBO = 0;
//void RenderCube()
//{
//	// Initialize (if necessary)
//	if (cubeVAO == 0)
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
//		glGenVertexArrays(1, &cubeVAO);
//		glGenBuffers(1, &cubeVBO);
//		// Fill buffer
//		glBindBuffer(GL_ARRAY_BUFFER, cubeVBO);
//		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//		// Link vertex attributes
//		glBindVertexArray(cubeVAO);
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
//	glBindVertexArray(cubeVAO);
//	glDrawArrays(GL_TRIANGLES, 0, 36);
//	glBindVertexArray(0);
//}
//
//void framebuffer_size_callback(GLFWwindow* window, int width, int height)
//{
//	//确保视口与新的窗口尺寸匹配；注意宽度和高度将大于屏幕显示上指定的尺寸
//	glViewport(0, 0, width, height);
//}
//
////加载一般的图片
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
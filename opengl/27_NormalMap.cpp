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
//void renderQuad();
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
//	Shader shader("glsl/vNormalMapping.glsl", "glsl/fNormalMapping.glsl");
//
//	GLuint diffuseMap = loadTexture("texture/brickwall.jpg");
//	GLuint normalMap = loadTexture("texture/brickwall_normal.jpg");
//
//	shader.Use();
//	shader.SetInt("diffuseMap", 0);
//	shader.SetInt("normalMap", 1);
//
//	glm::vec3 lightPos(0.5f, 1.0f, 0.3f);
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
//		//move light position over time
//		//lightPos.z = sin(glfwGetTime() * 0.5f) * 3.0f;
//
//		shader.Use();
//		glm::mat4 view = camera.GetViewMatrix();
//		glm::mat4 projection = glm::perspective(camera.zoom, (float)WIDTH / (float)HEIGHT, 0.1f, 100.0f);
//		shader.SetMat4("view", view);
//		shader.SetMat4("projection", projection);
//		glm::mat4 model;
//		model = glm::rotate(model, (GLfloat)glfwGetTime() * -1, glm::normalize(glm::vec3(1.0, 0.0, 1.0)));
//		shader.SetMat4("model", model);
//		shader.SetVec3("lightPos", lightPos);
//		shader.SetVec3("viewPos", camera.position);
//		glActiveTexture(GL_TEXTURE0);
//		glBindTexture(GL_TEXTURE_2D, diffuseMap);
//		glActiveTexture(GL_TEXTURE1);
//		glBindTexture(GL_TEXTURE_2D, normalMap);
//		renderQuad();
//
//		model = glm::mat4();
//		model = glm::translate(model, lightPos);
//		model = glm::scale(model, glm::vec3(0.5f));
//		shader.SetMat4("model", model);
//		renderQuad();
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
//		//positions
//		glm::vec3 pos1(-1.0, 1.0, 0.0);
//		glm::vec3 pos2(-1.0, -1.0, 0.0);
//		glm::vec3 pos3(1.0, -1.0, 0.0);
//		glm::vec3 pos4(1.0, 1.0, 0.0);
//		//texture coordinates
//		glm::vec2 uv1(0.0, 1.0);
//		glm::vec2 uv2(0.0, 0.0);
//		glm::vec2 uv3(1.0, 0.0);
//		glm::vec2 uv4(1.0, 1.0);
//		//normal vector
//		glm::vec3 nm(0.0, 0.0, 1.0);
//
//		//calculate tangent/bitangent vectors of both triangles
//		glm::vec3 tangent1, bitangent1;
//		glm::vec3 tangent2, bitangent2;
//		//triangle 1
//		glm::vec3 edge1 = pos2 - pos1;
//		glm::vec3 edge2 = pos3 - pos1;
//		glm::vec2 deltaUV1 = uv2 - uv1;
//		glm::vec2 deltaUV2 = uv3 - uv1;
//		GLfloat f = 1.0f / (deltaUV1.x * deltaUV2.y - deltaUV2.x * deltaUV1.y);
//
//		tangent1.x = f * (deltaUV2.y * edge1.x - deltaUV1.y * edge2.x);
//		tangent1.y = f * (deltaUV2.y * edge1.y - deltaUV1.y * edge2.y);
//		tangent1.z = f * (deltaUV2.y * edge1.z - deltaUV1.y * edge2.z);
//		tangent1 = glm::normalize(tangent1);
//
//		bitangent1.x = f * (-deltaUV2.x * edge1.x + deltaUV1.x * edge2.x);
//		bitangent1.y = f * (-deltaUV2.x * edge1.y + deltaUV1.x * edge2.y);
//		bitangent1.z = f * (-deltaUV2.x * edge1.z + deltaUV1.x * edge2.z);
//		bitangent1 = glm::normalize(bitangent1);
//
//		//triangle 2
//		edge1 = pos3 - pos1;
//		edge2 = pos4 - pos1;
//		deltaUV1 = uv3 - uv1;
//		deltaUV2 = uv4 - uv1;
//		f = 1.0f / (deltaUV1.x * deltaUV2.y - deltaUV2.x * deltaUV1.y);
//
//		tangent2.x = f * (deltaUV2.y * edge1.x - deltaUV1.y * edge2.x);
//		tangent2.y = f * (deltaUV2.y * edge1.y - deltaUV1.y * edge2.y);
//		tangent2.z = f * (deltaUV2.y * edge1.z - deltaUV1.y * edge2.z);
//		tangent2 = glm::normalize(tangent2);
//
//		bitangent2.x = f * (-deltaUV2.x * edge1.x + deltaUV1.x * edge2.x);
//		bitangent2.y = f * (-deltaUV2.x * edge1.y + deltaUV1.x * edge2.y);
//		bitangent2.z = f * (-deltaUV2.x * edge1.z + deltaUV1.x * edge2.z);
//		bitangent2 = glm::normalize(bitangent2);
//
//		GLfloat quadVertices[] = {
//			// Positions            // normal         // TexCoords  // Tangent                          // Bitangent
//			pos1.x, pos1.y, pos1.z, nm.x, nm.y, nm.z, uv1.x, uv1.y, tangent1.x, tangent1.y, tangent1.z, bitangent1.x, bitangent1.y, bitangent1.z,
//			pos2.x, pos2.y, pos2.z, nm.x, nm.y, nm.z, uv2.x, uv2.y, tangent1.x, tangent1.y, tangent1.z, bitangent1.x, bitangent1.y, bitangent1.z,
//			pos3.x, pos3.y, pos3.z, nm.x, nm.y, nm.z, uv3.x, uv3.y, tangent1.x, tangent1.y, tangent1.z, bitangent1.x, bitangent1.y, bitangent1.z,
//
//			pos1.x, pos1.y, pos1.z, nm.x, nm.y, nm.z, uv1.x, uv1.y, tangent2.x, tangent2.y, tangent2.z, bitangent2.x, bitangent2.y, bitangent2.z,
//			pos3.x, pos3.y, pos3.z, nm.x, nm.y, nm.z, uv3.x, uv3.y, tangent2.x, tangent2.y, tangent2.z, bitangent2.x, bitangent2.y, bitangent2.z,
//			pos4.x, pos4.y, pos4.z, nm.x, nm.y, nm.z, uv4.x, uv4.y, tangent2.x, tangent2.y, tangent2.z, bitangent2.x, bitangent2.y, bitangent2.z
//		};
//
//		glGenVertexArrays(1, &quadVao);
//		glGenBuffers(1, &quadVbo);
//		glBindVertexArray(quadVao);
//		glBindBuffer(GL_ARRAY_BUFFER, quadVbo);
//		glBufferData(GL_ARRAY_BUFFER, sizeof(quadVertices), &quadVertices, GL_STATIC_DRAW);
//		glEnableVertexAttribArray(0);
//		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 14 * sizeof(GLfloat), (GLvoid*)0);
//		glEnableVertexAttribArray(1);
//		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 14 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
//		glEnableVertexAttribArray(2);
//		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 14 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));
//		glEnableVertexAttribArray(3);
//		glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, 14 * sizeof(GLfloat), (GLvoid*)(8 * sizeof(GLfloat)));
//		glEnableVertexAttribArray(4);
//		glVertexAttribPointer(4, 3, GL_FLOAT, GL_FALSE, 14 * sizeof(GLfloat), (GLvoid*)(11 * sizeof(GLfloat)));
//	}
//
//	glBindVertexArray(quadVao);
//	glDrawArrays(GL_TRIANGLES, 0, 6);
//	glBindVertexArray(0);
//}
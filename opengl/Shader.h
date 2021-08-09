#pragma once

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include <GL/glew.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

using namespace std;

class Shader
{
public:
	GLuint program;
	Shader(const GLchar* vertexPath, const GLchar* fragmentPath, const char* geometryPath = nullptr);
	void Use();
	void SetBool(const GLchar* name, bool value);
	void SetInt(const GLchar* name, GLint value);
	void SetFloat(const GLchar* name, GLfloat value);
	void SetFloat3(const GLchar* name, GLfloat value1, GLfloat value2, GLfloat value3);
	void SetVec2(const GLchar* name, glm::vec2 value);
	void SetVec2(const GLchar* name, GLfloat x, GLfloat y);
	void SetVec3(const GLchar* name, glm::vec3 value);
	void SetVec3(const GLchar* name, GLfloat x, GLfloat y, GLfloat z);
	void SetMat2(const GLchar* name, glm::mat2 value);
	void SetMat3(const GLchar* name, glm::mat3 value);
	void SetMat4(const GLchar* name, glm::mat4 value);

private:
	void CheckCompileError(GLuint shader, string type);
};


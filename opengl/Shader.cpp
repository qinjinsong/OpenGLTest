#include "Shader.h"

Shader::Shader(const GLchar* vertexPath, const GLchar* fragmentPath, const char* geometryPath)
{
	string vertexCode, fragmentCode, geometryCode;
	ifstream vShaderFile, fShaderFile, gShaderFile;

	vShaderFile.exceptions(ifstream::failbit | ifstream::badbit);
	fShaderFile.exceptions(ifstream::failbit | ifstream::badbit);
	gShaderFile.exceptions(ifstream::failbit | ifstream::badbit);
	try
	{
		vShaderFile.open(vertexPath);
		fShaderFile.open(fragmentPath);
		stringstream vShaderStream, fShaderStream;
		vShaderStream << vShaderFile.rdbuf();
		fShaderStream << fShaderFile.rdbuf();
		vShaderFile.close();
		fShaderFile.close();
		vertexCode = vShaderStream.str();
		fragmentCode = fShaderStream.str();

		if (geometryPath != nullptr)
		{
			gShaderFile.open(geometryPath);
			stringstream gShaderStream;
			gShaderStream << gShaderFile.rdbuf();
			gShaderFile.close();
			geometryCode = gShaderStream.str();
		}
	}
	catch (ifstream::failure e)
	{
		cout << "error::shader::read shader file failed\n" << e.what() << endl;
	}

	const GLchar* vShaderCode = vertexCode.c_str();
	const GLchar* fShaderCode = fragmentCode.c_str();

	GLuint vertex, fragment;
	vertex = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertex, 1, &vShaderCode, NULL);
	glCompileShader(vertex);
	CheckCompileError(vertex, "vertex");
	fragment = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragment, 1, &fShaderCode, NULL);
	glCompileShader(fragment);
	CheckCompileError(fragment, "fragment");
	GLuint geometry;
	if (geometryPath != nullptr)
	{
		const GLchar* gShaderCode = geometryCode.c_str();
		geometry = glCreateShader(GL_GEOMETRY_SHADER);
		glShaderSource(geometry, 1, &gShaderCode, NULL);
		glCompileShader(geometry);
		CheckCompileError(geometry, "geometry");
	}

	this->program = glCreateProgram();
	glAttachShader(this->program, vertex);
	glAttachShader(this->program, fragment);
	glLinkProgram(program);
	CheckCompileError(this->program, "program");

	glDeleteShader(vertex);
	glDeleteShader(fragment);
	if (geometryPath != nullptr)
		glDeleteShader(geometry);
}

void Shader::Use()
{
	glUseProgram(this->program);
}

void Shader::SetBool(const GLchar* name, bool value)
{
	GLint loc = glGetUniformLocation(program, name);
	glUniform1i(loc, (int)value);
}

void Shader::SetInt(const GLchar* name, GLint value)
{
	glUniform1i(glGetUniformLocation(program, name), value);
}

void Shader::SetFloat(const GLchar* name, GLfloat value)
{
	GLint loc = glGetUniformLocation(program, name);
	glUniform1f(loc, value);
}

void Shader::SetFloat3(const GLchar* name, GLfloat value1, GLfloat value2, GLfloat value3)
{
	GLint loc = glGetUniformLocation(program, name);
	glUniform3f(loc, value1, value2, value3);
}

void Shader::SetVec2(const GLchar* name, glm::vec2 value)
{
	GLint loc = glGetUniformLocation(program, name);
	glUniform2fv(loc, 1, &value[0]);
}

void Shader::SetVec2(const GLchar* name, GLfloat x, GLfloat y)
{
	GLint loc = glGetUniformLocation(program, name);
	glUniform2f(loc, x, y);
}

void Shader::SetVec3(const GLchar* name, glm::vec3 value)
{
	GLint loc = glGetUniformLocation(program, name);
	glUniform3fv(loc, 1, &value[0]);
}

void Shader::SetVec3(const GLchar* name, GLfloat x, GLfloat y, GLfloat z)
{
	GLint loc = glGetUniformLocation(program, name);
	glUniform3f(loc, x, y, z);
}

void Shader::SetMat2(const GLchar* name, glm::mat2 value)
{
	GLint loc = glGetUniformLocation(program, name);
	glUniformMatrix2fv(loc, 1, GL_FALSE, glm::value_ptr(value));
}

void Shader::SetMat3(const GLchar* name, glm::mat3 value)
{
	GLint loc = glGetUniformLocation(program, name);
	glUniformMatrix3fv(loc, 1, GL_FALSE, glm::value_ptr(value));
}

void Shader::SetMat4(const GLchar* name, glm::mat4 value)
{
	GLint loc = glGetUniformLocation(program, name);
	glUniformMatrix4fv(loc, 1, GL_FALSE, glm::value_ptr(value));
}

void Shader::CheckCompileError(GLuint shader, string type)
{
	GLint success;
	GLchar infoLog[1024];
	if (type != "program")
	{
		glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(shader, 1024, NULL, infoLog);
			cout << "error::shader compile failed, type: " << type << "\n" << infoLog << "\n--------------------\n" << endl;
		}
	}
	else
	{
		glGetProgramiv(shader, GL_LINK_STATUS, &success);
		if (!success)
		{
			glGetProgramInfoLog(shader, 1024, NULL, infoLog);
			cout << "error::program linking failed, type: " << type << "\n" << infoLog << "\n--------------------\n" << endl;
		}
	}
}
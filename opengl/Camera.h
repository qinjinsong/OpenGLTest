#pragma once

#include <vector>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

enum CameraMovement {
	FORWARD,
	BACKWARD,
	LEFT,
	RIGHT,
};

const GLfloat YAW = -90.0f;
const GLfloat PITCH = 0.0f;
const GLfloat SPEED = 3.0f;
const GLfloat SENSITIVITY = 0.05f;
const GLfloat ZOOM = 45.0f;

class Camera
{
public:
	//camera attributes
	glm::vec3 position;
	glm::vec3 front;
	glm::vec3 up;
	glm::vec3 right;
	glm::vec3 worldUp;
	//eular angles
	GLfloat yaw;
	GLfloat pitch;
	GLfloat speed;
	GLfloat sensitivity;
	GLfloat zoom;

	Camera(glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3 up = glm::vec3(0.0, 1.0f, 0.0f), GLfloat yaw = YAW, GLfloat pitch = PITCH)
		: front(glm::vec3(0.0f, 0.0f, -1.0f)), speed(SPEED), sensitivity(SENSITIVITY), zoom(ZOOM)
	{
		this->position = position;
		this->worldUp = up;
		this->yaw = yaw;
		this->pitch = pitch;
		this->UpdateVectors();
	}
	Camera(GLfloat posx, GLfloat posy, GLfloat posz, GLfloat upx, GLfloat upy, GLfloat upz, GLfloat yaw, GLfloat pitch)
		: front(glm::vec3(0.0f, 0.0f, -1.0f)), speed(SPEED), sensitivity(SENSITIVITY), zoom(ZOOM)
	{
		this->position = glm::vec3(posx, posy, posz);
		this->worldUp = glm::vec3(upx, upy, upz);
		this->yaw = yaw;
		this->pitch = pitch;
		this->UpdateVectors();
	}
	glm::mat4 GetViewMatrix()
	{
		return glm::lookAt(this->position, this->position + this->front, this->up);
	}
	void KeyboardMove(CameraMovement dir, GLfloat deltatime)
	{
		GLfloat velocity = this->speed * deltatime;
		if (dir == FORWARD)
			this->position += this->front * velocity;
		if(dir == BACKWARD)
			this->position -= this->front * velocity;
		if (dir == LEFT)
			this->position -= this->right * velocity;
		if (dir == RIGHT)
			this->position += this->right * velocity;

		// 7_Camera_t1
		//this->position.y = 0.0f;
	}
	void MouseMove(GLfloat xoffset, GLfloat yoffset, GLboolean constrainPitch = true)
	{
		xoffset *= this->sensitivity;
		yoffset *= this->sensitivity;

		this->yaw += xoffset;
		this->pitch += yoffset;

		if (constrainPitch)
		{
			if (this->pitch > 89.0f)
				this->pitch = 89.0;
			if (this->pitch < -89.0f)
				this->pitch = -89.0f;
		}

		this->UpdateVectors();
	}
	void MouseScroll(GLfloat yoffset)
	{
		if (this->zoom >= 1.0f && this->zoom <= 45.0f)
			this->zoom -= yoffset;
		if (this->zoom <= 1.0f)
			this->zoom = 1.0f;
		if (this->zoom >= 45.0f)
			this->zoom = 45.0f;
	}

private:
	void UpdateVectors()
	{
		glm::vec3 tmpFront;
		GLfloat yaw_radians = glm::radians(yaw);
		GLfloat pitch_radians = glm::radians(pitch);
		tmpFront.x = cos(yaw_radians) * cos(pitch_radians);
		tmpFront.y = sin(pitch_radians);
		tmpFront.z = sin(yaw_radians) * cos(pitch_radians);

		front = glm::normalize(tmpFront);
		right = glm::normalize(glm::cross(front, worldUp));
		up = glm::normalize(glm::cross(right, front));
	}
};


/*
#version 330 core
layout (location = 0) in vec3 position;
layout (location = 1) in vec2 texCoords;

out vec2 ourTexCoords;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
	ourTexCoords = texCoords;
	gl_Position = projection * view * model * vec4(position, 1.0f);
}
*/


//18_Cubemap2
#version 330 core
layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normal;

out vec3 ourNormal;
out vec3 ourPos;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
	ourNormal = mat3(transpose(inverse(model))) * normal;
	ourPos = vec3(model * vec4(position, 1.0));
	gl_Position = projection * view * model * vec4(position, 1.0);
}
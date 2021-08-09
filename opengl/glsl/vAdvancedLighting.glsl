#version 330 core
layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normal;
layout (location = 2) in vec2 texCoords;

out VS_OUT {
	vec3 ourPos;
	vec3 ourNormal;
	vec2 ourTexCoords;
} vs_out;

uniform mat4 projection;
uniform mat4 view;

void main()
{
	gl_Position = projection * view * vec4(position, 1.0f);
	vs_out.ourPos = position;
	vs_out.ourNormal = normal;
	vs_out.ourTexCoords = texCoords;
}
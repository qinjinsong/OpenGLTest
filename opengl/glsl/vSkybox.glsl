#version 330 core
layout (location = 0) in vec3 position;

out vec3 ourTexCoords;

uniform mat4 view;
uniform mat4 projection;

void main()
{
	ourTexCoords = position;
	vec4 pos = projection * view * vec4(position, 1.0f);
	gl_Position = pos.xyww;
}
#version 330 core
layout (location = 0) in vec3 position;
layout (location = 2) in vec2 texCoords;
layout (location = 3) in mat4 instanceMatrix;

out vec2 ourTexCoords;

uniform mat4 projection;
uniform mat4 view;

void main()
{
	ourTexCoords = texCoords;
	gl_Position = projection * view * instanceMatrix * vec4(position, 1.0f);
}
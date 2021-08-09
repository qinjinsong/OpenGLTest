/*
#version 330 core
layout (location = 0) in vec2 position;
layout (location = 1) in vec3 color;
layout (location = 2) in vec2 offset;

out vec3 ourColor;

void main()
{
	//gl_Position = vec4(position + offset, 0.0, 1.0);
	//ourColor = color;

	vec2 pos = position * (gl_InstanceID / 100.0f);
	gl_Position = vec4(pos + offset, 0.0f, 1.0f);
	ourColor = color;
}
*/

#version 330 core
layout (location = 0) in vec3 position;
layout (location = 2) in vec2 texCoords;

out vec2 ourTexCoords;

uniform mat4 projection;
uniform mat4 view;
uniform mat4 model;

void main()
{
	gl_Position = projection * view * model * vec4(position, 1.0f);
	ourTexCoords = vec2(texCoords.x, 1.0 - texCoords.y);
}
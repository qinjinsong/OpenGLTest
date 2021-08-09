//15_Model
/*
#version 330 core
layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normal;
layout (location = 2) in vec2 texCoords;

out vec2 ourTexCoords;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
	gl_Position = projection * view * model * vec4(position, 1.0f);
	ourTexCoords = vec2(texCoords.x, 1-texCoords.y);
}
*/



//15_Model_t1
#version 330 core
layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normal;
layout (location = 2) in vec2 texCoords;

out vec2 ourTexCoords;
out vec3 ourPos;
out vec3 ourNormal;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
	gl_Position = projection * view * model * vec4(position, 1.0f);
	ourPos = vec3(model * vec4(position, 1.0f));
	ourNormal = mat3(transpose(inverse(model))) * normal;
	ourTexCoords = vec2(texCoords.x, 1-texCoords.y);
}
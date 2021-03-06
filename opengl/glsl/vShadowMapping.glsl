#version 330 core
layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normal;
layout (location = 2) in vec2 texCoords;

out VS_OUT {
	vec3 ourPos;
	vec3 ourNormal;
	vec2 ourTexCoords;
	vec4 ourPosLightSpace;
} vs_out;

uniform mat4 projection;
uniform mat4 view;
uniform mat4 model;
uniform mat4 lightSpaceMatrix;

void main()
{
	vs_out.ourPos = vec3(model * vec4(position, 1.0));
	vs_out.ourNormal = transpose(inverse(mat3(model))) * normal;
	vs_out.ourTexCoords = vec2(texCoords.x, 1.0 - texCoords.y);
	vs_out.ourPosLightSpace = lightSpaceMatrix * vec4(vs_out.ourPos, 1.0);
	gl_Position = projection * view * model * vec4(vs_out.ourPos, 1.0);
}
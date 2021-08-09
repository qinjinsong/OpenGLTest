/*
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
uniform mat4 model;
uniform bool reverse_normals;

void main()
{
	vs_out.ourPos = vec3(model * vec4(position, 1.0));
	if (reverse_normals)
		vs_out.ourNormal = transpose(inverse(mat3(model))) * (-1.0 * normal);
	else
		vs_out.ourNormal = transpose(inverse(mat3(model))) * normal;
	vs_out.ourTexCoords = vec2(texCoords.x, 1.0 - texCoords.y);
	gl_Position = projection * view * model * vec4(position, 1.0);
}
*/



#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;
layout (location = 2) in vec2 aTexCoords;

out vec2 TexCoords;

out VS_OUT {
    vec3 FragPos;
    vec3 Normal;
    vec2 TexCoords;
} vs_out;

uniform mat4 projection;
uniform mat4 view;
uniform mat4 model;

uniform bool reverse_normals;

void main()
{
    vs_out.FragPos = vec3(model * vec4(aPos, 1.0));
    if(reverse_normals) // a slight hack to make sure the outer large cube displays lighting from the 'inside' instead of the default 'outside'.
        vs_out.Normal = transpose(inverse(mat3(model))) * (-1.0 * aNormal);
    else
        vs_out.Normal = transpose(inverse(mat3(model))) * aNormal;
    vs_out.TexCoords = aTexCoords;
    gl_Position = projection * view * model * vec4(aPos, 1.0);
}
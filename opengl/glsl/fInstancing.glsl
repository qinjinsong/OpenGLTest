/*
#version 330 core
in vec3 ourColor;

out vec4 color;

void main()
{
	color = vec4(ourColor, 1.0);
}
*/


#version 330 core
in vec2 ourTexCoords;

out vec4 color;

uniform sampler2D texture_diffuse1;

void main()
{
	color = texture(texture_diffuse1, ourTexCoords);
}
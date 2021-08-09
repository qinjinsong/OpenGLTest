#version 330 core
in vec2 ourTexCoords;

out vec4 color;

uniform sampler2D texture1;

void main()
{
	/*
	vec4 ret = texture(texture1, ourTexCoords);
	if(ret.a < 0.1)
		discard;
	color = ret;
	*/

	color = texture(texture1, ourTexCoords);
}
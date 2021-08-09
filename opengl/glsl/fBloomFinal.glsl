#version 330 core
layout (location = 0) out vec4 color;

in vec2 ourTexCoords;

uniform sampler2D scene;
uniform sampler2D bloomBlur;
uniform bool bloom;
uniform float exposure;

void main()
{
	const float gamma = 2.2;
	vec3 hdrColor = texture(scene, ourTexCoords).rgb;
	if(bloom)
	{
		vec3 bloomColor = texture(bloomBlur, ourTexCoords).rgb;
		hdrColor += bloomColor;
	}
	vec3 result = vec3(1.0) - exp(-hdrColor * exposure);
	result = pow(result, vec3(1.0 / gamma));
	color = vec4(result, 1.0);
}
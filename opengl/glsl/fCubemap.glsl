/*
#version 330 core
in vec2 ourTexCoords;

out vec4 color;

uniform sampler2D texture1;

void main()
{
	color = texture(texture1, ourTexCoords);
}
*/


//18_Cubemap2
#version 330 core
in vec3 ourNormal;
in vec3 ourPos;

out vec4 color;

uniform vec3 cameraPos;
uniform samplerCube skybox;

void main()
{
	/*
	//reflection
	vec3 I = normalize(ourPos - cameraPos);
	vec3 R = reflect(I, normalize(ourNormal));
	color = vec4(texture(skybox, R).rgb, 1.0);
	*/

	//refraction
	float ratio = 1.00 / 1.52;
	vec3 I = normalize(ourPos - cameraPos);
	vec3 R = refract(I, normalize(ourNormal), ratio);
	color = vec4(texture(skybox, R).rgb, 1.0);
}
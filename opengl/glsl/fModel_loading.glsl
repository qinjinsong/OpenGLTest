//15_Model
/*
#version 330 core
in vec2 ourTexCoords;

out vec4 color;

uniform sampler2D texture_diffuse1;

void main()
{
	color = vec4(texture(texture_diffuse1, ourTexCoords));
}
*/



//15_Model_t1
#version 330
struct Material {
	sampler2D texture_diffuse1;
	sampler2D texture_specular1;
	float shininess;
};

struct PointLight {
	vec3 position;
	float constant;
	float linear;
	float quadratic;
	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
};

#define NR_POINT_LIGHTS 2

in vec3 ourPos;
in vec3 ourNormal;
in vec2 ourTexCoords;

out vec4 color;

uniform vec3 viewPos;
uniform PointLight pointLights[NR_POINT_LIGHTS];
uniform Material material;

vec3 CalcPointLight(PointLight light, Material mat, vec3 normal, vec3 fragPos, vec3 viewDir);

void main()
{
	vec3 result;
	vec3 viewDir = normalize(viewPos - ourPos);
	vec3 norm = normalize(ourNormal);

	for(int i=0; i< NR_POINT_LIGHTS; i++)
		result += CalcPointLight(pointLights[i], material, norm, ourPos, viewDir);

	color = vec4(result, 1.0f);
}

vec3 CalcPointLight(PointLight light, Material mat, vec3 normal, vec3 fragPos, vec3 viewDir)
{
	vec3 lightDir = normalize(light.position - fragPos);
	float diff = max(dot(normal, lightDir), 0.0f);
	vec3 reflectDir = reflect(-lightDir, normal);
	float spec = pow(max(dot(viewDir, reflectDir), 0.0), mat.shininess);
	float distance = length(light.position - fragPos);
	float attenuation = 1.0f / (light.constant + light.linear * distance + light.quadratic * (distance * distance));

	vec3 ambient = light.ambient * vec3(texture(mat.texture_diffuse1, ourTexCoords));
	vec3 diffuse = light.diffuse * diff * vec3(texture(mat.texture_diffuse1, ourTexCoords));
	vec3 specular = light.specular * spec * vec3(texture(mat.texture_specular1, ourTexCoords));

	ambient *= attenuation;
	diffuse *= attenuation;
	specular *= attenuation;

	return (ambient + diffuse + specular); 
}
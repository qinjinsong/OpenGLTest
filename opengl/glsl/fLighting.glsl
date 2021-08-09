// 9_Color
//#version 330 core
//out vec4 color;

//uniform vec3 objectColor;
//uniform vec3 lightColor;

//void main()
//{
	//color = vec4(lightColor * objectColor, 1.0f);
//}


// 10_LightBase
//#version 330 core
//in vec3 ourNormal;
//in vec3 ourPos;

//out vec4 color;

//uniform vec3 objectColor;
//uniform vec3 lightColor;
//uniform vec3 lightPos;
//uniform vec3 viewPos;

//void main()
//{
	//ambient
	//float ambientStrength = 0.1f;
	//vec3 ambient = ambientStrength * lightColor;

	//diffuse
	//vec3 norm = normalize(ourNormal);
	//vec3 lightDir = normalize(lightPos - ourPos);
	//float diff = max(dot(norm, lightDir), 0.0f);
	//vec3 diffuse = diff * lightColor;

	//specular
	//float specularStrength = 0.5f;
	//vec3 viewDir = normalize(viewPos - ourPos);
	//vec3 reflectDir = reflect(-lightDir, norm);
	//float spec = pow(max(dot(viewDir, reflectDir), 0.0f), 32);
	//vec3 specular = specularStrength * spec * lightColor;

	//vec3 result = (ambient + diffuse + specular) * objectColor;
	//color = vec4(result, 1.0f);
//}




// 10_LightBase_t3
//#version 330 core
//out vec4 color;

//in vec3 ourPos;
//in vec3 ourNormal;
//in vec3 ourLightPos;

//uniform vec3 lightColor;
//uniform vec3 objectColor;

//void main()
//{
	//ambient
	//float ambientStrength = 0.1;
	//vec3 ambient = ambientStrength * lightColor;

	//diffuse
	//vec3 norm = normalize(ourNormal);
	//vec3 lightDir = normalize(ourLightPos - ourPos);
	//float diff = max(dot(norm, lightDir), 0.0);
	//vec3 diffuse = diff * lightColor;

	//specular
	//float specularStrength = 0.5;
	//vec3 viewDir = normalize(-ourPos);// the viewer is always at (0,0,0) in view-space, so viewDir is (0,0,0) - Position => -Position
	//vec3 reflectDir = reflect(-lightDir, norm);
	//float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);
	//vec3 specular = specularStrength * spec * lightColor;

	//vec3 result = (ambient + diffuse + specular) * objectColor;
	//color = vec4(result, 1.0);
//}



// 10_lightBase_t4
//#version 330 core
//out vec4 color;

//in vec3 ourColor;

//uniform vec3 objectColor;

//void main()
//{
	//color = vec4(ourColor * objectColor, 1.0);
//}




 // 11_Material
/*
 #version 330 core
 struct Material {
	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
	float shininess;
 };

 struct Light {
	vec3 position;
	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
 };

 in vec3 ourPos;
 in vec3 ourNormal;

 out vec4 color;

 uniform vec3 viewPos;
 uniform Material material;
 uniform Light light;

 void main()
 {
	//ambient
	vec3 ambient = light.ambient * material.ambient;

	//diffuse
	vec3 norm = normalize(ourNormal);
	vec3 lightDir = normalize(light.position - ourPos);
	float diff = max(dot(norm, lightDir), 0.0);
	vec3 diffuse = light.diffuse * (diff * material.diffuse);

	//specular
	vec3 viewDir = normalize(viewPos - ourPos);
	vec3 reflectDir = reflect(-lightDir, norm);
	float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
	vec3 specular = light.specular * (spec * (material.specular));

	vec3 result = ambient + diffuse + specular;
	color = vec4(result, 1.0f);
 }
 */


// 12_LightTexture
/*
 #version 330 core
 struct Material {
	sampler2D diffuse;
	sampler2D specular;
	float shininess;
 };

 struct Light {
	vec3 position;
	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
 };

 in vec3 ourPos;
 in vec3 ourNormal;
 in vec2 ourTexCoord;

 out vec4 color;

 uniform vec3 viewPos;
 uniform Material material;
 uniform Light light;

 void main()
 {
	//ambient
	vec3 ambient = light.ambient * vec3(texture(material.diffuse, ourTexCoord));

	//diffuse
	vec3 norm = normalize(ourNormal);
	vec3 lightDir = normalize(light.position - ourPos);
	float diff = max(dot(norm, lightDir), 0.0);
	vec3 diffuse = light.diffuse * diff * vec3(texture(material.diffuse, ourTexCoord));

	//specular
	vec3 viewDir = normalize(viewPos - ourPos);
	vec3 reflectDir = reflect(-lightDir, norm);
	float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
	vec3 specular = light.specular * spec * vec3(texture(material.specular, ourTexCoord));

	// 12_LightTexture_t2
	//vec3 specular = light.specular * spec * (vec3(1.0) - vec3(texture(material.specular, ourTexCoord)));

	vec3 result = ambient + diffuse + specular;
	color = vec4(result, 1.0f);
 }
 */


 // 12_LightTexture_t4
 /*
 #version 330 core
 struct Material {
	sampler2D diffuse;
	sampler2D specular;
	sampler2D emission;
	float shininess;
 };

 struct Light {
	vec3 position;
	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
 };

 in vec3 ourPos;
 in vec3 ourNormal;
 in vec2 ourTexCoord;

 out vec4 color;

 uniform vec3 viewPos;
 uniform Material material;
 uniform Light light;

 void main()
 {
	//ambient
	vec3 ambient = light.ambient * vec3(texture(material.diffuse, ourTexCoord));

	//diffuse
	vec3 norm = normalize(ourNormal);
	vec3 lightDir = normalize(light.position - ourPos);
	float diff = max(dot(norm, lightDir), 0.0);
	vec3 diffuse = light.diffuse * diff * vec3(texture(material.diffuse, ourTexCoord));

	//specular
	vec3 viewDir = normalize(viewPos - ourPos);
	vec3 reflectDir = reflect(-lightDir, norm);
	float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
	vec3 specular = light.specular * spec * vec3(texture(material.specular, ourTexCoord));

	//emission
	vec3 emission = vec3(texture(material.emission, ourTexCoord));

	vec3 result = ambient + diffuse + specular + emission;
	color = vec4(result, 1.0f);
 }
 */



 //13_ThrowLight  Directional Light
 /*
 #version 330 core
 struct Material {
	sampler2D diffuse;
	sampler2D specular;
	float shininess;
 };

 struct Light {
	vec3 direction;
	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
 };

 in vec3 ourPos;
 in vec3 ourNormal;
 in vec2 ourTexCoord;

 out vec4 color;

 uniform vec3 viewPos;
 uniform Material material;
 uniform Light light;

 void main()
 {
	//ambient
	vec3 ambient = light.ambient * vec3(texture(material.diffuse, ourTexCoord));

	//diffuse
	vec3 norm = normalize(ourNormal);
	vec3 lightDir = normalize(-light.direction);
	float diff = max(dot(norm, lightDir), 0.0);
	vec3 diffuse = light.diffuse * diff * vec3(texture(material.diffuse, ourTexCoord));

	//specular
	vec3 viewDir = normalize(viewPos - ourPos);
	vec3 reflectDir = reflect(-lightDir, norm);
	float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
	vec3 specular = light.specular * spec * vec3(texture(material.specular, ourTexCoord));

	color = vec4(ambient + diffuse + specular, 1.0f);
 }
 */



  //13_ThrowLight  Point Light
  /*
  #version 330 core
  struct Material {
	sampler2D diffuse;
	sampler2D specular;
	float shininess;
  };

  struct Light {
	vec3 position;
	vec3 ambient;
	vec3 diffuse;
	vec3 specular;

	float constant;
	float linear;
	float quadratic;
  };

  in vec3 ourPos;
  in vec3 ourNormal;
  in vec2 ourTexCoord;

  out vec4 color;

  uniform vec3 viewPos;
  uniform Material material;
  uniform Light light;

  void main()
  {
	//ambient
	vec3 ambient = light.ambient * vec3(texture(material.diffuse, ourTexCoord));

	//diffuse
	vec3 norm = normalize(ourNormal);
	vec3 lightDir = normalize(light.position - ourPos);
	float diff = max(dot(norm, lightDir), 0.0);
	vec3 diffuse = light.diffuse * diff * vec3(texture(material.diffuse, ourTexCoord));

	//specular
	vec3 viewDir = normalize(viewPos - ourPos);
	vec3 reflectDir = reflect(-lightDir, norm);
	float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
	vec3 specular = light.specular * spec * vec3(texture(material.specular, ourTexCoord));

	//attenuation
	float distance = length(light.position - ourPos);
	float attenuation = 1.0f / (light.constant + light.linear * distance + light.quadratic * (distance * distance));

	ambient *= attenuation;
	diffuse *= attenuation;
	specular *= attenuation;

	color = vec4(ambient + diffuse + specular, 1.0f);
  }
  */




  //13_ThrowLight  Spotlight
/*
#version 330 core
struct Material {
	sampler2D diffuse;
	sampler2D specular;
	float shininess;
};

struct Light {
	vec3 position;
	vec3 direction;
	float cutOff;
	float outerCutOff;

	vec3 ambient;
	vec3 diffuse;
	vec3 specular;

	float constant;
	float linear;
	float quadratic;
};

in vec3 ourPos;
in vec3 ourNormal;
in vec2 ourTexCoord;

out vec4 color;

uniform vec3 viewPos;
uniform Material material;
uniform Light light;

void main()
{
	vec3 lightDir = normalize(light.position - ourPos);

	//check if lighting is inside the spotlight cone
	float theta = dot(lightDir, normalize(-light.direction));
	float epsilon = light.cutOff - light.outerCutOff;
	float intensity = clamp((theta - light.outerCutOff) / epsilon,0.0, 1.0);

	//ambient
	vec3 ambient = light.ambient * vec3(texture(material.diffuse, ourTexCoord));
		
	//diffuse
	vec3 norm = normalize(ourNormal);
	float diff = max(dot(norm, lightDir), 0.0);
	vec3 diffuse = light.diffuse * diff * vec3(texture(material.diffuse, ourTexCoord));

	//specular
	vec3 viewDir = normalize(viewPos - ourPos);
	vec3 reflectDir = reflect(-lightDir, norm);
	float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
	vec3 specular = light.specular * spec * vec3(texture(material.specular, ourTexCoord));

	diffuse *= intensity;
	specular *= intensity;

	//attenuation
	float distance = length(light.position - ourPos);
	float attenuation = 1.0f / (light.constant + light.linear * distance + light.quadratic * (distance * distance));

	diffuse *= attenuation;
	specular *= attenuation;

	color = vec4(ambient + diffuse + specular, 1.0f);
}
*/


//14_MoreLight
#version 330 core
struct Material {
	sampler2D diffuse;
	sampler2D specular;
	float shininess;
};

struct DirLight {
	vec3 direction;
	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
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

struct SpotLight {
	vec3 position;
	vec3 direction;
	float cutOff;
	float outerCutOff;
	float constant;
	float linear;
	float quadratic;
	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
};

#define NR_POINT_LIGHTS 4

in vec3 ourPos;
in vec3 ourNormal;
in vec2 ourTexCoord;

out vec4 color;

uniform vec3 viewPos;
uniform DirLight dirLight;
uniform PointLight pointLights[NR_POINT_LIGHTS];
uniform SpotLight spotLight;
uniform Material material;

vec3 CalcDirLight(DirLight light, vec3 normal, vec3 viewDir);
vec3 CalcPointLight(PointLight light, vec3 normal, vec3 fragPos, vec3 viewDir);
vec3 CalcSpotLight(SpotLight light, vec3 normal, vec3 fragPos, vec3 viewDir);

void main()
{
	vec3 norm = normalize(ourNormal);
	vec3 viewDir = normalize(viewPos - ourPos);

	//directional light
	vec3 result = CalcDirLight(dirLight, norm, viewDir);
	//point light
	for(int i=0; i < NR_POINT_LIGHTS; i++)
		result += CalcPointLight(pointLights[i], norm, ourPos, viewDir);

	//14_MoreLight_t1
	//spot light
	result += CalcSpotLight(spotLight, norm, ourPos, viewDir);

	color = vec4(result, 1.0);
}

vec3 CalcDirLight(DirLight light, vec3 normal, vec3 viewDir)
{
	vec3 lightDir = normalize(-light.direction);
	float diff = max(dot(normal, lightDir), 0.0);
	vec3 reflectDir = reflect(-lightDir, normal);
	float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);

	vec3 ambient = light.ambient * vec3(texture(material.diffuse, ourTexCoord));
	vec3 diffuse = light.diffuse * diff * vec3(texture(material.diffuse, ourTexCoord));
	vec3 specular = light.specular * spec * vec3(texture(material.specular, ourTexCoord));

	return (ambient + diffuse + specular);
}

vec3 CalcPointLight(PointLight light, vec3 normal, vec3 fragPos, vec3 viewDir)
{
	vec3 lightDir = normalize(light.position - fragPos);
	float diff = max(dot(normal, lightDir), 0.0);
	vec3 reflectDir = reflect(-lightDir, normal);
	float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
	float distance = length(light.position - fragPos);
    float attenuation = 1.0f / (light.constant + light.linear * distance + light.quadratic * (distance * distance)); 

	vec3 ambient = light.ambient * vec3(texture(material.diffuse, ourTexCoord));
	vec3 diffuse = light.diffuse * diff * vec3(texture(material.diffuse, ourTexCoord));
	vec3 specular = light.specular * spec * vec3(texture(material.specular, ourTexCoord));

	ambient *= attenuation;
	diffuse *= attenuation;
	specular *= attenuation;

	return (ambient + diffuse + specular);
}

vec3 CalcSpotLight(SpotLight light, vec3 normal, vec3 fragPos, vec3 viewDir)
{
	vec3 lightDir = normalize(light.position - fragPos);
	float diff = max(dot(normal, lightDir), 0.0);
	vec3 reflectDir = reflect(-lightDir, normal);
	float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
	float distance = length(light.position - fragPos);
	float attenuation = 1.0f / (light.constant + light.linear * distance + light.quadratic * (distance * distance));

	float theta = dot(lightDir, normalize(-light.direction));
	float epsilon = light.cutOff - light.outerCutOff;
	float intensity = clamp((theta - light.outerCutOff) / epsilon, 0.0, 1.0);

	vec3 ambient = light.ambient * vec3(texture(material.diffuse, ourTexCoord));
	vec3 diffuse = light.diffuse * diff * vec3(texture(material.diffuse, ourTexCoord));
	vec3 specular = light.specular * spec * vec3(texture(material.specular, ourTexCoord));

	ambient *= attenuation * intensity;
	diffuse *= attenuation * intensity;
	specular *= attenuation * intensity;

	return (ambient + diffuse + specular);
}
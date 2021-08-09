// 9_Color
//#version 330 core
//layout (location = 0) in vec3 position;

//uniform mat4 model;
//uniform mat4 view;
//uniform mat4 projection;

//void main()
//{
	//gl_Position = projection * view * model * vec4(position, 1.0f);
//}


// 10_LightBase
//#version 330 core
//layout (location = 0) in vec3 position;
//layout (location = 1) in vec3 normal;

//out vec3 ourNormal;
//out vec3 ourPos;

//uniform mat4 model;
//uniform mat4 view;
//uniform mat4 projection;

//void main()
//{
	//gl_Position = projection * view * model * vec4(position, 1.0f);
	//ourNormal = mat3(transpose(inverse(model))) * normal;
	//ourPos = vec3(model * vec4(position, 1.0f));
//}



// 10_LightBase_t3
//#version 330 core
//layout (location = 0) in vec3 position;
//layout (location = 1) in vec3 normal;

//out vec3 ourPos;
//out vec3 ourNormal;
//out vec3 ourLightPos;

//uniform vec3 lightPos;
//uniform mat4 model;
//uniform mat4 view;
//uniform mat4 projection;

//void main()
//{
	//gl_Position = projection * view * model vec4(position, 1.0f);
	//ourPos = vec3(view * model * vec4(ourPos, 1.0f));
	//ourNormal = mat3(transpose(inverse(view * model))) * ourNormal;
	//ourLightPos = vec3(view * vec4(lightPos, 1.0f));
//}



// 10_LightBase_t4
//#version 330 core
//layout (location = 0) in vec3 position;
//layout (location = 1) in vec3 normal;

//out vec3 ourColor;

//uniform vec3 lightPos;
//uniform vec3 viewPos;
//uniform vec3 lightColor;

//uniform mat4 model;
//uniform mat4 view;
//uniform mat4 projection;

//void main()
 //{
	//gl_Position = projection * view * model * vec4(position, 1.0);

	//gouraud shading 
	//vec3 tpos = vec3(model * vec4(position, 1.0));
	//vec3 tnor = mat3(transpose(inverse(model))) * normal;

	//ambient
	//float ambientStrength = 0.1;
	//vec3 ambient = ambientStrength * lightColor;

	//diffuse
	//vec3 norm = normalize(tnor);
	//vec3 lightDir = normalize(lightPos - tpos);
	//float diff = max(dot(norm, lightDir), 0.0);
	//vec3 diffuse = diff * lightColor;

	//specular
	//float specularStrength = 1.0;
	//vec3 viewDir = normalize(viewPos - tpos);
	//vec3 reflectDir = reflect(-lightDir, norm);
	//float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);
	//vec3 specular = specularStrength * spec * lightColor;
	
	//ourColor = ambient + diffuse + specular;
 //}



// 11_Material
/*
#version 330 core
layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normal;

out vec3 ourNormal;
out vec3 ourPos;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
	gl_Position = projection * view * model * vec4(position, 1.0f);
	ourNormal = mat3(transpose(inverse(model))) * normal;
	ourPos = vec3(model * vec4(position, 1.0f));
}
*/

// 12_LightTexture
/*
#version 330 core
layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normal;
layout (location = 2) in vec2 texCoord;

out vec3 ourNormal;
out vec2 ourTexCoord;
out vec3 ourPos;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
	gl_Position = projection * view * model * vec4(position, 1.0f);
	ourNormal = mat3(transpose(inverse(model))) * normal;
	ourPos = vec3(model * vec4(position, 1.0f));
	ourTexCoord = texCoord;
}
*/


//14_MoreLight
#version 330 core
layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normal;
layout (location = 2) in vec2 texCoord;

out vec3 ourNormal;
out vec3 ourPos;
out vec2 ourTexCoord;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
	gl_Position = projection * view * model *  vec4(position, 1.0f);
	ourPos = vec3(model * vec4(position, 1.0f));
	ourNormal = mat3(transpose(inverse(model))) * normal;
	ourTexCoord = texCoord;
}
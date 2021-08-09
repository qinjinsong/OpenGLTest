#version 330 core
in VS_OUT {
	vec3 ourPos;
	vec3 ourNormal;
	vec2 ourTexCoords;
} fs_in;

out vec4 color;

uniform sampler2D floorTexture;
uniform vec3 lightPos;
uniform vec3 viewPos;
uniform bool blinn;

void main()
{
	vec3 col = texture(floorTexture, fs_in.ourTexCoords).rgb;
	//ambient
	vec3 ambient = 0.05 * col;
	//diffuse
	vec3 lightDir = normalize(lightPos - fs_in.ourPos);
	vec3 normal = normalize(fs_in.ourNormal);
	float diff = max(dot(lightDir, normal), 0.0);
	vec3 diffuse = diff * col;
	//specular
	vec3 viewDir = normalize(viewPos - fs_in.ourPos);
	vec3 reflectDir = reflect(-lightDir, normal);
	float spec = 0.0;
	if(blinn)
	{
		vec3 halfwayDir = normalize(lightDir + viewDir);
		spec = pow(max(dot(normal, halfwayDir), 0.0), 32.0);
	}
	else
	{
		vec3 reflectDir = reflect(-lightDir, normal);
		spec = pow(max(dot(viewDir, reflectDir), 0.0), 8.0);
	}
	vec3 specular = vec3(0.3) * spec;

	color = vec4(ambient + diffuse + specular, 1.0f);
}
#version 330 core
in VS_OUT {
	vec3 ourPos;
	vec3 ourNormal;
	vec2 ourTexCoords;
	vec4 ourPosLightSpace;
} fs_in;

out vec4 color;

uniform sampler2D diffuseTexture;
uniform sampler2D shadowMap;
uniform vec3 lightPos;
uniform vec3 viewPos;

float ShadowCalculation(vec4 fragPosLightSpace)
{
    vec3 projCoords = fragPosLightSpace.xyz / fragPosLightSpace.w;
    projCoords = projCoords * 0.5 + 0.5;
    float closestDepth = texture(shadowMap, projCoords.xy).r;
    float currentDepth = projCoords.z;
    
    //float shadow = currentDepth > closestDepth ? 1.0 : 0.0;

    //float bias = 0.005;
    vec3 normal = normalize(fs_in.ourNormal);
    vec3 lightDir = normalize(lightPos - fs_in.ourPos);
    float bias = max(0.05 * (1.0 - dot(normal, lightDir)), 0.05);
    //float shadow = currentDepth - bias > closestDepth ? 1.0 : 0.0;

    float shadow = 0.0;
    vec2 texelSize = 1.0 / textureSize(shadowMap, 0);
    for(int x=-1; x<=1; ++x)
    {
        for(int y=-1; y <= 1; ++y)
        {
            float pcfDepth = texture(shadowMap, projCoords.xy + vec2(x,y) * texelSize).r;
            shadow += currentDepth - bias > pcfDepth ? 1.0 : 0.0;
        }
    }
    shadow /= 9.0;

    if(projCoords.z > 1.0)
        shadow = 0.0;

    return shadow;
}

 void main()
 {
    vec3 col = texture(diffuseTexture, fs_in.ourTexCoords).rgb;
    vec3 normal = normalize(fs_in.ourNormal);
    vec3 lightColor = vec3(0.8);
    //ambient
    vec3 ambient = 0.3 * col;
    //diffuse
    vec3 lightDir = normalize(lightPos - fs_in.ourPos);
    float diff = max(dot(lightDir, normal), 0.0);
    vec3 diffuse = diff * lightColor;
    //specular
    vec3 viewDir = normalize(viewPos - fs_in.ourPos);
    vec3 reflectDir = reflect(-lightDir, normal);
    float spec = 0.0;
    vec3 halfwayDir = normalize(lightDir + viewDir);
    spec = pow(max(dot(normal, halfwayDir), 0.0), 64.0);
    vec3 specular = spec * lightColor;
    //calculate shadow
    float shadow = ShadowCalculation(fs_in.ourPosLightSpace);
    vec3 lighting = (ambient + (1.0 - shadow) * (diffuse + specular)) * col;

    color = vec4(lighting, 1.0);
 }
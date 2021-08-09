/*
#version 330 core
in vec4 ourPos;

uniform vec3 lightPos;
uniform float far_plane;

void main()
{
	float lightDistance = length(ourPos.xyz - lightPos);
	float offset = lightDistance / far_plane;
	gl_FragDepth = offset;
}
*/



#version 330 core
in vec4 FragPos;

uniform vec3 lightPos;
uniform float far_plane;

void main()
{
    float lightDistance = length(FragPos.xyz - lightPos);
    
    // map to [0;1] range by dividing by far_plane
    lightDistance = lightDistance / far_plane;
    
    // write this as modified depth
    gl_FragDepth = lightDistance;
}
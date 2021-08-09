#version 330 core
in vec2 ourTexCoords;

out vec4 color;

uniform sampler2D depthMap;
uniform float near_plane;
uniform float far_plane;

float LinearizeDepth(float depth)
{
    float z = depth * 2.0 - 1.0;
    return (2.0 * near_plane * far_plane) / (far_plane + near_plane - z * (far_plane - near_plane));
}

 void main()
 {
    float depthValue = texture(depthMap, ourTexCoords).r;
    color = vec4(vec3(depthValue), 1.0);
 }
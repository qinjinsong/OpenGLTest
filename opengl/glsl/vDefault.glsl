//#version 330 core

//layout (location = 0) in vec3 position;
//layout (location = 1) in vec3 color;

//out vec3 ourColor;

//uniform float xOffset;

//void main()
//{
	//gl_Position = vec4(position, 1.0f);
	//gl_Position = vec4(position.x, -position.y, position.z, 1.0f);
	//gl_Position = vec4(position.x + xOffset, position.y, position.z, 1.0f);
	//ourColor = color;
//}




// 3_Shader_t2
//#version 330 core

//layout (location = 0) in vec3 position;
//layout (location = 1) in vec3 color;

//out vec3 ourPosition;
//uniform float xOffset;

//void main()
//{
	//gl_Position = vec4(position.x + xOffset, position.y, position.z, 1.0f);
	//gl_Position = vec4(position, 1.0f);
	//ourPosition = position;
//}




// 4_Texture
//#version 330 core

//layout (location = 0) in vec3 position;
//layout (location = 1) in vec3 color;
//layout (location = 2) in vec2 texCoord;

//out vec3 ourColor;
//out vec2 ourTexCoord;

//void main()
//{
	//gl_Position = vec4(position, 1.0f);
	//ourColor = color;
	//ourTexCoord = texCoord;
	//ourTexCoord = vec2(texCoord.x, 1.0 - texCoord.y);
//}




// 5_Transformation
//#version 330 core

//layout (location = 0) in vec3 position;
//layout (location = 1) in vec3 color;
//layout (location = 2) in vec2 texCoord;

//out vec3 ourColor;
//out vec2 ourTexCoord;

//uniform mat4 transform;

//void main()
//{
	//gl_Position = transform * vec4(position, 1.0f);
	//ourColor = color;
	//ourTexCoord = vec2(texCoord.x, 1.0 - texCoord.y);
//}




//6_CoordinateSystem
//#version 330 core
//layout (location = 0) in vec3 position;
//layout (location = 1) in vec3 color;
//layout (location = 2) in vec2 texCoord;

//out vec3 ourColor;
//out vec2 ourTexCoord;

//uniform mat4 model;
//uniform mat4 view;
//uniform mat4 projection;

//void main()
//{
	//gl_Position = projection * view * model * vec4(position, 1.0f);
	//ourColor = color;
	//ourTexCoord = vec2(texCoord.x, 1.0f - texCoord.y);
//}





// 7_Camera
#version 330 core
layout (location = 0) in vec3 position;
layout (location = 1) in vec3 color;
layout (location = 2) in vec2 texCoord;

out vec3 ourColor;
out vec2 ourTexCoord;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
	gl_Position = projection * view * model * vec4(position, 1.0f);
	ourColor = color;
	ourTexCoord = vec2(texCoord.x, 1.0f - texCoord.y);
}
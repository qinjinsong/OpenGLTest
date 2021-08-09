//#version 330 core

//in vec3 ourColor;

//out vec4 color;

//void main()
//{
	//color = vec4(ourColor, 1.0f);
//}




// 3_Shader_t2
//#version 330 core

//in vec3 ourPosition;
//out vec4 fragColor;

//void main()
//{
	//fragColor = vec4(ourPosition, 1.0f);
//}




//#version 330 core
//in vec3 ourColor;
//in vec2 ourTexCoord;

//out vec4 color;

//uniform float mixValue;
//uniform sampler2D ourTexture0;
//uniform sampler2D ourTexture1;

//void main()
//{
	//color = texture(ourTexture0, ourTexCoord) * vec4(ourColor, 1.0f);
	//color = texture(ourTexture1, ourTexCoord) * vec4(ourColor, 1.0f);
	//color = mix(texture(ourTexture0, ourTexCoord), texture(ourTexture1, ourTexCoord), 0.2) * vec4(ourColor, 1.0f);
	//color = mix(texture(ourTexture0, ourTexCoord), texture(ourTexture1, ourTexCoord), 0.2);

	// 4_Texture_t1
	//vec2 tmpTexCoord = vec2(1.0 - ourTexCoord.x, ourTexCoord.y);
	//color = mix(texture(ourTexture0, ourTexCoord), texture(ourTexture1, tmpTexCoord), 0.2);

	// 4_Texture_t4
	//color = mix(texture(ourTexture0, ourTexCoord), texture(ourTexture1, ourTexCoord), mixValue);
//}



//#version 330 core
//in vec3 ourColor;
//in vec2 ourTexCoord;

//out vec4 color;

//uniform sampler2D ourTexture0;
//uniform sampler2D ourTexture1;

//void main()
//{
	//color = mix(texture(ourTexture0, ourTexCoord), texture(ourTexture1, ourTexCoord), 0.2);
//}




// 6_CoordinateSystem
//#version 330 core
//in vec3 ourColor;
//in vec2 ourTexCoord;

//out vec4 color;

//uniform sampler2D ourTexture0;
//uniform sampler2D ourTexture1;

//void main()
//{
	//color = mix(texture(ourTexture0, ourTexCoord), texture(ourTexture1, ourTexCoord), 0.2);
	//color = mix(texture(ourTexture0, ourTexCoord), texture(ourTexture1, ourTexCoord), 0.2) * vec4(ourColor, 1.0f);
//}




// 7_Camera
#version 330 core
in vec3 ourColor;
in vec2 ourTexCoord;

out vec4 color;

uniform sampler2D ourTexture0;
uniform sampler2D ourTexture1;

void main()
{
	color = mix(texture(ourTexture0, ourTexCoord), texture(ourTexture1, ourTexCoord), 0.2) * vec4(ourColor, 1.0f);
}
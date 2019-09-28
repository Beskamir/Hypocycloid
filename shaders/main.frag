#version 430 core

in VertexData{
    vec2 mTexCoord;
    vec4 mColor;
} VertexIn;

out vec4 colour;

void main(void) {    	
	colour = VertexIn.mColor;
	//colour = vec4(1.0, 0.0, 0.0, 1.0);
}
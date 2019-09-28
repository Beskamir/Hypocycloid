#version 430 core

uniform mat4 modelView;
uniform mat4 ortho;

layout (location = 0) in vec3 vertex;
//layout (location = 1) in vec3 color;

out VertexData{
    vec2 mTexCoord;
    vec4 mColor;
} OutVertex;

void main(void) {
	OutVertex.mColor = vec4(1.0f, 0.f, 0.f, 1.0f);
	gl_Position = ortho * modelView * vec4(vertex, 1.0f);   
}

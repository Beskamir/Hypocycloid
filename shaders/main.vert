#version 430 core

uniform mat4 modelView;
uniform mat4 ortho;
uniform vec4 color;

layout (location = 0) in vec3 vertex;

out vec4 fragColor;
// out VertexData{
//     vec2 mTexCoord;
//     vec4 mColor;
// } OutVertex;

void main(void) {
	// OutVertex.mColor = vec4(1.0f, 0.f, 0.f, 1.0f);
    fragColor = color;
	gl_Position = ortho * modelView * vec4(vertex, 1.0f);   
}

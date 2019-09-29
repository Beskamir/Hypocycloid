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
	float vNormal = sqrt(vertex.x*vertex.x + vertex.y*vertex.y + vertex.z*vertex.z);
    fragColor = glm::vec4(color.x * color.w + (1-color.w) * vertex.z, color.y * color.w + (1-color.w) * abs(vertex.x/vNormal), color.z * color.w + (1-color.w) * abs(vertex.y/vNormal), color.w);
	gl_Position = ortho * modelView * vec4(vertex, 1.0f);   
}

#version 430 core

uniform mat4 modelView;
uniform mat4 ortho;

layout (location = 0) in vec3 vertex;

void main(void) {	
	gl_Position = ortho * modelView * vec4(vertex, 1.0);   
}

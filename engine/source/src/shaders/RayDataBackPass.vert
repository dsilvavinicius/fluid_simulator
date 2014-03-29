#version 330 core

uniform Matrices {
	mat4 modelView;
	mat4 projection;
}

in vec4 vertex;

out vec4 viewSpacePos;

void main() {
	viewSpacePos = modelView * vertex;
	gl_Position = projection * viewSpacePos;
}
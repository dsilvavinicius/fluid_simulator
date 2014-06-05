#version 330 core

uniform Uniforms {
	vec4 camPos;
};
out vec4 camToPixelDistance;
in vec4 viewSpacePos;

void main() {	
	camToPixelDistance.a = (0.f, 0.f, 0.f, distance(viewSpacePos, camPos));
}
#include <stdlib.h>
#include <stdio.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

int main(void) { 
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
 
	GLFWwindow* window = glfwCreateWindow(640, 480, "Simple example", NULL, NULL);
	if (!window) {
		fprintf(stderr, "Failed to create GLFW window\n");
		glfwTerminate();
		return -1;
	}
 
	glfwMakeContextCurrent(window);

	GLenum err = glewInit();
	if (err != GLEW_OK) {
		fprintf(stderr, "Error initializing GLEW.\n");
		glfwTerminate();
		return -1;
	}

	glClearColor(1.0, 0.0, 0.0, 1.0);
	while (!glfwWindowShouldClose(window)) {
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate();
	
	return 0;
}
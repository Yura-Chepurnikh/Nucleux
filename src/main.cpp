//#include <../third-party/glad/include/glad/gl.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <stdexcept>

int main() {
	try {
		if (!glfwInit()) {
			throw std::runtime_error("Failed to Initialize GLFW");
		}

		GLFWwindow* window = glfwCreateWindow(800, 800, "NucleuxPrime", nullptr, nullptr);
		if (!window) {
			throw std::runtime_error("Failed to create GLFW window");
		}

		glfwMakeContextCurrent(window);

		while (!glfwWindowShouldClose(window)) {
			glClear(GL_COLOR_BUFFER_BIT);	
			glfwPollEvents();
			glfwSwapBuffers(window);
		}

		glfwDestroyWindow(window);
		glfwTerminate();

	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl; 
		return -1;
	}
	return 0;
}
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

int main() {
// Initialize GLFW
// a -1 return value means an error occurred
// :: means the function is inside of std namespace
// << means push on to the stream (error type) 
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW\n";
        return -1;
    }

// Create settings for the window before creating it
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
// preprocessor directive to check if the platform is Apple
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

// Create the window 
// type(class/struct) * pointer_name = function_call 
// glfwCreateWindow creates a window object in memory and variable window points to it and it is GLFWwindow type
    GLFWwindow* window = glfwCreateWindow(800, 600, "Pipit Engine", nullptr, nullptr);
    if (!window) {
        std::cerr << "Failed to create window\n";
        glfwTerminate();
        return -1;
    }
// context is what OpenGL commands operate on and contains all the state for the window
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Failed to initialize GLAD\n";
        glfwDestroyWindow(window);
        glfwTerminate();
        return -1;
    }

    std::cout << "OpenGL version: " << glGetString(GL_VERSION) << '\n';

    while (!glfwWindowShouldClose(window)) {
        glViewport(0, 0, 800, 600);
        glClearColor(0.1f, 0.1f, 0.15f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
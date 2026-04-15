#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

//Graphics Pipeline:
// 1. Vertex Data: The vertices of the object are passed to the vertex shader.
// 2. Vertex Shader: Process vertices
// 3. Rasterizer: Convert geometry to pixels and fills them in
// 4. Fragment Shader: Process pixels with different intensity values

// Context: A structure that has state management for the graphics pipeline
// Buffer: A memory data structure that stores vertex data for individual frames 
/* Front/Back Buffer: Allows us to render a frame completly before showing 
there is no partial frame of new and old on the screen */
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
    int width = 800;
    int height = 600;
    GLFWwindow* window = glfwCreateWindow(width, height, "Pipit Engine", nullptr, nullptr);
    if (!window) {
        std::cerr << "Failed to create window\n";
        glfwTerminate();
        return -1;
    }

// context is what OpenGL commands operate on and contains all the state for the window
// attaches the context to the window
    glfwMakeContextCurrent(window);

// GLAD loader loads the OpenGL functions
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Failed to initialize GLAD\n";
        glfwDestroyWindow(window);
        glfwTerminate();
        return -1;
    }

// output the OpenGL version
    std::cout << "OpenGL version: " << glGetString(GL_VERSION) << '\n';

// glfwWindowShouldClose(window) returns true if user closes the window
// main render loop that runs until the window is closed
//viewport is mapping render coordinates [-1, 1] to window pixels [0, width] and [0, height]
// glClearColor selects background color, specifically to gray
// glClear applies the background color to the entire window for 1 frame
// glfwSwapBuffers swaps from front to back buffer which switches frames
// glfwPollEvents pauses for user input like clicking a button 
    while (!glfwWindowShouldClose(window)) {
        glViewport(0, 0, 800, 600);
        glClearColor(0.1f, 0.1f, 0.15f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

// After loop ends, clean up and exit
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
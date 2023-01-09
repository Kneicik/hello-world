#include <iostream>
#include <adder.h>
#include <GLFW/glfw3.h>

int main(int argc, char* argv[]){
    std::cout << "hello world!\n";
    std::cout << add(2345.2, 2345.7) << '\n';


    GLFWwindow *window;

    if( !glfwInit() )
    {
        fprintf( stderr, "Failed to initialize GLFW\n" );
        exit( EXIT_FAILURE );
    }
    window = glfwCreateWindow( 300, 300, "Gears", NULL, NULL );
    if (!window)
    {
        fprintf( stderr, "Failed to open GLFW window\n" );
        glfwTerminate();
        exit( EXIT_FAILURE );
    }

    while( !glfwWindowShouldClose(window) )
    {


        // Swap buffers
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
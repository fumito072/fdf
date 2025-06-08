#include "fdf.h"

void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods)
{
    (void)scancode;
    (void)mods;
    t_camera *camera = glfwGetWindowUserPointer(window);

    if (action == GLFW_PRESS || action == GLFW_REPEAT)
    {
        if (key == GLFW_KEY_LEFT)
            camera->offset_x -= 10;
        else if (key == GLFW_KEY_RIGHT)
            camera->offset_x += 10;
        else if (key == GLFW_KEY_UP)
            camera->offset_y -= 10;
        else if (key == GLFW_KEY_DOWN)
            camera->offset_y += 10;
    }
}
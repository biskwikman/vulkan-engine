#pragma once

#include <vulkan/vulkan_core.h>
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <string>
namespace kc_engine {

class KcWindow {

public:
    KcWindow(int w, int h, std::string name);
    ~KcWindow();

    KcWindow(const KcWindow &) = delete;
    KcWindow &operator=(const KcWindow &) = delete;
    
    bool shouldClose() { return glfwWindowShouldClose(window); }

    void createWindowSurface(VkInstance instance, VkSurfaceKHR *surface);
    
private:

    void initWindow();

    const int width;
    const int height;

    std::string windowName;
    GLFWwindow *window;
};
}

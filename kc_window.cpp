#include "kc_window.hpp"
#include <GLFW/glfw3.h>
#include <stdexcept>
#include <vulkan/vulkan_core.h>

namespace kc_engine {

KcWindow::KcWindow(int w, int h, std::string name) : width{w}, height{h}, windowName{name} {
    initWindow();
}

KcWindow::~KcWindow() {
    glfwDestroyWindow(window);
    glfwTerminate();
}

void KcWindow::initWindow() {
    glfwInit();
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    window = glfwCreateWindow(width, height, windowName.c_str(), nullptr, nullptr);
}

void KcWindow::createWindowSurface(VkInstance instance, VkSurfaceKHR *surface) {
    if (glfwCreateWindowSurface(instance, window, nullptr, surface) != VK_SUCCESS) {
        throw std::runtime_error("failed to create windows surface");
    }
}
}

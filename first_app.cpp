#include "first_app.hpp"

namespace kc_engine {

void FirstApp::run() {
    while(!kcWindow.shouldClose()) {
        glfwPollEvents();
    }   
}
}

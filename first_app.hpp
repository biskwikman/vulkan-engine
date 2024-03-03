#pragma once

#include "kc_window.hpp"

namespace kc_engine {
class FirstApp {
    
    public:
        static constexpr int WIDTH = 800;
        static constexpr int HEIGHT = 600;

        void run();

    private:
        KcWindow kcWindow{WIDTH, HEIGHT, "Hello, Vulkan!"};
};
}

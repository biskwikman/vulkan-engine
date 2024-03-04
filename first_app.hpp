#pragma once

#include "kc_window.hpp"
#include "kc_engine_pipeline.hpp"
#include "kc_device.hpp"
namespace kc_engine {
class FirstApp {
    
    public:
        static constexpr int WIDTH = 800;
        static constexpr int HEIGHT = 600;

        void run();

    private:
        KcWindow kcWindow{WIDTH, HEIGHT, "Hello, Vulkan!"};
        KcDevice kcDevice{kcWindow};
        KcEnginePipeline kcenginePipeline{
            kcDevice, "shaders/simple_shader.vert.spv",
            "shaders/simple_shader.frag.spv",
            KcEnginePipeline::defaultPipelineConfigInfo(WIDTH, HEIGHT)};
};
}

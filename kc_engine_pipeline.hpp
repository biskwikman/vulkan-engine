#pragma once

#include <string>
#include <vector>
#include <vulkan/vulkan_core.h>
#include "kc_device.hpp"

namespace kc_engine {

struct PipelineConfigInfo {};

class KcEnginePipeline {
    public:   
        KcEnginePipeline(
            KcDevice &device, 
            const std::string& vertFilepath, 
            const std::string& fragFilepath, 
            const PipelineConfigInfo& configInfo);
        ~KcEnginePipeline() {}
        KcEnginePipeline(const KcEnginePipeline&) = delete;
        void operator=(const KcEnginePipeline&) = delete;

        static PipelineConfigInfo defaultPipelineConfigInfo(uint32_t width, uint32_t height);

    private:
        static std::vector<char> readFile(const std::string& filepath);
        
        void createGraphicsPipeline(
            const std::string& vertFilepath, 
            const std::string& fragFilepath,
            const PipelineConfigInfo& configInfo);

        void createShaderModule(const std::vector<char>& code, VkShaderModule* shaderModule);

        KcDevice &kcDevice;
        VkPipeline graphicsPipeline;
        VkShaderModule vertShaderModule;
        VkShaderModule fragShaderModule;
};
}

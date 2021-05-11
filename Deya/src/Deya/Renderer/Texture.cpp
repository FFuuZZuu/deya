#include "dypch.h"
#include "Deya/Renderer/Texture.h"

#include "Deya/Renderer/Renderer.h"
#include "Platform/OpenGL/OpenGLTexture.h"

namespace Deya
{
    Ref<Texture2D> Texture2D::Create(const std::string& path)
    {
        switch (Renderer::GetAPI())
        {
            case RendererAPI::API::None:
                DY_CORE_ASSERT(false, "RendererAPI::None is not supported");
                return nullptr;
            case RendererAPI::API::OpenGL:
                return std::make_shared<OpenGLTexture2D>(path);
        }

        DY_CORE_ASSERT(false, "Unknown RendererAPI");
        return nullptr;
    }
}
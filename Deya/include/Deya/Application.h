#pragma once

#include "Deya/Core.h"

#include "Deya/LayerStack.h"
#include "Deya/Events/Event.h"
#include "Deya/Window.h"
#include "Deya/Events/ApplicationEvent.h"
#include "Deya/Renderer/VertexArray.h"
#include "Deya/Renderer/Shader.h"
#include "Deya/Renderer/Buffer.h"
#include "Deya/ImGui/ImGuiLayer.h"

namespace Deya 
{
    class DEYA_API Application
    {
    public:
        Application();
        virtual ~Application();

        void Run();

        void OnEvent(Event& e);

        void PushLayer(Layer* layer);
        void PushOverlay(Layer* layer);

        inline static Application& Get() { return *s_Instance; }
        inline Window& GetWindow() { return *m_Window; }
    private:
        bool OnWindowClose(WindowCloseEvent& e);

        std::unique_ptr<Window> m_Window;
        ImGuiLayer* m_ImGuiLayer;
        bool m_Running = true;
        LayerStack m_LayerStack;

        std::shared_ptr<Shader> m_Shader;
        std::shared_ptr<VertexArray> m_VertexArray;
        std::shared_ptr<VertexBuffer> m_VertexBuffer;
        std::shared_ptr<IndexBuffer> m_IndexBuffer;

        std::shared_ptr<VertexArray> m_MansVA;
    private:
        static Application* s_Instance;
    };

    // To be defined in CLIENT
    Application* CreateApplication();
}
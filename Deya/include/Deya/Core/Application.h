#pragma once

#include "Deya/Core/Core.h"

#include "Deya/Core/LayerStack.h"
#include "Deya/Events/Event.h"
#include "Deya/Core/Window.h"
#include "Deya/Events/ApplicationEvent.h"
#include "Deya/Renderer/VertexArray.h"
#include "Deya/Renderer/Shader.h"
#include "Deya/Renderer/Buffer.h"
#include "Deya/ImGui/ImGuiLayer.h"

#include "Deya/Core/Timestep.h"

#include "Deya/Renderer/OrthographicCamera.h"

namespace Deya 
{
    class DEYA_API Application
    {
    public:
        Application(const std::string& name = "Deya App");
        virtual ~Application();

        void Run();

        void OnEvent(Event& e);

        void PushLayer(Layer* layer);
        void PushOverlay(Layer* layer);

        inline static Application& Get() { return *s_Instance; }
        inline Window& GetWindow() { return *m_Window; }

        void Close();

        ImGuiLayer* GetImGuiLayer() { return m_ImGuiLayer; }
    private:
        bool OnWindowClose(WindowCloseEvent& e);
        bool OnWindowResize(WindowResizeEvent& e);
    private:
        std::unique_ptr<Window> m_Window;
        ImGuiLayer* m_ImGuiLayer;
        bool m_Running = true;
        bool m_Minimized = false;
        LayerStack m_LayerStack;
        float m_LastFrameTime = 0.0f;
    private:
        static Application* s_Instance;
    };

    // To be defined in CLIENT
    Application* CreateApplication();
}
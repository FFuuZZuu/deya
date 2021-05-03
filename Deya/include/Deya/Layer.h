#pragma once

#include "Deya/Core.h"
#include "Deya/Events/Event.h"

namespace Deya
{
    class DEYA_API Layer
    {
    public:
        Layer(const std::string& name = "Layer");
        virtual ~Layer();

        virtual void OnAttach() {}
        virtual void OnDetach() {}
        virtual void OnUpdate() {}
        virtual void OnImGuiRender() {}
        virtual void OnEvent(Event& event) {}

        inline const std::string& GetName() const { return m_DebugName; }
    protected:
        std::string m_DebugName; // ! Shouldnt be used in Release Builds
    };
}
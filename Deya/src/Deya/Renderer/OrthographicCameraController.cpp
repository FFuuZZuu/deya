#include "dypch.h"
#include "Deya/Renderer/OrthographicCameraController.h"

#include "Deya/Core/Input.h"
#include "Deya/Core/KeyCodes.h"

namespace Deya
{
    OrthographicCameraController::OrthographicCameraController(float aspectRatio, bool rotation)
        : m_AspectRatio(aspectRatio),
            m_Rotation(rotation),
            m_Bounds({ -m_AspectRatio * m_ZoomLevel, m_AspectRatio * m_ZoomLevel, -m_ZoomLevel, m_ZoomLevel }), 
            m_Camera(m_Bounds.Left, m_Bounds.Right, m_Bounds.Bottom, m_Bounds.Top) {}

    void OrthographicCameraController::OnUpdate(Timestep ts)
    {
        DY_PROFILE_FUNCTION();

        if (Input::IsKeyPressed(DY_KEY_A))
            m_CameraPosition.x -= m_CameraTranslationSpeed * ts;
        else if (Deya::Input::IsKeyPressed(DY_KEY_D))
            m_CameraPosition.x += m_CameraTranslationSpeed * ts;

        if (Input::IsKeyPressed(DY_KEY_W))
            m_CameraPosition.y += m_CameraTranslationSpeed * ts;
        else if (Input::IsKeyPressed(DY_KEY_S))
            m_CameraPosition.y -= m_CameraTranslationSpeed * ts;

        if (m_Rotation)
        {
            if (Input::IsKeyPressed(DY_KEY_Q))
                m_CameraRotation += m_CameraRotationSpeed * ts;
            else if (Input::IsKeyPressed(DY_KEY_E))
                m_CameraRotation -= m_CameraRotationSpeed * ts;

            m_Camera.SetRotation(m_CameraRotation);
        }
        
        m_Camera.SetPosition(m_CameraPosition);
    }

    void OrthographicCameraController::OnEvent(Event& e)
    {
        DY_PROFILE_FUNCTION();

        EventDispatcher dispatcher(e);
        dispatcher.Dispatch<MouseScrolledEvent>(DY_BIND_EVENT_FN(OrthographicCameraController::OnMouseScrolled));
        dispatcher.Dispatch<WindowResizeEvent>(DY_BIND_EVENT_FN(OrthographicCameraController::OnWindowResized));
    }

    void OrthographicCameraController::OnResize(float width, float height) 
    {
        m_AspectRatio = width / height;
        CalculateView();
    }

    void OrthographicCameraController::CalculateView() 
    {
        m_Bounds = { -m_AspectRatio * m_ZoomLevel, m_AspectRatio * m_ZoomLevel, -m_ZoomLevel, m_ZoomLevel };
        m_Camera.SetProjection(m_Bounds.Left, m_Bounds.Right, m_Bounds.Bottom, m_Bounds.Top);
    }


    bool OrthographicCameraController::OnMouseScrolled(MouseScrolledEvent& e)
    {
        DY_PROFILE_FUNCTION();

        m_ZoomLevel -= e.GetYOffset() * m_CameraZoomSpeed;
        m_ZoomLevel = std::max(m_ZoomLevel, 0.1f);
        CalculateView();

        return false;
    }

    bool OrthographicCameraController::OnWindowResized(WindowResizeEvent& e)
    {
        DY_PROFILE_FUNCTION();

        OnResize((float) e.GetWidth(), (float) e.GetHeight());

        return false;
    }
}
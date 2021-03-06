#pragma once

#include <Deya.h>

#include "ParticleSystem.h"

class Sandbox2D : public Deya::Layer
{
public:
    Sandbox2D();
    virtual ~Sandbox2D() = default;

    virtual void OnAttach() override;
    virtual void OnDetach() override;

    virtual void OnUpdate(Deya::Timestep ts) override;
    virtual void OnImGuiRender() override;
    virtual void OnEvent(Deya::Event& event) override;
private:
    Deya::OrthographicCameraController m_CameraController;

    Deya::Ref<Deya::Framebuffer> m_Framebuffer;

    Deya::Ref<Deya::Texture2D> m_MansTexture;
    Deya::Ref<Deya::Texture2D> m_MansSlimTexture;
    Deya::Ref<Deya::Texture2D> m_SpriteSheet;
    Deya::Ref<Deya::SubTexture2D> m_SpriteError;

    std::vector<ProfileResult> m_ProfileResults;

    glm::vec4 m_BackgroundColour = { 0.1f, 0.1f, 0.1f, 1.0f };
    glm::vec4 m_SquareColour = { 1.0f, 0.0f, 0.0f, 0.5f };
    glm::vec4 m_Square2Colour = { 0.0f, 0.0f, 1.0f, 0.5f };

    ParticleSystem m_ParticleSystem;
    ParticleProps m_Particle;

    float m_Angle = 0.0f;

    uint32_t m_MapWidth, m_MapHeight;
    std::unordered_map<char, Deya::Ref<Deya::SubTexture2D>> s_TextureMap;
};
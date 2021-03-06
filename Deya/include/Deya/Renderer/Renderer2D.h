#pragma once

#include "Deya/Renderer/OrthographicCamera.h"
#include "Deya/Renderer/Texture.h"
#include "Deya/Renderer/SubTexture2D.h"

#include "Deya/Renderer/Camera.h"
#include "Deya/Renderer/EditorCamera.h"

#include "Deya/Scene/Components.h"

namespace Deya
{
    class Renderer2D
    {
    public:
        static void Init();
        static void Shutdown();

        static void BeginScene(const Camera& camera, const glm::mat4& transform);
        static void BeginScene(const EditorCamera& camera); // DELETE
        static void BeginScene(const OrthographicCamera& camera); // DELETE
        static void EndScene();
        static void Flush();

        // Primitives

        // !=====Non-Rotated Quads===============================

        /**
         * Draws a rectangle (quad) with a certain colour
         * 
         * @param position The X,Y position of the quad
         * @param size The X,Y size of the quad (width, height)
         * @param colour The RGBA colour of the quad
         */
        static void DrawQuad(const glm::vec2& position, const glm::vec2& size, const glm::vec4& colour);

        /**
         * Draws a rectangle (quad) with a certain colour, at a certain Z depth
         * 
         * @param position The X,Y position of the quad + The Z depth of the quad
         * @param size The X,Y size of the quad (width, height)
         * @param colour The RGBA colour of the quad
         */
        static void DrawQuad(const glm::vec3& position, const glm::vec2& size, const glm::vec4& colour);

        /**
         * Draws a rectangle (quad) with a certain texture
         * 
         * @param position The X,Y position of the quad
         * @param size The X,Y size of the quad (width, height)
         * @param texture The texture of the quad (Texture2D)
         * @param tilingFactor (=1.0f) How much the texture should tile on both the X and Y axis.
         * @param tintColour (={1.0f, 1.0f, 1.0f, 1.0f}) An RGBA tint for the texture 
         */
        static void DrawQuad(const glm::vec2& position, const glm::vec2& size, const Ref<Texture2D>& texture, float tilingFactor = 1.0f, const glm::vec4& tintColour = glm::vec4(1.0f));

        /**
         * Draws a rectangle (quad) with a certain texture, at a certain Z depth
         * 
         * @param position The X,Y position of the quad + The Z depth of the quad
         * @param size The X,Y size of the quad (width, height)
         * @param texture The texture of the quad (Texture2D)
         * @param tilingFactor (=1.0f) How much the texture should tile on both the X and Y axis.
         * @param tintColour (={1.0f, 1.0f, 1.0f, 1.0f}) An RGBA tint for the texture 
         */
        static void DrawQuad(const glm::vec3& position, const glm::vec2& size, const Ref<Texture2D>& texture, float tilingFactor = 1.0f, const glm::vec4& tintColour = glm::vec4(1.0f));

        // !=====================================================

        // !=====Quads from Transform Matrix=====================

        /**
         * Draws a rectangle (quad) with a certain colour with a given transform matrix
         * 
         * @param transform A mat4 transform matrix
         * @param colour The RGBA colour for the quad
         */
        static void DrawQuad(const glm::mat4& transform, const glm::vec4& colour, int entityID = -1);

        /**
         * Draws a rectangle (quad) with a certain texture with a given transform matrix
         * 
         * @param transform A mat4 transform matrix
         * @param colour The RGBA colour for the quad
         * @param texture The texture of the quad (Texture2D)
         * @param tilingFactor (=1.0f) How much the texture should tile on both the X and Y axis.
         * @param tintColour (={1.0f, 1.0f, 1.0f, 1.0f}) An RGBA tint for the texture 
         */
        static void DrawQuad(const glm::mat4& transform, const Ref<Texture2D>& texture, float tilingFactor = 1.0f, const glm::vec4& tintColour = glm::vec4(1.0f), int entityID = -1);

        // !=====================================================

        // !=====Rotated Quads===================================

        /**
         * Draws a rectangle (quad) with a certain colour
         * 
         * @param position The X,Y position of the quad
         * @param rotation The rotation of the quad **IN RADIANS**
         * @param size The X,Y size of the quad (width, height)
         * @param colour The RGBA colour of the quad
         */
        static void DrawRotatedQuad(const glm::vec2& position, float rotation, const glm::vec2& size, const glm::vec4& colour);

        /**
         * Draws a rectangle (quad) with a certain colour, at a certain Z depth
         * 
         * @param position The X,Y position of the quad + The Z depth of the quad
         * @param rotation The rotation of the quad **IN RADIANS**
         * @param size The X,Y size of the quad (width, height)
         * @param colour The RGBA colour of the quad
         */
        static void DrawRotatedQuad(const glm::vec3& position, float rotation, const glm::vec2& size, const glm::vec4& colour);

        /**
         * Draws a rectangle (quad) with a certain texture
         * 
         * @param position The X,Y position of the quad
         * @param rotation The rotation of the quad **IN RADIANS**
         * @param size The X,Y size of the quad (width, height)
         * @param texture The texture of the quad (Texture2D)
         * @param tilingFactor (=1.0f) How much the texture should tile on both the X and Y axis.
         * @param tintColour (={1.0f, 1.0f, 1.0f, 1.0f}) An RGBA tint for the texture 
         */
        static void DrawRotatedQuad(const glm::vec2& position, float rotation, const glm::vec2& size, const Ref<Texture2D>& texture, float tilingFactor = 1.0f, const glm::vec4& tintColour = glm::vec4(1.0f));

        /**
         * Draws a rectangle (quad) with a certain texture, at a certain Z depth
         * 
         * @param position The X,Y position of the quad + The Z depth of the quad
         * @param rotation The rotation of the quad **IN RADIANS**
         * @param size The X,Y size of the quad (width, height)
         * @param texture The texture of the quad (Texture2D)
         * @param tilingFactor (=1.0f) How much the texture should tile on both the X and Y axis.
         * @param tintColour (={1.0f, 1.0f, 1.0f, 1.0f}) An RGBA tint for the texture 
         */
        static void DrawRotatedQuad(const glm::vec3& position, float rotation, const glm::vec2& size, const Ref<Texture2D>& texture, float tilingFactor = 1.0f, const glm::vec4& tintColour = glm::vec4(1.0f));

        // !=====================================================

        static void DrawSprite(const glm::mat4& transform, SpriteRendererComponent& src, int entityID);

        // Stats
        struct Statistics
        {
            uint32_t DrawCalls = 0;
            uint32_t QuadCount = 0;

            uint32_t GetTotalVertexCount() { return QuadCount * 4; }
            uint32_t GetTotalIndexCount() { return QuadCount * 6; }
        };

        static Statistics GetStats(); 
        static void ResetStats();
    private:
        static void FlushAndReset();
    };
}

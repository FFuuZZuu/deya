#pragma once

#include "Deya/Renderer/OrthographicCamera.h"
#include "Deya/Renderer/Texture.h"

namespace Deya
{
    class Renderer2D
    {
    public:
        static void Init();
        static void Shutdown();

        static void BeginScene(const OrthographicCamera& camera);
        static void EndScene();

        // Primitives
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
         * Draws a rectangle (quad) with a certain colour
         * 
         * @param position The X,Y position of the quad
         * @param size The X,Y size of the quad (width, height)
         * @param texture The texture of the quad (Texture2D)
         * @param tilingFactor (=1.0f) How much the texture should tile on both the X and Y axis.
         * @param tintColour (={1.0f, 1.0f, 1.0f, 1.0f}) An RGBA tint for the texture 
         */
        static void DrawQuad(const glm::vec2& position, const glm::vec2& size, const Ref<Texture2D>& texture, float tilingFactor = 1.0f, const glm::vec4& tintColour = glm::vec4(1.0f));

        /**
         * Draws a rectangle (quad) with a certain colour, at a certain Z depth
         * 
         * @param position The X,Y position of the quad + The Z depth of the quad
         * @param size The X,Y size of the quad (width, height)
         * @param texture The texture of the quad (Texture2D)
         * @param tilingFactor (=1.0f) How much the texture should tile on both the X and Y axis.
         * @param tintColour (={1.0f, 1.0f, 1.0f, 1.0f}) An RGBA tint for the texture 
         */
        static void DrawQuad(const glm::vec3& position, const glm::vec2& size, const Ref<Texture2D>& texture, float tilingFactor = 1.0f, const glm::vec4& tintColour = glm::vec4(1.0f));

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
         * Draws a rectangle (quad) with a certain colour
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
         * Draws a rectangle (quad) with a certain colour, at a certain Z depth
         * 
         * @param position The X,Y position of the quad + The Z depth of the quad
         * @param rotation The rotation of the quad **IN RADIANS**
         * @param size The X,Y size of the quad (width, height)
         * @param texture The texture of the quad (Texture2D)
         * @param tilingFactor (=1.0f) How much the texture should tile on both the X and Y axis.
         * @param tintColour (={1.0f, 1.0f, 1.0f, 1.0f}) An RGBA tint for the texture 
         */
        static void DrawRotatedQuad(const glm::vec3& position, float rotation, const glm::vec2& size, const Ref<Texture2D>& texture, float tilingFactor = 1.0f, const glm::vec4& tintColour = glm::vec4(1.0f));
    };
}
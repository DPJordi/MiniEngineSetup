#include "MiniginPCH.h"
#include "LivesComponent.h"
#include "Renderer.h"
#include "Font.h"
#include "Texture2D.h"
#include <SDL.h>
#include <SDL_ttf.h>


int dae::LivesComponent::m_Lives = 3;

dae::LivesComponent::LivesComponent(const std::shared_ptr<Font>& font, const Transform& transform)
	: m_Font(font)
	, m_Transform(transform)
{
}
dae::LivesComponent::~LivesComponent()
{
}
void dae::LivesComponent::Update()
{
	if (m_NeedsUpdate)
	{
		auto m_LivesInChar = std::to_string(m_Lives);
		const SDL_Color color = { 255,255,255 }; // only white text is supported now
		const auto surf = TTF_RenderText_Blended(m_Font->GetFont(), m_LivesInChar.c_str(), color);
		if (surf == nullptr)
		{
			throw std::runtime_error(std::string("Render text failed: ") + SDL_GetError());
		}
		auto texture = SDL_CreateTextureFromSurface(Renderer::GetInstance().GetSDLRenderer(), surf);
		if (texture == nullptr)
		{
			throw std::runtime_error(std::string("Create text texture from surface failed: ") + SDL_GetError());
		}
		SDL_FreeSurface(surf);
		m_Texture = std::make_shared<Texture2D>(texture);
		m_NeedsUpdate = false;
	}
}
void dae::LivesComponent::Render() const
{
	const auto pos = m_Transform.GetPosition();
	Renderer::GetInstance().RenderTexture(*m_Texture, pos.x, pos.y);
}
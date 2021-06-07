#include "MiniginPCH.h"
#include "Texture2DComponent.h"
#include "ResourceManager.h"
#include "Renderer.h"

dae::Texture2DComponent::Texture2DComponent(const std::string& fileName,const Transform& transform)
	:m_Transform(transform)
{
	m_pTexture = ResourceManager::GetInstance().LoadTexture(fileName);
}

dae::Texture2DComponent::~Texture2DComponent()
{
}

void dae::Texture2DComponent::Update()
{
}

void dae::Texture2DComponent::Render() const
{
	const auto pos = m_Transform.GetPosition();
	Renderer::GetInstance().RenderTexture(*m_pTexture, pos.x, pos.y);
}

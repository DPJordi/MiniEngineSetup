#pragma once
#include "BaseComponent.h"
#include "Transform.h"


namespace dae
{
	class Font;
	class Texture2D;
	class LivesComponent final : public BaseComponent
	{
	public:
		LivesComponent(const std::shared_ptr<Font>& font, const Transform& transform);
		~LivesComponent();

		void Update() override;
		void Render() const override;

	private:
		Transform m_Transform;
		std::shared_ptr<Font> m_Font;
		std::shared_ptr<Texture2D> m_Texture;
		static int m_Lives;
		bool m_NeedsUpdate = true;
	};
}




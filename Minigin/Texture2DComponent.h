#pragma once
#include "BaseComponent.h"
#include "GameObject.h"
#include "Transform.h"

class Texture2D;

namespace dae
{
	class Texture2DComponent : public BaseComponent
	{
	public:
		Texture2DComponent(const std::string& fileName, const Transform& transform);
		~Texture2DComponent();

		void Update() override;
		void Render() const override;

	private:
		std::shared_ptr<Texture2D> m_pTexture;
		const Transform m_Transform;

	};
}


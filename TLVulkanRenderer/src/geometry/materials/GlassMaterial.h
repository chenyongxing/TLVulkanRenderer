#pragma once
#include "Material.h"

class GlassMaterial : public Material
{
public:
	GlassMaterial() : Material() {};
	GlassMaterial(MaterialPacked packed, Texture* texture) :
		Material(packed, texture)
	{
		m_castShadow = true;
		m_receiveShadow = true;
		m_translucent = false;
	}

	ColorRGB EvaluateEnergy(
		const Intersection& isx,
		const Direction& lightDirection,
		const Ray& in,
		Ray& out,
		bool& shouldTerminate
	) override;
};


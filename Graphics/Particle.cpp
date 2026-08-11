#include "graphics_pch.h"
#include "Particle.h"

using namespace GE::Graphics;

bool Particle::operator<(const Particle& that) const
{
	// Sort in reverse order : far particles drawn first.
	return this->cameradistance > that.cameradistance;
}
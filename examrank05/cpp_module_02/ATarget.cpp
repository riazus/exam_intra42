#include "ATarget.hpp"

ATarget::ATarget()
{
}

ATarget::ATarget(std::string type)
{
    this->type = type;
}

ATarget::~ATarget()
{
}

const std::string &ATarget::getType() const
{
    return this->type;
}

void ATarget::getHitBySpell(ASpell const &spell) const
{
    std::cout << this->type << " has been " << spell.getEffects() << "!\n";
}
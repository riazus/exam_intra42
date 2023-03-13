#include "ASpell.hpp"

ASpell::ASpell(std::string name, std::string effect)
{
    this->name = name;
    this->effects = effect;
}

ASpell::ASpell(const ASpell &target) : name(target.name), effects(target.effects) {}

ASpell::~ASpell()
{
    
}

std::string const &ASpell::getName() const
{
    return this->name;
}

std::string const &ASpell::getEffects() const
{
    return this->effects; 
}

void ASpell::launch(ATarget const &target) const
{
    target.getHitBySpell((*this));
}

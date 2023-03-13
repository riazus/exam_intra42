#pragma once
#include "iostream"
#include "ATarget.hpp"

class ATarget;

class ASpell
{
    public : 
        ASpell(std::string name, std::string effect);
        ASpell(const ASpell &target);
        virtual ~ASpell();

        std::string const &getName() const;
        std::string const &getEffects() const;

        virtual ASpell *clone() const = 0;

        void launch(ATarget const &target) const;

    private :
        std::string name;
        std::string effects;

};
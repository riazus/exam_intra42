#pragma once
#include <iostream>
#include <string>
#include "ASpell.hpp"

class ASpell;

class ATarget
{
    public :
        ATarget();
        ATarget(std::string type);
        virtual ~ATarget();

        const std::string &getType() const;

        virtual ATarget *clone() const = 0;

        void getHitBySpell(ASpell const &spell) const;

    private :
        std::string type;
};
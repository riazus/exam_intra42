#include <string>
#include <iostream>
#include <vector>
#include "ATarget.hpp"
#include "ASpell.hpp"

class Warlock
{
    public :
        Warlock(std::string name, std::string title);
        virtual ~Warlock();

        std::string getName() const;
        std::string getTitle() const;

        void setTitle(std::string title);

        void introduce() const;

        void learnSpell(ASpell *spell);
        void forgetSpell(std::string const &spellName);
        void launchSpell(std::string const &spellName, ATarget const &target);

    private :
        std::string name;
        std::string title;
        std::vector<ASpell*> spells;
};
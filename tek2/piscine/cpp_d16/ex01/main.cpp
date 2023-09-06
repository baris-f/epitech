#include <iostream>
#include <cstdlib>
#include "DomesticKoala.h"
#include "KoalaAction.h"

int main(int argc, char **argv)
{
    KoalaAction action;
    DomesticKoala *dk = new DomesticKoala(action);

    dk->learnAction('<', &KoalaAction::eat);
    dk->learnAction('>', &KoalaAction::goTo);
    dk->learnAction('#', &KoalaAction::sleep);
    dk->learnAction('X', &KoalaAction::reproduce);

    dk->doAction(">", "{EPITECH.}");
    dk->doAction("<", "a DoubleCheese");
    dk->doAction("X", "a Seagull");
    dk->doAction("#", "The end of the C++ pool, and an Astek burning on a stake");
    return 0;
}

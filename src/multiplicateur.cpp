//
// Created by theo on 15/05/23.
//

#include "multiplicateur.h"

#include "imp_flot.h"

#include <cassert>

multiplicateur::multiplicateur() {
    m_entrees.push_back(std::make_shared<imp_flot>());
    m_entrees.push_back(std::make_shared<imp_flot>());

    m_sorties.push_back(std::make_shared<imp_flot>());
}

void multiplicateur::calculer() {
    assert(yaDesEchantillons());

    m_sorties[0]->inserer(m_entrees[0]->extraire() * m_entrees[1]->extraire());
}
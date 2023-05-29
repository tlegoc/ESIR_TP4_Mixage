//
// Created by theo on 11/05/23.
//

#include "producteur_base.h"

#include <cassert>

producteur_base::producteur_base() = default;

const std::shared_ptr<flot> &producteur_base::getSortie(unsigned int numsortie) const {
    assert(numsortie < m_sorties.size());

    return m_sorties[numsortie];
}

unsigned int producteur_base::nbSorties() const {
    return m_sorties.size();
}
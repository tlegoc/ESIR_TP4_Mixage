//
// Created by theo on 15/05/23.
//

#include "consommateur_base.h"

#include <cassert>

consommateur_base::consommateur_base() = default;

unsigned int consommateur_base::nbEntrees() const {
    return m_entrees.size();
}

const std::shared_ptr<flot> &consommateur_base::getEntree(unsigned int numentree) const {
    assert(numentree < nbEntrees());

    return m_entrees[numentree];
}

void consommateur_base::connecterEntree(const std::shared_ptr<flot> &f, unsigned int numentree) {
    assert(numentree < nbEntrees());

    m_entrees[numentree] = f;
}

bool consommateur_base::yaDesEchantillons() const {
    for (const auto& entree : m_entrees) {
        if (entree->vide()) return false;
    }

    return true;
}
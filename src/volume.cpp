//
// Created by theo on 22/05/23.
//

#include "volume.h"

#include <cassert>
#include <iostream>

volume::volume(double vol) : filtre_base(), m_sc(vol), m_mul() {
    m_entrees.push_back(std::make_shared<imp_flot>());

    m_sorties.push_back(std::make_shared<imp_flot>());

    // volume e0 -> multiplicateur e0
    // m_mul.connecterEntree(getEntree(0), 0);
    // signal_constant s0 -> multiplicateur e1
    m_mul.connecterEntree(m_sc.getSortie(0), 1);
    // multiplicateur s0 -> volume s0
    m_sorties[0] = m_mul.getSortie(0);
}

void volume::connecterEntree(const std::shared_ptr<flot> &f, unsigned int numentree) {
    filtre_base::connecterEntree(f, numentree);

    m_mul.connecterEntree(getEntree(numentree), 0);
}

void volume::calculer() {
    m_sc.calculer();
    m_mul.calculer();
}

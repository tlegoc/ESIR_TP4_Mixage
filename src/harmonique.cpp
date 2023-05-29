//
// Created by theo on 15/05/23.
//

#include "harmonique.h"

#include "constantes.h"
#include "imp_flot.h"

#include <math.h>

harmonique::harmonique(float f, float phi) {
    m_f = f;
    m_phi = phi;
    m_i = 0;
    m_sorties.push_back(std::make_shared<imp_flot>());
}

void harmonique::calculer() {
    m_sorties[0]->inserer(sin(m_i/((float) MixageSonore::frequency) * MixageSonore::pi * 2.0 * m_f + m_phi));

    m_i += 1;
    // Pour éviter l'overflow
    m_i = m_i % MixageSonore::frequency;
}
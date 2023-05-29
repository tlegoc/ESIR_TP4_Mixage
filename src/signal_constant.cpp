//
// Created by theo on 11/05/23.
//

#include "signal_constant.h"

#include "imp_flot.h"

#include <cassert>

signal_constant::signal_constant(double value) : m_value(value) {
    m_flot = std::make_shared<imp_flot>();
}

const std::shared_ptr<flot> &signal_constant::getSortie(unsigned int numsortie) const {
    assert(numsortie < nbSorties());

    return m_flot;
}

unsigned int signal_constant::nbSorties() const {
    return 1;
}

void signal_constant::calculer() {
    m_flot->inserer(m_value);
}
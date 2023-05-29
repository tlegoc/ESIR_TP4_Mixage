//
// Created by theo on 11/05/23.
//

#include "imp_flot.h"

#include <cassert>

imp_flot::imp_flot() {

}

imp_flot::~imp_flot() {

}

void imp_flot::inserer(double echantillon) {
    m_samples.push_back(echantillon);
}

double imp_flot::extraire() {
    assert(!vide() && "Le flot est vide");
    double front = m_samples.front();
    m_samples.pop_front();
    return front;
}

bool imp_flot::vide() const {
    return m_samples.empty();
}
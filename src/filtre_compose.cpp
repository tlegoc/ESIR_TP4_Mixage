//
// Created by theo on 23/05/23.
//

#include "filtre_compose.h"

#include "consommateur_base.h"

#include <cassert>
#include <iostream>

void filtre_compose::calculer() {
    assert(consommateur_base::yaDesEchantillons());

    for (auto comp: m_composants)
        comp->calculer();
}

void filtre_compose::ajouterComposant(const std::shared_ptr<composant> &composant) {
    m_composants.push_back(composant);
}

void filtre_compose::connecterEntree(const std::shared_ptr<flot> &f, unsigned int numentree) {
    assert(numentree < m_entrees.size());

    m_entrees[numentree].first->connecterEntree(f, m_entrees[numentree].second);
}

std::shared_ptr<composant> filtre_compose::getComposant(int i) {
    assert(i < m_composants.size());

    return m_composants[i];
}

const std::shared_ptr<flot> &filtre_compose::getEntree(unsigned int numentree) const {
    assert(numentree < m_entrees.size());

    return m_entrees[numentree].first->getEntree(m_entrees[numentree].second);
}

void filtre_compose::lierEntree(std::shared_ptr<consommateur_base> comp, unsigned int numentree) {
    m_entrees.emplace_back(comp, numentree);
}

void filtre_compose::lierSortie(std::shared_ptr<producteur_base> comp, unsigned int numsortie) {
    m_sorties.push_back(comp->getSortie(numsortie));
}
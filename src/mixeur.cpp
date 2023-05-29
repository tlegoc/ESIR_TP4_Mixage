//
// Created by theo on 26/05/23.
//

#include "mixeur.h"

#include "volume_compose.h"
#include "imp_flot.h"

#include <iostream>

mixeur::mixeur(std::vector<float> volumes) {
    m_sorties.push_back(std::make_shared<imp_flot>());

    for (auto v : volumes) {
        auto vol_comp = std::make_shared<volume_compose>(v);

        ajouterComposant(vol_comp);

        lierEntree(vol_comp, 0);

        m_private_sorties.push_back(vol_comp->getSortie(0));
    }
}

void mixeur::calculer() {
    // On met a jour tous nos volumes
    filtre_compose::calculer();

    // On somme la sortie de toutes nos entrees
    float sum = 0;
    for (auto s : m_private_sorties)
        sum += s->extraire();

    m_sorties[0]->inserer(sum);
}
//
// Created by theo on 23/05/23.
//

#include "volume_compose.h"

#include "composant.h"

#include <memory>

volume_compose::volume_compose(double vol) : filtre_compose() {
    auto sc = std::make_shared<signal_constant>(vol);
    auto mul = std::make_shared<multiplicateur>();

    ajouterComposant(sc);
    ajouterComposant(mul);

    mul->connecterEntree(sc->getSortie(0), 0);

    // Ajoute une entree qui correspond à l'entrée
    // 1 du multiplicateur
    lierEntree(mul, 1);

    // Ajoute une sortie qui correspond a la sortie
    // 0 du multiplicateur
    lierSortie(mul, 0);
}
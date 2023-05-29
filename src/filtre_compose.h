//
// Created by theo on 23/05/23.
//

#ifndef TP4_FILTRE_COMPOSE_H
#define TP4_FILTRE_COMPOSE_H

#include "filtre_base.h"

#include <cassert>

class filtre_compose : public filtre_base {
public:
    void calculer() override;

    void connecterEntree(const std::shared_ptr<flot> &f, unsigned int numentree) override;

    // Ajoute un composant dans la liste des composants
    // a mettre à jour
    // L'ORDRE EST IMPORTANT
    void ajouterComposant(const std::shared_ptr<composant> &composant);

    std::shared_ptr<composant> getComposant(int i);

    // Le système d'entrées est différent pour les filtres composés, il
    // faut donc redéfinir la fonction
    const std::shared_ptr<flot> & getEntree(unsigned int numentree) const override;

protected:
    // Utilisé dans les composants dérivés, associe une entrée du filtre à une entrée d'un composant
    // interne
    void lierEntree(std::shared_ptr<consommateur_base> comp, unsigned int numentree);

    // Même chose pour les sorties
    void lierSortie(std::shared_ptr<producteur_base> comp, unsigned int numsortie);

    std::vector<std::shared_ptr<composant>> m_composants;

    // Au lieu d'avoir des flots en entrées, on a une paire qui associe
    // l'entree du composant et le composant a la sortie x, x etant l'index
    // dans le tableau
    std::vector<std::pair<std::shared_ptr<consommateur_base>, int>> m_entrees;
};


#endif //TP4_FILTRE_COMPOSE_H

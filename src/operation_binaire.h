//
// Created by theo on 22/05/23.
//

#ifndef TP4_OPERATION_BINAIRE_H
#define TP4_OPERATION_BINAIRE_H

#include "filtre_base.h"

#include <cassert>

template<class T>
class operation_binaire : public filtre_base {

public:
    operation_binaire(){
        m_entrees.push_back(std::make_shared<imp_flot>());
        m_entrees.push_back(std::make_shared<imp_flot>());

        m_sorties.push_back(std::make_shared<imp_flot>());
    }

    void calculer() override {
        assert(consommateur_base::yaDesEchantillons());

        T bo;
        m_sorties[0]->inserer(bo(m_entrees[0]->extraire(), m_entrees[1]->extraire()));
    }
};


#endif //TP4_OPERATION_BINAIRE_H

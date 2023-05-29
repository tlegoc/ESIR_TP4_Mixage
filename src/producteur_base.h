//
// Created by theo on 11/05/23.
//

#ifndef TP4_PRODUCTEUR_BASE_H
#define TP4_PRODUCTEUR_BASE_H

#include "producteur.h"

#include <vector>

class producteur_base : public virtual producteur {

public:
    producteur_base();
    unsigned int nbSorties() const override;
    const std::shared_ptr<flot> & getSortie(unsigned int numsortie) const override;

protected:
    std::vector<std::shared_ptr<flot>> m_sorties;
};


#endif //TP4_PRODUCTEUR_BASE_H

//
// Created by theo on 15/05/23.
//

#ifndef TP4_CONSOMMATEUR_BASE_H
#define TP4_CONSOMMATEUR_BASE_H

#include "consommateur.h"

#include <vector>

class consommateur_base : public virtual consommateur {

public:
    consommateur_base();
    unsigned int nbEntrees() const override;
    const std::shared_ptr<flot> & getEntree(unsigned int numentree) const override;
    void connecterEntree(const std::shared_ptr<flot> &f, unsigned int numentree) override;
    bool yaDesEchantillons() const override;

protected:
    std::vector<std::shared_ptr<flot>> m_entrees;
};

#endif //TP4_CONSOMMATEUR_BASE_H

//
// Created by theo on 11/05/23.
//

#ifndef TP4_SIGNAL_CONSTANT_H
#define TP4_SIGNAL_CONSTANT_H

#include "producteur.h"

#include "imp_flot.h"

class signal_constant : public producteur {
public:
    signal_constant(double value);
    unsigned int nbSorties() const override;
    const std::shared_ptr<flot> & getSortie(unsigned int numsortie) const override;
    void calculer() override;

private:
    double m_value;
    std::shared_ptr<flot> m_flot;
};


#endif //TP4_SIGNAL_CONSTANT_H

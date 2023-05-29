//
// Created by theo on 11/05/23.
//

#ifndef TP4_IMP_FLOT_H
#define TP4_IMP_FLOT_H

#include "flot.h"

#include <deque>

class imp_flot : public flot {
private:
    std::deque<double> m_samples;

public:
    imp_flot();
    ~imp_flot() override;

    void inserer(double echantillon) override;
    double extraire() override;
    bool vide() const override;
};


#endif //TP4_IMP_FLOT_H

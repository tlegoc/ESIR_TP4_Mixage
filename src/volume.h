//
// Created by theo on 22/05/23.
//

#ifndef TP4_VOLUME_H
#define TP4_VOLUME_H

#include "filtre_base.h"
#include "signal_constant.h"
#include "multiplicateur.h"

class volume : public filtre_base {

public:
    volume(double vol);

    void calculer() override;

    void connecterEntree(const std::shared_ptr<flot> &f, unsigned int numentree) override;

private:
    signal_constant m_sc;
    multiplicateur m_mul;
};


#endif //TP4_VOLUME_H

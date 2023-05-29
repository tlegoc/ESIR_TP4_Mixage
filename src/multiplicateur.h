//
// Created by theo on 15/05/23.
//

#ifndef TP4_MULTIPLICATEUR_H
#define TP4_MULTIPLICATEUR_H

#include "filtre_base.h"

class multiplicateur : public filtre_base {
public:
    multiplicateur();
    void calculer() override;
};


#endif //TP4_MULTIPLICATEUR_H

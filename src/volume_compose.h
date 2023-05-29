//
// Created by theo on 23/05/23.
//

#ifndef TP4_VOLUME_COMPOSE_H
#define TP4_VOLUME_COMPOSE_H

#include "filtre_compose.h"

#include "signal_constant.h"

#include "multiplicateur.h"

class volume_compose : public filtre_compose {
public:
    volume_compose(double vol);
};


#endif //TP4_VOLUME_COMPOSE_H

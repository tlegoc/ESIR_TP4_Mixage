//
// Created by theo on 15/05/23.
//

#ifndef TP4_FILTRE_BASE_H
#define TP4_FILTRE_BASE_H

#include "consommateur_base.h"
#include "producteur_base.h"

#include "filtre.h"

class filtre_base : public virtual filtre, public virtual consommateur_base, public virtual producteur_base {

};

#endif //TP4_FILTRE_BASE_H

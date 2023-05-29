//
// Created by theo on 15/05/23.
//

#ifndef TP4_HARMONIQUE_H
#define TP4_HARMONIQUE_H

#include "producteur_base.h"

class harmonique : public producteur_base {
public:
    harmonique(float f, float phi = 0.0);
    void calculer() override;

private:
    float m_f;
    float m_phi;
    unsigned int m_i;
};


#endif //TP4_HARMONIQUE_H

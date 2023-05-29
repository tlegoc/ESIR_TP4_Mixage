//
// Created by theo on 26/05/23.
//

#ifndef TP4_MIXEUR_H
#define TP4_MIXEUR_H

#include "filtre_compose.h"

#include <vector>

class mixeur : public filtre_compose{
public:
    mixeur(std::vector<float> volumes);

    void calculer() override;

private:
    std::vector<std::shared_ptr<flot>> m_private_sorties;
};


#endif //TP4_MIXEUR_H

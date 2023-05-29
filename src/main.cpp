/*
 * main.cpp
 *
 *  Created on: 8 mars 2013
 *      Author: engel
 */

#include "constantes.h"
#include "enregistreur_fichier_wav.h"
#include "enregistreur_fichier_texte.h"
#include "harmonique.h"
#include "signal_constant.h"
#include "multiplicateur.h"
#include "operation_binaire.h"
#include "volume.h"
#include "volume_compose.h"
#include "mixeur.h"

#include <iostream>

void q2_signal_constant() {
    std::cout << "q2" << std::endl;
    signal_constant constant(0.5);
    enregistreur_fichier_texte enregistreur("02_constant.txt", 1);
    enregistreur.connecterEntree(constant.getSortie(0), 0);
    // générer des valeurs
    for (unsigned int i = 0; i < 50; ++i) {
        constant.calculer();
        enregistreur.calculer();
    }
}

void q4_harmonique() {
    std::cout << "q4" << std::endl;
    harmonique la440(440); // la 440Hz (voir fr.wikipedia.org/wiki/Note_de_musique)
    enregistreur_fichier_wav enregistreur("04_harmonique.wav", 1);    // fichier mono
    enregistreur.connecterEntree(la440.getSortie(0), 0);
    // produire 2 secondes de son
    for (unsigned long int i = 0; i < 2 * MixageSonore::frequency; ++i) {
        la440.calculer();
        enregistreur.calculer();
    }
}

void q9_multiplicateur() {
    std::cout << "q9" << std::endl;
    harmonique n440(440);
    harmonique n880(880);
    multiplicateur m;
    enregistreur_fichier_wav enregistreur("09_multiplicateur.wav", 1);
    enregistreur.connecterEntree(m.getSortie(0), 0);

    m.connecterEntree(n440.getSortie(0), 0);
    m.connecterEntree(n880.getSortie(0), 1);

    // produire 2 secondes de son
    for (unsigned long int i = 0; i < 2 * MixageSonore::frequency; ++i) {
        n440.calculer();
        n880.calculer();
        m.calculer();
        enregistreur.calculer();
    }
}

void q10_multiplicateur_binaire() {
    std::cout << "q10" << std::endl;
    harmonique n440(440);
    harmonique n880(880);
    operation_binaire m = operation_binaire<std::multiplies<double>>();
    enregistreur_fichier_wav enregistreur("10_multiplicateur.wav", 1);
    enregistreur.connecterEntree(m.getSortie(0), 0);

    m.connecterEntree(n440.getSortie(0), 0);
    m.connecterEntree(n880.getSortie(0), 1);

    // produire 2 secondes de son
    for (unsigned long int i = 0; i < 2 * MixageSonore::frequency; ++i) {
        n440.calculer();
        n880.calculer();
        m.calculer();
        enregistreur.calculer();
    }
}

void q12_volume() {
    std::cout << "q12" << std::endl;
    harmonique la440(440); // la 440Hz (voir fr.wikipedia.org/wiki/Note_de_musique)
    volume vol(0.2);
    vol.connecterEntree(la440.getSortie(0), 0);
    enregistreur_fichier_wav enregistreur("12_volume.wav", 1);    // fichier mono
    enregistreur.connecterEntree(vol.getSortie(0), 0);
    // produire 2 secondes de son
    for (unsigned long int i = 0; i < 2 * MixageSonore::frequency; ++i) {
        la440.calculer();
        vol.calculer();
        enregistreur.calculer();
    }
}

void q14_volume_compose() {
    std::cout << "q14" << std::endl;
    harmonique la440(440); // la 440Hz (voir fr.wikipedia.org/wiki/Note_de_musique)
    volume_compose vol(0.2);

    vol.connecterEntree(la440.getSortie(0), 0);

    enregistreur_fichier_wav enregistreur("14_volume_compose.wav", 1);    // fichier mono
    enregistreur.connecterEntree(vol.getSortie(0), 0);

    // produire 2 secondes de son
    for (unsigned long int i = 0; i < 2 * MixageSonore::frequency; ++i) {
        la440.calculer();
        vol.calculer();
        enregistreur.calculer();
    }
}

void q15_mixeur() {
    std::cout << "q15" << std::endl;
    harmonique do3(261.63); // la 440Hz (voir fr.wikipedia.org/wiki/Note_de_musique)
    harmonique mi3(329.63);
    harmonique sol3(392);

    mixeur mix({.2, .2, .2});

    mix.connecterEntree(do3.getSortie(0), 0);
    mix.connecterEntree(mi3.getSortie(0), 1);
    mix.connecterEntree(sol3.getSortie(0), 2);

    enregistreur_fichier_wav enregistreur("15_mixeur.wav", 1);    // fichier mono
    enregistreur.connecterEntree(mix.getSortie(0), 0);

    // produire 2 secondes de son
    for (unsigned long int i = 0; i < 2 * MixageSonore::frequency; ++i) {
        do3.calculer();
        mi3.calculer();
        sol3.calculer();
        mix.calculer();
        enregistreur.calculer();
    }
}

int main() {
    q2_signal_constant();
    q4_harmonique();
    q9_multiplicateur();
    q10_multiplicateur_binaire();
    q12_volume();
    q14_volume_compose();
    q15_mixeur();

    return 0;
}

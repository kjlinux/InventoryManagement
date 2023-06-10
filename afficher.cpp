#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include "tools.hpp"

void afficherProduits(){
    cout << "===================================================" << std::endl;
    cout << "=================LOGICIEL DE STOCK=================" << std::endl;
    cout << "===========AFFICHER LISTE DES PRODUITS=============" << std::endl << std::endl;
    std::ifstream fichierProduit("mes_produits.txt");
    std::string lecteur;
    if(fichierProduit){
        while (std::getline(fichierProduit, lecteur))
        {
            std::cout << lecteur << std::endl;
        }  
    } else {
        retourMenuPrincipal("Impossible d'ouvrir le fichier");
    }
    retourMenuPrincipal("Ci-dessus la liste des produits");
}

void afficherVentes(){
    cout << "===================================================" << std::endl;
    cout << "=================LOGICIEL DE STOCK=================" << std::endl;
    cout << "=============AFFICHER LISTE DES VENTES=============" << std::endl << std::endl;
    std::ifstream fichierProduit("mes_ventes.temp");
    std::string lecteur;
    if(fichierProduit){
        while (std::getline(fichierProduit, lecteur))
        {
            std::cout << lecteur << std::endl;
        } 
    } else {
        retourMenuPrincipal("Impossible d'ouvrir le fichier");      
    }
    retourMenuPrincipal("Ci-dessus la liste des ventes");
}
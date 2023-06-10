#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include "tools.hpp"
#include "produit.hpp"

void nouveauProduit(){
    cout << "===================================================" << std::endl;
    cout << "=================LOGICIEL DE STOCK=================" << std::endl;
    cout << "==============ENREGISTRER UN PRODUIT===============" << std::endl << std::endl;

    struct Produit{
    std::string ref;
    std::string designation;
    int prix_Unitaire;
    int stock;
};

    Produit n_produit;
    std::string validation;
    std::string const nomFichier = "mes_produits.txt";
    std::ofstream fichierProduit(nomFichier.c_str(), ios::app);
    std::string choix1;
    std::string choix2;
    std::string choix3;
    if (fichierProduit){
        std::cout << "Entrer nom du produit: ";
        std::cin >> n_produit.designation;
        fflush(stdin);
        if (existe(n_produit.designation)){ 
            do{
                std::cout << 
                "Le produit existe deja, entrez un autre nom de produit (1) ou revenir au menu principal (2): ";
                std::getline(std::cin, choix1);
            } while (!isdigit(choix1[0]) || (choix1 != "1" || choix1 != "2") && (choix1.length() != 1 && 
            choix1 == "3"));
            if (choix1 == "1"){
                do{
                    std::cout << "Entrez un autre nom de produit: ";
                    std::cin >> n_produit.designation;
                } while(existe(n_produit.designation));
                std::cout << "Entrer reference du produit: ";
                fflush(stdin);
                std::getline(std::cin, n_produit.ref);
                verifierEntree(n_produit.ref);
                std::cout << "Entrer le prix unitaire du produit: ";
                std::cin >> n_produit.prix_Unitaire;
                std::cout << "Entrer le stock actuel du produit: ";
                std::cin >> n_produit.stock;

                fichierProduit << "Produit " << n_produit.designation << std::endl;
                fichierProduit << "Reference produit: " << n_produit.ref << std::endl;
                fichierProduit << "Nom: " << n_produit.designation << std::endl;
                fichierProduit << "Prix unitaire: " << n_produit.prix_Unitaire << std::endl;
                fichierProduit << "Stock courant: " << n_produit.stock << std::endl << std::endl;

                std::cout << "Produit enregistre avec succes !" << std::endl;
                fflush(stdin);                
                fichierProduit.close();
                do{
                    std::cout << 
                    "Enregistrer un autre produit (1) ou revenir au menu principal (2): ";
                    std::getline(std::cin, choix2);
                } while (!isdigit(choix2[0]) || (choix2 != "1" && choix2 != "2") && (choix2.length() != 1));
            if (choix2 == "1"){
                fflush(stdin);
                system("cls");
                nouveauProduit();
            } else {
                fflush(stdin);
                fichierProduit.close();
                menu();
            }
            }
        } else {
            std::cout << "Entrer reference du produit: ";
            std::cin >> n_produit.ref;
            std::cout << "Entrer le prix unitaire du produit: ";
            std::cin >> n_produit.prix_Unitaire;
            std::cout << "Entrer le stock actuel du produit: ";
            std::cin >> n_produit.stock;

            fichierProduit << "Produit " << n_produit.designation << std::endl;
            fichierProduit << "Reference produit: " << n_produit.ref << std::endl;
            fichierProduit << "Nom: " << n_produit.designation << std::endl;
            fichierProduit << "Prix unitaire: " << n_produit.prix_Unitaire << std::endl;
            fichierProduit << "Stock courant: " << n_produit.stock << std::endl << std::endl;

            std::cout << "Produit enregistre avec succes !" << std::endl;
            fflush(stdin);
            fichierProduit.close();
            do{
                std::cout << 
                "Enregistrer un autre produit (1) ou revenir au menu principal (2): ";
                std::getline(std::cin, choix2);
            } while (!isdigit(choix2[0]) || (choix2 != "1" && choix2 != "2") && (choix2.length() != 1));
            if (choix2 == "1"){
                fflush(stdin);
                system("cls");
                nouveauProduit();
            } else {
                system("cls");
                menu();
            }
        }
    } else {
        retourMenuPrincipal("Impossible d'ouvrir le fichier");
    }
}

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdio>
#include "tools.hpp"
#include "produit.hpp"
#include "stock.hpp"
#include "ventes.hpp"
#include "afficher.hpp"

int existe(std::string produit){
    std::string chercheur;
    std::ifstream C ("mes_produits.txt");
    int var;
    if(C){
        while (std::getline(C, chercheur)) {
            if(chercheur == "Produit " + produit){
                break;
            }
        }
        C.close();
    } else { 
        C.close();
    }
    if (chercheur == "Produit " + produit){ 
        var = 1;
    } else {
        var = 0;
    }
    return var;
}



std::string Date(){
    std::time_t temps = std::time(nullptr);
    std::tm* now = std::localtime(&temps);
    char Date[112];
    strftime(Date, sizeof(Date), "Date: %m-%d-%Y // Heure: %X", now);
    return Date;
}



void menu(){
    system("cls");
    std::string choice;
    cout << "===================================================" << std::endl;
    cout << "=================LOGICIEL DE STOCK=================" << std::endl;
    cout << "=======================MENU========================" << std::endl << std::endl;
    cout << "1: ENREGISTRER UN PRODUIT" << std::endl;
    cout << "2: ENREGISTRER UN STOCK" << std::endl;
    cout << "3: ENREGISTRER UNE VENTE" << std::endl;
    cout << "4: AFFICHER LISTE DES PRODUITS" << std::endl;
    cout << "5: AFFICHER LISTE DES VENTES" << std::endl;
    cout << "6: SORTIR" << std::endl << std::endl;
    cout << "OPTION: ";
    cin >> choice;
    fflush(stdin);
    while (!isdigit(choice[0]) || (choice != "1" && choice != "2" && choice != "3" && choice != "4"  && choice != "5" && choice != "6") && (choice.length() != 1)){
        std::cout << 
        "Entree invalide, veuillez saisir un chiffre compris entre 1 et 6: ";
        std::getline(std::cin, choice);    
    }
    if (choice == "1")
    {
        system("cls");
        nouveauProduit();
    }
    else if (choice == "2")
    {
        system("cls");
        enregistrerStock();
    }
    else if (choice == "3")
    {
        system("cls");
        enregistrerVente();
    }
    else if (choice == "4")
    {
        system("cls");
        afficherProduits();
    }
    else if (choice == "5")
    {
        system("cls");
        afficherVentes();
    }
    else
    {
        exit(0);
    }
}

void retourMenuPrincipal(std::string message){
        fflush(stdin);
        std::string choix;
        do{
            std::cout << message << ", tapez (1) pour retour au menu principal: ";
            std::getline(std::cin, choix);
        } while (!isdigit(choix[0]) || (choix != "1") && (choix.length() != 1) && (choix == "2" || \
        choix == "3" || choix == "4" || choix == "5" || choix == "6" || choix == "7" || choix == "8" || choix == "9"));
        fflush(stdin);
        if (choix == "1")
        {
            system("cls");
            menu();
        }
}

void verifierEntree(std::string valeur){
    fflush(stdin);
    for(int i = 0; i<valeur.length(); i++){
        while (!isdigit(valeur[i]))
        {
            std::cout << "Entree invalide, veuillez entrer un nombre: ";
            std::getline(std::cin, valeur);      
            i=0;    
        }
    }
    fflush(stdin);
}

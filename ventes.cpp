#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <ctime>
#include <cstdio>
#include "tools.hpp"
#include "ventes.hpp"



void enregistrerVente(){
    cout << "===================================================" << std::endl;
    cout << "=================LOGICIEL DE STOCK=================" << std::endl;
    cout << "===============ENREGISTRER UNE VENTE===============" << std::endl << std::endl;
    int nouveauStock = 1;
    std::string index ="";
    std::string produitReherche;
    std::string stockVendu;
    bool continuer = false;
    std::ifstream fichierCible("mes_produits.txt");
    std::cout << "Entrez le nom du produit concerne: ";
    std::cin >> produitReherche;
    while(existe(produitReherche) != 1){
            std::cout << "Le produit n'existe pas, reessayez avec un autre nom: ";
            std::cin >> produitReherche;         
    }
    fflush(stdin);
    if (existe(produitReherche)){
        if (fichierCible){
            std::cout << "Entrez le stock vendu: ";
            std::getline(std::cin, stockVendu);
            verifierEntree(stockVendu);
            //fflush(stdin);
            while(fichierCible >> index){
                if (index == "Nom:"){
                    fichierCible >> index;
                    if(index == produitReherche){
                        for (int i = 1; i<=6; i++){ 
                            fichierCible >> index; 
                        }
                        if(std::stoi(index) >= std::stoi(stockVendu)){
                            nouveauStock = (std::stoi(index))-std::stoi(stockVendu);
                            continuer = true;
                            break;
                        } else {
                            retourMenuPrincipal("Stock insuffisant (en stock: " + index + ")");
                            break;
                        }
                    }
                }
            }
            fichierCible.close();
        } else { 
            retourMenuPrincipal("Impossible d'ouvrir le fichier");
            fichierCible.close();
        }
    } 
    
    if(continuer){
        std::ifstream BaseA("mes_produits.txt");
        std::ofstream CibleA("liste_ventes.temp");
        std::string parcourir;
        std::string ecritureRemplacement = "Stock courant: " + std::to_string(nouveauStock);
        if(BaseA){
            if (CibleA){
                int i=1;
                while(std::getline(BaseA, parcourir)){
                    if(parcourir == "Produit " + produitReherche){
                        CibleA << parcourir << std::endl;
                        i++;
                        continue;
                    } 
                    if(parcourir == "Stock courant: " + index && i==2){
                        CibleA << ecritureRemplacement << std::endl;
                        i=1;
                        continue;
                    }        
                    CibleA << parcourir << std::endl;}
            } else {
                retourMenuPrincipal("Impossible d'ouvrir le fichier");
            }
            CibleA.close();
        } else {
            retourMenuPrincipal("Impossible d'ouvrir le fichier");
        }
        BaseA.close();
        parcourir = "";
        std::ifstream BaseB("liste_ventes.temp");
        std::ofstream CibleB("mes_produits.txt");
        if(BaseB){
            if(CibleB){
                while(std::getline(BaseB, parcourir)){
                    CibleB << parcourir << std::endl;
                }
            } else {
                retourMenuPrincipal("Impossible d'ouvrir le fichier");
            }
            CibleB.close();
        } else {
            retourMenuPrincipal("Impossible d'ouvrir le fichier");
        }
        BaseB.close();
        remove("liste_ventes.temp"); 

        std::ifstream fichierVente("mes_ventes.txt");
        std::ofstream fVenteTemp("mes_ventes.temp");
        std::string copie;
        if(fichierVente){
            if(fVenteTemp){
                fVenteTemp << Date() << " // " << "Produit vendu: " << produitReherche << " // " << 
                "Quantite: " << stockVendu << std::endl;
                while (std::getline(fichierVente, copie)){
                    fVenteTemp << copie << std::endl;
                }
                std::cout << "Vente enregistree avec succes !" << std::endl;
        } else {
            retourMenuPrincipal("Impossible d'ouvrir le fichier");
        }
        fichierVente.close();
        fVenteTemp.close();
        remove("mes_ventes.txt");
        rename("mes_ventes.temp", "mes_ventes.txt");
    }
    std::string ch;
    do{
        std::cout << 
        "Vendre un autre produit (1) ou revenir au menu principal (2): ";
        std::getline(std::cin, ch);
    } while (!isdigit(ch[0]) || (ch != "1" && ch != "2") && (ch.length() != 1));
    if (ch == "1"){
        fflush(stdin);
        system("cls");
        enregistrerVente();
    } else {
        fflush(stdin);
        fichierVente.close();
        fVenteTemp.close();
        menu();
    }
}
}
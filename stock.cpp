#include <iostream>
#include <fstream>
#include "tools.hpp"
#include <string>
#include <cstdio>

void enregistrerStock(){
    cout << "===================================================" << std::endl;
    cout << "=================LOGICIEL DE STOCK=================" << std::endl;
    cout << "================ENREGISTRER UN STOCK===============" << std::endl << std::endl;
    int nouveauStock=1;
    std::string index ="";
    std::string produitReherche;
    std::string stockAjout;
    std::cout << "Entrez le nom du produit concerne:";
    std::cin >> produitReherche;
    while(existe(produitReherche) != 1){
        std::cout << "Le produit n'existe pas, reessayez avec un autre nom: ";
        std::cin >> produitReherche;         
    }
    fflush(stdin);
    std::ifstream fichierCible("mes_produits.txt");
    if (existe(produitReherche)){
        if (fichierCible){
                std::cout << "Entrez le stock ajoute:";
                std::getline(std::cin, stockAjout);
                fflush(stdin);
                for(int i = 0; i<stockAjout.length(); i++){
                    while (!isdigit(stockAjout[i]))
                    {
                        std::cout << "Entree invalide, veuillez entrer un nombre: ";
                        std::getline(std::cin, stockAjout);      
                        i=0;    
                    }
                }
                while(fichierCible >> index){
                    if (index == "Nom:"){
                        fichierCible >> index;
                        if(index == produitReherche){
                            for (int i = 1; i<=6; i++){
                                fichierCible >> index;
                            }
                            nouveauStock = (std::stoi(index))+std::stoi(stockAjout);
                            break;
                        }
                    }
                }
        } else {retourMenuPrincipal("Impossible d'ouvrir le fichier"); }

        std::ifstream BaseA("mes_produits.txt");
        std::ofstream CibleA("liste_produits.temp");
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
                    if(parcourir == "Stock courant: " + index && i== 2){
                        CibleA << ecritureRemplacement << std::endl;
                        i=1;
                        continue;
                    }        
                    CibleA << parcourir << std::endl;
                }
            } else {retourMenuPrincipal("Impossible d'ouvrir le fichier");}
            CibleA.close();
        } else {retourMenuPrincipal("Impossible d'ouvrir le fichier");}
        BaseA.close();
        parcourir = "";
        std::ifstream BaseB("liste_produits.temp");
        std::ofstream CibleB("mes_produits.txt");
        if(BaseB){
            if(CibleB){
                while(std::getline(BaseB, parcourir)){
                    CibleB << parcourir << std::endl;
                }
                std::cout << "Stock enregistre avec succes !" << std::endl;
                std::string ch;
                do{
                    std::cout << 
                    "Enregistrer un autre stock (1) ou revenir au menu principal (2): ";
                    std::getline(std::cin, ch);
                } while (!isdigit(ch[0]) || (ch != "1" && ch != "2") && (ch.length() != 1));
                if (ch == "1"){
                    fflush(stdin);
                    system("cls");
                    enregistrerStock();
                } else {
                    system("cls");
                    menu();
                }
            } else {retourMenuPrincipal("Impossible d'ouvrir le fichier");}
        } else {retourMenuPrincipal("Impossible d'ouvrir le fichier");}
        remove("liste_produits.temp");
    }
}
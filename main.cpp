//Programme principale main.cpp

//Les includes
#include <iostream>
#include <vector>
#include "Cave.hpp"
#include "Vin.hpp"
#include "Fournisseur.hpp"
#include "Fournir.hpp"
#include "Marge.hpp"
#include "Reduction.hpp"
#include <algorithm>//utilise dans la fonction find if

using namespace std;
// Global variables :
// Les vecteurs qui contiennent des pointeurs vers les caves, les vins, les fournisseurs et les marges.
vector<Cave*> caves;
vector<Vin*> vins;
vector<Fournisseur*> fournisseurs;
vector<Marge*> marges;
int MAX_Val= 1000000;

// Function prototypes
void creerCave();
void creerVin();
void creerFournisseur();
void creerFournir();
void creerMarge();
void afficherStock();
void editCave();
void ajouterVinaCave();
void trouverCaveMeilleurPrix();
void creeReduction();


//fonction qui affiche un Menu :
void afficherMenu() {
    cout << "===== Menu =====" << endl;
    cout << "1. Creer une cave" << endl;
    cout << "2. Creer un vin" << endl;
    cout << "3. Creer un fournisseur" << endl;
    cout << "4. Creer une Fournir" << endl;
    cout << "5. Creer une marge" << endl;
    cout << "6. Creer les reductions d'un fournisseur" << endl;
    cout << "7. Afficher le stock d'une cave" << endl;
    cout << "8. Getion de stock (ajout de vins dans une cave) "<<endl;
    cout << "9. Trouver la cave ou un vin est propose au meilleur prix" << endl;
    cout << "10. Editer une cave "<<endl;
    cout << "12. Quitter" << endl;
    cout << "==L'edit des autres elements va venir lors d'une nouvelle mise a jour !!=="<<endl;
}

int main() {
    int choix;
    cout<<"Bienvenue dans notre logiciel de gestion de cave v 1.0.0"<<endl;
    do {
        afficherMenu();
        cout << "Entrez votre choix : ";
        cin >> choix;

        switch (choix) {
            case 1://cree une cave
                creerCave();
                break;
            case 2://cree un vin
                creerVin();
                break;
            case 3://cree un fournisseur
                creerFournisseur();
                break;
            case 4://cree une relation Fournir entre un Vin et un Fournisseur
                creerFournir();
                break;
            case 5://cree une marge entre une Cave et et le prix d'un Vin
                creerMarge();
                break;
            case 6://cree les reductions d'un fournisseur
                creeReduction();
                break;
            case 7://afficher le stock d'une cave
                afficherStock();
                break;
            case 8://ajouter un vin a un stock d'une cave
                ajouterVinaCave();
                break;
            case 9://trouver la cave ou un vin est propose au meilleur prix
                trouverCaveMeilleurPrix();
                break;
            case 10://Modification d'une cave
                editCave();
                break;
            case 12:
                cout << "Au revoir !" << endl;
                break;
            default:
                cout << "Choix invalide. Veuillez reessayer." << endl;
        }
    } while (choix != 12); //le choix de quitter le programme
    return 0;
}

//Fonction de creation d'une cave: celle si verifie si y a pas deja une cave avec le meme ID
void creerCave() {
    string id, nom, adresse;
    cout << "Entrez l'ID de la cave : ";
    cin >> id;
    // Verifier si l'ID de la cave existe dejà
    for (Cave* cave : caves) {
        if (cave->getIdCave() == id) {
            cout << "Une cave avec cet ID existe dejà. La creation de la cave a echoue." << endl;
            return; // Sortir de la fonction si l'ID existe dejà
        }
    }
    cout << "Entrez le nom de la cave : ";
    cin >> nom;
    cout << "Entrez l'adresse de la cave : ";
    cin >> adresse;
    Cave* nouvelleCave = new Cave(id, nom, adresse); //Creation Dynamique d'une cave
    caves.push_back(nouvelleCave); //ajout de la cave a la liste
    cout << "La cave a ete creee avec succes." << endl;
}

// Fonction de creation d'un vin : celle-ci verifie si ya pas deja un vin du meme ID cree
void creerVin() {
    int choixTypeVin;
    cout << "Choisissez le type de vin : " << endl;
    cout << "1. Vin normal" << endl;
    cout << "2. Vin de Garde" << endl;
    cout << "3. Vin de Consommation" << endl;
    cout << "Votre choix : ";
    cin >> choixTypeVin;
    string id, origine, producteur, nom;
    int millesime, dureeDeConser;
    cout << "Entrez l'ID du vin : ";
    cin >> id;
    // Verifier si l'ID du vin existe dejà
    for (Vin* vin : vins) {
        if (vin->getIdVin() == id) {
            cout << "Un vin avec cet ID existe dejà. La creation du vin a echoue." << endl;
            return; // Sortir de la fonction si l'ID existe dejà
        }
    }
    cout << "Entrez l'origine du vin : ";
    cin >> origine;
    cout << "Entrez le producteur du vin : ";
    cin >> producteur;
    cout << "Entrez le nom du vin : ";
    cin >> nom;
    cout << "Entrez le millesime du vin : ";
    cin >> millesime;
    switch (choixTypeVin) {
        case 1: {
            // Vin normal
            Vin* nouveauVin = new Vin(id, origine, producteur, nom, millesime);
            vins.push_back(nouveauVin);
            cout << "Le vin normal a ete cree avec succes." << endl;
            break;
        }
        case 2: {
            // Vin de Garde
            cout << "Entrez la duree de conservation du vin de garde : ";
            cin >> dureeDeConser;
            Vin* nouveauVinGarde = new VinDeGarde(id, origine, producteur, nom, millesime, dureeDeConser);
            vins.push_back(nouveauVinGarde);
            cout << "Le vin de garde a ete cree avec succes." << endl;
            break;
        }
        case 3: {
            // Vin de Consommation
            cout << "Entrez la date d'expiration du vin de consommation : ";
            cin >> dureeDeConser;
            Vin* nouveauVinConso = new VinDeConsomation(id, origine, producteur, nom, millesime, dureeDeConser);
            vins.push_back(nouveauVinConso);
            cout << "Le vin de consommation a ete cree avec succes." << endl;
            break;
        }
        default:
            cout << "Choix de type de vin invalide." << endl;
    }
}

//Fonction pour cree un fournisseur
void creerFournisseur() {
    string id, nom, adresse;
    cout << "Entrez l'ID du fournisseur : ";
    cin >> id;
    cout << "Entrez le nom du fournisseur : ";
    cin >> nom;
    cout << "Entrez l'adresse du fournisseur : ";
    cin >> adresse;
    auto* nouveauFournisseur = new Fournisseur(id, nom, adresse);
    fournisseurs.push_back(nouveauFournisseur);
    cout << "Le fournisseur a ete cree avec succes." << endl;
}

//Fonction pour cree une relation Fournir entre un Vin et un Fournisseur
void creerFournir() {
    // Verifier si des vins et des fournisseurs existent
    if (vins.empty() || fournisseurs.empty() || caves.empty()) {
        cout << "Veuillez creer au moins un vin, un fournisseur et une cave avant de creer une fourniture." << endl;
        return;
    }
    int choixVin, choixFournisseur, choixCave;
    double prix;
    cout << "Choisissez un vin : " << endl;
    for (size_t i = 0; i < vins.size(); ++i) {
        cout << i + 1 << ". " << vins[i]->getNomVin() << endl;
    }
    cout << "Votre choix : ";
    cin >> choixVin;
    // Verifier la validite du choix du vin
    if (choixVin > 0 && choixVin <= static_cast<int>(vins.size())) {
        cout << "Choisissez un fournisseur : " << endl;
        for (size_t i = 0; i < fournisseurs.size(); ++i) {
            cout << i + 1 << ". " << fournisseurs[i]->getNomFournisseur() << endl;
        }
        cout << "Votre choix : ";
        cin >> choixFournisseur;
        if (choixFournisseur > 0 && choixFournisseur <= static_cast<int>(fournisseurs.size())) {
            cout << "Choisissez une cave : " << endl;
            for (size_t i = 0; i < caves.size(); ++i) {
                cout << i + 1 << ". " << caves[i]->getNomCave() << endl;
            }
            cout << "Votre choix : ";
            cin >> choixCave;
            // Verifier la validite du choix de la cave
            if (choixCave > 0 && choixCave <= static_cast<int>(caves.size())) {
                cout << "Entrez le prix : ";
                cin >> prix;
                auto* nouvelleFourniture = new Fournir (vins[choixVin - 1], fournisseurs[choixFournisseur - 1], caves[choixCave - 1], prix);
                // Ajouter la nouvelle fourniture à la cave et au vin automatiquement a chaque creation de fourniture
                caves[choixCave - 1]->ajouterFourniture(nouvelleFourniture);
                vins[choixVin - 1]->addFourniture(nouvelleFourniture);
                cout << "La fourniture a ete creee avec succes dans la cave " << caves[choixCave - 1]->getNomCave() << "." << endl;
            } else {
                cout << "Choix de cave invalide." << endl;
            }
        } else {
            cout << "Choix de fournisseur invalide." << endl;
        }
    } else {
        cout << "Choix de vin invalide." << endl;
    }
}

//Fonction pour cree une marge entre une Cave et et le prix d'un Vin
void creerMarge() {
    // Verifier si des vins et des caves existent
    if (vins.empty() || caves.empty()) {
        cout << "Veuillez creer au moins un vin et une cave avant de creer une marge." << endl;
        return;
    }
    int choixVin, choixCave;
    double taux;
    cout << "Choisissez un vin : " << endl;
    for (size_t i = 0; i < vins.size(); ++i) {
        cout << i + 1 << ". " << vins[i]->getNomVin() << endl;
    }
    cout << "Votre choix : ";
    cin >> choixVin;
    if (choixVin > 0 && choixVin <= static_cast<int>(vins.size())) {
        cout << "Choisissez une option : " << endl;
        cout << "1. Choisir une cave existante" << endl;
        cout << "2. Creer une nouvelle cave" << endl;
        int choixOption;
        cout << "Votre choix : ";
        cin >> choixOption;
        if (choixOption == 1) {
            // Afficher la liste des caves existantes
            cout << "Choisissez une cave existante : " << endl;
            for (size_t i = 0; i < caves.size(); ++i) {
                cout << i + 1 << ". " << caves[i]->getNomCave() << endl;
            }
            cout << "Votre choix : ";
            cin >> choixCave;
            if (choixCave > 0 && choixCave <= static_cast<int>(caves.size())) {
                cout << "Entrez le taux : ";
                cin >> taux;
                auto* nouvelleMarge = new Marge(vins[choixVin - 1], caves[choixCave - 1], taux);
                marges.push_back(nouvelleMarge);
                // Mettre à jour la marge du vin automatiquement a chaque creation
                vins[choixVin - 1]->setMarge(nouvelleMarge);
                cout << "La marge a ete creee avec succes." << endl;
            } else {
                cout << "Choix de cave invalide." << endl;
            }
        } else if (choixOption == 2) {
            // Logique pour creer une nouvelle cave si necessaire
            cout << "Fonctionnalite non implementee pour creer une nouvelle cave." << endl;
        } else {
            cout << "Option invalide." << endl;
        }
    } else {
        cout << "Choix de vin invalide." << endl;
    }
}

// Fonction pour afficher le stock d'une cave
void afficherStock() {
    if (!caves.empty()) {
        cout << "Choisissez une cave : " << endl;
        for (size_t i = 0; i < caves.size(); ++i) {
            cout << i + 1 << ". " << caves[i]->getNomCave() << endl;
        }
        int choixCave;
        cout << "Votre choix : ";
        cin >> choixCave;
        if (choixCave > 0 && choixCave <= static_cast<int>(caves.size())) {
            if (caves[choixCave - 1]->stockVide()) {
                cout << "Le stock de la cave est vide pensez a ajoutez du vin au stock d'abord." << endl;
            } else {
                caves[choixCave - 1]->afficherStock();
            }
        } else {
            cout << "Choix de cave invalide." << endl;
        }
    } else {
        cout << "Aucune cave n'a ete creee." << endl;
    }
}

//Fonction pour cree les reductions d'un fournisseur
void creeReduction() {
    if (fournisseurs.empty()) {
        cout << "Veuillez creer au moins un fournisseur avant de gerer les reductions." << endl;
        return;
    }else{
    // Afficher la liste des fournisseurs
    cout << "Choisissez un fournisseur : " << endl;
    for (size_t i = 0; i < fournisseurs.size(); ++i) {
        cout << i + 1 << ". " << fournisseurs[i]->getNomFournisseur() << endl;
    }
    int choixFournisseur;
    cout << "Votre choix : ";
    cin >> choixFournisseur;
    // Verifier la validite du choix du fournisseur
    if (choixFournisseur > 0 && choixFournisseur <= static_cast<int>(fournisseurs.size())) {
        // Afficher les reductions existantes pour le fournisseur
        cout << "Reductions actuelles pour le fournisseur " << fournisseurs[choixFournisseur - 1]->getNomFournisseur() << " :" << endl;
        for (Reduction* reduction : fournisseurs[choixFournisseur - 1]->getReductions()) {
            reduction->afficherReduction();
        }
        // Demander à l'utilisateur d'ajouter une nouvelle reduction
        int firstentry, secondentry;
        float taux;
        cout << "Entrez la premiere entree : ";
        cin >> firstentry;
        cout << "Entrez la deuxieme entree : ";
        cin >> secondentry;
        cout << "Entrez le taux de reduction : ";
        cin >> taux;
        // Creer une nouvelle reduction
        auto* nouvelleReduction = new Reduction(firstentry, secondentry, taux);
        // Ajouter la nouvelle reduction pour le fournisseur selectionne
        fournisseurs[choixFournisseur - 1]->ajouterReduction(nouvelleReduction);
        cout << "Reduction ajoutee avec succes pour le fournisseur " << fournisseurs[choixFournisseur - 1]->getNomFournisseur() << "." << endl;
    } else {
        cout << "Choix de fournisseur invalide." << endl;
    }
    }
}

//Fonction pour editer une cave
void editCave() {
    if (caves.empty()) {
        cout << "Aucune cave n'a ete creee." << endl;
        return;
    }
    cout << "Liste des caves disponibles :" << endl;
    for (Cave* cave : caves) {
        cout << "ID: " << cave->getIdCave() << ", Nom: " << cave->getNomCave()<<", Adresse: "<<cave->getAdresseCave()<< endl;
    }
    string IdCave;
    cout << "Entrez l'ID de la cave que vous souhaitez modifier : ";
    cin >> IdCave;
    // Recherche de la cave avec l'ID donne dans la liste des caves
    auto it = find_if(caves.begin(), caves.end(), [IdCave](Cave *cave) {
        return cave->getIdCave() == IdCave;
    });
    if (it != caves.end()) {
        // La cave a ete trouvee
        cout << "Cave trouvee. Entrez les nouvelles informations :" << endl;
        string nouveauNom, nouvelleAdresse;
        cout << "Nouveau nom de la cave : ";
        cin >> nouveauNom;
        cout << "Nouvelle adresse de la cave : ";
        cin >> nouvelleAdresse;
        // Mettez à jour les informations de la cave
        (*it)->setNomCave(nouveauNom);
        (*it)->setAdresseCave(nouvelleAdresse);
        cout << "La cave a ete modifiee avec succes." << endl;
    } else {
        cout << "Aucune cave trouvee avec l'ID fourni." << endl;
    }
}

//Fonction qui ajoute un vin dans une cave
void ajouterVinaCave() {
    // Verifier si des caves et des vins existent
    if (caves.empty() || vins.empty()) {
        cout << "Veuillez creer au moins une cave et un vin avant d'ajouter un vin a une cave." << endl;
        return;
    }
    // Afficher la liste des caves
    cout << "Choisissez une cave : " << endl;
    for (size_t i = 0; i < caves.size(); ++i) {
        cout << i + 1 << ". " << caves[i]->getNomCave() << endl;
    }
    int choixCave;
    cout << "Votre choix : ";
    cin >> choixCave;
    // Verifier la validite du choix de la cave
    if (choixCave > 0 && choixCave <= static_cast<int>(caves.size())) {
        // Afficher la liste des vins
        cout << "Choisissez un vin : " << endl;
        for (size_t i = 0; i < vins.size(); ++i) {
            cout << i + 1 << ". " << vins[i]->getNomVin() << endl;
        }
        int choixVin;
        cout << "Votre choix : ";
        cin >> choixVin;
        // Verifier la validite du choix du vin
        if (choixVin > 0 && choixVin <= static_cast<int>(vins.size())) {
            // Entrer la quantite
            int quantite;
            cout << "Entrez la quantite : ";
            cin >> quantite;
            // Ajouter le vin à la cave avec la quantite
            caves[choixCave - 1]->ajouterVinAvecQuantite(vins[choixVin - 1], quantite);
        } else {
            cout << "Choix de vin invalide." << endl;
        }
    } else {
        cout << "Choix de cave invalide." << endl;
    }
}

//Fonction qui trouve la cave ou un vin est propose au meilleur prix en dependent d'un vin et de son mellinisme
void trouverCaveMeilleurPrix() {
    //affichage de la lite des vins
    cout<<"Liste des vins disponibles :"<<endl;
    for(int i=0; i<vins.size(); i++){
        cout<<i+1<<". "<<vins[i]->getNomVin()<<"("<<vins[i]->getMillesime()<<")"<<endl;
    }
    // Demander à l'utilisateur le nom du vin et son millesime
    string nomVin;
    int millesime;
    cout << "Entrez le nom du vin : ";
    cin >> nomVin;
    cout << "Entrez le millesime du vin : ";
    cin >> millesime;

    // Recherche du vin dans le stock de toutes les caves
    Fournir* fournitureTrouvee = nullptr;
    Cave* caveMeilleurPrix = nullptr;
    float prixMin = MAX_Val; // Initialiser le prix minimum à la valeur maximale possible
    for (Cave* cave : caves) {
        // Verifier si la cave a des stocks
        if (!cave->stockVide()) {
            Fournir* fournitureDansCave = cave->getFourniture(nomVin, millesime);
            if (fournitureDansCave != nullptr) {
                float prixFourniture = cave->calculerPrixFourniture(fournitureDansCave);
                // Mettre à jour la fournitureTrouvee si le prix actuel est inferieur au prix minimum enregistre
                if (prixFourniture < prixMin) {
                    prixMin = prixFourniture;
                    fournitureTrouvee = fournitureDansCave;
                    caveMeilleurPrix = cave;
                }
            }
        }
    }
    // Afficher les resultats
    if (fournitureTrouvee != nullptr) {
        cout << "La cave proposant le vin au meilleur prix est : " << caveMeilleurPrix->getNomCave()<<" au prix de : " << prixMin << "$" << endl;
    } else {
        cout << "Aucune fourniture trouvee pour le vin specifie." << endl;
    }
}





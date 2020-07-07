// ConsoleApplication1.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream> //E/S fichier
#include <string> //String
#include <vector> //tableau de vector
#include <array> //Tableau d'array
#include <algorithm> 
#include <numeric> //Produit et somme
#include <cctype> //Test de caractere PREDICAT
#include <functional> //Produit et somme aussi
#include <fstream> //Flux d'entree sorties

int main()
{
    /*
    //Tester l'affchage et les caractere speciaux tabulation, apostrophe et guillemet
    std::cout << "Il m'a demande \" Comment vas-tu ? \"" << std::endl;
    std::cout << "Dossier principal : \tC:\\Program Files (x86)" << std::endl;

    //Affichage sur les chiffres + explication sur les flottants
    std::cout << "1 + 2 = " << 1 + 2 << std::endl;
    std::cout << "1 - 4 = " << 1 - 4 << std::endl;
    std::cout << "7.5 * 2 = " << 7.5 * 2 << std::endl;
    std::cout << "9 / 2 = " << 9 / 2 << std::endl;
    std::cout << "9. / 2 = " << 9. / 2 << std::endl;
    std::cout << "9 % 2 = " << 9 % 2 << std::endl;

    //Ici on découvre la nouvelle forme du C++ moderne et on déclare un string
    int reponse{ 42 };
    std::string phrase22{ "Bonjour tout le monde !" };
    std::cout << "En entrant dans la salle, il s'écria : " << phrase22 << reponse << std::endl;
    */
    /*
    //Declaration d'une variable vide et il faut l'initialiser si on veut l'utiliser
    int entier5{};
    int entier2;
    std::cout << "Mon entier vaut " << entier5 << " et le 2eme " << entier2 << std::endl;
    
    //Le const permet de figer les variables, on met en MAJ. le const se met à droite ou a gauche pour les pointeurs
    double const PI{ 3.141592 };
    const double PI2{ 3.141592 };
    int someInt = { 2 };
    const int* p = &someInt; // La data ne peut pas etre changé
    int* const p2 = &someInt; //L'adresse ne peut pas etre changé
    */
    // Le compilateur déduit que 'entier' est de type 'int'.
    auto entier3{ 0 };

    //Pour les strings il faut rajouter le package puis rajouter s a la fin
    //using namespace std::literals;
    //auto chaine{ "Du texte."s };
    //std::cout << chaine << std::endl;

    //On utilise std::in l'entree clavier
    //Si on rentre un char a la place  d'un int il considere comme un False et n'execute pas tout les std::cin suivant
    std::cout << "Entre ton age : " << std::endl;
    int age{ 0 };
    bool success_marker{};
    // std::cin >> age;
    std::cout << "Tu as " << age << " ans.\n";
    // std::cin >> age;
    std::cout << "Tu as " << age << " ans.\n";

    /*On demande à l'utilisateur de rentrer un nombre correspondant
    à une heure. Puis nous lui retournerons le moment de la journée
    à laquel cette heure correspond. Nous allons traiter les cas
    tels que midi, minuit, un nombre non compris ou des lettres.
    *//*
    int hour_asked{};
    std::cin >> hour_asked;
    if (hour_asked >= 6 && hour_asked < 12)
    {
        std::cout << "C'est le matin" << std::endl;
    }
    else if (hour_asked > 12 && hour_asked <= 18)
    {
        std::cout << "C'est l'apres midi" << std::endl;
    }
    else if (hour_asked > 18 && hour_asked < 6 && hour_asked != 24)
    {
        std::cout << "C'est le soir" << std::endl;
    }
    else if (hour_asked == 24 || (std::cin.fail() == false && hour_asked == 0))
    {
        std::cout << "Il est minuit" << std::endl;
    }
    else if (hour_asked == 12)
    {
        std::cout << "Il est midi" << std::endl;
    }
    else if (std::cin.fail() == true)
    {
        std::cout << "Please only enter a number" << std::endl;
    }
    else
    {
        std::cout << "Not treated" << std::endl;
    }
    */

    /* Ce programme permet de verifier que l'entree utilisateur correspond
    au type designé sinon rebouclage
    // std::cin.clear()
    // std::cin.ignore()
    *//*
    std::cout << "Quel jour es-tu né ? ";
    int jour{ 0 };
    while (!(std::cin >> jour)) //Attention parenthese
    {
        std::cin.clear();
        std::cout << "Again 1 ";
        std::cin.ignore(255, '\n');
    }

    std::cout << "Quel mois es-tu né ? ";
    int mois{ 0 };
    while (!(std::cin >> mois))
    {
        std::cin.clear();
        std::cout << "Again 2";
        std::cin.ignore(255, '\n');
    }
    */
    /*
    int variable{};
    int var2{};
    std::cin >> variable >> var2;
    std::cout << variable;*/
    //BREAK => Casse la boucle dans laquel il se trouve
    //CONTINUE => saute l'iteration dans laquel il se trouve pour passer a 
    //          la suivante. Peut s'utiliser dans un while.

    /* -------------TABLEAU ---------------------------
    _______VECTOR________
    On commence avec les std::vector. Il ne faut pas oublier l'include.

    DECLARATION => std::vector<TYPE> VARIABLE {};
    AFFECTATION => VARIABLE[i]
    Ne pas acceder à un élément >i sinon UNDEFINED BEHAVIOR
    1er et DERNIER element => VARIABLE.front(); VARIABLE.back()
    TAILLE => std::size(TABLEAU); de type syze_t ou TABLEAU.size()
    AFFECTATION => auto const taill { std::size(TABLEAU) };
    AFFICHAGE => for(auto ELEMENT : TABLEAU) { std::cout << ELEMENT }
    VIDE/EMPTY => std::empty(TABLEAU)
    AJOUTER => push_back(VALUE); ajoute a la suite et modifie la taille
    RETIRER => pop_back(); retire derniere element Attention ne pas le faire quand vide
    REMPLIR => TABLEAU.assigne(nombre, value) nombre fois la valeur value

    Exercice pour calculer les moyennes
    */
    std::vector<double> tableau{};
    while (true)
    {
        std::cout << "rentrer une note negative pour sortir";
        double note{};

        while (!(std::cin >> note))
        {
            std::cout << "rentrer un double";
            std::cin.clear();
            std::cin.ignore(255,'\n');
        }
        if (note < 0)
        {
            break;
        }
        tableau.push_back(note);
    }
    double moyenne{};
    double somme{0.0};
    double nombre{0.0};
    for (auto element : tableau)
    {
        somme = somme + element;
        nombre = nombre + 1.0;

    }
    moyenne = somme / nombre;
    std::cout << moyenne;


//_______ARRAY________
//LA TAILLE EST FIGER A LA COMPILATION
    // Tableau contenant cinq entiers explicitement précisés.
    std::array<int, 5> const tableau_de_5_entiers { 1, 2, 3, 4, 5 };
    for (auto const element : tableau_de_5_entiers)
    {
        std::cout << element << std::endl;
    }

    // Tableau contenant deux décimaux définis puis cinq zéros.
    std::array<double, 7> const tableau_de_7_decimaux { 3.14159, 2.1878 };
    for (auto const element : tableau_de_7_decimaux)
    {
        std::cout << element << std::endl;
    }

    // Tableau qui a trop d'éléments et ne compilera pas.
    //std::array<int, 2> const tableau_qui_ne_compilera_pas { 1, 2, 3, 4 };

    // Il est tout à fait possible de copier un tableau.
    auto copie { tableau_de_5_entiers };
    for (auto const element : copie)
    {
        std::cout << element << std::endl;
    }


    //_______STRING________
    //TABLEAU DE CARACTERE
    std::string const phrase{ "Voici une phrase normale." };
    std::cout << "Voici la longueur de cette phrase : " << std::size(phrase) << " caractères." << std::endl;
    */

    /* -------------ITERATOR ---------------------------
    Agit un peu comme les pointeurs en C. Permet de parcourir les conteneur que ce soit de type
    array, vector etc. En effet certain conteneur comme list ne sont pas accessible via des crochet []

    std::vector<int> const tableau { -1, 28, 346 };
    std::vector<int>::const_iterator debut_tableau { std::begin(tableau) }; //Iterator du meme type, peut ne pas etre const
    auto fin_tableau { std::end(tableau) }; // Sinon on utilise auto

    std::vector<int> mon_tableau_int{ 2,4,6 };
    std::vector<int>::iterator mon_it{std::begin(mon_tableau_int)};
    auto fin_tableau{ std::end(mon_tableau_int) };
    //Toujours commencer par le debut ou la fin car on connait pas l'adresse
    std::cout << *mon_it;
    *mon_it = 5;
    std::cout << *mon_it;
    mon_it++;
    std::cout << *mon_it << std::endl;

    //PARCOURS d'un conteneur
    std::vector<int> tableau{ -1, 28, 346, 84 };

    for (auto it{ std::begin(tableau) }; it != std::end(tableau); ++it)
    {
        std::cout << *it << std::endl;
    }

    //CONSTANTE => pour le type de l'iterateur on peut plus modifier son adresse
    std::string phrase{ "Balut la famille" };
    auto const it_phrase{ std::begin(phrase) };
    *it_phrase = 'S';
    // it_phrase++; PAS POSSIBLE SI CONST
    std::cout << phrase << std::endl;

    //CONSTANTE => On ne peut plus modifier la valeur mais uniquement l'adresse
    auto iterateur_non_constant{ std::cbegin(phrase) };
    // Ceci est impossible.
    // *iterateur_non_constant = 'D';
    // Ceci est parfaitement autorisé.
    iterateur_non_constant = std::cend(phrase) - 1;
    //ON PEUT COMBINER LES 2
    //INVERSE => std::rbegin(CONTENEUR) & std::crbegin
    //INVERSE => std::rend(CONTNEEUR) & std::crend
    //Existe pour ne pas reculer en en i-- sinon on aurait pu partir de end ->begin
    //ERASE
    std::string phrase2{ "Voici une phrase beurk !" };
    // Jusqu'à la fin.
    phrase2.erase(std::begin(phrase2) + 16, std::end(phrase2));
    std::cout << phrase2 << std::endl;

    // --------OPERATEUR COUNT -------------
    std::string const phrase{ "Exemple illustrant le tutoriel C++ de Zeste de Savoir." };
    auto const total_phrase{ std::count(std::begin(phrase), std::end(phrase), 'e') };
    std::cout << "Dans la phrase entière, il y a " << total_phrase << " 'e' minuscule." << std::endl;

    // --------OPERATEUR FIND -------------
    // On obtient un ITERATEUR pointant sur le premier espace trouvé.
    // Si l'on n'avait rien trouvé, on aurait obtenu std::end(phrase) comme valeur de retour.
    std::string const phrase{ "Exemple illustrant le tutoriel C++ de Zeste de Savoir." };

    auto const iterateur_premier_mot{ std::find(std::begin(phrase), std::end(phrase), ' ') };

    // On peut donc s'en servir ici. Même si l'on modifie la longueur du premier mot, on est assuré que cette solution marche.
    auto const total_premier_mot{ std::count(std::begin(phrase), iterateur_premier_mot, 'e') };
    std::cout << "Dans le premier mot, il y a " << total_premier_mot << " 'e' minuscule." << std::endl;


    std::string phrase{};
    std::cin >> phrase;
    auto const iterateur_debut_phrase{ std::begin(phrase) };
    auto const iterateur_fin_phrase{ std::end(phrase) };
    auto iterateur_debut_mot{ iterateur_debut_phrase };
    auto iterateur_fin_mot{ std::find(iterateur_debut_phrase,iterateur_fin_phrase,' ') };
    std::string mot { iterateur_debut_mot,iterateur_fin_mot };
    std::cout << mot << std::endl;
    for (auto it{ iterateur_debut_mot }; it != iterateur_fin_mot; it++)
    {
        std::cout << *it;
    }
    auto count_mot{ std::count(iterateur_debut_phrase,iterateur_fin_phrase,'e') };
    if (iterateur_fin_mot == iterateur_fin_phrase && iterateur_debut_mot == iterateur_debut_phrase)
    {
        std::cout << "rien dans le mot entrer";
    }
    while (iterateur_fin_mot != iterateur_fin_phrase)
    {
        count_mot = std::count(iterateur_debut_mot, iterateur_fin_mot, 'e');
        mot = { iterateur_debut_mot,iterateur_fin_mot }; //PERMET d'afficher un mot a partir de 2 pointeur
        std::cout << "il y a " << count_mot << "dans " << mot;
        iterateur_debut_mot = iterateur_fin_mot+1;
        iterateur_fin_mot = std::find(iterateur_debut_mot, iterateur_fin_phrase, ' ');
        std::cout << std::endl;
    }
    if (iterateur_fin_mot == iterateur_fin_phrase && iterateur_debut_mot != iterateur_debut_phrase)
    {
        count_mot = std::count(iterateur_debut_mot, iterateur_fin_mot, 'e');
        mot = { iterateur_debut_mot,iterateur_fin_mot };
        std::cout << "il y a " << count_mot << "dans " << mot;
    }


    //STD::SORT permet de trier les conteneur non constant sauf LIST car il n'est que bidirectionnel
    //Pour LIST il existe deja une fonction => tableau.sort();
    //STD::REVERSE <= std::reverse(std::begin(nombres), std::end(nombres));
    std::vector<double> constantes_mathematiques{ 2.71828, 3.1415, 1.0836, 1.4142, 1.6180 };
    std::sort(std::begin(constantes_mathematiques), std::end(constantes_mathematiques));

    for (auto constante : constantes_mathematiques)
    {
        std::cout << constante << std::endl;
    }

    //STD::REMOVE <= enleve toute les iteration et les met a la fin de  la chaine car il ne peut pas modifier la taille du conteneur
    //    C'est pour cela qu'on utilise paroles.erase() qui vas supprimer le reste de la chaine pour nous;
    //STD::BOOLALPHA <= renvoie True or False selon l'evaluation pour le STR stream
    //STD::NOBOOLALPHA <= Inversement renvoi une valeur. Dure pour toute la suite du programme
    std::string paroles{ "I'm blue, da ba dee da ba daa !" };

    auto iterateur_fin{ std::remove(std::begin(paroles), std::end(paroles), 'b') };
    paroles.erase(iterateur_fin, std::end(paroles));

    std::cout << paroles << std::endl;


    auto num1{ 1 };
    auto num2{ 2 };
    std::cout << "eval :" << std::boolalpha << (num1 < num2);
    std::cout << "eval :" << (num1 < num2) << std::endl;

    std::string phrase{ "Salut les amis" };
    std::string mot{ "Salut" };
    auto it_debut{ std::begin(phrase) };
    auto it_fin{ std::end(phrase) };

    std::cout << std::boolalpha;

    std::cout << (std::search(it_debut, it_fin, std::begin(mot),std::end(mot))!=it_fin);
    mot = "loir";
    std::cout << (std::search(it_debut, it_fin, std::begin(mot),std::end(mot)) != it_fin);
    //STD::SEARCH
    //RENVOI TRUE OR FALSE si il a trouver le mot dans la phrase
    //STD::EQUAL(deb1,fin1,deb2,fin2) <= compare 2 ensemble


    //FONCTEUR : std::greater<TYPE> {(value1,value2)}
    //REnvoi true si val 1 > val 2
    std::cout << std::boolalpha << std::greater<int> {} (2, 1)  << std::endl;
    std::greater<double> foncteur{};
    std::cout << foncteur(1, 5);
    std::vector<int> tableau{ -8, 5, 45, -945 };
    std::sort(std::begin(tableau), std::end(tableau), std::greater<int> {});
    //Trie du plus grand au plus petit
    for (auto x : tableau)
    {
        std::cout << x << std::endl;
    }

    //Operation de SOMME et MULTIPLICATION
std::vector<int> const nombres{ 1,2,3,4,5 };
auto somme{ std::accumulate(std::cbegin(nombres),std::cend(nombres),0) }; //FAIT la somme
std::cout << somme;
auto produit{ std::accumulate(std::cbegin(nombres),std::cend(nombres),1,std::multiplies<int>{}) }; //Fait le produit
std::cout << produit;

//Predicat pour tester si LETTRE, CARACTERE, SIGNE
char const lettre{ ';' };
std::cout << std::boolalpha;
std::cout << std::boolalpha << "Minuscule " << std::islower(lettre) << std::endl; // Renvoi 2 ou 0
std::cout << "Majuscule " << std::isupper(lettre) << std::endl; //REnvoi 1 ou 0
std::cout << "Chiffre " << std::isdigit(lettre) << std::endl; //Renvoi 4 ou 0
std::cout << "Ponctuation " << std::ispunct(lettre) << std::endl; //Renvoi 16 ou 0
//std::all_of(std::cbegin(numero), std::cend(numero), isdigit)
//VERIFIE que toute la chaine correspond à une propriete

-----------------FLUX D'ENTREES SORTIES ----------------------------

//RAW STRING
std::cout << R"(Elle a dit "Va dans le dossier C:\Program Files" et regarde.)" << std::endl;
//std::cout << R"(Il a écrit "f(x)" au tableau.)" << std::endl; NE FONCTIONNE PAS a cause des delimiteurs
std::cout << R"&(Il a écrit "f(x)" au tableau.)&" << std::endl;

// OUTPUT STREAM FILE
//std::ofstream
    // Je veux ouvrir un fichier nommé 'sortie.txt', qui se trouve dans le dossier du projet.
    // S'il existe, il sera ouvert. Sinon, il sera d'abord créé puis ouvert.
//Supprime ce qui sera avant
std::ofstream fichier{ "sortie.txt" , std::ios::app};
//ios est pour E/S et app pour ajouter (append)
fichier << 3 << " " << 4;
fichier << std::string{ "une phrase" };

std::ifstream fichier{ "entree.txt" };
int entier;
fichier >> entier;
std::cout << "hekk fef" << entier;
std::string mot{ "" };
fichier >> mot;
std::cout << "yeah fe ef"  << mot;
    return 0;
}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer :
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
*/
}
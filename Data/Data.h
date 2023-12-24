// Created by abcd on 27/11/2023.

#ifndef TP2_DATA_H
#define TP2_DATA_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>


struct Grade {
    char *nom;
    int niveau;
};

char titles[][30] = {
        "Officiers Generaux",
        "Officiers Superieurs",
        "Officiers Subalternes",
        "Sous-Officiers",
        "Hommes du Rang"
};

struct Grade grades[] = {
        {"General d'Armee", 1},
        {"General de Corps d'Armee", 1},
        {"General Major", 1},
        {"General", 1},
        {"Colonel", 2},
        {"Lieutenant Colonel", 2},
        {"Commandant", 2},
        {"Capitaine", 3},
        {"Lieutenant", 3},
        {"Sous Lieutenant", 3},
        {"Aspirant", 3},
        {"Adjudant Major", 4},
        {"Adjudant Chef", 4},
        {"Adjudant", 4},
        {"Sergent Chef", 4},
        {"Sergent", 4},
        {"Caporal Chef", 5},
        {"Caporal", 5},
        {"Djoundi", 5}
};

char forceArmees[][50] = {
        "Forces Aeriennes",
        "Forces Navales",
        "Forces de Defense Aerienne du Territoire",
        "Gendarmerie Nationale",
        "Garde Republicaine",
        "Sante Militaire",
        "Departement du renseignement et de la securite,"
};

struct RegionMilitaire {
    char nom[30];
    int numero;
};

struct RegionMilitaire regionsMilitaires[] = {
        {"1RM-Blida", 1},
        {"2RM-Oran", 2},
        {"3RM-Bechar", 3},
        {"4RM-Ouargla", 4},
        {"5RM-Constantine", 5},
        {"6RM-Tamanrasset", 6}
};

struct Wilaya {
    char nom[30];
    int numero;
};

struct Wilaya wilayas[] = {
        {"Adrar", 1},
        {"Chlef", 2},
        {"Laghouat", 3},
        {"Oum El Bouaghi", 4},
        {"Batna", 5},
        {"Bejaia", 6},
        {"Biskra", 7},
        {"Bechar", 8},
        {"Blida", 9},
        {"Bouira", 10},
        {"Tamanrasset", 11},
        {"Tebessa", 12},
        {"Tlemcen", 13},
        {"Tiaret", 14},
        {"Tizi Ouzou", 15},
        {"Alger", 16},
        {"Djelfa", 17},
        {"Jijel", 18},
        {"Setif", 19},
        {"Saida", 20},
        {"Skikda", 21},
        {"Sidi Bel Abbes", 22},
        {"Annaba", 23},
        {"Guelma", 24},
        {"Constantine", 25},
        {"Medea", 26},
        {"Mostaganem", 27},
        {"M'Sila", 28},
        {"Mascara", 29},
        {"Ouargla", 30},
        {"Oran", 31},
        {"El Bayadh", 32},
        {"Illizi", 33},
        {"Bordj Bou Arreridj", 34},
        {"Boumerdes", 35},
        {"El Tarf", 36},
        {"Tindouf", 37},
        {"Tissemsilt", 38},
        {"El Oued", 39},
        {"Khenchela", 40},
        {"Souk Ahras", 41},
        {"Tipaza", 42},
        {"Mila", 43},
        {"Ain Defla", 44},
        {"Naama", 45},
        {"Ain Temouchent", 46},
        {"Ghardaia", 47},
        {"Relizane", 48},
        {"Tebessa", 49},
        {"Tissemsilt", 50},
        {"El Oued", 51},
        {"Khenchela", 52},
        {"Souk Ahras", 53},
        {"Tipaza", 54},
        {"Mila", 55},
        {"Ain Defla", 56},
        {"Naama", 57},
        {"Ain Temouchent", 58}
};

char groupesSanguins[][4] = {
        "A+", "A-", "B+", "B-",
        "AB+", "AB-", "O+", "O-"
};

const char *names[60] = {
        "Abadi", "Mansoor", "Saad", "Khalil", "Nazim",
        "Abbas", "Fars", "Chakib", "Suleiman", "Badawi",
        "Nasser", "Hakim", "Zubair", "Halim", "Talib",
        "Zin-din", "Salim", "Aymen", "Kazan", "Abdullah",
        "Aziz", "Said", "Mahmoud", "Daher", "Haddad",
        "Hadid", "Sharif", "Zarif", "Fahmy", "Ghanem",
        "Hadad", "Hamdan", "Jabar", "Kanaan", "Rahal",
        "Riyad", "Brahim", "Rami", "Moussaab", "Anis",
        "Abboud", "Fawaz", "Ghannam", "Issa", "Karam",
        "Najjar", "Abd-Rahman", "Wahhab", "Yousef", "Zarour",
        "Abedllah", "Oussama", "Chahine", "Yacine", "Islem",
        "Hanna", "Ibrahim", "Jalali", "Kassab", "Lutfi"
};

#endif //TP2_DATA_H

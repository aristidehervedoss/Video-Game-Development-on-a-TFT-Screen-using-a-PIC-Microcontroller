/* 
 * File:                DSPIC_TFT.H
 * Author:              Julien CLaudel
 * Comments:
 * Revision history:    26 juillet 2017
 */

#ifndef DEF_DSPIC_TFT
#define DEF_DSPIC_TFT

#include <xc.h> // include processor files - each processor file is guarded.  

/* Définiton des Entrées/sorties de commande de l'écran TFT*/

#define	TFT_CSX _RD10
#define	TFT_RSX _RD7
#define	TFT_DCX _RD9
#define	TFT_WRX _RD4
#define	TFT_RDX _RD5
#define	TFT_PWM _RD2

/* Définiton de plusieurs couleurs de base dont les couleurs primaires (couleurs 24 bits RGB) */

#define TFT_RED     0xFF,0x00,0x00
#define TFT_GREEN   0x00,0xFF,0x00
#define TFT_BLUE    0x00,0x00,0xFF
#define TFT_YELLOW  0xFF,0xFF,0x00
#define TFT_MAGENTA 0xFF,0x00,0xFF
#define TFT_CYAN    0x00,0xFF,0xFF
#define TFT_BLACK   0x00,0x00,0x00
#define TFT_WHITE   0xFF,0xFF,0xFF

#define TFT_ORANGE  0xED,0x7F,0x10
#define TFT_BROWN  0xCD,0x85,0x3F

/* Définiton des fonctions d'affichage pour l'écran TFT */


///////////////////////////fonctions de commande de base//////////////////////////////

// fonction permettant d'initialiser une écriture mémoire
void tft_write_mem (void);
// fonction permettant d'envoyer une commande
void tft_write_cmd (char);
// fonction permettant d'envoyer une donnée à l'écran
void tft_write_data (char);


////////////////////// fonction permettant d'initialiser l'écran/////////////////////
// mettre '0' comme argument par défaut///
// mettre '1' si l'écran et les couleurs sont inversés ///
void tft_init (int);


////////////////////////////////fonctions avancées/////////////////////////////////////

// fonction permettant d'afficher une couleur RGB pour le pixel courant (caractère R,G,B)
void tft_write_pixel (char,char,char);

// fonction permettant de remplir l'écran d'une couleur uniforme (caractères R,G,B)
void tft_full (char,char,char); 

// fonction permettant de désigner les bornes (colonnes) dune zone d'affichage (adresse de départ,Adresse de fin)
void tft_Column_Adress_set (unsigned int,unsigned int);

// fonction permettant de désigner les bornes (colonnes) d'une zone d'affichage (adresse de départ,Adresse de fin)
void tft_Page_Adress_set (unsigned int,unsigned int);

// fonction permettant de dessiner un rectangle
// arguments: (Couleur RGB, Départ colonne, Départ ligne, Fin colonne, Fin ligne )
void tft_square (char,char,char,unsigned int,unsigned int,unsigned int,unsigned int);

// fonction permettant de dessiner des carrés dans un écran partitionné en cases de 10x10
// arguments: (Couleur RGB, numéro de la case (verticale), numéro de la case (horizontale))
void tft_square_10 (char,char,char,unsigned int,unsigned int);

// fonction permettant de dessiner des carrés dans un écran partitionné en cases de 5x5
// arguments: (Couleur RGB, numéro de colonne, numéro de ligne)
void tft_square_5 (char,char,char,unsigned int, unsigned int);

// fonction permettant de dessiner un caractère (8x8 pixels) dans un écran partionné en bloc de 8x8 pixels
// arguments: (numéro de colonne, numéro de ligne,caractère à afficher, Couleur RGB caractère, couleur RGB fond)
void tft_char (unsigned int,unsigned int,char,char,char,char,char,char,char);

// fonction permettant d'afficher à l'écran un nombre entier en caractère de(8x8 pixels) dans un écran partionné en bloc de 8x8 pixels
// arguments: (nombre entier à afficher, numéro de colonne, numéro de ligne, Couleur RGB caractère, couleur RGB fond)
void tft_disp_int (int,unsigned int,unsigned int,char,char,char,char,char,char);

// fonction permettant d'afficher à l'écran un motif de N x N pixels dans un écran partionné en cases de N x N pixels
// Arguments: (nom du tableau contenant la texture,numéro de colonne, numéro de ligne, largeur en pixels(N) )
void tft_texture (char*,unsigned int,unsigned int,unsigned int);

/* Définiton des fonctions pour l'utilisation de l'écran tactile*/
//fonction donnant la position 
unsigned int TFT_vertical_pos (void);

unsigned int TFT_horizontal_pos (void);

#endif
/* 
 * File:                DSPIC_TFT.H
 * Author:              Julien CLaudel
 * Comments:
 * Revision history:    26 juillet 2017
 */

#ifndef DEF_DSPIC_TFT
#define DEF_DSPIC_TFT

#include <xc.h> // include processor files - each processor file is guarded.  

/* D�finiton des Entr�es/sorties de commande de l'�cran TFT*/

#define	TFT_CSX _RD10
#define	TFT_RSX _RD7
#define	TFT_DCX _RD9
#define	TFT_WRX _RD4
#define	TFT_RDX _RD5
#define	TFT_PWM _RD2

/* D�finiton de plusieurs couleurs de base dont les couleurs primaires (couleurs 24 bits RGB) */

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

/* D�finiton des fonctions d'affichage pour l'�cran TFT */


///////////////////////////fonctions de commande de base//////////////////////////////

// fonction permettant d'initialiser une �criture m�moire
void tft_write_mem (void);
// fonction permettant d'envoyer une commande
void tft_write_cmd (char);
// fonction permettant d'envoyer une donn�e � l'�cran
void tft_write_data (char);


////////////////////// fonction permettant d'initialiser l'�cran/////////////////////
// mettre '0' comme argument par d�faut///
// mettre '1' si l'�cran et les couleurs sont invers�s ///
void tft_init (int);


////////////////////////////////fonctions avanc�es/////////////////////////////////////

// fonction permettant d'afficher une couleur RGB pour le pixel courant (caract�re R,G,B)
void tft_write_pixel (char,char,char);

// fonction permettant de remplir l'�cran d'une couleur uniforme (caract�res R,G,B)
void tft_full (char,char,char); 

// fonction permettant de d�signer les bornes (colonnes) dune zone d'affichage (adresse de d�part,Adresse de fin)
void tft_Column_Adress_set (unsigned int,unsigned int);

// fonction permettant de d�signer les bornes (colonnes) d'une zone d'affichage (adresse de d�part,Adresse de fin)
void tft_Page_Adress_set (unsigned int,unsigned int);

// fonction permettant de dessiner un rectangle
// arguments: (Couleur RGB, D�part colonne, D�part ligne, Fin colonne, Fin ligne )
void tft_square (char,char,char,unsigned int,unsigned int,unsigned int,unsigned int);

// fonction permettant de dessiner des carr�s dans un �cran partitionn� en cases de 10x10
// arguments: (Couleur RGB, num�ro de la case (verticale), num�ro de la case (horizontale))
void tft_square_10 (char,char,char,unsigned int,unsigned int);

// fonction permettant de dessiner des carr�s dans un �cran partitionn� en cases de 5x5
// arguments: (Couleur RGB, num�ro de colonne, num�ro de ligne)
void tft_square_5 (char,char,char,unsigned int, unsigned int);

// fonction permettant de dessiner un caract�re (8x8 pixels) dans un �cran partionn� en bloc de 8x8 pixels
// arguments: (num�ro de colonne, num�ro de ligne,caract�re � afficher, Couleur RGB caract�re, couleur RGB fond)
void tft_char (unsigned int,unsigned int,char,char,char,char,char,char,char);

// fonction permettant d'afficher � l'�cran un nombre entier en caract�re de(8x8 pixels) dans un �cran partionn� en bloc de 8x8 pixels
// arguments: (nombre entier � afficher, num�ro de colonne, num�ro de ligne, Couleur RGB caract�re, couleur RGB fond)
void tft_disp_int (int,unsigned int,unsigned int,char,char,char,char,char,char);

// fonction permettant d'afficher � l'�cran un motif de N x N pixels dans un �cran partionn� en cases de N x N pixels
// Arguments: (nom du tableau contenant la texture,num�ro de colonne, num�ro de ligne, largeur en pixels(N) )
void tft_texture (char*,unsigned int,unsigned int,unsigned int);

/* D�finiton des fonctions pour l'utilisation de l'�cran tactile*/
//fonction donnant la position 
unsigned int TFT_vertical_pos (void);

unsigned int TFT_horizontal_pos (void);

#endif
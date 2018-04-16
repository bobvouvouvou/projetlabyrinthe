#include <stdio.h>
#include <stdlib.h>

#include "libgraphique.h"
#include "Fonctions.c"
#include "Creation_interactive.c"
#include "Enregistrements.c"
#include "Jeu_Interactif.c"
#include "Jeu_Automatique.c"
#include "Creation_Automatique.c"

#define MAX 100

int main (void)
{int i, j, Score, Choix, Choix2, Choix3, Choix4, Boucle ;
int x, y, x2, y2, n ;
FILE *f ;

start_graphics() ;

// Menu graphique
set_drawing_color (color_BLACK) ;
set_font (font_HELVETICA_18) ;
draw_string (240, 290, "The Maze Runner") ;
draw_string (160, 250, "CLERC Billy") ;
draw_string (320, 250, "DE JAHAM Charles") ;
set_font (font_HELVETICA_12) ;
draw_string (200, 210, "Pour commencer, appuyez sur une touche") ;
update_graphics () ;
get_key () ;

do
{

  // Initialisation MUR
  int MUR [MAX][MAX] ;
  int MUR2 [MAX][MAX] ;
  for (i = 0 ; i < MAX ; i++)
    {for (j = 0 ; j < MAX ; j++)
      {MUR[i][j] = 1 ;
      }
    }

  // Menu 1
  clear_screen () ;
  set_drawing_color (color_BLACK) ;
  set_font (font_HELVETICA_18) ;
  draw_string (100, 400, "Entrez le chiffre correspondant à votre choix :") ;
  set_font (font_HELVETICA_12) ;
  draw_string (120, 360, "1 : Construction interactive d'un labyrinthe") ;
  draw_string (120, 320, "2 : Construction automatique d'un labyrinthe") ;
  draw_string (120, 280, "3 : Jouer a un labyrinthe precedemment sauvegarde") ;
  draw_string (120, 240, "4 : Resolution automatique d'un labyrinthe sauvegarde") ;
  update_graphics () ;
  Choix = get_key () - 48 ;

  if (Choix == 1)
  {
    // Taille du labyrinthe
    clear_screen () ;
    set_drawing_color (color_BLACK) ;
    set_font (font_HELVETICA_18) ;
    draw_string (100, 290, "Le labyrinthe que vous allez construire sera un carre") ;
    set_font (font_HELVETICA_12) ;
    draw_string (120, 250, "Saisir le parametre n correspondant aux nombres de lignes/colonnes") ;
    update_graphics () ;
    n = get_key () - 48 ;
    clear_screen () ;
    update_graphics () ;

    x=30 , y= (n*60)-30, x2 = 0, y2 = n - 1 ;

    // Créer labyrinthe Interactivement
    Grille (n) ;
    Creer_Curseur (&x, &y) ;
    Mouvement_Creation (&x, &y, &x2, &y2, n, MUR) ;
    set_drawing_color (color_BLACK) ;
    set_font (font_HELVETICA_12) ;
    draw_string (530, 210, "Pour finir,") ;
    draw_string (490, 170, "appuyez sur une touche") ;
    update_graphics () ;
    get_key () ;

    // Choix emplacement de sauvegarde
    clear_screen () ;
    set_drawing_color (color_BLACK) ;
    set_font (font_HELVETICA_18) ;
    draw_string (100, 400, "Entrez le chiffre correspondant à votre choix :") ;
    set_font (font_HELVETICA_12) ;
    draw_string (120, 360, "1 : Sauvegarde du labyrinthe dans 'Labyrinthe1.txt'") ;
    draw_string (120, 320, "2 : Sauvegarde du labyrinthe dans 'Labyrinthe2.txt'") ;
    draw_string (120, 280, "3 : Sauvegarde du labyrinthe dans 'Labyrinthe3.txt'") ;
    update_graphics () ;
    Choix2 = get_key () - 48 ;

    if (Choix2 == 2)
      // Enregister dans 'Labyrinthe2.txt'
      {f = fopen ("Labyrinthe2.txt", "w") ;
      Enregistrement (f, MUR) ;
      fclose (f) ;
      f = fopen ("Labyrinthe2n.txt", "w") ;
      Enregistrement_n (f, n) ;
      fclose (f) ;
      }

    if (Choix2 == 3)
      // Enregister dans 'Labyrinthe3.txt'
      {f = fopen ("Labyrinthe3.txt", "w") ;
      Enregistrement (f, MUR) ;
      fclose (f) ;
      f = fopen ("Labyrinthe3n.txt", "w") ;
      Enregistrement_n (f, n) ;
      fclose (f) ;
      }

     else
       // Enregister dans 'Labyrinthe1.txt' si le Choix2 ne correspond ni à 2 ni à 3
       {f = fopen ("Labyrinthe1.txt", "w") ;
       Enregistrement (f, MUR) ;
       fclose (f) ;
      f = fopen ("Labyrinthe1n.txt", "w") ;
      Enregistrement_n (f, n) ;
      fclose (f) ;
       }

  Boucle = 1 ;
  }

  if (Choix == 2)
    {}

  if (Choix == 3)
    {

    // Choix emplacement de chargement
    clear_screen () ;
    set_drawing_color (color_BLACK) ;
    set_font (font_HELVETICA_18) ;
    draw_string (100, 400, "Entrez le chiffre correspondant à votre choix :") ;
    set_font (font_HELVETICA_12) ;
    draw_string (120, 360, "1 : Chargement du labyrinthe dans 'Labyrinthe1.txt'") ;
    draw_string (120, 320, "2 : Chargement du labyrinthe dans 'Labyrinthe2.txt'") ;
    draw_string (120, 280, "3 : Chargement du labyrinthe dans 'Labyrinthe3.txt'") ;
    update_graphics () ;
    Choix3 = get_key () - 48 ;

    if (Choix3 == 2)
      // Charger 'Labyrinthe2.txt'
      {f = fopen ("Labyrinthe2n.txt", "r") ;
      Charger_n (f, &n) ;
      fclose (f) ;
      f = fopen("Labyrinthe2.txt", "r") ;
      Charger_Labyrinthe (f, MUR2) ;
      fclose (f) ;
      }

    if (Choix3 == 3)
      // Charger 'Labyrinthe3.txt'
      {f = fopen ("Labyrinthe3n.txt", "r") ;
      Charger_n (f, &n) ;
      fclose (f) ;
      f = fopen("Labyrinthe3.txt", "r") ;
      Charger_Labyrinthe (f, MUR2) ;
      fclose (f) ;
      }

     else
      // Charger 'Labyrinthe1.txt' si le Choix3 ne correspond ni à 2 ni à 3
      {f = fopen ("Labyrinthe1n.txt", "r") ;
      Charger_n (f, &n) ;
      fclose (f) ;
      f = fopen("Labyrinthe1.txt", "r") ;
      Charger_Labyrinthe (f, MUR2) ;
      fclose (f) ;
      }

    clear_screen () ;
    set_drawing_color (color_BLACK) ;
    set_font (font_HELVETICA_18) ;
    draw_string (100, 400, "Entrez le chiffre correspondant à votre choix :") ;
    set_font (font_HELVETICA_12) ;
    draw_string (120, 360, "1 : Jouer en voyant les limites du labyrinthe") ;
    draw_string (120, 320, "2 : Jouer en decouvrant les limites du labyrinthe") ;
    update_graphics () ;
    Choix4 = get_key () - 48 ;

    if (Choix4 == 2)
      // Jeu du joueur avec limite invisible
      {clear_screen () ;
      Grille_Limites (n) ;
      x=30 , y= (n*60)-30, x2 = 0, y2 = n - 1 ;
      Score = 0 ;
      Creer_Curseur (&x, &y) ;
      Mouvement_Jeu_Limites_Invisibles (&x, &y, &x2, &y2, n, MUR2, &Score) ;
      printf("%d\n", Score) ;
      get_key () ;
      }

    else
      // Générer labyrinthe et jeu joueur (limite visible)
      {clear_screen () ;
      Generer_Labyrinthe (n, MUR2) ;
      x=30 , y= (n*60)-30, x2 = 0, y2 = n - 1 ;
      Score = 0 ;
      Creer_Curseur (&x, &y) ;
      Mouvement_Jeu_Limites_Visibles (&x, &y, &x2, &y2, n, MUR2, &Score) ;
      printf("%d\n", Score) ;
      get_key () ;
      }

    Boucle = 1 ;
  }

  if (Choix == 4)
    {}

}
while (Boucle == 1) ;

stop_graphics () ;
return 0 ;
}

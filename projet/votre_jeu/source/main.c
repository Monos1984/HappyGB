/*************************************
* Programme vierge pour Happylib GB  *
* 02 / 01 / 20                       *
**************************************/

// ===========================
// * Fichier includes du SDK *
// ===========================
#include <happylib_gb.h>


// =================
// * Fonction main *
// =================
void main()
{
  
  // -----------------------
  // * Boucle du programme *
  // -----------------------
  while(1)
  {
  
    // ---------------
    // * Zone du VBL *
    // ---------------
    Wait_VBL();  
     
    update_sprite(); // Affichage des sprites
 
    // --------------------------------------
    // * Fin du VBL début d'affichage vidéo *
    // --------------------------------------
    End_VBL();
  }

}
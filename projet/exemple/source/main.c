/*************************************
* Programme Exemple pour Happylib GB *
* 02 / 01 / 20                       *
**************************************/

// ===========================
// * Fichier includes du SDK *
// ===========================
#include <happylib_gb.h>

// =================================
// * Déclaration Externe des datas *
// =================================
extern unsigned char data_tiles[];
extern unsigned char data_player_sprite[];

// ===================================
// * Création de la fonction player  *
// ===================================
void player_sprite(unsigned char px,unsigned char py)
{
  sprite[1].position_x=px;
  sprite[1].position_y=py;
  sprite[1].pattern=1;
  sprite[1].mask_sprite=0;

  sprite[2].position_x=px+8;
  sprite[2].position_y=py;
  sprite[2].pattern=3;
  sprite[2].mask_sprite=0;
  
  sprite[3].position_x=px;
  sprite[3].position_y=py+8;
  sprite[3].pattern=2;
  sprite[3].mask_sprite=0;

  sprite[4].position_x=px+8;
  sprite[4].position_y=py+8;
  sprite[4].pattern=4;
  sprite[4].mask_sprite=0;
}



// =================
// * Fonction main *
// =================
void main()
{
  // -----------------------------
  // * Déclaration des variables *
  // -----------------------------
  unsigned char t = 0;
  unsigned char i;
  unsigned char j = 0;
  unsigned char player_px=32;
  unsigned char player_py=32;
  
  // --------------
  // * Initiation *
  // --------------
  LCDC_OFF();         // Ecran étein
  BG_data_0x8800(); 
  BG_ON();            // Activation du background
  Sprite_8();         // Sprite mode 8x8
  Sprite_ON();        // Affichage des sprites
  BG_0x9800();
   
  // --------------------
  // * Palette sprite 0 *
  // --------------------
  POKE(0XFF48,0b00100100);  

  // ------------------------------------------
  // * Mise en mémoire des tiles dans la VRAM *
  // ------------------------------------------
  Set_Vram(data_tiles,TILES_DATA+32, 16);
 
  // --------------------------------
  // * Chargement des tiles sprites *
  // --------------------------------
  Set_Vram(data_player_sprite,SPRITE_DATA+16,64);

  // ----------------------------------
  // * Affichage d'une simple tilemap *
  // ----------------------------------
  for (i=0;i<10;i++)
  {
    draw_tiles(i,0,0x82,BG_DISPLAY_D1); 
draw_tiles(i,1,0x82,BG_DISPLAY_D1); 
  }

  LCDC_ON(); // Activation de l'écran

  // -----------------------
  // * Boucle du programme *
  // -----------------------
  while(1)
  {

    // ------------------------------------------
    // * Test simple des entrées de la Game Boy *
    // ------------------------------------------
    if (get_key_input() & PAD_DROITE)
    {
      player_px=player_px+1;
    }
    if (get_key_input() & PAD_GAUCHE)
    {
      player_px=player_px-1;
    }
    if (get_key_input() & PAD_HAUT)
    {
      player_py=player_py-1;
    }

    if (get_key_input() & PAD_BAS)
    {
      player_py=player_py+1;
    }

    if (get_key_input()& PAD_BTN_START)
    {
      player_px=0;
    }

    
    if (get_key_input()& PAD_BTN_SELECT)
    {
      player_py=0;
    }
    
    // --------------------------------
    // * update des données du player *
    // --------------------------------
    player_sprite(player_px,player_py);

  

  
    // ---------------
    // * Zone du VBL *
    // ---------------
    Wait_VBL();  
       move_scrolling_x(-1);
    // ------------------------------------
    // * Mise à jour des sprites machines *
    // ------------------------------------
   
   update_sprite();
 
    // --------------------------------------
    // * Fin du VBL début d'affichage vidéo *
    // --------------------------------------
    End_VBL();
  }

}
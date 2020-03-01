// *************************************
// *              HAPY GB              *
// ************************************* 
// * Auteur ......... : Jean Monos     *
// * Fichier ........ : HAPPYGB.H      *
// * Version ........ : 0.0.0b         *
// * Mise à jour..... : 30/12/2019     *
// * Compilateur .... : SDCC           *
// *************************************


#ifndef HAPYGB_H
  #define HAPYGB_H
  
  // ===========================
  // ** define de la ram map  **
  // ===========================
  #define SPRITE_DATA         0x8000 // Adresse de la VRAM des sprites
  #define TILES_DATA          0x8800 // Adresse de la VRAM des tiles 
  #define WINDOW_DATA         0x9000 // Adresse de la VRAM des tiles Windows
  #define BG_DISPLAY_D1       0x9800 // Adresse Tilemap 1
  #define BG_DISPLAY_D2       0x9C00 // Adresse Tilemap 2
  #define LCD_REG             0xFF40 // Registre du LCDC
  
  #define SPRITE_OAM          0xFE00 // Début de la zone OAM pour les sprites.
                                     // +0 : position Y du sprite 0
                                     // *1 : position X du sprite 0
                                     // *2 : pattern du sprite 0
                                     // *3 : attribut du sprute 0
                                     // +4 : position y du sprite 1...

  #define SCX_REG             0xFF43 // Registre du scrolling X
  #define SCY_REG             0xFF42 // Registre du scrolling Y
  #define LY_REG              0xFF44 // Registre ligne Vblank
  #define P1_REG              0xFF00 // Registre de la gestion des entrées
  #define TAC_REG             0XFF07 // Registre du TAC
  
  // ======================
  // * Registre du Window *
  // ======================
  #define WX_REG              0xFF4B // Registre de la position du Window en X
  #define WY_REG              0xFF4A // Registre de la position du Window en Y
  
  // =====================================
  // * Registre des palettes de couleurs *  
  // =====================================
  #define BGP_REG             0xFF47 // Palette Background/windows
  #define OBP0_REG            0xFF48 // Palette Sprite 1
  #define OBP1_REG            0xFF49 // Palette Sprite 2
  
  // =============================
  // * Registre des interuptions *
  // =============================
  #define IE_REG              0xFFFF // Registre interupt Enable. 

  // ====================================
  // * Attribut sprites (masque sprite) *
  // ====================================
  /*
     Define d'attribue dans le masque attribut des sprites
     utiliser le séparateur | pour cumuler des effets.
     Exemple :  sprite[1].mask_sprite = SPRITE_FLIP_VERTICAL | SPRITE_PALETTE_2;
  */

  #define SPRITE_PRIORITE_BG     0b10000000
  #define SPRITE_FLIP_VERTICAL   0b01000000
  #define SPRITE_FLIP_HORIZONTAL 0b00100000
  #define SPRITE_PALETTE_2       0b00010000
  
  // ======================
  // * Define des touches *
  // ======================
  #define PAD_DROITE     0b00010000
  #define PAD_GAUCHE     0b00100000
  #define PAD_HAUT       0b01000000
  #define PAD_BAS        0b10000000
  #define PAD_BTN_A      0b00000001
  #define PAD_BTN_B      0b00000010
  #define PAD_BTN_START  0b00001000
  #define PAD_BTN_SELECT 0b00000100

  // ===================
  // * Registre Sonore *
  // ===================
  
  // -----------
  // * Canal 1 *
  // -----------
  #define NR10 0xFF10
  #define NR11 0xFF11
  #define NR12 0xFF12   
  #define NR13 0xFF13
  #define NR14 0xFF14

  // -----------
  // * Canal 2 *
  // -----------

  #define NR21 0xFF16
  #define NR22 0xFF17
  #define NR23 0xFF18
  #define NR24 0xFF19
  
  // -----------
  // * Canal 3 *
  // -----------
  #define NR30 0xFF1A
  #define NR31 0xFF1B
  #define NR32 0xFF1C   
  #define NR33 0xFF1D
  #define NR34 0xFF1E

  // -----------
  // * Canal 4 *
  // -----------
  #define NR41 0xFF20
  #define NR42 0xFF21
  #define NR43 0xFF22  
  #define NR44 0xFF23

  // -----------------
  // * Sound control *
  // -----------------
  #define NR50 0xFF24 
  #define NR51 0xFF25
  #define NR52 0xFF26
  // ==================================================
  // ** Gestion Video  (Registre LCDC 0xFF40)        **
  // ==================================================
  
  // ---------------------------------------
  // * Wait_VBL()                          *
  // ---------------------------------------
  /* 
    Permet d'attendre le début du V Blank    
  */
   void Wait_VBL(void) ;
  

  // ---------------------------------------
  // * end_VBL()                          *
  // ---------------------------------------
  /* 
    Permet d'attendre le fin du V Blank    
  */
   void End_VBL(void) ;
  // ---------------------------------------
  // * BG_ON()                            *
  // ---------------------------------------
  /* 
    Permet d'activer le background
  */
  void BG_ON(void);

  // ---------------------------------------
  // * BG_OFF()                            *
  // ---------------------------------------
  /* 
    Permet desactiver le background
  */
  void BG_OFF(void);
  
  // ---------------------------------------
  // * Sprite_ON()                         *
  // ---------------------------------------
  /* 
    Permet d'activer l"affichage des sprites
  */
  void Sprite_ON(void);
  
  // ---------------------------------------
  // * Sprite_OFF()                        *
  // ---------------------------------------
  /* 
    Permet de désactiver l'affichage des sprites
  */
  void Sprite_OFF(void);
  
  // -------------------------------------
  // * Sprite_8()                        *
  // -------------------------------------
  /* 
    Mode 8x8 des sprites
  */
  void Sprite_8(void);
  
  // -------------------------------------
  // * Sprite_16()                       *
  // -------------------------------------
  /* 
    Mode 8x16 des sprites
  */
  void Sprite_16(void);
  
  // -------------------------------------
  // * BG_0x9800()                       *
  // -------------------------------------
  /* 
    Zone background en 0x9800
  */
  void BG_0x9800(void);
  
  // -------------------------------------
  // * BG_0x9C00()                       *
  // -------------------------------------
  /* 
    Zone background en 0x9C00
  */
  void BG_0x9C00(void);
  
  
  // ------------------------------------------
  // * BG_data_0x8800()                       *
  // ------------------------------------------
  /* 
    Lecture du pattern des tiles en 0x8800
  */
  void BG_data_0x8800(void);
  
  // ------------------------------------------
  // * BG_data_0x8000()                       *
  // ------------------------------------------
  /* 
    Lecture du pattern des tiles en 0x8000
  */
  void BG_data_0x8000(void);
  
  
  // -------------------------------------
  // * LCDC_ON()                       *
  // -------------------------------------
  /* 
    Active l'affichage Vidée
  */
  void LCDC_ON(void);
  
  // -------------------------------------
  // * LCDC_OFF()                        *
  // -------------------------------------
  /* 
    Desactive l'affichage Video
  */
  void LCDC_OFF(void);
  
  // ===============
  // ** Scrolling **
  // ===============
  void set_scrolling_x(unsigned char id_scrolling);
  void set_scrolling_y(unsigned char id_scrolling);
  unsigned char get_scrolling_x();
  unsigned char get_scrolling_y();
void move_scrolling_x(unsigned char id);
void move_scrolling_y(unsigned char id);
  // ===========================
  // ** Gestion de la mémoire **
  // ===========================
  
// ---------------------------------
// * Set_Vram(source,cible,taille) *
// ---------------------------------
/*
  Permet de mémoriser des donnés en mémoire vram. 
  source : Nom du tableau de donnée.
  cible : adresse de destination. 
  size  : taille en octet du tableau.

*/
void Set_Vram(unsigned char *source,unsigned int cible, unsigned int size);


  // ---------------------------------------
  // * PEEK(addr)                          *
  // ---------------------------------------
  /* 
    Permet de lire un octet à une adresse 
    * addr : Adresse mémoire sur 2 octets (int )
  */
 
  #define PEEK(addr)         (*(unsigned char*) (addr))
  
  // ---------------------------------------
  // * POKE(adrr,val)                      *
  // ---------------------------------------
  /* 
    Permet d'écrire un octet à une adresse
    * addr : Adresse mémoire sur 2 octets (int)
    * val  : valeur 1 octet (0-255) 
  */
  
  #define POKE(addr,val)     (*(unsigned char*) (addr) = (val))
  


  // =====================
  // * Gestion des tiles *
  // =====================
  
  // -------------------------------
  // * Afficher un tiles à l'écran *
  // -------------------------------
  /*
   position_x : Position horizontale entre 0 et 31
   position_y : position verticale entre 0 et 31
   id_tiles : numéros du tiles entre 0 et 255
   adr_tilmap :  BG_DISPLAY_D1  ou  BG_DISPLAY_D2  
  */
 
  void draw_tiles(unsigned char position_x,unsigned char position_y,unsigned char id_tiles,unsigned int adr_tilemap);  


  // =========================
  // ** Gestion des sprites **
  // =========================

  // ---------------------------------------------
  // * Structure des sprites                     *
  // ---------------------------------------------
  typedef struct
	{
		unsigned char position_y;
		unsigned char position_x;
		unsigned char pattern;
    unsigned char mask_sprite;
	} stucture_sprite;
  
  extern stucture_sprite sprite[40];

  // ---------------------------------------
  // * update_sprite()                     *
  // ---------------------------------------
  /* 
    Enregistre dans les registres sprites les 40 sprites dispo 
  */
  void update_sprite();
  


  // ======================
  // ** Gestion du timer **
  // ======================

  // ------------------
  // * Timer_On()     *
  // ------------------
  /* 
    Active le Timer 
  */
  void Timer_On(void);

  // ------------------
  // * Timer_Off()    *
  // ------------------
  /* 
    Desactive le Timer 
  */
  void Timer_Off(void);
  
  // ------------------
  // * Get_Timer()    *
  // ------------------
  /*
    Recupére la valeur du timer
  */
  unsigned char Get_Timer(void);

  // =========================== 
  // ** Gestion des commandes **
  // ===========================
  void get_input(void);
  unsigned char get_key_input();
  unsigned char get_key_input_press();
#endif
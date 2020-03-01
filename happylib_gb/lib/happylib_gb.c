#include <happylib_gb.h>
#include <stdbool.h>
#include <string.h>


stucture_sprite sprite[40];

// ======================================
// ** Mise en mémoire VRAM des données **
// ======================================
void Set_Vram(unsigned char *source,unsigned int cible, unsigned int size)
{
 unsigned int i;
 for (i=0;i<size;i++)
 POKE(cible+i,*(source+i));

}


// ===============================
// ** Activer le timer          **
// ===============================
void Timer_On(void)
{
  // POKE(0xFF07, PEEK (0xFF07) | 0b00000100);
  POKE(0xFF07, PEEK (0xFF07) |(1<<2));
}

// ===============================
// ** Desactiver le timer       **
// ===============================
void Timer_Off(void)
{
  POKE(0xFF07, PEEK (0xFF07) & 0b11111011);

}

// ===============================
// ** Recuperer le temps        **
// ===============================
unsigned char Get_Timer(void)
{
  return PEEK (0xFF05);

}

// ===========================
// ** Attente du VBL        **
// ===========================
void Wait_VBL(void) 
{

 while((PEEK(0xFF44))< 144)
 {}


}

void End_VBL(void) 
{

 while(PEEK(0xFF44) >= 144)
 {

 }


}

// ===========================
// ** Activer le Background **
// ===========================
void BG_ON(void)
{
  POKE(LCD_REG, PEEK (0xFF40) | 0b00000001);  
}

// ==============================
// ** Desactiver le Background **
// ==============================
void BG_OFF(void)
{
  POKE(LCD_REG, PEEK (0xFF40) & 0b11111110);  
}


// =====================================
// ** Activer l'affichage des sprites **
// =====================================
void Sprite_ON(void)
{
  // POKE(LCD_REG, PEEK (0xFF40) | 0b00000010);
  POKE(LCD_REG, PEEK (0xFF40) | (1<<1));
}

// ========================================
// ** Desactiver l'affichage des sprites **
// ========================================
void Sprite_OFF(void)
{
  POKE(LCD_REG, PEEK (0xFF40) & 0b11111101);
  
}

// ===========================
// ** Mode 8x8 des sprites  **
// ===========================
void Sprite_8(void)
{
  POKE(LCD_REG, PEEK (0xFF40) & 0b11111011);
}

// ===========================
// ** Mode 8x16 des sprites **
// ===========================
void Sprite_16(void)
{
  POKE(LCD_REG, PEEK (0xFF40) | 0b00000100);
}

// ===========================
// ** Background en 0x9800  **
// ===========================
void BG_0x9800(void)
{
  POKE(LCD_REG, PEEK (0xFF40) & 0b11110111);
}

// ===========================
// ** Background en 0x9C00 **
// ===========================
void BG_9C00(void)
{
  POKE(LCD_REG, PEEK (0xFF40) | 0b00001000);
}


// ================================
// ** Background_Data en 0x8800  **
// ================================
void BG_data_0x8800(void)
{
  POKE(LCD_REG, PEEK (0xFF40) & 0b11101111);
}

// ================================
// ** Background_Data en 0x8000  **
// ================================
void BG_data_0x8000(void)
{
  POKE(LCD_REG, PEEK (0xFF40) | 0b00010000);
}

// ===================================
// ** Desactiver l'affichage video  **
// ===================================
void LCDC_OFF(void)
{
  POKE(LCD_REG, PEEK (0xFF40) & 0b01111111);
}

// ===============================
// ** Activer l'affichage video **
// ===============================
void LCDC_ON(void)
{
  POKE(LCD_REG, PEEK (0xFF40) | 0b10000000);
}

// =========================
// ** Updater les sprites **
// =========================
void update_sprite()
{
 
unsigned char i=0;
unsigned int j=0;


#define SPRITE_DATA_UP  POKE(0xFE00+j,sprite[i].position_y); POKE(0xFE01+j,sprite[i].position_x); POKE(0xFE02+j,sprite[i].pattern); POKE(0xFE03+j,sprite[i].mask_sprite); i++;j=j+4;


SPRITE_DATA_UP
SPRITE_DATA_UP
SPRITE_DATA_UP
SPRITE_DATA_UP
SPRITE_DATA_UP
SPRITE_DATA_UP
SPRITE_DATA_UP
SPRITE_DATA_UP
SPRITE_DATA_UP
SPRITE_DATA_UP
SPRITE_DATA_UP
SPRITE_DATA_UP
SPRITE_DATA_UP
SPRITE_DATA_UP
SPRITE_DATA_UP
SPRITE_DATA_UP
SPRITE_DATA_UP
SPRITE_DATA_UP
SPRITE_DATA_UP
SPRITE_DATA_UP
SPRITE_DATA_UP
SPRITE_DATA_UP
SPRITE_DATA_UP
SPRITE_DATA_UP
SPRITE_DATA_UP
SPRITE_DATA_UP
SPRITE_DATA_UP
SPRITE_DATA_UP
SPRITE_DATA_UP
SPRITE_DATA_UP
SPRITE_DATA_UP
SPRITE_DATA_UP
SPRITE_DATA_UP
SPRITE_DATA_UP
SPRITE_DATA_UP
SPRITE_DATA_UP
SPRITE_DATA_UP
SPRITE_DATA_UP
SPRITE_DATA_UP
SPRITE_DATA_UP
  
}

// ==========================
// ** Fonction  get_input  **
// ==========================
void get_input(void) 
{     
  
  __asm
  LD A,#0x20 
  LD (0xFF00),A 
  LD A,(0xFF00)
  LD A,(0xFF00) 
  CPL 
  AND #0x0F 
  SWAP A
  LD B,A 
  LD A,#0x10
  LD (0xFF00),A 
  LD A,(0xFF00)
  LD A,(0xFF00)
  LD A,(0xFF00)
  LD A,(0xFF00)
  LD A,(0xFF00)
  LD A,(0xFF00)
  CPL
  AND #0x0F 
  OR B 
  LD B,A 
  LD A,(0xFF8B) 
  XOR B 
  AND B 
  LD (0xFF8C),A 
  LD A,B 
  LD (0xFF8B),A 
  LD A,#0x30 
  LD (0xFF00),A 

  __endasm;

  
}

unsigned char get_key_input()
{
  get_input();
  return PEEK(0xFF8B);
}

unsigned char get_key_input_press()
{
  get_input();
  return PEEK(0xFF8c);
}


// ========================
// * Gestion du scrolling *
// ========================
void set_scrolling_x(unsigned char id_scrolling)
{
   POKE(SCX_REG,id_scrolling);
}

void set_scrolling_y(unsigned char id_scrolling)
{
   POKE(SCY_REG,id_scrolling);
}

unsigned char get_scrolling_x()
{
  return PEEK(SCX_REG);
}

unsigned char get_scrolling_y()
{
  return PEEK(SCY_REG);
}

void move_scrolling_x(unsigned char id)
{
 POKE(SCX_REG,PEEK(SCX_REG)+id);

}

void move_scrolling_y(unsigned char id)
{
 POKE(SCY_REG,PEEK(SCY_REG)+id);

}
// =====================
// * Afficher un tilrd *
// =====================
void draw_tiles(unsigned char position_x,unsigned char position_y,unsigned char id_tiles,unsigned int adr_tilemap)
{

  POKE((position_y<<5)+position_x+adr_tilemap,id_tiles);


}
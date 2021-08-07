#include <allegro.h>
#include <stdio.h>
#include <stdlib.h>

void init();
void deinit();

BITMAP *buffer;
BITMAP *imggameover; // tela de Game Over
int p1pts = 0; //Pontos do jogador 1
int p2pts = 0; //Pontos do jogador 2
int p1card = 0; //Recebe o valor da carta escolhida pelo player 1 | 0 == vazia
int p2card = 0; //Recebe o valor da carta escolhida pelo player 2 | 0 ==  vazia

int main() {
	init();
    //Declaração de variável
     
    //BITMAP *bgi; // BackGround Image - Imagem de fundo
    
    /*Declaração das variáveis que carregarão as imagens das cartas; 
    o número representa seu índice no array cardstate, on pra carta ativa e off para inativa*/
    BITMAP *cardimg00on;
    //BITMAP *cardimg00off;
    BITMAP *cardimg01on;
    //BITMAP *cardimg01off;
    BITMAP *cardimg02on;
    //BITMAP *cardimg02off;
    BITMAP *cardimg03on;
    //BITMAP *cardimg03off;
    BITMAP *cardimg04on;
    //BITMAP *cardimg04off;
    BITMAP *cardimg05on;
    BITMAP *cardimg06on;
    BITMAP *cardimg07on;
    BITMAP *cardimg08on;
    BITMAP *cardimg09on;
    PALLETE pal;
    
    int cardstate [10] = {1,1,1,1,1,1,1,1,1,1}; //Define se a carta ativa (1) "on" ou inativa (0) "off"
    int tesoura = 1;
    int papel = 2;
    int lagarto = 3; // Ou gato raivoso
    int pedra = 4;
    int spock = 5; //Ou humano, ou cachorro
    
    
    buffer = create_bitmap(640,480);
    //imgcenario = load_bitmap("imagens\\cenario.bmp", pal); 
    cardimg00on = load_bitmap("imagens\\gato.bmp", pal);
    //cardimg00off = load_bitmap("imagens\\gatomorto.bmp", pal);
    cardimg01on = load_bitmap("imagens\\gato.bmp", pal);
    //cardimg01off = load_bitmap("imagens\\gatomorto.bmp", pal);
    cardimg02on = load_bitmap("imagens\\gato.bmp", pal);
    //cardimg02off = load_bitmap("imagens\\gatomorto.bmp", pal);
    cardimg03on = load_bitmap("imagens\\gato.bmp", pal);
    //cardimg03off = load_bitmap("imagens\\gatomorto.bmp", pal);
    cardimg04on = load_bitmap("imagens\\gato.bmp", pal);
    //cardimg04off = load_bitmap("imagens\\gatomorto.bmp", pal);
    cardimg05on = load_bitmap("imagens\\gato.bmp", pal);
    cardimg06on = load_bitmap("imagens\\gato.bmp", pal);
    cardimg07on = load_bitmap("imagens\\gato.bmp", pal);
    cardimg08on = load_bitmap("imagens\\gato.bmp", pal);
    cardimg09on = load_bitmap("imagens\\gato.bmp", pal);
    imggameover = load_bitmap("imagens\\gameover.bmp", pal);

	while (!key[KEY_ESC]) {
          
		/* put your code here */
	
	//=========================================
    clear_bitmap(buffer); //limpa o buffer
    //=========================================
    

    textprintf_ex( buffer, font, 10, 10, makecol(255,255,255), -1, "Player 1 - Score: %i", p1pts);
    textprintf_ex( buffer, font, 10, 20, makecol(255,255,255), -1, "Player 2 - Score: %i", p2pts);

    textprintf_ex( buffer, font, 10, 40, makecol(255,255,255), -1, "Player 1 - Card: %i", p1card);
    textprintf_ex( buffer, font, 10, 50, makecol(255,255,255), -1, "Player 2 - Card: %i", p2card);    


/*============================================================================
============== VALIDAÇÃO DA CARTA ESCOLHIDA PELO JOGADOR 1 ===================
============================================================================*/
    
    if (key[KEY_Q]) 
    {
     
         if (p1card==0)
         {
            p1card = tesoura;          
         }
         //  cardstate[0]=0;
       key[KEY_Q] = 0;
    }
    
    if (key[KEY_W]) 
    {
         if (p1card==0)
         {
            p1card = papel;          
         }     
         //  cardstate[1]=0;
       key[KEY_W] = 0;
    }
    
    if (key[KEY_E]) 
    {
     if (p1card==0)
         {
            p1card = lagarto;          
         }
     //  cardstate[2]=0;
       key[KEY_E] = 0;
    }
    
    if (key[KEY_R]) 
    {
     if (p1card==0)
         {
            p1card = pedra;          
         }
     //  cardstate[3]=0;
       key[KEY_R] = 0;
    }
    
    if (key[KEY_T]) 
    {
      if (p1card==0)
         {
            p1card = spock;          
         }              
     //  cardstate[4]=0;
       key[KEY_T] = 0;
    }

/*============================================================================
============== VALIDAÇÃO DA CARTA ESCOLHIDA PELO JOGADOR 2 ===================
============================================================================*/
    
    if (key[KEY_1_PAD]) 
    {
     
         if (p2card==0)
         {
            p2card = tesoura;          
         }
         //  cardstate[0]=0;
       key[KEY_1_PAD] = 0;
    }
    
    if (key[KEY_2_PAD]) 
    {
         if (p2card==0)
         {
            p2card = papel;          
         }     
         //  cardstate[1]=0;
       key[KEY_2_PAD] = 0;
    }
    
    if (key[KEY_3_PAD]) 
    {
     if (p2card==0)
         {
            p2card = lagarto;          
         }
     //  cardstate[2]=0;
       key[KEY_3_PAD] = 0;
    }
    
    if (key[KEY_4_PAD]) 
    {
     if (p2card==0)
         {
            p2card = pedra;          
         }
     //  cardstate[3]=0;
       key[KEY_4_PAD] = 0;
    }
    
    if (key[KEY_5_PAD]) 
    {
      if (p2card==0)
         {
            p2card = spock;          
         }              
     //  cardstate[4]=0;
       key[KEY_5_PAD] = 0;
    }


/*============================================================================
 APÓS AMBOS OS JOGADORES ESCOLHEREM SUAS CARTAS INICIA-SE A COMPARAÇÃO A SEGUIR
============================================================================*/

     while (p1card!=0 && p2card!=0)
     {
        switch (p1card)
        {
        
        case  1: //Tesoura
             
             switch (p2card)
             {
             
             case 2:
                p1pts++;
                p1card=0;
                p2card=0;
                break;
             
             case 3:
                p1pts++;
                p1card=0;
                p2card=0;
                break;
             
             case 4:
                p2pts++;
                p1card=0;
                p2card=0;
                break;
             
             case 5:
                p2pts++;
                p1card=0;
                p2card=0;
                break;
             
             default:
                p1card=0;
                p2card=0;
             }
             
        break;
        
        case 2: //Papel
             
             switch (p2card)
             {
             
             case 4:
                p1pts++;
                p1card=0;
                p2card=0;
                break;
             
             case 5:
                p1pts++;
                p1card=0;
                p2card=0;
                break;
             
             case 1:
                p2pts++;
                p1card=0;
                p2card=0;
                break;
             
             case 3:
                p2pts++;
                p1card=0;
                p2card=0;
                break;
             
             default:
                p1card=0;
                p2card=0;
             }
             
        break;
        
        case 3: //Lagarto / Gato raivoso
             
             switch (p2card)
             {
             
             case 2:
                p1pts++;
                p1card=0;
                p2card=0;
                break;
             
             case 5:
                p1pts++;
                p1card=0;
                p2card=0;
                break;
             
             case 1:
                p2pts++;
                p1card=0;
                p2card=0;
                break;
             
             case 4:
                p2pts++;
                p1card=0;
                p2card=0;
                break;
             
             default:
                p1card=0;
                p2card=0;
             }
             
        break;
        
        case 4: //Pedra
             
             switch (p2card)
             {
             
             case 1:
                p1pts++;
                p1card=0;
                p2card=0;
                break;
             
             case 3:
                p1pts++;
                p1card=0;
                p2card=0;
                break;
             
             case 2:
                p2pts++;
                p1card=0;
                p2card=0;
                break;
             
             case 5:
                p2pts++;
                p1card=0;
                p2card=0;
                break;
             
             default:
                p1card=0;
                p2card=0;
             }
             
        break;
        
        case 5: // Spock / Humano / Cachorro
             
             switch (p2card)
             {
             
             case 1:
                p1pts++;
                p1card=0;
                p2card=0;
                break;
             
             case 4:
                p1pts++;
                p1card=0;
                p2card=0;
                break;
             
             case 2:
                p2pts++;
                p1card=0;
                p2card=0;
                break;
             
             case 3:
                p2pts++;
                p1card=0;
                p2card=0;
                break;
             
             default:
                p1card=0;
                p2card=0;
             }
             
        break;
        }            
     }
    
/*============================================================================
=========================== CONDIÇÃO DE VITÓRIA ==============================
============================================================================*/

     if (p1pts>=3)
     {
         gameover();
         //textprintf_ex( buffer, font, 10, 222, makecol(238,255,28), -1, "Congratulations! Player 1 WIN!");          
     }
    
    if (p2pts>=3)
     {
         gameover();        
         //textprintf_ex( buffer, font, 10, 222, makecol(238,255,28), -1, "Congratulations! Player 2 WIN!");          
     }
    
    /*========================================================================
    Verifica e desenha a carta na tela de acordo o índice e seu estado on/off
    ========================================================================*/
    
    /*======================= Mão do Jogador 1 =============================*/
     
    if (cardstate [0]==1)
    {
       draw_sprite(buffer,cardimg00on,5,60);               
    } 
    /*else 
    {
       draw_sprite(buffer,cardimg00off,5,60);
    }*/
         
    if (cardstate [1]==1)
    {
       draw_sprite(buffer,cardimg01on,120,60);               
    } 
    /*else 
    {
       draw_sprite(buffer,cardimg01off,120,60);
    }*/
    
    if (cardstate [2]==1)
    {
       draw_sprite(buffer,cardimg02on,235,60);               
    } 
    /*else 
    {
       draw_sprite(buffer,cardimg02off,235,60);
    }*/     
    
    if (cardstate [3]==1)
    {
       draw_sprite(buffer,cardimg03on,350,60);               
    } 
    /*else 
    {
       draw_sprite(buffer,cardimg03off,350,60);
    }*/
    
    if (cardstate [4]==1)
    {
       draw_sprite(buffer,cardimg04on,465,60);               
    } 
    /*else 
    {
       draw_sprite(buffer,cardimg04off,465,60);
    }*/
    
    /*======================= Mão do Jogador 2 =============================*/
     
    if (cardstate [0]==1)
    {
       draw_sprite(buffer,cardimg05on,5,240);               
    }
    
    if (cardstate [0]==1)
    {
       draw_sprite(buffer,cardimg06on,120,240);               
    }
    
    if (cardstate [0]==1)
    {
       draw_sprite(buffer,cardimg07on,235,240);               
    }
    
    if (cardstate [0]==1)
    {
       draw_sprite(buffer,cardimg08on,350,240);               
    }
    
    if (cardstate [0]==1)
    {
       draw_sprite(buffer,cardimg09on,465,240);               
    }
    
         
    //==========================================================================
    
    
    //Desenha o restante dos sprites na tela
    
	//draw_sprite(buffer,imgcenario,0,0); 
	 
	 //============================================
             draw_sprite(screen,buffer,0,0);
	//=============================================

	deinit();
	
   }
   return 0;
}

END_OF_MAIN()

void init() {
	int depth, res;
	allegro_init();
	depth = desktop_color_depth();
	if (depth == 0) depth = 32;
	set_color_depth(depth);
	res = set_gfx_mode(GFX_AUTODETECT_WINDOWED, 640, 480, 0, 0);
	if (res != 0) {
		allegro_message(allegro_error);
		exit(-1);
	}

	install_timer();
	install_keyboard();
	install_mouse();
	/* add other initializations here */
}

void deinit() {
	clear_keybuf();
	/* add other deinitializations here */
}


/* Cria função tela de gameover - rematch */
gameover() 
{    

   while (!key[KEY_ESC] && !key[KEY_ENTER])
   {              
      clear_bitmap(buffer);
      draw_sprite(buffer,imggameover,0,0);
      
      if (p1pts >=3)
      {
          textprintf_ex( buffer, font, 10, 50, makecol(238,255,28), -1, "Congratulations! Player 1 WIN!");          
                
      }
      
      else
      {
          textprintf_ex( buffer, font, 10, 50, makecol(238,255,28), -1, "Congratulations! Player 2 WIN!");          
      }
      
      draw_sprite(screen,buffer,0,0);  // Atualiza a tela gráfica           
                 
      if (key[KEY_ESC]) 
      {
         break;               
      }
     
     if (key[KEY_ENTER])
     {
        p1pts = 0;
        p2pts= 0;
        p1card = 0;
        p2card = 0;                        
     }     
   }
}
/* FIM da função tela de gameover - rematch */

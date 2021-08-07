#include <allegro.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void init();
void deinit();

//To create delay function
void delay(int number_of_seconds) 
{ 
    // Converting time into milli_seconds 
    int milli_seconds = 1000 * number_of_seconds; 
  
    // Stroing start time 
    clock_t start_time = clock(); 
  
    // looping till required time is not acheived 
    while (clock() < start_time + milli_seconds) 
        ; 
}

/*======= Declaração de variáveis públicas ======== */

    BITMAP *buffer;
    BITMAP *imggameoverp1; // tela de Game Over P1 Win
    BITMAP *imggameoverp2; // tela de Game Over P2 Win
    BITMAP *imggameovercom; // tela de Game Over COM Win
    BITMAP *imgfundobatalhapvc;
    BITMAP *imgfundobatalhapvp;
    BITMAP *fundopause;
    BITMAP *pausebatalha; //imagem de pause em batalha
    BITMAP *legenda; // Legenda que aparecerá ao pausar o jogo
    int p1pts = 0; //Pontos do jogador 1
    int p2pts = 0; //Pontos do jogador 2
    int p1card = 0; //Recebe o valor da carta escolhida pelo player 1 | 0 == vazia
    int p2card = 0; //Recebe o valor da carta escolhida pelo player 2 | 0 ==  vazia
    int p1wins = 0; //Usado p/ atribuir pts a var p1pts
    int p2wins = 0; //Usado p/ atribuir pts a var p2pts
    int towin = 3; //Informa qnts pontos são necessários para vencer


    int menu = 0; 
    /*Informa qual das telas do menu está ativa:
    0 - Menu principal
    1 - Single Player Mode
    2 - Multiplayer Mode
    3 - Tutorial + Credits
    */


    MIDI *bgm;    // Musica de fundo 
    SAMPLE *menuselect; // Efeito Sonoro - formato .wav
    SAMPLE *p1select; //Toca qnd o p1 escolhe sua carta
    SAMPLE *p2select; //Toca qnd o p2 escolhe sua carta
    SAMPLE *ptup; //Toca qnd alguém ganha ponto
    SAMPLE *draw; //Toca qnd ninguém ganha ponto
    SAMPLE *end; //Toca na tela de gameover
    SAMPLE *ptselect; //Toca ao selecionar quantos pontos vence-se a partida


int main() {
	init();
	
/*=============== Declaração de variável ==============*/
     
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
//    BITMAP *setar; //Seta que indica a carta do p1
//    BITMAP *setav; //Seta que indica a carta do p2   
    BITMAP *imgfundomenu;
    BITMAP *imgmenu;
    BITMAP *imgcredits;
    
    
    PALLETE pal;
       
    int empate = 0; //informa se a disputa deu empate - 0 == N | 1 == Y
    
    int move = 0; //Variável usada para movimentar as cartas
        
    int cardstate [10] = {1,1,1,1,1,1,1,1,1,1}; //Define se a carta ativa (1) "on" ou inativa (0) "off"
    int tesoura = 1;
    int papel = 2;
    int lagarto = 3; // Ou gato raivoso
    int pedra = 4;
    int spock = 5; //Ou humano, ou cachorro

//Altura de todas as cartas da mão do jogador 1, de 1 a 5
    int card1y = 60; 
    int card2y = 60;
    int card3y = 60;
    int card4y = 60;
    int card5y = 60;
    
//Altura de todas as cartas da mão do jogador 2, de 6 a 10    
    int card6y = 430; 
    int card7y = 430;
    int card8y = 430;
    int card9y = 430;
    int card10y = 430;    
    
/* Alinhamento no eixo x das cartas de ambas as mãos sendo da esquerda para direita
1,2,3,4,5 suas posições, onde 1 é a carta mais a esquerda e 5 a mais a direita  */

    int card1x = 200;
    int card2x = 360;
    int card3x = 520;
    int card4x = 680;
    int card5x = 840;    

    //int p1cardpos = 0; //Variável usada no laço de repetição que movimenta as cartas do P1
    //int p2cardpos = 0; //Variável usada no laço de repetição que movimenta as cartas do P2

    srand((unsigned int)time(0));
    int waittime= 0 ; //Recebe um valor aleatório para definir o tempo que a CPU leva pra jogar
        
    buffer = create_bitmap(1000,700);
    imgmenu = load_bitmap("imagens\\menu.bmp", pal);
    //imgcenario = load_bitmap("imagens\\cenario.bmp", pal); 
    cardimg00on = load_bitmap("imagens\\tesourar.bmp", pal);
    //cardimg00off = load_bitmap("imagens\\gatomorto.bmp", pal);
    cardimg01on = load_bitmap("imagens\\papelr.bmp", pal);
    //cardimg01off = load_bitmap("imagens\\gatomorto.bmp", pal);
    cardimg02on = load_bitmap("imagens\\fogor.bmp", pal);
    //cardimg02off = load_bitmap("imagens\\gatomorto.bmp", pal);
    cardimg03on = load_bitmap("imagens\\pedrar.bmp", pal);
    //cardimg03off = load_bitmap("imagens\\gatomorto.bmp", pal);
    cardimg04on = load_bitmap("imagens\\coroar.bmp", pal);
    //cardimg04off = load_bitmap("imagens\\gatomorto.bmp", pal);
    cardimg05on = load_bitmap("imagens\\tesourav.bmp", pal);
    cardimg06on = load_bitmap("imagens\\papelv.bmp", pal);
    cardimg07on = load_bitmap("imagens\\fogov.bmp", pal);
    cardimg08on = load_bitmap("imagens\\pedrav.bmp", pal);
    cardimg09on = load_bitmap("imagens\\coroav.bmp", pal);
//    setar = load_bitmap("imagens\\setar.bmp", pal);
//    setav = load_bitmap("imagens\\setav.bmp", pal);
    imggameoverp1 = load_bitmap("imagens\\gameover1.bmp", pal);
    imggameoverp2 = load_bitmap("imagens\\gameover2.bmp", pal);
    imggameovercom = load_bitmap("imagens\\gameover3.bmp", pal);
    legenda = load_bitmap("imagens\\legenda.bmp", pal);
    imgfundobatalhapvp = load_bitmap("imagens\\fundobatalhapvp.bmp", pal);
    imgfundobatalhapvc = load_bitmap("imagens\\fundobatalhapvc.bmp", pal);
    imgfundomenu = load_bitmap("imagens\\fundomenu.bmp", pal);
    imgcredits = load_bitmap("imagens\\credits.bmp", pal);
    fundopause = load_bitmap("imagens\\pause.bmp", pal);
    pausebatalha = load_bitmap("imagens\\pausedt.bmp", pal);


    bgm = load_midi("sons\\angelicstrain.mid"); // Som - Musica de fundo
    menuselect = load_sample("sons\\meow4.wav"); //Exemplo carregamento de efeito sonoro
    p1select = load_sample("sons\\meow1.wav"); //Exemplo carregamento de efeito sonoro
    p2select = load_sample("sons\\meow3.wav"); //Exemplo carregamento de efeito sonoro
    ptup = load_sample("sons\\up2.wav"); //Exemplo carregamento de efeito sonoro
    draw = load_sample("sons\\wrong1.wav"); //Exemplo carregamento de efeito sonoro
    end = load_sample("sons\\levelcompleted1.wav"); //Exemplo carregamento de efeito sonoro
    ptselect = load_sample("sons\\up1.wav"); //Exemplo carregamento de efeito sonoro



     play_midi(bgm, TRUE); // Começa a tocar a musica de fundo


	while (!key[KEY_ESC]) {
		/* put your code here */

         if (key[KEY_ESC]){
            return;                  
         }

    //Botão de pausa

    if (key[KEY_ENTER]) {
    
         if(menu !=3){
                    
                key[KEY_ENTER]=0;
                pause();
         }
                        
    }


         switch(menu){

               case 1: //Single Player Mode
                    
                    
   	//=========================================
    clear_bitmap(buffer); //limpa o buffer
    //=========================================

/*============== Volta a carta para posição inicial =================*/

     if (p1card==0 && p2card==0 && move==1){
     
            sleep(3000);
            card1y = 60; 
            card2y = 60;
            card3y = 60;
            card4y = 60;
            card5y = 60;       
            card6y = 430; 
            card7y = 430;
            card8y = 430;
            card9y = 430;
            card10y = 430;
            p1pts = p1wins;
            p2pts = p2wins;
            move=0;
            if (empate==0){ 
            play_sample(ptup, 500, 128, 1000, FALSE); // Toca o som uma vez (FALSE)          
            }
            else{
            play_sample(draw, 500, 128, 1000, FALSE); // Toca o som uma vez (FALSE)          
            empate=0;     
            }                       
     }


    //Botão de pausa

    if (key[KEY_ENTER]) {
    
         if(menu !=3){
                    
                key[KEY_ENTER]=0;
                pause();
         }
                        
    }
    
/*============================================================================
============== VALIDAÇÃO DA CARTA ESCOLHIDA PELO JOGADOR 1 ===================
============================================================================*/
    
    if (key[KEY_Q]) 
    {
     
         if (p1card==0)
         {
            play_sample(p1select, 500, 128, 1000, FALSE); // Toca o som uma vez (FALSE)          
            p1card = tesoura;          
         }
         //  cardstate[0]=0;
       key[KEY_Q] = 0;
    }
    
    if (key[KEY_W]) 
    {
         if (p1card==0)
         {
            play_sample(p1select, 500, 128, 1000, FALSE); // Toca o som uma vez (FALSE)          
            p1card = papel;          
         }     
         //  cardstate[1]=0;
       key[KEY_W] = 0;
    }
    
    if (key[KEY_E]) 
    {
     if (p1card==0)
         {
            play_sample(p1select, 500, 128, 1000, FALSE); // Toca o som uma vez (FALSE)          
            p1card = lagarto;          
         }
     //  cardstate[2]=0;
       key[KEY_E] = 0;
    }
    
    if (key[KEY_R]) 
    {
     if (p1card==0)
         {
             play_sample(p1select, 500, 128, 1000, FALSE); // Toca o som uma vez (FALSE)          
             p1card = pedra;          
         }
     //  cardstate[3]=0;
       key[KEY_R] = 0;
    }
    
    if (key[KEY_T]) 
    {
      if (p1card==0)
         {
             play_sample(p1select, 500, 128, 1000, FALSE); // Toca o som uma vez (FALSE)          
             p1card = spock;          
         }              
     //  cardstate[4]=0;
       key[KEY_T] = 0;
    }

/*============================================================================
============== VALIDAÇÃO DA CARTA ESCOLHIDA PELO COM ===================
============================================================================*/

      while(p2card==0 && p1card!=0){
          p2card = rand() % 6;
          if (p2card!=0){
             waittime = rand() % 2001;
             sleep(waittime);
          }
      }
      

/*============================================================================
 APÓS AMBOS OS JOGADORES ESCOLHEREM SUAS CARTAS INICIA-SE A COMPARAÇÃO A SEGUIR
============================================================================*/

     while (p1card!=0 && p2card!=0)
     {
        
            play_sample(p2select, 700, 128, 1000, FALSE); // Toca o som uma vez (FALSE)                          
            move=1;
                
            switch (p1card)
            {
            
            case  1: //Tesoura
                 
                 switch (p2card)
                 {
                 
                 case 2:
                    
                    card1y = card1y+80;
                    card7y = card7y-80;          
                    p1wins++;
                    p1card=0;
                    p2card=0;
                    break;
                 
                 case 3:

                    card1y = card1y+80;
                    card8y = card8y-80;          
                    p1wins++;
                    p1card=0;
                    p2card=0;
                    break;
                 
                 case 4:

                    card1y = card1y+80;
                    card9y = card9y-80;          
                    p2wins++;
                    p1card=0;
                    p2card=0;
                    break;
                 
                 case 5:

                    card1y = card1y+80;
                    card10y = card10y-80;          
                    p2wins++;
                    p1card=0;
                    p2card=0;
                    break;
                 
                 default:
                      
                      empate = 1;          
                      card1y = card1y+80;
                      card6y = card6y-80;          
                      p1card=0;
                      p2card=0;
    
                 }//Fecha Switch p2card - Case 1
                 
            break;
            
            case 2: //Papel
                 
                 switch (p2card)
                 {
                 
                 case 4:
                    card2y = card2y+80;
                    card9y = card9y-80;            
                    p1wins++;
                    p1card=0;
                    p2card=0;
                    break;
                 
                 case 5:
                    card2y = card2y+80;
                    card10y = card10y-80;          
                    p1wins++;
                    p1card=0;
                    p2card=0;
                    break;
                 
                 case 1:
                    card2y = card2y+80;
                    card6y = card6y-80;          
                    p2wins++;
                    p1card=0;
                    p2card=0;
                    break;
                 
                 case 3:
                    card2y = card2y+80;
                    card8y = card8y-80;          
                    p2wins++;
                    p1card=0;
                    p2card=0;
                    break;
                 
                 default:
                    empate = 1;          
                    card2y = card2y+80;
                    card7y = card7y-80;          
                    p1card=0;
                    p2card=0;
                 }
                 
            break;
            
            case 3: //Lagarto / Gato raivoso
                 
                 switch (p2card)
                 {
                 
                 case 2:
                    card3y = card3y+80;
                    card7y = card7y-80;          
                    p1wins++;
                    p1card=0;
                    p2card=0;
                    break;
                 
                 case 5:
                    card3y = card3y+80;
                    card10y = card10y-80;          
                    p1wins++;
                    p1card=0;
                    p2card=0;
                    break;
                 
                 case 1:
                    card3y = card3y+80;
                    card6y = card6y-80;          
                    p2wins++;
                    p1card=0;
                    p2card=0;
                    break;
                 
                 case 4:
                    card3y = card3y+80;
                    card9y = card9y-80;          
                    p2wins++;
                    p1card=0;
                    p2card=0;
                    break;
                 
                 default:
                    empate = 1;          
                    card3y = card3y+80;
                    card8y = card8y-80;          
                    p1card=0;
                    p2card=0;
                 }
                 
            break;
            
            case 4: //Pedra
                 
                 switch (p2card)
                 {
                 
                 case 1:
                    card4y = card4y+80;
                    card6y = card6y-80;          
                    p1wins++;
                    p1card=0;
                    p2card=0;
                    break;
                 
                 case 3:
                    card4y = card4y+80;
                    card8y = card8y-80;          
                    p1wins++;
                    p1card=0;
                    p2card=0;
                    break;
                 
                 case 2:
                    card4y = card4y+80;
                    card7y = card7y-80;          
                    p2wins++;
                    p1card=0;
                    p2card=0;
                    break;
                 
                 case 5:
                    card4y = card4y+80;
                    card10y = card10y-80;          
                    p2wins++;
                    p1card=0;
                    p2card=0;
                    break;
                 
                 default:
                    empate = 1;          
                    card4y = card4y+80;
                    card9y = card9y-80;          
                    p1card=0;
                    p2card=0;
                 }
                 
            break;
            
            case 5: // Spock / Humano / Cachorro
                 
                 switch (p2card)
                 {
                 
                 case 1:
                    card5y = card5y+80;
                    card6y = card6y-80;          
                    p1wins++;
                    p1card=0;
                    p2card=0;
                    break;
                 
                 case 4:
                    card5y = card5y+80;
                    card9y = card9y-80;          
                    p1wins++;
                    p1card=0;
                    p2card=0;
                    break;
                 
                 case 2:
                    card5y = card5y+80;
                    card7y = card7y-80;          
                    p2wins++;
                    p1card=0;
                    p2card=0;
                    break;
                 
                 case 3:
                    card5y = card5y+80;
                    card8y = card8y-80;          
                    p2wins++;
                    p1card=0;
                    p2card=0;
                    break;
                 
                 default:
                    empate = 1;          
                    card5y = card5y+80;
                    card10y = card10y-80;          
                    p1card=0;
                    p2card=0;
                 }
                 
            break;
            }            
     }//Fecha o while (p1card!=0 && p2card!=0)
    
    
    
//Desenha o restante dos sprites na tela

draw_sprite(buffer,imgfundobatalhapvc,0,0); //Desenha o fundo de batalha
    
    /*========================================================================
    Verifica e desenha a carta na tela de acordo o índice e seu estado on/off
    ========================================================================*/
    
    /*======================= Mão do Jogador 1 =============================*/
     
    if (cardstate [0]==1)
    {
       draw_sprite(buffer,cardimg00on,card1x,card1y);               
    } 
    /*else 
    {
       draw_sprite(buffer,cardimg00off,5,60);
    }*/
         
    if (cardstate [1]==1)
    {
       draw_sprite(buffer,cardimg01on,card2x,card2y);            
    } 
    /*else 
    {
       draw_sprite(buffer,cardimg01off,120,60);
    }*/
    
    if (cardstate [2]==1)
    {
       draw_sprite(buffer,cardimg02on,card3x,card3y);               
    } 
    /*else 
    {
       draw_sprite(buffer,cardimg02off,235,60);
    }*/     
    
    if (cardstate [3]==1)
    {
       draw_sprite(buffer,cardimg03on,card4x,card4y);               
    } 
    /*else 
    {
       draw_sprite(buffer,cardimg03off,350,60);
    }*/
    
    if (cardstate [4]==1)
    {
       draw_sprite(buffer,cardimg04on,card5x,card5y);               
    } 
    /*else 
    {
       draw_sprite(buffer,cardimg04off,465,60);
    }*/
    
    /*======================= Mão do Jogador 2 =============================*/
     
    if (cardstate [5]==1)
    {
       draw_sprite(buffer,cardimg05on,card1x,card6y);               
    }
    
    if (cardstate [6]==1)
    {
       draw_sprite(buffer,cardimg06on,card2x,card7y);               
    }
    
    if (cardstate [7]==1)
    {
       draw_sprite(buffer,cardimg07on,card3x,card8y);               
    }
    
    if (cardstate [8]==1)
    {
       draw_sprite(buffer,cardimg08on,card4x,card9y);               
    }
    
    if (cardstate [9]==1)
    {
       draw_sprite(buffer,cardimg09on,card5x,card10y);               
    }
    
         
//============================================================================
 
 
 /* Exibe os textos sobre as imagens */
 
    textprintf_ex( buffer, font, 35, 225, makecol(255,255,255), -1, "PLAYER");
    textprintf_ex( buffer, font, 35, 455, makecol(255,255,255), -1, "COMPUTER");

    textprintf_ex( buffer, font,102, 165, makecol(255,255,255), -1, "%i", p1pts); //Pontos P1
    textprintf_ex( buffer, font, 95, 500, makecol(255,255,255), -1, "%i", p2pts); //Pontos P2

//    textprintf_ex( buffer, font, 10, 40, makecol(255,255,255), -1, "Player 1 - Card: %i", p1card);
//    textprintf_ex( buffer, font, 10, 50, makecol(255,255,255), -1, "Player 2 - Card: %i", p2card);    

/*    textprintf_ex( buffer, font, 270, 40, makecol(238,255,28), -1, "Q");          
    textprintf_ex( buffer, font, 430, 40, makecol(238,255,28), -1, "W");          
    textprintf_ex( buffer, font, 590, 40, makecol(238,255,28), -1, "E");          
    textprintf_ex( buffer, font, 750, 40, makecol(238,255,28), -1, "R");          
    textprintf_ex( buffer, font, 910, 40, makecol(238,255,28), -1, "T");          

    textprintf_ex( buffer, font, 10, 680, makecol(255,255,255), -1, "PRESS 'ENTER' to PAUSE/HELP");
*/
	 
/*============================================================================
=========================== CONDIÇÃO DE VITÓRIA ==============================
============================================================================*/

     if (p1pts>=towin)
     {
         sleep(500);
         midi_pause();
         play_sample(end, 500, 128, 1000, FALSE); // Toca o som uma vez (FALSE)          
         sleep(3000);
         gameover();
     }
    
    if (p2pts>=towin)
     {
         sleep(500);
         midi_pause();
         play_sample(end, 500, 128, 1000, FALSE); // Toca o som uma vez (FALSE)          
         sleep(3000);
         gameover();        
     }
    


	 //============================================
             draw_sprite(screen,buffer,0,0);
	//=============================================

                    
                    
               break; //Break case 1
   
               case 2: //Multiplayers Mode
                    
   	//=========================================
    clear_bitmap(buffer); //limpa o buffer
    //=========================================

/*============== Volta a carta para posição inicial =================*/

     if (p1card==0 && p2card==0 && move==1){
     
            sleep(3000);
            card1y = 60; 
            card2y = 60;
            card3y = 60;
            card4y = 60;
            card5y = 60;       
            card6y = 430; 
            card7y = 430;
            card8y = 430;
            card9y = 430;
            card10y = 430;
            p1pts = p1wins;
            p2pts = p2wins;
            move=0;
            if (empate==0){ 
            play_sample(ptup, 500, 128, 1000, FALSE); // Toca o som uma vez (FALSE)          
            }
            else{
            play_sample(draw, 500, 128, 1000, FALSE); // Toca o som uma vez (FALSE)          
            empate=0;     
            }                       
     }


    //Botão de pausa

    if (key[KEY_ENTER]) {
    
         if(menu==1 || menu==2){
                    
                key[KEY_ENTER]=0;
                pause();
         }
                        
    }
    
/*============================================================================
============== VALIDAÇÃO DA CARTA ESCOLHIDA PELO JOGADOR 1 ===================
============================================================================*/
    
    if (key[KEY_Q]) 
    {
     
         if (p1card==0)
         {
            play_sample(p1select, 500, 128, 1000, FALSE); // Toca o som uma vez (FALSE)          
            p1card = tesoura;          
         }
         //  cardstate[0]=0;
       key[KEY_Q] = 0;
    }
    
    if (key[KEY_W]) 
    {
         if (p1card==0)
         {
            play_sample(p1select, 500, 128, 1000, FALSE); // Toca o som uma vez (FALSE)          
            p1card = papel;          
         }     
         //  cardstate[1]=0;
       key[KEY_W] = 0;
    }
    
    if (key[KEY_E]) 
    {
     if (p1card==0)
         {
            play_sample(p1select, 500, 128, 1000, FALSE); // Toca o som uma vez (FALSE)          
            p1card = lagarto;          
         }
     //  cardstate[2]=0;
       key[KEY_E] = 0;
    }
    
    if (key[KEY_R]) 
    {
     if (p1card==0)
         {
             play_sample(p1select, 500, 128, 1000, FALSE); // Toca o som uma vez (FALSE)          
             p1card = pedra;          
         }
     //  cardstate[3]=0;
       key[KEY_R] = 0;
    }
    
    if (key[KEY_T]) 
    {
      if (p1card==0)
         {
             play_sample(p1select, 500, 128, 1000, FALSE); // Toca o som uma vez (FALSE)          
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
             play_sample(p2select, 700, 128, 1000, FALSE); // Toca o som uma vez (FALSE)          
             p2card = tesoura;          
         }
         //  cardstate[0]=0;
       key[KEY_1_PAD] = 0;
    }
    
    if (key[KEY_2_PAD]) 
    {
         if (p2card==0)
         {
            play_sample(p2select, 700, 128, 1000, FALSE); // Toca o som uma vez (FALSE)          
            p2card = papel;          
         }     
         //  cardstate[1]=0;
       key[KEY_2_PAD] = 0;
    }
    
    if (key[KEY_3_PAD]) 
    {
     if (p2card==0)
         {
            play_sample(p2select, 700, 128, 1000, FALSE); // Toca o som uma vez (FALSE)          
            p2card = lagarto;          
         }
     //  cardstate[2]=0;
       key[KEY_3_PAD] = 0;
    }
    
    if (key[KEY_4_PAD]) 
    {
     if (p2card==0)
         {
            play_sample(p2select, 700, 128, 1000, FALSE); // Toca o som uma vez (FALSE)          
            p2card = pedra;          
         }
     //  cardstate[3]=0;
       key[KEY_4_PAD] = 0;
    }
    
    if (key[KEY_5_PAD]) 
    {
      if (p2card==0)
         {
            play_sample(p2select, 700, 128, 1000, FALSE); // Toca o som uma vez (FALSE)          
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
        
//        if (p1card==1 && p2card==1){
//                      
//               card1y = card1y+80;
//               card6y = card6y-80;          
//               p1card=0;
//               p2card=0;
//               move=1;                         
//        }              
//                      
//        }
        
            move=1;
                
            switch (p1card)
            {
            
            case  1: //Tesoura
                 
                 switch (p2card)
                 {
                 
                 case 2:
                    
                    card1y = card1y+80;
                    card7y = card7y-80;          
                    p1wins++;
                    p1card=0;
                    p2card=0;
                    break;
                 
                 case 3:

                    card1y = card1y+80;
                    card8y = card8y-80;          
                    p1wins++;
                    p1card=0;
                    p2card=0;
                    break;
                 
                 case 4:

                    card1y = card1y+80;
                    card9y = card9y-80;          
                    p2wins++;
                    p1card=0;
                    p2card=0;
                    break;
                 
                 case 5:

                    card1y = card1y+80;
                    card10y = card10y-80;          
                    p2wins++;
                    p1card=0;
                    p2card=0;
                    break;
                 
                 default:
                      
                      empate = 1;          
                      card1y = card1y+80;
                      card6y = card6y-80;          
                      p1card=0;
                      p2card=0;
    
                 }//Fecha Switch p2card - Case 1
                 
            break;
            
            case 2: //Papel
                 
                 switch (p2card)
                 {
                 
                 case 4:
                    card2y = card2y+80;
                    card9y = card9y-80;            
                    p1wins++;
                    p1card=0;
                    p2card=0;
                    break;
                 
                 case 5:
                    card2y = card2y+80;
                    card10y = card10y-80;          
                    p1wins++;
                    p1card=0;
                    p2card=0;
                    break;
                 
                 case 1:
                    card2y = card2y+80;
                    card6y = card6y-80;          
                    p2wins++;
                    p1card=0;
                    p2card=0;
                    break;
                 
                 case 3:
                    card2y = card2y+80;
                    card8y = card8y-80;          
                    p2wins++;
                    p1card=0;
                    p2card=0;
                    break;
                 
                 default:
                    empate = 1;          
                    card2y = card2y+80;
                    card7y = card7y-80;          
                    p1card=0;
                    p2card=0;
                 }
                 
            break;
            
            case 3: //Lagarto / Gato raivoso
                 
                 switch (p2card)
                 {
                 
                 case 2:
                    card3y = card3y+80;
                    card7y = card7y-80;          
                    p1wins++;
                    p1card=0;
                    p2card=0;
                    break;
                 
                 case 5:
                    card3y = card3y+80;
                    card10y = card10y-80;          
                    p1wins++;
                    p1card=0;
                    p2card=0;
                    break;
                 
                 case 1:
                    card3y = card3y+80;
                    card6y = card6y-80;          
                    p2wins++;
                    p1card=0;
                    p2card=0;
                    break;
                 
                 case 4:
                    card3y = card3y+80;
                    card9y = card9y-80;          
                    p2wins++;
                    p1card=0;
                    p2card=0;
                    break;
                 
                 default:
                    empate = 1;          
                    card3y = card3y+80;
                    card8y = card8y-80;          
                    p1card=0;
                    p2card=0;
                 }
                 
            break;
            
            case 4: //Pedra
                 
                 switch (p2card)
                 {
                 
                 case 1:
                    card4y = card4y+80;
                    card6y = card6y-80;          
                    p1wins++;
                    p1card=0;
                    p2card=0;
                    break;
                 
                 case 3:
                    card4y = card4y+80;
                    card8y = card8y-80;          
                    p1wins++;
                    p1card=0;
                    p2card=0;
                    break;
                 
                 case 2:
                    card4y = card4y+80;
                    card7y = card7y-80;          
                    p2wins++;
                    p1card=0;
                    p2card=0;
                    break;
                 
                 case 5:
                    card4y = card4y+80;
                    card10y = card10y-80;          
                    p2wins++;
                    p1card=0;
                    p2card=0;
                    break;
                 
                 default:
                    empate = 1;          
                    card4y = card4y+80;
                    card9y = card9y-80;          
                    p1card=0;
                    p2card=0;
                 }
                 
            break;
            
            case 5: // Spock / Humano / Cachorro
                 
                 switch (p2card)
                 {
                 
                 case 1:
                    card5y = card5y+80;
                    card6y = card6y-80;          
                    p1wins++;
                    p1card=0;
                    p2card=0;
                    break;
                 
                 case 4:
                    card5y = card5y+80;
                    card9y = card9y-80;          
                    p1wins++;
                    p1card=0;
                    p2card=0;
                    break;
                 
                 case 2:
                    card5y = card5y+80;
                    card7y = card7y-80;          
                    p2wins++;
                    p1card=0;
                    p2card=0;
                    break;
                 
                 case 3:
                    card5y = card5y+80;
                    card8y = card8y-80;          
                    p2wins++;
                    p1card=0;
                    p2card=0;
                    break;
                 
                 default:
                    empate = 1;          
                    card5y = card5y+80;
                    card10y = card10y-80;          
                    p1card=0;
                    p2card=0;
                 }
                 
            break;
            }            
     }
 //Fecha o while (p1card!=0 && p2card!=0)
    
/*============================================================================
=========================== CONDIÇÃO DE VITÓRIA ==============================
============================================================================*/

     if (p1pts>=towin)
     {
         sleep(500);
         midi_pause();
         play_sample(end, 500, 128, 1000, FALSE); // Toca o som uma vez (FALSE)          
         sleep(3000);
         gameover();
         //textprintf_ex( buffer, font, 10, 222, makecol(238,255,28), -1, "Congratulations! Player 1 WIN!");          
     }
    
    if (p2pts>=towin)
     {
         sleep(500);
         midi_pause();
         play_sample(end, 500, 128, 1000, FALSE); // Toca o som uma vez (FALSE)          
         sleep(3000);
         gameover();        
         //textprintf_ex( buffer, font, 10, 222, makecol(238,255,28), -1, "Congratulations! Player 2 WIN!");          
     }
    
    
    
//Desenha o restante dos sprites na tela

draw_sprite(buffer,imgfundobatalhapvp,0,0); //Desenha o fundo de batalha
    
    /*========================================================================
    Verifica e desenha a carta na tela de acordo o índice e seu estado on/off
    ========================================================================*/
    
    /*======================= Mão do Jogador 1 =============================*/
     
    if (cardstate [0]==1)
    {
       draw_sprite(buffer,cardimg00on,card1x,card1y);               
    } 
    /*else 
    {
       draw_sprite(buffer,cardimg00off,5,60);
    }*/
         
    if (cardstate [1]==1)
    {
       draw_sprite(buffer,cardimg01on,card2x,card2y);            
    } 
    /*else 
    {
       draw_sprite(buffer,cardimg01off,120,60);
    }*/
    
    if (cardstate [2]==1)
    {
       draw_sprite(buffer,cardimg02on,card3x,card3y);               
    } 
    /*else 
    {
       draw_sprite(buffer,cardimg02off,235,60);
    }*/     
    
    if (cardstate [3]==1)
    {
       draw_sprite(buffer,cardimg03on,card4x,card4y);               
    } 
    /*else 
    {
       draw_sprite(buffer,cardimg03off,350,60);
    }*/
    
    if (cardstate [4]==1)
    {
       draw_sprite(buffer,cardimg04on,card5x,card5y);               
    } 
    /*else 
    {
       draw_sprite(buffer,cardimg04off,465,60);
    }*/
    
    /*======================= Mão do Jogador 2 =============================*/
     
    if (cardstate [5]==1)
    {
       draw_sprite(buffer,cardimg05on,card1x,card6y);               
    }
    
    if (cardstate [6]==1)
    {
       draw_sprite(buffer,cardimg06on,card2x,card7y);               
    }
    
    if (cardstate [7]==1)
    {
       draw_sprite(buffer,cardimg07on,card3x,card8y);               
    }
    
    if (cardstate [8]==1)
    {
       draw_sprite(buffer,cardimg08on,card4x,card9y);               
    }
    
    if (cardstate [9]==1)
    {
       draw_sprite(buffer,cardimg09on,card5x,card10y);               
    }
    
         
//============================================================================
 
 
 /* Exibe os textos sobre as imagens */
 
    textprintf_ex( buffer, font, 35, 225, makecol(255,255,255), -1, "PLAYER 1");
    textprintf_ex( buffer, font, 35, 455, makecol(255,255,255), -1, "PLAYER 2");

    textprintf_ex( buffer, font,102, 165, makecol(255,255,255), -1, "%i", p1pts); //Pontos P1
    textprintf_ex( buffer, font, 95, 500, makecol(255,255,255), -1, "%i", p2pts); //Pontos P2

//    textprintf_ex( buffer, font, 10, 40, makecol(255,255,255), -1, "Player 1 - Card: %i", p1card);
//    textprintf_ex( buffer, font, 10, 50, makecol(255,255,255), -1, "Player 2 - Card: %i", p2card);    

/*    textprintf_ex( buffer, font, 270, 40, makecol(238,255,28), -1, "Q");          
    textprintf_ex( buffer, font, 430, 40, makecol(238,255,28), -1, "W");          
    textprintf_ex( buffer, font, 590, 40, makecol(238,255,28), -1, "E");          
    textprintf_ex( buffer, font, 750, 40, makecol(238,255,28), -1, "R");          
    textprintf_ex( buffer, font, 910, 40, makecol(238,255,28), -1, "T");          

    textprintf_ex( buffer, font, 270, 660, makecol(238,255,28), -1, "1");          
    textprintf_ex( buffer, font, 430, 660, makecol(238,255,28), -1, "2");          
    textprintf_ex( buffer, font, 590, 660, makecol(238,255,28), -1, "3");          
    textprintf_ex( buffer, font, 750, 660, makecol(238,255,28), -1, "4");          
    textprintf_ex( buffer, font, 910, 660, makecol(238,255,28), -1, "5");          

    textprintf_ex( buffer, font, 10, 680, makecol(255,255,255), -1, "PRESS 'ENTER' to PAUSE/HELP");
*/	 
	 //============================================
             draw_sprite(screen,buffer,0,0);
	//=============================================

                    
                    break; //break case 2

                    case 3:
                    
                    clear_bitmap(buffer);
                    
                    draw_sprite(buffer,imgcredits,0,0); //Desenha o fundo
                    //draw_sprite(buffer,imgmenu,200,130);
                    
                          if (key[KEY_C]) {
                                         
                                //play_sample(menuselect, 255, 128, 1000, FALSE); // Toca o som uma vez (FALSE)          
                                menu = 0;
                                key[KEY_C] = 0;
                                //return;
                          
                          }
                                         
                    draw_sprite(screen,buffer,0,0); 
                    
                    break; //break case 3


               
/*Menu principal*/  default: //Tela de menu principal
                                           
                    clear_bitmap(buffer);
                    
                    draw_sprite(buffer,imgfundomenu,0,0); //Desenha o fundo do menu
//                    draw_sprite(buffer,imgmenu,200,130);

                    
                          if (key[KEY_1]) {
                             towin = 1;
                             play_sample(ptselect, 500, 128, 1000, FALSE); // Toca o som uma vez (FALSE)          
                             key[KEY_1]=0;
                          }

                          if (key[KEY_2]) {
                             towin = 2;
                             play_sample(ptselect, 500, 128, 1000, FALSE); // Toca o som uma vez (FALSE)          
                             key[KEY_2]=0;
                          }

                          if (key[KEY_3]) {
                             towin = 3;
                             play_sample(ptselect, 500, 128, 1000, FALSE); // Toca o som uma vez (FALSE)          
                             key[KEY_3]=0;
                          }

                          if (key[KEY_4]) {
                             towin = 4;
                             play_sample(ptselect, 500, 128, 1000, FALSE); // Toca o som uma vez (FALSE)          
                             key[KEY_4]=0;
                          }

                          if (key[KEY_5]) {
                             towin = 5;
                             play_sample(ptselect, 500, 128, 1000, FALSE); // Toca o som uma vez (FALSE)          
                             key[KEY_5]=0;
                          }

                          if (key[KEY_6]) {
                             towin = 6;
                             play_sample(ptselect, 500, 128, 1000, FALSE); // Toca o som uma vez (FALSE)          
                             key[KEY_6]=0;
                          }

                          if (key[KEY_7]) {
                             towin = 7;
                             play_sample(ptselect, 500, 128, 1000, FALSE); // Toca o som uma vez (FALSE)          
                             key[KEY_7]=0;
                          }

                          if (key[KEY_8]) {
                             towin = 8;
                             play_sample(ptselect, 500, 128, 1000, FALSE); // Toca o som uma vez (FALSE)          
                             key[KEY_8]=0;
                          }

                          if (key[KEY_9]) {
                             towin = 9;
                             play_sample(ptselect, 500, 128, 1000, FALSE); // Toca o som uma vez (FALSE)          
                             key[KEY_9]=0;
                          }
                          
                          if (key[KEY_Z]) {
                                         
                                play_sample(menuselect, 255, 128, 1000, FALSE); // Toca o som uma vez (FALSE)          
                                menu = 1;
                          
                          }
                          
                          if (key[KEY_X]) {
                                         
                                play_sample(menuselect, 255, 128, 1000, FALSE); // Toca o som uma vez (FALSE)          
                                menu = 2;
                          
                          }
                          
                          if (key[KEY_C]) {
                                         
                                play_sample(menuselect, 255, 128, 1000, FALSE); // Toca o som uma vez (FALSE)          
                                menu = 3;
                                key[KEY_C] = 0;
                          
                          }
                    
                    textprintf_ex( buffer, font, 10, 680, makecol(255,255,255), -1, "Select how many points are required to WIN a match (1-9) - Current: %i", towin);          
                    //textprintf_ex( buffer, font,735, 680, makecol(138,255,28), -1, "Press ENTER to learn how to play");          

                    
                    draw_sprite(screen,buffer,0,0); 
                    
//================= break; //break default  (Tirei pq default não precisa break)
                    
         } //Fecha Switch(menu)
 
    } //Fecha while (!key[KEY_ESC])

	deinit();
	return 0;
}
END_OF_MAIN()

void init() {
	int depth, res;
	allegro_init();
	depth = desktop_color_depth();
	if (depth == 0) depth = 32;
	set_color_depth(depth);
	res = set_gfx_mode(GFX_AUTODETECT_WINDOWED, 1000, 700, 0, 0);
	if (res != 0) {
		allegro_message(allegro_error);
		exit(-1);
	}

	install_timer();
	install_keyboard();
	install_mouse();
    install_sound(DIGI_AUTODETECT, MIDI_AUTODETECT, NULL); // Detectar e instalar o driver de som
	
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
//      play_midi(NULL, FALSE); // Para de tocar a musica de fundo
//      play_sample(end, 500, 128, 1000, FALSE); // Toca o som uma vez (FALSE)          
//      sleep(3000);
//      midi_pause();
//      draw_sprite(buffer,imggameover,0,0);
      
      if (p1pts >=towin)
      {
       draw_sprite(buffer,imggameoverp1,0,0);
                
      }
      
      else
      {
          if (menu==1){
          draw_sprite(buffer,imggameovercom,0,0);
          }
          if (menu==2){
          draw_sprite(buffer,imggameoverp2,0,0);
          }
          
      }
      
      draw_sprite(screen,buffer,0,0);  // Atualiza a tela gráfica           
                 
      if (key[KEY_ESC]) 
      {
         break;     
      }
     
     if (key[KEY_ENTER])
     {
        p1pts = 0;
        p2pts = 0;
        p1wins = 0;
        p2wins = 0;
        p1card = 0;
        p2card = 0;                        
//        play_midi(bgm, TRUE); // Toca a musica de fundo
//        stop_sample(end);
        midi_resume();
        key[KEY_ENTER]=0;
        return;
     }     
   }
}
/* FIM da função tela de gameover - rematch */

pause() 
{    

   while (!key[KEY_ESC] && !key[KEY_ENTER])
   {              
      clear_bitmap(buffer);
      //play_midi(NULL, FALSE); // Para de tocar a musica de fundo
      
      if (menu == 0){      
         draw_sprite(buffer,fundopause,0, 0);
         }
      if (menu == 1 || menu == 2){
         draw_sprite(buffer,pausebatalha,0, 0);               
      }

//      draw_sprite(buffer,legenda,350, 180);
//      textprintf_ex( buffer, font, 415,140, makecol(255,255,255), -1, "The GAME is PAUSED");
//      textprintf_ex( buffer, font, 400, 580, makecol(255,255,255), -1, "PRESS 'ENTER' to RESUME");
      
      if (menu == 1 || menu == 2){
         textprintf_ex( buffer, font, 10, 680, makecol(238,255,28), -1, "A total of %i points are required to WIN this match", towin);          
         textprintf_ex( buffer, font,102, 165, makecol(255,255,255), -1, "%i", p1pts); //Pontos P1
         textprintf_ex( buffer, font, 95, 500, makecol(255,255,255), -1, "%i", p2pts); //Pontos P2
         //textprintf_ex( buffer, font, 10, 10, makecol(138,255,28), -1, "Press BACKSPACE to return to main menu");          
      }

      if (menu==1){
      textprintf_ex( buffer, font, 35, 225, makecol(255,255,255), -1, "PLAYER");
      textprintf_ex( buffer, font, 35, 455, makecol(255,255,255), -1, "COMPUTER");
      }

      if (menu==2){
      textprintf_ex( buffer, font, 35, 225, makecol(255,255,255), -1, "PLAYER 1");
      textprintf_ex( buffer, font, 35, 455, makecol(255,255,255), -1, "PLAYER 2");
      }

      //Return to main menu
      if (menu == 1 || menu == 2){
               
            if (key[KEY_BACKSPACE])
            {                        
                  key[KEY_BACKSPACE]=0;
                  menu = 0;
                  play_midi(bgm, TRUE); // Toca a musica de fundo
                  return;
            }   
               
      }
      //end of rtmm
      
      draw_sprite(screen,buffer,0,0);  // Atualiza a tela gráfica           
                 
      if (key[KEY_ESC]) 
      {
         break;               
      }
     
     if (key[KEY_ENTER])
     {                        
        key[KEY_ENTER]=0;
        return;
        //play_midi(bgm, TRUE); // Toca a musica de fundo
     }     
   }
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Estrutura do personagem principal;
typedef struct Meu_Char {

  char name[20];
  char story[400];
  int class, alignment, job, goal, origin, porte, life;

} mChar;

// 1.1 Funcao do menu de apresentação (start_menu)
int start_menu(int start_game)
{
  int menu_choice;
  printf("Seja bem-vindo ao ( WIZARD HUNT Beta ), um RPG em fase inicial desenvolvido por alunos de APC!\n");
  printf("Divirta-se!\n---------------------------------------------------------\n\n");
  printf("1. Criar personagem\n");
  printf("2. Iniciar jogo\n");
  printf("3. Sair\n");
  scanf("%d", &menu_choice);
  getchar();
  if(menu_choice == 1)
  {
    return 1;
  } else if((menu_choice == 2) && (start_game == 0))
  {
    return 2;
  } else if((menu_choice == 2) && (start_game == 1))
  {
    return 4;
  }
  else if(menu_choice == 3)
  {
    return 0;
  } else {
    printf("Tente novamente...\n");
    start_menu(start_game);
  }
}

// 1.2 Funcao da criação do personagem

  // 1.2.1 nome (20 caracteres max)
void def_name(char *n){
  char username[20];

  printf("Me conte o seu nome\n");
  scanf("%20[^\n]", username);
  getchar();
}

  // 1.2.2 raca(humano/anao/elfo)
int def_class(){
  int userclass;

  printf("Escolha a raca \n 1. Humano\n 2. Anao\n 3. Elfo\n");
  scanf("%d", &userclass);
  getchar();
  switch(userclass){
    case 1: break;
    case 2: break;
    case 3: break;
  default:
      printf("Escolha uma opcao real\n");
      def_class();
  }
  return userclass;
}

  // 1.2.3 alignment(mal/neutro/bom)
int def_ali(){
  int userali;

  printf("Escolha o seu alignment\n 1. Mal\n 2. Neutro\n 3. Bom\n");
  scanf("%d", &userali);
  getchar();
  switch(userali){
    case 1: break;
    case 2: break;
    case 3: break;
  default:
      printf("Escolha uma opcao real\n");
      def_ali();
  }
  return userali;
}

  // 1.2.4 profissao(guerreiro/mago/ladino)
int def_job(int alignment){
  int userjob;

  if (alignment == 3){
    printf("Escolha seu trabalho\n 1. Guerreiro\n 2. Mago\n");
    scanf("%d", &userjob);
    getchar();
    switch(userjob){
      case 1: break;
      case 2: break;
    default:
        printf("Escolha uma opcao real\n");
        def_job(alignment);
    }
  } else{
    printf("Escolha seu trabalho\n 1. Guerreiro\n 2. Mago\n 3. Ladino\n");
    scanf("%d", &userjob);
    getchar();
    switch(userjob){
      case 1: break;
      case 2: break;
      case 3: break;
    default:
        printf("Escolha uma opcao real\n");
        def_job(alignment);
    }
  }
  return userjob;
  }

  // 1.2.5 meta(1 - Governar o reino, 2 - Ficar rico, 3 - Destruir o mal)
int def_goal(int alignment){
  int usergoal;

  if(alignment == 1){
    printf("Escolha o seu objetivo\n 1 - Governar o reino\n 2 - Ficar rico\n");
    scanf("%d", &usergoal);
    getchar();
    switch(usergoal){
      case 1: break;
      case 2: break;
    default:
        printf("Escolha uma opcao real\n");
        def_goal(alignment);
    }
  }else{
    printf("Escolha o seu objetivo\n 1 - Governar o reino\n 2 - Ficar rico\n 3 - Destruir o mal\n");
    scanf("%d", &usergoal);
    getchar();
    switch(usergoal){
      case 1: break;
      case 2: break;
      case 3: break;
    default:
        printf("Escolha uma opcao real\n");
        def_goal(alignment);
    }
  }
  return usergoal;
}

  // 1.2.6 meio em que vive(1 - Urbano, 2 - Rural, 3 - Tribal)
int def_origins(int job){
  int userorigins;

  if(job == 3){
    printf("Escolha de que meio vens\n 1 - Urbano\n 2 - Rural\n");
    scanf("%d", &userorigins);
    getchar();
    switch(userorigins){
      case 1: break;
      case 2: break;
    default:
        printf("Escolha uma opcao real\n");
        def_origins(job);
    }
  } else{
    printf("Escolha de que meio vens\n 1 - Urbano\n 2 - Rural\n 3 - Tribal\n");
    scanf("%d", &userorigins);
    getchar();
    switch(userorigins){
      case 1: break;
      case 2: break;
      case 3: break;
    default:
        printf("Escolha uma opcao real\n");
        def_origins(job);
    }
  }
  return userorigins;
}
  // 1.2.8 porte(grande/medio/pequeno)
int def_size(int class){
  int usersize;

  if(class == 2){
    printf("Por final, escolha seu tamanho\n 1 - Pequeno \n 2 - Medio\n");
    scanf("%d", &usersize);
    getchar();
    switch(usersize){
      case 1: break;
      case 2: break;
    default:
        printf("Escolha uma opcao real\n");
        def_size(class);
    }

  } else{
    printf("Por final, escolha seu tamanho\n 1 - Pequeno \n 2 - Medio\n 3 - Grande\n");
    scanf("%d", &usersize);
    getchar();
    switch(usersize){
      case 1: break;
      case 2: break;
      case 3: break;
    default:
        printf("Escolha uma opcao real\n");
        def_size(class);
    }

  }
  return usersize;
}
// 1.2.7 historia previa(como vivia antes\ maximo 400 caracteres)
void def_story(char *n){

  printf("Me conte a historia do seu personagem\n");
  getchar();
  scanf("%[^\n]", n);
  getchar();

}
//Funcao para a Criacao do Personagem

mChar create_char(int userlife){

  mChar userchar1;

  // HELP
  def_name(userchar1.name);
  //
  userchar1.class      =  def_class();
  userchar1.alignment  =  def_ali();
  userchar1.job        =  def_job(userchar1.alignment);
  userchar1.goal       =  def_goal(userchar1.alignment);
  userchar1.origin     =  def_origins(userchar1.job);
  userchar1.porte      =  def_size(userchar1.class);
  //HELP
    def_story(userchar1.story);
  //
  userchar1.life       =  100;
  userchar1.life       =   userlife;

  printf("Personagem criado com sucesso!\n");
  return userchar1;
}

// 1.4 Funcao pra chamar subjogos

// 1.4.1 Subjogo 1 :: Pedra-Papel-Tesoura
int subjogo1(int userlife){

    int user_PPT, cpu_PPT;
    int user_win = 0, user_loss = 0;

    //Mensagem de introdução ao subjogo
    while ((user_win < 2) && (user_loss < 2))
    {
      printf ("\n---JokenPo---\n");
      printf ("-------------\n");
      printf ("0. Pedra\n");
      printf ("1. Papel\n");
      printf ("2. Tesoura\n");

      // Coleta a resposta do usuario
      scanf ("%d", &user_PPT);
      getchar();
      if (user_PPT < 0 || user_PPT > 2)
      {
          printf("NÃO EXISTE ESSA OPÇÃO");

      } else{
          // Gera um numero aleatorio
          srand(time(NULL));
          cpu_PPT = rand() % 3;
          switch(cpu_PPT)
          {
              case 0: printf ("CPU -> Pedra\n"); break;
              case 1: printf ("CPU -> Papel\n"); break;
              case 2: printf ("CPU -> Tesoura\n"); break;
          }

          //verifica se o jogador venceu
          if ((user_PPT == 0 && cpu_PPT==2) || (user_PPT == 1 && cpu_PPT == 0) || (user_PPT == 2 && cpu_PPT == 1))
          {
              printf("Voce venceu esse round!\n");
              printf("Vida: %d\n", userlife);
              user_win += 1;
          } else if (user_PPT == cpu_PPT) //verifica se houve empate
          {
              printf ("Empate!\n");
          }
          // verifica se a CPU venceu
          else if ((cpu_PPT == 0 && user_PPT==2) || (cpu_PPT == 1 && user_PPT == 0) || (cpu_PPT == 2 && user_PPT == 1))
          {
              printf ("CPU venceu esse round!\nVoce perdeu 10 pontos de vida\n");
              user_loss += 1;
              userlife -= 10;
              printf("Vida: %d\n", userlife);
          }

        }
        switch (user_win){
          case 2: printf ("Voce passou no desafio!\n");

        }
        switch (user_loss){
          case 2: printf("Voce foi derrotado..\n");

        }
    }
    return userlife;
}

// 1.4.2 Subjogo 2
int subjogo2(int userlife){

  int user_resp, computer, user_wins;

  user_wins = 0;

  printf("Finalmente, depois de passar pela porta encontrei o Diretor, que estava inciando uma invocacao de um antigo demonio. O lugar estava tenso, mas decidi desafiar o Diretor para uma 'Guerra de Charadas', na qual se eu acertar 3 charadas ele para a invocacao e se eu errar perco 50 de vida por cada erro.\n");
  printf("Bom, vamos la...\n");

  while((user_wins < 3) && (userlife > 0)){

      srand(time(NULL));
      computer = rand() % 9; //gera um numero aleatorio
      switch(computer)
      {
          case 0: printf ("O que uma bola disse para a outra?\n");
                  printf ("1. Vamos jogar futebol? \n2. Estou bolada com voce \n3. Que bola dia.\n");
                  scanf ("%d", &user_resp);
                  getchar();
                  if (user_resp == 2){
                    printf("Voce matou a charada! \n");
                    user_wins += 1;
                  } else{
                    printf("Errouuu...\n");
                    printf("Voce perdeu 50 pontos de vida!\n");
                    userlife -= 50;
                  }
                  break;

          case 1: printf ("Qual eh o cereal favorito da vaca?\n");
                  printf ("1. Sucrilhos \n2. Nescau Cereal \n3. Muucilon\n");
                  scanf ("%d", &user_resp);
                  getchar();
                  if (user_resp == 3){
                    printf("Voce matou a charada! \n");
                    user_wins += 1;
                  } else{
                    printf("Errouuu...\n");
                    printf("Voce perdeu 50 pontos de vida!\n");
                    userlife -= 50;
                  }
                  break;

          case 2: printf ("Eu bato como relógio, relógio como este não há igual, tenho raízes e não sou vegetal. Quem sou?\n");
                  printf ("1. Lutador de Boxe \n2. Coracao \n3. Belchior \n");
                  scanf ("%d", &user_resp);
                  getchar();
                  if (user_resp == 2){
                    printf("Voce matou a charada! \n");
                    user_wins += 1;
                  } else{
                    printf("Errouuu...\n");
                    printf("Voce perdeu 50 pontos de vida!\n");
                    userlife -= 50;
                  }
                  break;

          case 3: printf ("Qual o barulho que o gaucho odeia?\n");
                  printf ("1. Flauta \n2. Vuvuzela \n3. Bahtuque\n");
                  scanf ("%d", &user_resp);
                  getchar();
                  if (user_resp == 3){
                    printf("Voce matou a charada! \n");
                    user_wins += 1;
                  } else{
                    printf("Errouuu...\n");
                    printf("Voce perdeu 50 pontos de vida!\n");
                    userlife -= 50;
                  }
                  break;

          case 4: printf ("Qual o animal que avisa quando vai fazer coco?\n");
                  printf ("1. Cavalo \n2. Humano \n3. Galinha\n");
                  scanf ("%d", &user_resp);
                  getchar();
                  if (user_resp == 3){
                    printf("Voce matou a charada! \n");
                    user_wins += 1;
                  } else{
                    printf("Errouuu...\n");
                    printf("Voce perdeu 50 pontos de vida!\n");
                    userlife -= 50;
                  }
                  break;

          case 5: printf ("O que tem perna mas nao anda?\n");
                  printf ("1. Oculos \n2. Escada \n3. Plantas");
                  scanf ("%d", &user_resp);
                  getchar();
                  if (user_resp == 1){
                    printf("Voce matou a charada! \n");
                    user_wins += 1;
                  } else{
                    printf("Errouuu...\n");
                    printf("Voce perdeu 50 pontos de vida!\n");
                    userlife -= 50;
                  }
                  break;

          case 6: printf ("O que eh um pontinho preto na neve?\n");
                  printf ("1. Um pinguim \n2. Um mosquito \n3. Um urso polar\n");
                  scanf ("%d", &user_resp);
                  getchar();
                  if (user_resp == 1){
                    printf("Voce matou a charada! \n");
                    user_wins += 1;
                  } else{
                    printf("Errouuu...\n");
                    printf("Voce perdeu 50 pontos de vida!\n");
                    userlife -= 50;
                  }
                  break;

          case 7: printf ("O que todos tem, mas todos perdem?\n");
                  printf ("1. As chaves \n2. A vida \n3. A carteira \n");
                  scanf ("%d", &user_resp);
                  getchar();
                  if (user_resp == 2){
                    printf("Voce matou a charada! \n");
                    user_wins += 1;
                  } else{
                    printf("Errouuu...\n");
                    printf("Voce perdeu 50 pontos de vida!\n");
                    userlife -= 50;

                  }
                  break;

          case 8: printf ("O que um jogador de futebol faz quando descobre que o goleiro eh professor de portugues?\n");
                  printf ("1. Gol de bunda \n2. Gol de costas \n3. Gol de letra\n");
                  scanf ("%d", &user_resp);
                  getchar();
                  if (user_resp == 3){
                    printf("Voce matou a charada! \n");
                    user_wins += 1;
                  } else{
                    printf("Errouuu...\n");
                    printf("Voce perdeu 50 pontos de vida!\n");
                    userlife -= 50;

                  }
                  break;

          case 9: printf ("O que nao funciona? \n");
                  printf ("1. Capitalismo \n2. Redes sociais \n3. Monogamia\n");
                  scanf ("%d", &user_resp);
                  getchar();
                  if (user_resp == 3){
                    printf("Voce matou a charada! \n");
                    user_wins += 1;
                  } else{
                    printf("Errouuu...\n");
                    printf("Voce perdeu 50 pontos de vida!\n");
                    userlife -= 50;
                  }
                  break;

      }
      if(userlife <= 0){
        printf("Vida: %ls\n", &userlife);
        printf("GAME OVER!!!");
      }
      switch (user_wins){
        case 3 : printf ("Depois de derrotar o Diretor e com sensacao de dever cumprido voltei para avisar ao Principe, que me recebeu muito feliz. Assim nosso reino continuava livre de qualquer ameaca, por enquanto...");
        break;
      }
  }
}
// Funcao que chama o enredo do jogo e os eventos
int show_game_story(int userlife){

    int evento1, evento2, evento3, evento4, evento5;
    int userlife1;

    printf("Seja bem-vindo!\n------------------------------------------------------------------------\n");
    printf("Era inverno, tempo de ressuscitamento de antigos Demonios. Eu fui contratado pelo Principe para investigar um colegio de bruxas onde o principe desconfiava do diretor, achando que o mesmo estaria ressussitando antigas entidades demoniadoras com poder para devastar reinos\n"); //introdução da historia
    printf("1. Aceitar o convite do Principe e viver uma aventura.\n"); // primeira opção do evento
    printf("2. Cobrar 500 ouros e desafiar a ira do pricipe.\n"); // segunda opção do evento
    printf("3. Aceitar e pedir uma espada para uma possível luta\n"); // terceira opção do evento
    scanf("%d", &evento1);
    getchar();
    switch(evento1){
        case 1: // Caso escolha a opção 1
            printf("Depois de uma longa noite de bebidas e mulheres, saimos em busca de informacoes a pe por falta de dinheiro. Depois de 4 dias andando encontramos um senhor mais velho com um cavalo grande e forte.\n");
            printf("1. Roubar o cavalo do velho senhor e chegar mais rapido a escola.\n");
            printf("2. Deixar o senhor passar e seguir a viagem durante dias.\n");
            printf("3. Matar o senhor e roubar seu cavalo.\n");
            scanf("%d", &evento2);
            getchar();
                switch(evento2){
                    case 1: // evento 2
                        printf("Logo, chegamos rapidamente a escola e fui investigar sobre o Diretor, mas o mesmo estava fugindo de mim e usando seus truques.\n"); // fazer dps
                        printf("1. Procurar ele na sala do diretor e uma possível passagem secreta.\n");
                        printf("2. Procurar ele em todas a salas.\n");
                        printf("3. Procurar por pistas de possíveis invocação de demonios.\n");
                        scanf("%d", &evento3);
                        getchar();
                          switch(evento3){
                            case 1: // evento 3
                              printf ("Apos muito tempo procurando o diretor, encontrei uma uma porta esquisita na qual tinha uma cabeça de Javali falante, que falava apenas 'Jokenpo'. E tinha anotado ao lado uma regra 'Ganhe duas vezes para avançar e cada derrota eh menos 10 de vida'.\n");
                              printf ("Bom, so nos resta brincar...\n");
                              userlife1 = subjogo1(userlife); // evento 4
                              if(userlife1 > 0){

                                subjogo2(userlife1); // evento 5
                              } else{
                                printf("GAME OVER !!!\n");
                              }
                              break;
                            case 2: // evento 3
                              printf ("Apos muito tempo procurando o diretor, encontrei uma uma porta esquisita na qual tinha uma cabeça de Javali falante, que falava apenas 'Jokenpo'. E tinha anotado ao lado uma regra 'Ganhe duas vezes para avançar e cada derrota eh menos 10 de vida'.\n");
                              printf ("Bom, so nos resta brincar...\n");
                              userlife1 = subjogo1(userlife); // evento 4
                              if(userlife1 > 0){
                                subjogo2(userlife1); // evento 5
                              } else{
                                printf("GAME OVER !!!\n");
                              }
                              break;
                            case 3: // evento 3
                              printf ("Apos muito tempo procurando o diretor, encontrei uma uma porta esquisita na qual tinha uma cabeça de Javali falante, que falava apenas 'Jokenpo'. E tinha anotado ao lado uma regra 'Ganhe duas vezes para avançar e cada derrota eh menos 10 de vida'.\n");
                              printf ("Bom, so nos resta brincar...\n");
                              userlife1 = subjogo1(userlife); // evento 4
                              if(userlife1 > 0){
                                subjogo2(userlife1); // evento 5
                              } else{
                                printf("GAME OVER !!!\n");
                              }
                              break;
                            default:
                              printf("Essa opcao nao existe");
                          }
                        break;
                    case 2: // evento 2
                        printf("Depois de 11 dias de viagem chegamos a escola e fui rapidamente investigar sobre o Diretor, mas o mesmo estava fugindo de mim e usando seus truques.\n");
                        printf("1. Procurar ele na sala do diretor e uma possível passagem secreta.\n");
                        printf("2. Procurar ele em todas a salas.\n");
                        printf("3. Procurar por pistas de possíveis invocação de demonios.\n");
                        scanf("%d", &evento3);
                        getchar();
                          switch(evento3){
                            case 1: // evento 3
                              printf ("Apos muito tempo procurando o diretor, encontrei uma uma porta esquisita na qual tinha uma cabeça de Javali falante, que falava apenas 'Jokenpo'. E tinha anotado ao lado uma regra 'Ganhe duas vezes para avançar e cada derrota eh menos 10 de vida'.\n");
                              printf ("Bom, so nos resta brincar...\n");
                              userlife1 = subjogo1(userlife); // evento 4
                              if(userlife1 > 0){
                                subjogo2(userlife1); // evento 5
                              } else{
                                printf("GAME OVER !!!\n");
                              }
                              break;
                            case 2: // evento 3
                              printf ("Apos muito tempo procurando o diretor, encontrei uma uma porta esquisita na qual tinha uma cabeça de Javali falante, que falava apenas 'Jokenpo'. E tinha anotado ao lado uma regra 'Ganhe duas vezes para avançar e cada derrota eh menos 10 de vida'.\n");
                              printf ("Bom, so nos resta brincar...\n");
                              userlife1 = subjogo1(userlife); // evento 4
                              if(userlife1 > 0){
                                subjogo2(userlife1); // evento 5
                              } else{
                                printf("GAME OVER !!!\n");
                              }
                              break;
                            case 3: // evento 3
                              printf ("Apos muito tempo procurando o diretor, encontrei uma uma porta esquisita na qual tinha uma cabeça de Javali falante, que falava apenas 'Jokenpo'. E tinha anotado ao lado uma regra 'Ganhe duas vezes para avançar e cada derrota eh menos 10 de vida'.\n");
                              printf ("Bom, so nos resta brincar...\n");
                              userlife1 = subjogo1(userlife); // evento 4
                              if(userlife1 > 0){
                                subjogo2(userlife1); // evento 5
                              } else{
                                printf("GAME OVER !!!\n");
                              }
                              break;
                            default:
                              printf("Essa opcao nao existe");
                          }
                        break;
                    case 3: // evento 2
                        printf("Depois de matar o senhor, percebi que o mesmo tinha sangue preto bem assutador e um escudo que me deixou ainda mais forte. Logo, chegamos rapidamente a escola e fui investigar sobre o Diretor, mas o mesmo estava fugindo de mim e usando seus truques.\n");
                        printf("1. Procurar ele na sala do diretor e uma possível passagem secreta.\n");
                        printf("2. Procurar ele em todas a salas.\n");
                        printf("3. Procurar por pistas de possíveis invocação de demonios.\n");
                        scanf("%d", &evento3);
                        getchar();
                          switch(evento3){
                            case 1: // evento 3
                              printf ("Apos muito tempo procurando o diretor, encontrei uma uma porta esquisita na qual tinha uma cabeça de Javali falante, que falava apenas 'Jokenpo'. E tinha anotado ao lado uma regra 'Ganhe duas vezes para avançar e cada derrota eh menos 10 de vida'.\n");
                              printf ("Bom, so nos resta brincar...\n");
                              userlife1 = subjogo1(userlife); // evento 4
                              if(userlife1 > 0){
                                subjogo2(userlife1); // evento 5
                              } else{
                                printf("GAME OVER !!!\n");
                              }
                              break;
                            case 2: // evento 3
                              printf ("Apos muito tempo procurando o diretor, encontrei uma uma porta esquisita na qual tinha uma cabeça de Javali falante, que falava apenas 'Jokenpo'. E tinha anotado ao lado uma regra 'Ganhe duas vezes para avançar e cada derrota eh menos 10 de vida'.\n");
                              printf ("Bom, so nos resta brincar...\n");
                              userlife1 = subjogo1(userlife); // evento 4
                              if(userlife1 > 0){
                                subjogo2(userlife1); // evento 5
                              } else{
                                printf("GAME OVER !!!\n");
                              }
                              break;
                            case 3: // evento 3
                              printf ("Apos muito tempo procurando o diretor, encontrei uma uma porta esquisita na qual tinha uma cabeça de Javali falante, que falava apenas 'Jokenpo'. E tinha anotado ao lado uma regra 'Ganhe duas vezes para avançar e cada derrota eh menos 10 de vida'.\n");
                              printf ("Bom, so nos resta brincar...\n");
                              userlife1 = subjogo1(userlife); // evento 4
                              if(userlife1 > 0){
                                subjogo2(userlife1); // evento 5
                              } else{
                                printf("GAME OVER !!!\n");
                              }
                              break;
                            default:
                              printf("Essa opcao nao existe");
                          }
                        break;
                    default:
                        printf("Essa opção não existe.\n");


            }
            break;
        case 2:
            printf("Depois de uma longa noite de bebidas e mulheres, saimos em busca de informacoes. Com parte do dinheiro, fomos atras de um senhor que vendia cavalos.");
            printf("1. Poupar o dinheiro e comprar um cavalo de pequeno porte.\n"); // primeira opção do evento
            printf("2. Não quero um cavalo, prefiro ir a pe. \n"); // segunda opção do evento
            printf("3. Gastar 350 ouros e comprar um cavalo grande e forte.\n"); // terceira opção do evento
            scanf("%d", &evento2);
            getchar();
                switch(evento2){
                    case 1:
                        printf("Depois de 6 dias de viagem chegamos a escola e fui rapidamente investigar sobre o Diretor, mas o mesmo estava fugindo de mim e usando seus truques.\n");
                        printf("1. Procurar ele na sala do diretor e uma possível passagem secreta.\n");
                        printf("2. Procurar ele em todas a salas.\n");
                        printf("3. Procurar por pistas de possíveis invocação de demonios.\n");
                        scanf("%d", &evento3);
                        getchar();
                          switch(evento3){
                            case 1: // evento 3
                              printf ("Apos muito tempo procurando o diretor, encontrei uma uma porta esquisita na qual tinha uma cabeça de Javali falante, que falava apenas 'Jokenpo'. E tinha anotado ao lado uma regra 'Ganhe duas vezes para avançar e cada derrota eh menos 10 de vida'.\n");
                              printf ("Bom, so nos resta brincar...\n");
                              userlife1 = subjogo1(userlife); // evento 4
                              if(userlife1 > 0){
                                subjogo2(userlife1); // evento 5
                              } else{
                                printf("GAME OVER !!!\n");
                              }
                              break;
                            case 2: // evento 3
                              printf ("Apos muito tempo procurando o diretor, encontrei uma uma porta esquisita na qual tinha uma cabeça de Javali falante, que falava apenas 'Jokenpo'. E tinha anotado ao lado uma regra 'Ganhe duas vezes para avançar e cada derrota eh menos 10 de vida'.\n");
                              printf ("Bom, so nos resta brincar...\n");
                              userlife1 = subjogo1(userlife); // evento 4
                              if(userlife1 > 0){
                                subjogo2(userlife1); // evento 5
                              } else{
                                printf("GAME OVER !!!\n");
                              }
                              break;
                            case 3: // evento 3
                              printf ("Apos muito tempo procurando o diretor, encontrei uma uma porta esquisita na qual tinha uma cabeça de Javali falante, que falava apenas 'Jokenpo'. E tinha anotado ao lado uma regra 'Ganhe duas vezes para avançar e cada derrota eh menos 10 de vida'.\n");
                              printf ("Bom, so nos resta brincar...\n");
                              userlife1 = subjogo1(userlife); // evento 4
                              if(userlife1 > 0){
                                subjogo2(userlife1); // evento 5
                              } else{
                                printf("GAME OVER !!!\n");
                              }
                              break;
                            default:
                              printf("Essa opcao nao existe");
                          }
                        break;
                    case 2:
                        printf("Depois de 11 dias de viagem chegamos a escola e fui rapidamente investigar sobre o Diretor, mas o mesmo estava fugindo de mim e usando seus truques.\n");
                        printf("1. Procurar ele na sala do diretor e uma possível passagem secreta.\n");
                        printf("2. Procurar ele em todas a salas.\n");
                        printf("3. Procurar por pistas de possíveis invocação de demonios.\n");
                          switch(evento3){
                            case 1: // evento 3
                              printf ("Apos muito tempo procurando o diretor, encontrei uma uma porta esquisita na qual tinha uma cabeça de Javali falante, que falava apenas 'Jokenpo'. E tinha anotado ao lado uma regra 'Ganhe duas vezes para avançar e cada derrota eh menos 10 de vida'.\n");
                              printf ("Bom, so nos resta brincar...\n");
                              userlife1 = subjogo1(userlife); // evento 4
                              if(userlife1 > 0){
                                subjogo2(userlife1); // evento 5
                              } else{
                                printf("GAME OVER !!!\n");
                              }
                              break;
                            case 2: // evento 3
                              printf ("Apos muito tempo procurando o diretor, encontrei uma uma porta esquisita na qual tinha uma cabeça de Javali falante, que falava apenas 'Jokenpo'. E tinha anotado ao lado uma regra 'Ganhe duas vezes para avançar e cada derrota eh menos 10 de vida'.\n");
                              printf ("Bom, so nos resta brincar...\n");
                              userlife1 = subjogo1(userlife); // evento 4
                              if(userlife1 > 0){
                                subjogo2(userlife1); // evento 5
                              } else{
                                printf("GAME OVER !!!\n");
                              }
                              break;
                            case 3: // evento 3
                              printf ("Apos muito tempo procurando o diretor, encontrei uma uma porta esquisita na qual tinha uma cabeça de Javali falante, que falava apenas 'Jokenpo'. E tinha anotado ao lado uma regra 'Ganhe duas vezes para avançar e cada derrota eh menos 10 de vida'.\n");
                              printf ("Bom, so nos resta brincar...\n");
                              userlife1 = subjogo1(userlife); // evento 4
                              if(userlife1 > 0){
                                subjogo2(userlife1); // evento 5
                              } else{
                                printf("GAME OVER !!!\n");
                              }
                              break;
                            default:
                              printf("Essa opcao nao existe");
                          }
                        break;
                    case 3:
                        printf("Por estar em um cavalo grande e forte chegamos rapidamente a escola e bem descansado. Logo, fui investigar sobre o Diretor, mas o mesmo estava fugindo de mim e usando seus truques.\n");
                        printf("1. Procurar ele na sala do diretor e uma possível passagem secreta.\n");
                        printf("2. Procurar ele em todas a salas.\n");
                        printf("3. Procurar por pistas de possíveis invocação de demonios.\n");
                        scanf("%d", &evento3);
                        getchar();
                          switch(evento3){
                            case 1: // evento 3
                              printf ("Apos muito tempo procurando o diretor, encontrei uma uma porta esquisita na qual tinha uma cabeça de Javali falante, que falava apenas 'Jokenpo'. E tinha anotado ao lado uma regra 'Ganhe duas vezes para avançar e cada derrota eh menos 10 de vida'.\n");
                              printf ("Bom, so nos resta brincar...\n");
                              userlife1 = subjogo1(userlife); // evento 4
                              if(userlife1 > 0){
                                subjogo2(userlife1); // evento 5
                              } else{
                                printf("GAME OVER !!!\n");
                              }
                              break;
                            case 2: // evento 3
                              printf ("Apos muito tempo procurando o diretor, encontrei uma uma porta esquisita na qual tinha uma cabeça de Javali falante, que falava apenas 'Jokenpo'. E tinha anotado ao lado uma regra 'Ganhe duas vezes para avançar e cada derrota eh menos 10 de vida'.\n");
                              printf ("Bom, so nos resta brincar...\n");
                              userlife1 = subjogo1(userlife); // evento 4
                              if(userlife1 > 0){
                                subjogo2(userlife1); // evento 5
                              } else{
                                printf("GAME OVER !!!\n");
                              }
                              break;
                            case 3: // evento 3
                              printf ("Apos muito tempo procurando o diretor, encontrei uma uma porta esquisita na qual tinha uma cabeça de Javali falante, que falava apenas 'Jokenpo'. E tinha anotado ao lado uma regra 'Ganhe duas vezes para avançar e cada derrota eh menos 10 de vida'.\n");
                              printf ("Bom, so nos resta brincar...\n");
                              userlife1 = subjogo1(userlife); // evento 4
                              if(userlife1 > 0){
                                subjogo2(userlife1); // evento 5
                              } else{
                                printf("GAME OVER !!!\n");
                              }
                              break;
                            default:
                              printf("Essa opcao nao existe");
                          }
                        break;

                    default:
                        printf("Essa opção não existe\n");
      }
            break;
        case 3:
            printf("Depois de uma longa noite de bebidas e mulheres, saimos em busca de informacoes a pe por falta de dinheiro. Depois de 4 dias andando encontramos um senhor mais velho com um cavalo grande e forte.\n");
            printf("1. Roubar o cavalo do velho senhor e chegar mais rapido a escola.\n");
            printf("2. Deixar o senhor passar e seguir a viagem durante dias.\n");
            printf("3. Matar o senhor e roubar seu cavalo.\n");
            scanf("%d", &evento2);
            getchar();
                switch(evento2){
                    case 1: // evento 2
                        printf("Logo, chegamos rapidamente a escola e fui investigar sobre o Diretor, mas o mesmo estava fugindo de mim e usando seus truques.\n"); // fazer dps
                        printf("1. Procurar ele na sala do diretor e uma possível passagem secreta.\n");
                        printf("2. Procurar ele em todas a salas.\n");
                        printf("3. Procurar por pistas de possíveis invocação de demonios.\n");
                        scanf("%d", &evento3);
                        getchar();
                          switch(evento3){
                            case 1: // evento 3
                              printf ("Apos muito tempo procurando o diretor, encontrei uma uma porta esquisita na qual tinha uma cabeça de Javali falante, que falava apenas 'Jokenpo'. E tinha anotado ao lado uma regra 'Ganhe duas vezes para avançar e cada derrota eh menos 10 de vida'.\n");
                              printf ("Bom, so nos resta brincar...\n");
                              userlife1 = subjogo1(userlife); // evento 4
                              if(userlife1 > 0){
                                subjogo2(userlife1); // evento 5
                              } else{
                                printf("GAME OVER !!!\n");
                              }
                              break;
                            case 2: // evento 3
                              printf ("Apos muito tempo procurando o diretor, encontrei uma uma porta esquisita na qual tinha uma cabeça de Javali falante, que falava apenas 'Jokenpo'. E tinha anotado ao lado uma regra 'Ganhe duas vezes para avançar e cada derrota eh menos 10 de vida'.\n");
                              printf ("Bom, so nos resta brincar...\n");
                              userlife1 = subjogo1(userlife); // evento 4
                              if(userlife1 > 0){
                                subjogo2(userlife1); // evento 5
                              } else{
                                printf("GAME OVER !!!\n");
                              }
                              break;
                            case 3: // evento 3
                              printf ("Apos muito tempo procurando o diretor, encontrei uma uma porta esquisita na qual tinha uma cabeça de Javali falante, que falava apenas 'Jokenpo'. E tinha anotado ao lado uma regra 'Ganhe duas vezes para avançar e cada derrota eh menos 10 de vida'.\n");
                              printf ("Bom, so nos resta brincar...\n");
                              userlife1 = subjogo1(userlife); // evento 4
                              if(userlife1 > 0){
                                subjogo2(userlife1); // evento 5
                              } else{
                                printf("GAME OVER !!!\n");
                              }
                              break;
                            default:
                              printf("Essa opcao nao existe");
                          }

                        break;
                    case 2: // evento 2
                        printf("Depois de 11 dias de viagem chegamos a escola e fui rapidamente investigar sobre o Diretor, mas o mesmo estava fugindo de mim e usando seus truques.\n");
                        printf("1. Procurar ele na sala do diretor e uma possível passagem secreta.\n");
                        printf("2. Procurar ele em todas a salas.\n");
                        printf("3. Procurar por pistas de possíveis invocação de demonios.\n");
                        scanf("%d", &evento3);
                        getchar();
                          switch(evento3){
                            case 1: // evento 3
                              printf ("Apos muito tempo procurando o diretor, encontrei uma uma porta esquisita na qual tinha uma cabeça de Javali falante, que falava apenas 'Jokenpo'. E tinha anotado ao lado uma regra 'Ganhe duas vezes para avançar e cada derrota eh menos 10 de vida'.\n");
                              printf ("Bom, so nos resta brincar...\n");
                              userlife1 = subjogo1(userlife); // evento 4
                              if(userlife1 > 0){
                                subjogo2(userlife1); // evento 5
                              } else{
                                printf("GAME OVER !!!\n");
                              }
                              break;
                            case 2: // evento 3
                              printf ("Apos muito tempo procurando o diretor, encontrei uma uma porta esquisita na qual tinha uma cabeça de Javali falante, que falava apenas 'Jokenpo'. E tinha anotado ao lado uma regra 'Ganhe duas vezes para avançar e cada derrota eh menos 10 de vida'.\n");
                              printf ("Bom, so nos resta brincar...\n");
                              userlife1 = subjogo1(userlife); // evento 4
                              if(userlife1 > 0){
                                subjogo2(userlife1); // evento 5
                              } else{
                                printf("GAME OVER !!!\n");
                              }
                              break;
                            case 3: // evento 3
                              printf ("Apos muito tempo procurando o diretor, encontrei uma uma porta esquisita na qual tinha uma cabeça de Javali falante, que falava apenas 'Jokenpo'. E tinha anotado ao lado uma regra 'Ganhe duas vezes para avançar e cada derrota eh menos 10 de vida'.\n");
                              printf ("Bom, so nos resta brincar...\n");
                              userlife1 = subjogo1(userlife); // evento 4
                              if(userlife1 > 0){
                                subjogo2(userlife1); // evento 5
                              } else{
                                printf("GAME OVER !!!\n");
                              }
                              break;
                            default:
                              printf("Essa opcao nao existe");
                          }

                        break;
                    case 3: // evento 2
                        printf("Depois de matar o senhor, percebi que o mesmo tinha sangue preto bem assutador e um escudo que me deixou ainda mais forte. Logo, chegamos rapidamente a escola e fui investigar sobre o Diretor, mas o mesmo estava fugindo de mim e usando seus truques.\n");
                        printf("1. Procurar ele na sala do diretor e uma possível passagem secreta.\n");
                        printf("2. Procurar ele em todas a salas.\n");
                        printf("3. Procurar por pistas de possíveis invocação de demonios.\n");
                        scanf("%d", &evento3);
                        getchar();
                          switch(evento3){
                            case 1: // evento 3
                              printf ("Apos muito tempo procurando o diretor, encontrei uma uma porta esquisita na qual tinha uma cabeça de Javali falante, que falava apenas 'Jokenpo'. E tinha anotado ao lado uma regra 'Ganhe duas vezes para avançar e cada derrota eh menos 10 de vida'.\n");
                              printf ("Bom, so nos resta brincar...\n");
                              userlife1 = subjogo1(userlife); // evento 4
                              if(userlife1 > 0){
                                subjogo2(userlife1); // evento 5
                              } else{
                                printf("GAME OVER !!!\n");
                              }
                              break;
                            case 2: // evento 3
                              printf ("Apos muito tempo procurando o diretor, encontrei uma uma porta esquisita na qual tinha uma cabeça de Javali falante, que falava apenas 'Jokenpo'. E tinha anotado ao lado uma regra 'Ganhe duas vezes para avançar e cada derrota eh menos 10 de vida'.\n");
                              printf ("Bom, so nos resta brincar...\n");
                              userlife1 = subjogo1(userlife); // evento 4
                              if(userlife1 > 0){
                                subjogo2(userlife1); // evento 5
                              } else{
                                printf("GAME OVER !!!\n");
                              }
                              break;
                            case 3: // evento 3
                              printf ("Apos muito tempo procurando o diretor, encontrei uma uma porta esquisita na qual tinha uma cabeça de Javali falante, que falava apenas 'Jokenpo'. E tinha anotado ao lado uma regra 'Ganhe duas vezes para avançar e cada derrota eh menos 10 de vida'.\n");
                              printf ("Bom, so nos resta brincar...\n");
                              userlife1 = subjogo1(userlife); // evento 4
                              if(userlife1 > 0){
                                subjogo2(userlife1); // evento 5
                              } else{
                                printf("GAME OVER !!!\n");
                              }
                              break;
                            default:
                              printf("Essa opcao nao existe");
                          }


                        break;
                    default:
                        printf("Essa opção não existe.\n");


            }
            break;
        default:
            printf("Essa opção não existe\n");
    }
    return 0;
}


// 1.0 Controle do jogo (main)
int main(int start_game)
{
  mChar userchar;
  int userlife = 100, real_choice, user_win, user_loss;

  real_choice = start_menu(start_game);

  if (real_choice == 1){

    userchar    = create_char(userlife);
    start_game  = 1;
    real_choice = start_menu(start_game);

    switch(real_choice){
      case 4 : show_game_story(userlife);
      break;
    }
  }
   else if(real_choice == 2){
    printf("Voce precisa criar seu personagem primeiro\n");
    main(start_game);

  }
  else if (real_choice == 0){
    printf("Adeus :>P\n");

  } else{
    printf("Essa opcao nao eh viavel!\n");
    main(start_game);

  }
  return 0;
}

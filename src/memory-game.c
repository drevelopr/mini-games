#include<stdio.h>
#include<time.h>
#include<string.h>
#define INDEFINITE 250000
title(){
       system("cls");
       printf("\n\n\n\n\t\t\t     M E M O R Y   G A M E\n\n\n\n");
       }
info(char player[41],int L,int combi_set,int combi_past)
       {
       int i;
       system("cls");
       printf("\n\n\n      %s",player);
       printf("\n\t\t\t\t\t\t\t    [S] - Summary");
       printf("\n      LEVEL  %d",L);
       printf("\n\t\t\t\t\t\t\t    [V] - View Again");
       printf("\n      ");
       for(i=0;i<combi_set;i++)printf("%c ",1);
       for(i=0;i<combi_set;i++)printf("\b\b");
       for(i=0;i<combi_past;i++)printf("%c ",2);
       printf("\n\t\t\t\t\t\t\t    [Q] - Quit");
       printf("\n\t\t\t");
       }
pdirections()
       {
       title();
       printf("\n\t\t\t\t\t\t     %c\n\n",24);
       printf("\t\t     Use arrow keys to move.     %c       %c",27,26);
       printf("\n\n\t\t\t\t\t\t     %c",25);
       printf("\n\n\n\n\t\t\t %c    to increase value",24);
       printf("\n\n\n\t\t\t %c    to decrease value\n",25);
       }
wait(int seconds)
       {
       clock_t endwait;
       endwait=clock()+seconds*CLK_TCK;
       while(clock()<endwait){}
       }
timed_getch(int seconds)
       {
       clock_t endwait; int x;
       endwait=clock()+seconds*CLK_TCK;
       while(clock()<endwait)
              {
              if(kbhit())
                     {
                     x=getch();
                     if(x==224)getch();break;
                     }
              }
       }
int place_value(float max_length)
       {
       int unit_size=1;
       while(10*unit_size<=max_length)
              {
              unit_size*=10;
              }
       return unit_size;
       }
align_right(float length, int max_length)
       {
       while(length<max_length)
              {
              printf(" ");
              max_length/=10;
              }
       }
main() {
       system("color 0b");
       int opt,opti, on=1, on_, exit=0, start=1, about=0, L=1, selection=0, instruction=0, top=0, combi, select_combi=0, Back=0, select_Lv=1, countdown;
       int game, nextLv, correct_ans[5], correct, combi_past, combi_set=3, top_combi_set[16], answer, dgt, x[INDEFINITE], i,j, n[5][4], quit, playing_record=0, top_Lv1=11, top_Lv2=6, top_Lv3=1, plcdgt;
       float millis, duration[5], ave, top_ave[16];
       char see, player[41], top_player[16][41], text[4][162];
       clock_t begin, stop;
       
       printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t     M E M O R Y   G A M E\n");
       timed_getch(2);
       while(on!=0)
              {       /* compound statement 18 */
              on_=1;
              title();
              printf("\n\t\t\t     ");
              if(start==1)printf("%c     ",17); else printf("      ");
              printf("  START  ");
              if(start==1)printf("     %c",16);
              printf("\n\n\n\t\t\t     ");
              if(top==1)printf("%c  ",17); else printf("   ");
              printf("  High Scores  ");
              if(top==1)printf("  %c",16);
              printf("\n\n\n\t\t\t     ");
              if(instruction==1)printf("%c  ",17); else printf("   ");
              printf("  Instruction  ");
              if(instruction==1)printf("  %c",16);
              printf("\n\n\n\t\t\t     ");
              if(about==1)printf("%c  ",17); else printf("   ");
              printf("     About     ");
              if(about==1)printf("  %c",16);
              printf("\n\n\n\n\t\t\t     ");
              if(exit==1)printf("%c   ",17); else printf("    ");
              printf("  Exit Game  ");
              if(exit==1)printf("   %c",16);
              printf("\n");
              opt=getch();
              switch(opt)
                 {       /* compound statement 17 */
                 case 224: opti=getch();switch(opti)
                     {
                     case 80:
                            if(exit==1)
                                   {
                                   exit=0;
                                   start=1;
                                   }
                            else if(start==1)
                                   {
                                   start=0;
                                   top=1;
                                   }
                            else if(top==1)
                                   {
                                   top=0;
                                   instruction=1;
                                   }
                            else if(instruction==1)
                                   {
                                   instruction=0;
                                   about=1;
                                   }
                            else if(about==1)
                                   {
                                   about=0;
                                   exit=1;
                                   }
                            break;
                     case 72:
                            if(instruction==1)
                                   {
                                   instruction=0;
                                   top=1;
                                   }
                            else if(exit==1)
                                   {
                                   exit=0;
                                   about=1;
                                   }
                            else if(top==1)
                                   {
                                   top=0;
                                   start=1;
                                   }
                            else if(start==1)
                                   {
                                   start=0;
                                   exit=1;
                                   }
                            else if(about==1)
                                   {
                                   about=0;
                                   instruction=1;
                                   }
                     default:{}
                     }
                     break;
                     case 13:
                            if(start==1)
                                   {       /* compound statement 14 */
                                   selection=1;
                                   while(selection==1)
                                          {       /* compound statement 1 */
                                          title();
                                          printf("\n\n\t\t\t\t\t  ");
                                          if(select_Lv==1)printf("%c",30); else printf(" ");
                                          printf("\t      ");
                                          if(select_combi==1)printf("%c",30); else printf(" ");
                                          printf("\n\n\t ");
                                          if(Back==1)printf("%c",17); else printf(" ");
                                          printf("  Back          ");
                                          printf("         Level  %d         ",L);
                                          printf("  %d  sets",combi_set);
                                          printf("\n\n");
                                          printf("\t\t\t\t\t  ");
                                          if(select_Lv==1)printf("%c",31); else printf(" ");
                                          printf("\t      ");
                                          if(select_combi==1)printf("%c",31);
                                          printf("\n");
                                          opt=getch();
                                          switch(opt)
                                             {       /* compound statement 2 */
                                             case 224: opti=getch();switch(opti)
                                                 {
                                                 case 77:
                                                        if(select_Lv==1)
                                                               {
                                                               select_Lv=0;
                                                               select_combi=1;
                                                               }
                                                        else if(select_combi==1)
                                                               {
                                                               select_combi=0;
                                                               Back=1;
                                                               }
                                                        else if(Back==1)
                                                               {
                                                               Back=0;
                                                               select_Lv=1;
                                                               }
                                                        break;
                                                 case 75:
                                                        if(select_Lv==1)
                                                               {
                                                               select_Lv=0;
                                                               Back=1;
                                                               }
                                                        else if(select_combi==1)
                                                               {
                                                               select_combi=0;
                                                               select_Lv=1;
                                                               }
                                                        else if(Back==1)
                                                               {
                                                               Back=0;
                                                               select_combi=1;
                                                               }
                                                        break;
                                                 case 72:
                                                        if(select_Lv==1)
                                                               {
                                                               if(L>=1&&L<=2)L++;
                                                               }
                                                        else if(select_combi==1)
                                                               {
                                                               if(combi_set>=3&&combi_set<=4)combi_set++;
                                                               }
                                                        break;
                                                 case 80:
                                                        if(select_Lv==1)
                                                               {
                                                               if(L>=2&&L<=3)--L;
                                                               }
                                                        else if(select_combi==1)
                                                               {
                                                               if(combi_set>=4&&combi_set<=5)--combi_set;
                                                               }
                                                 default:{}
                                                 }
                                                 break;
                                                 case 48:case 49:case 50:case 51:case 52:case 53:case 54:case 55:case 56:case 57:
                                                        break;
                                                 case 13:
                                                        if(Back==0)
                                                               {
                                                               do     {
                                                                      title();
                                                                      printf("\n\n\n\n\t\t  ");
                                                                      printf("Enter Player name :  ");
                                                                      gets(player);
                                                                      if(strlen(player)>15||(strlen(player)<2&&strlen(player)>0))
                                                                             {
                                                                             system("cls");
                                                                             title();
                                                                             printf("\n\n\n\n\t\t  ");
                                                                             if(strlen(player)>15)printf("        MAX of 15 characters ONLY %c\n",19);
                                                                             else printf("       Enter AT LEAST 2 characters %c\n",19);
                                                                             timed_getch(4);
                                                                             system("cls");
                                                                             }
                                                                      }while(strlen(player)>15||strlen(player)<2);
                                                               game=1; quit=2;
                                                               while(game==1)
                                                                      {
                                                                      combi=combi_set;
                                                                      combi_past=0;
                                                                      while(combi>0)
                                                                             {
                                                                             see=10;
                                                                             info(player,L,combi_set,combi_past);
                                                                             printf("\t   ");
                                                                             dgt=2*L+4;  srand(time(NULL));  i=0;
                                                                             if(L==1||L==3)
                                                                                    {
                                                                                    x[i]=rand();
                                                                                    while(x[i]>999||x[i]<100)
                                                                                           {
                                                                                           if(i>=INDEFINITE-3)i=0;
                                                                                           x[i+1]=rand();
                                                                                           i++;
                                                                                           }
                                                                                    n[combi-1][3]=x[i];
                                                                                    i++;
                                                                                    x[i]=rand();
                                                                                    while(x[i]>999)
                                                                                           {
                                                                                           if(i>=INDEFINITE-2)i=0;
                                                                                           x[i+1]=rand();
                                                                                           i++;
                                                                                           }
                                                                                    n[combi-1][2]=x[i];
                                                                                    i++;
                                                                                    }
                                                                             if(L==2)
                                                                                    {
                                                                                    x[i]=rand();
                                                                                    while(x[i]>9999||x[i]<1000)
                                                                                           {
                                                                                           if(i>=INDEFINITE-2)i=0;
                                                                                           x[i+1]=rand();
                                                                                           i++;
                                                                                           }
                                                                                    n[combi-1][1]=x[i];
                                                                                    i++;
                                                                                    }
                                                                             if(L==2||L==3)
                                                                                    {
                                                                                    x[i]=rand();
                                                                                    while(x[i]>9999)
                                                                                           {
                                                                                           if(i>=INDEFINITE-1)i=0;
                                                                                           x[i+1]=rand();
                                                                                           i++;
                                                                                           }
                                                                             n[combi-1][0]=x[i];
                                                                                    }
                                                                             if(L==1)correct_ans[combi-1]=n[combi-1][3]*1000+n[combi-1][2];
                                                                             else if(L==2)correct_ans[combi-1]=n[combi-1][1]*10000+n[combi-1][0];
                                                                             else if(L==3)correct_ans[combi-1]=n[combi-1][3]*10000000+n[combi-1][2]*10000+n[combi-1][0];
                                                                             if(L==1||L==3)
                                                                             {
                                                                             printf("%d",n[combi-1][3]);
                                                                             printf("%.3d",n[combi-1][2]);
                                                                             }
                                                                             if(L==2)printf("%d",n[combi-1][1]);
                                                                             if(L==2||L==3)printf("%.4d",n[combi-1][0]);
                                                                             printf("\n\n\t\t\t\t\t\t\t    ");
                                                                             for(countdown=L*2;countdown>=1;countdown--)
                                                                                    {
                                                                                    printf("%c ",219);
                                                                                    }
                                                                             printf("%c\b",219);
                                                                             for(countdown=L*2;countdown>=1;countdown--)
                                                                                    {
                                                                                    printf("\b\b");
                                                                                    }
                                                                             wait(1);
                                                                             for(countdown=L*2;countdown>=1;countdown--)
                                                                                    {
                                                                                    printf("%c ",-80);   wait(1);
                                                                                    }
                                                                             correct=1;
                                                                             begin=clock();
                                                                             while(correct<=1)
                                                                                    {
                                                                                    info(player,L,combi_set,combi_past);
                                                                                    printf("       ");
                                                                                    if(correct==0)printf("WRONG%c  Try Again",19);
                                                                                    printf("\n\n\t\t\t\t\t\t\t    ");
                                                                                    for(countdown=L*2;countdown>=1;countdown--)
                                                                                           {
                                                                                           printf("%c ",-80);
                                                                                           }
                                                                                    printf("%c",-80);
                                                                                    printf("\n\n\t\t\t");
                                                                                    if(correct==1)
                                                                                           {
                                                                                           if(see!='S'&&see!='s'&&see!='Q'&&see!='q')system("pause");
                                                                                           info(player,L,combi_set,combi_past);
                                                                                           printf("\t   ");
                                                                                           i=dgt;
                                                                                           while(i>=1)
                                                                                                  {
                                                                                                  printf("%c",'?');
                                                                                                  --i;
                                                                                                  }
                                                                                           printf("\n\n\t\t\t\t\t\t\t    ");
                                                                                           for(countdown=L*2;countdown>=1;countdown--)
                                                                                                  {
                                                                                                  printf("%c ",-80);
                                                                                                  }
                                                                                           printf("%c",-80);
                                                                                           printf("\n\n\t\t\t");
                                                                                           printf("\t   ");
                                                                                           }
                                                                                    else   printf("\t   ");
                                                                                    scanf("%d",&answer);scanf("%c",&see);
                                                                                    if(answer==correct_ans[combi-1])correct=2;
                                                                                    else                            correct=0;
                                                                                    if(see=='S'||see=='s')
                                                                                           {
                                                                                           system("cls");
                                                                                           printf("\n\n\n      %s",player);
                                                                                           printf("\n\t\t\t\t S U M M A R Y");
                                                                                           printf("\n      LEVEL  %d\n",L);
                                                                                           printf("\n      ");
                                                                                           for(i=0;i<combi_set;i++)printf("%c ",1);
                                                                                           for(i=0;i<combi_set;i++)printf("\b\b");
                                                                                           for(i=0;i<combi_past;i++)printf("%c ",2);
                                                                                           printf("\n");
                                                                                           if(combi_past>0)
                                                                                                  {
                                                                                                  for(i=combi_set-1,ave=0;i>=0;i--)
                                                                                                         {
                                                                                                         ave=ave+duration[i];
                                                                                                         }
                                                                                                  }
                                                                                           plcdgt=place_value(ave);
                                                                                           i=combi;
                                                                                           while( combi_past>0 && 2*combi_past+i>combi_set )
                                                                                                  {
                                                                                                  printf("\t\t     ");
                                                                                                  if(L==1||L==3)
                                                                                                         {
                                                                                                         printf("%d",n[i+(combi_past)-1][3]);
                                                                                                         printf("%.3d",n[i+(combi_past)-1][2]);
                                                                                                         }
                                                                                                  if(L==2)printf("%d",n[i+(combi_past)-1][1]);
                                                                                                  if(L==2||L==3)printf("%.4d",n[i+(combi_past)-1][0]);
                                                                                                  printf("              ");
                                                                                                  align_right(duration[i+combi_past-1], plcdgt);
                                                                                                  printf("%.2f",duration[i+combi_past-1]);
                                                                                                  printf("  seconds\n\n");
                                                                                                  i--;
                                                                                                  }
                                                                                           if(combi_past>0)
                                                                                                  {
                                                                                                  printf("\n");
                                                                                                  printf("\t\t     TOTAL TIME          ");
                                                                                                  for(i=((2*L+4)/2)-(4-L);i>0;i--)printf(" ");
                                                                                                  printf("%.2f  seconds\n\n",ave);
                                                                                                  printf("\n\n\t\t\t\t\t   ");system("pause");
                                                                                                  }
                                                                                           else   {
                                                                                                  printf("\n\t\t\t      No summary to show");
                                                                                                  printf("\n\n\n\n\n\n\t\t\t\t\t   ");
                                                                                                  system("pause");
                                                                                                  }
                                                                                           correct=1;
                                                                                           }
                                                                                    else if(see=='V'||see=='v')
                                                                                           {
                                                                                           info(player,L,combi_set,combi_past);
                                                                                           printf("\t   ");
                                                                                           if(L==1||L==3)
                                                                                                  {
                                                                                                  printf("%d",n[combi-1][3]);
                                                                                                  printf("%.3d",n[combi-1][2]);
                                                                                                  }
                                                                                           if(L==2)printf("%d",n[combi-1][1]);
                                                                                           if(L==2||L==3)printf("%.4d",n[combi-1][0]);
                                                                                           printf("\n\n\t\t\t\t\t\t\t    ");
                                                                                           for(countdown=L*2;countdown>=1;countdown--)
                                                                                                  {
                                                                                                  printf("%c ",219);
                                                                                                  }
                                                                                           printf("%c\b",219);
                                                                                           for(countdown=L*2;countdown>=1;countdown--)
                                                                                                  {
                                                                                                  printf("\b\b");
                                                                                                  }
                                                                                           wait(1);
                                                                                           for(countdown=L*2;countdown>=1;countdown--)
                                                                                                  {
                                                                                                  printf("%c ",-80);   wait(1);
                                                                                                  }
                                                                                           correct=1;
                                                                                           }
                                                                                    else if(see=='Q'||see=='q')
                                                                                           {
                                                                                           quit=1;
                                                                                           while(quit<=1)
                                                                                                  {       /* compound statement 20 */
                                                                                                  system("cls");
                                                                                                  printf("\n\n\n\n\n\n\n\t\t\t Are ");
                                                                                                  printf("you sure you want to quit?");
                                                                                                  printf("\n\n\n\n\n\t\t\t");
                                                                                                  if(quit==1)printf("%c",17); else printf(" ");
                                                                                                  printf("  YES  ");
                                                                                                  if(quit==1)printf("%c",16); else printf(" ");
                                                                                                  printf("\t\t");
                                                                                                  if(quit==0)printf("%c",17); else printf(" ");
                                                                                                  printf("  NO  ");
                                                                                                  if(quit==0)printf("%c",16);
                                                                                                  printf("\n");
                                                                                                  opt=getch();
                                                                                                  switch(opt)
                                                                                                     {       /* compound statement 19 */
                                                                                                     case 224: opti=getch();switch(opti)
                                                                                                         {
                                                                                                         case 72: case 75: case 80: case 77:
                                                                                                                if(quit==0)quit=1;
                                                                                                                else if(quit==1)quit=0;
                                                                                                                break;
                                                                                                         default:{}
                                                                                                         }
                                                                                                         break;
                                                                                                         case 'Y': case 'y':
                                                                                                                combi=0;game=0;correct=2;
                                                                                                                select_Lv=1;select_combi=0;quit=3;
                                                                                                                break;
                                                                                                         case 'N': case 'n':
                                                                                                         case 8: case 27:
                                                                                                                quit=2;
                                                                                                                break;
                                                                                                         case 13:
                                                                                                                if(quit==1)
                                                                                                                       {
                                                                                                                       combi=0;game=0;correct=2;
                                                                                                                       select_Lv=1;select_combi=0;
                                                                                                                       ave=0;for(i=0;i<5;i++)duration[i]=0;
                                                                                                                       playing_record=0;quit=3;
                                                                                                                       }
                                                                                                                if(quit==0)quit=2;
                                                                                                         default:{}
                                                                                                     }       /* compound statement 19 */
                                                                                                  }       /* compound statement 20 */
                                                                                           if(quit==2)correct=1;
                                                                                           }
                                                                                    if(answer==correct_ans[combi-1])correct=2;
                                                                                    }
                                                                             if(quit==2)
                                                                                    {
                                                                                    stop=clock();
                                                                                    millis=stop-begin;
                                                                                    duration[combi-1]=millis/1000;
                                                                                    combi_past++;
                                                                                    info(player,L,combi_set,combi_past);
                                                                                    printf("\t   ");
                                                                                    printf("CORRECT%c",19);
                                                                                    printf("\n\n\t\t\t\t\t\t\t    ");
                                                                                    for(countdown=L*2;countdown>=1;countdown--)
                                                                                           {
                                                                                           printf("%c ",-80);
                                                                                           }
                                                                                    printf("%c",-80);
                                                                                    printf("\n\n\t\t\t\t   ");
                                                                                    if(L==1||L==3)
                                                                                           {
                                                                                           printf("%d",n[combi-1][3]);
                                                                                           printf("%.3d",n[combi-1][2]);
                                                                                           }
                                                                                    if(L==2)printf("%d",n[combi-1][1]);
                                                                                    if(L==2||L==3)printf("%.4d",n[combi-1][0]);
                                                                                    wait(1);
                                                                                    combi--;
                                                                                    }
                                                                             }
                                                                      if(quit==2)
                                                                             {
                                                                             playing_record=playing_record+1;
                                                                             system("cls");
                                                                             printf("\n\n\n      %s",player);
                                                                             printf("\n\t\t\t\t S U M M A R Y");
                                                                             printf("\n      LEVEL  %d\n",L);
                                                                             printf("\n      ");
                                                                             for(i=0;i<combi_set;i++)printf("%c ",1);
                                                                             for(i=0;i<combi_set;i++)printf("\b\b");
                                                                             for(i=0;i<combi_past;i++)printf("%c ",2);
                                                                             printf("\n");
                                                                             for(i=combi_set-1,ave=0;i>=0;i--)
                                                                                    {
                                                                                    ave=ave+duration[i];
                                                                                    }
                                                                             plcdgt=place_value(ave);
                                                                             i=combi;
                                                                             while( combi_past>0 && 2*combi_past+i>combi_set )
                                                                                    {
                                                                                    printf("\t\t     ");
                                                                                    if(L==1||L==3)
                                                                                           {
                                                                                           printf("%d",n[i+(combi_past)-1][3]);
                                                                                           printf("%.3d",n[i+(combi_past)-1][2]);
                                                                                           }
                                                                                    if(L==2)printf("%d",n[i+(combi_past)-1][1]);
                                                                                    if(L==2||L==3)printf("%.4d",n[i+(combi_past)-1][0]);
                                                                                    printf("              ");
                                                                                    align_right(duration[i+combi_past-1], plcdgt);
                                                                                    printf("%.2f",duration[i+combi_past-1]);
                                                                                    printf("  seconds\n\n");
                                                                                    i--;
                                                                                    }
                                                                             printf("\n");
                                                                             printf("\t\t     TOTAL TIME          ");
                                                                             for(i=((2*L+4)/2)-(4-L);i>0;i--)printf(" ");
                                                                             printf("%.2f  seconds\n\n",ave);
                                                                             
                                                                             /* INPUT TO HIGH SCORES */
                                                                             if(L==3)
                                                                                    {
                                                                                    if(top_Lv3==1||top_combi_set[top_Lv3-1]>combi_set||(top_ave[top_Lv3-1]<=ave&&top_combi_set[top_Lv3-1]==combi_set))
                                                                                           {
                                                                                           if(top_Lv3<6)
                                                                                                  {
                                                                                                  strcpy(top_player[top_Lv3],player);
                                                                                                  top_ave[top_Lv3]=ave;
                                                                                                  top_combi_set[top_Lv3]=combi_set;
                                                                                                  top_Lv3++;
                                                                                                  }
                                                                                           }
                                                                                    else   {
                                                                                           i=top_Lv3-1;
                                                                                           if(top_Lv3<6)top_Lv3++;
                                                                                           while((combi_set>top_combi_set[i]||(ave<top_ave[i]&&combi_set==top_combi_set[i])) && i>0)
                                                                                                  {
                                                                                                  strcpy(top_player[0],top_player[i]);
                                                                                                  top_ave[0]=top_ave[i];
                                                                                                  top_combi_set[0]=top_combi_set[i];
                                                                                                  strcpy(top_player[i],player);
                                                                                                  top_ave[i]=ave;
                                                                                                  top_combi_set[i]=combi_set;
                                                                                                  if(i<5){
                                                                                                         strcpy(top_player[i+1],top_player[0]);
                                                                                                         top_ave[i+1]=top_ave[0];
                                                                                                         top_combi_set[i+1]=top_combi_set[0];
                                                                                                         }
                                                                                                  i--;
                                                                                                  }
                                                                                           }
                                                                                    }
                                                                             else if(L==2)
                                                                                    {
                                                                                    if(top_Lv2==6||top_combi_set[top_Lv2-1]>combi_set||(top_ave[top_Lv2-1]<=ave&&top_combi_set[top_Lv2-1]==combi_set))
                                                                                           {
                                                                                           if(top_Lv2<11)
                                                                                                  {
                                                                                                  strcpy(top_player[top_Lv2],player);
                                                                                                  top_ave[top_Lv2]=ave;
                                                                                                  top_combi_set[top_Lv2]=combi_set;
                                                                                                  top_Lv2++;
                                                                                                  }
                                                                                           }
                                                                                    else   {
                                                                                           i=top_Lv2-1;
                                                                                           if(top_Lv2<11)top_Lv2++;
                                                                                           while((combi_set>top_combi_set[i]||(ave<top_ave[i]&&combi_set==top_combi_set[i])) && i>5)
                                                                                                  {
                                                                                                  strcpy(top_player[0],top_player[i]);
                                                                                                  top_ave[0]=top_ave[i];
                                                                                                  top_combi_set[0]=top_combi_set[i];
                                                                                                  strcpy(top_player[i],player);
                                                                                                  top_ave[i]=ave;
                                                                                                  top_combi_set[i]=combi_set;
                                                                                                  if(i<10)
                                                                                                         {
                                                                                                         strcpy(top_player[i+1],top_player[0]);
                                                                                                         top_ave[i+1]=top_ave[0];
                                                                                                         top_combi_set[i+1]=top_combi_set[0];
                                                                                                         }
                                                                                                  i--;
                                                                                                  }
                                                                                           }
                                                                                    }
                                                                             else if(L==1)
                                                                                    {
                                                                                    if(top_Lv1==11||top_combi_set[top_Lv1-1]>combi_set||(top_ave[top_Lv1-1]<=ave&&top_combi_set[top_Lv1-1]==combi_set))
                                                                                           {
                                                                                           if(top_Lv1<16)
                                                                                                  {
                                                                                                  strcpy(top_player[top_Lv1],player);
                                                                                                  top_ave[top_Lv1]=ave;
                                                                                                  top_combi_set[top_Lv1]=combi_set;
                                                                                                  top_Lv1++;
                                                                                                  }
                                                                                           }
                                                                                    else   {
                                                                                           i=top_Lv1-1;
                                                                                           if(top_Lv1<16)top_Lv1++;
                                                                                           while((combi_set>top_combi_set[i]||(ave<top_ave[i]&&combi_set==top_combi_set[i])) && i>10)
                                                                                                  {
                                                                                                  strcpy(top_player[0],top_player[i]);
                                                                                                  top_ave[0]=top_ave[i];
                                                                                                  top_combi_set[0]=top_combi_set[i];
                                                                                                  strcpy(top_player[i],player);
                                                                                                  top_ave[i]=ave;
                                                                                                  top_combi_set[i]=combi_set;
                                                                                                  if(i<15)
                                                                                                         {
                                                                                                         strcpy(top_player[i+1],top_player[0]);
                                                                                                         top_ave[i+1]=top_ave[0];
                                                                                                         top_combi_set[i+1]=top_combi_set[0];
                                                                                                         }
                                                                                                  i--;
                                                                                                  }
                                                                                           }
                                                                                    }
                                                                             /* INPUT TO HIGH SCORES */
                                                                             
                                                                             printf("\n");if(!(combi_set==5&&combi<1))printf("\n");
                                                                             printf("\t\t\t\t\t   ");system("pause");
                                                                             ave=0;for(i=0;i<5;i++)duration[i]=0;
                                                                             if(L<=2)
                                                                                    {
                                                                                    nextLv=1;
                                                                                    while(nextLv>=1)
                                                                                           {
                                                                                           system("cls");
                                                                                           printf("\n\n\n\n\n\n\n\t\t      Do you wish to ");
                                                                                           printf("proceed to Level %d  ?\n\n\n\n\n\t\t\t",L+1);
                                                                                           if(nextLv==1)printf("%c",17); else printf(" ");
                                                                                           printf("  NO  ");
                                                                                           if(nextLv==1)printf("%c",16); else printf(" ");
                                                                                           printf("\t\t");
                                                                                           if(nextLv==2)printf("%c",17); else printf(" ");
                                                                                           printf("  YES  ");
                                                                                           if(nextLv==2)printf("%c",16); else printf(" ");
                                                                                           printf("\n");
                                                                                           opt=getch();
                                                                                           switch(opt)
                                                                                              {       /* compound statement 19 */
                                                                                              case 224: opti=getch();switch(opti)
                                                                                                  {
                                                                                                  case 72: case 75: case 80: case 77:
                                                                                                         if(nextLv==1)     nextLv=2;
                                                                                                         else if(nextLv==2)nextLv=1;
                                                                                                  default:{}
                                                                                                  }
                                                                                                  break;
                                                                                                  case 'Y':
                                                                                                  case 'y':
                                                                                                         L++;    nextLv=0;
                                                                                                         break;
                                                                                                  case 'N':
                                                                                                  case 'n':
                                                                                                         game=0; nextLv=0; select_Lv=1;select_combi=0;
                                                                                                         break;
                                                                                                  case 13:
                                                                                                         if(nextLv==2)L++;
                                                                                                    else if(nextLv==1)game=0, select_Lv=1;select_combi=0;
                                                                                                         nextLv=0;
                                                                                                  default:{}
                                                                                              }
                                                                                           }
                                                                                    }
                                                                             else   {
                                                                                    game=0; nextLv=0; select_Lv=1;select_combi=0;
                                                                                    if(playing_record<3)
                                                                                           {
                                                                                           system("cls");
                                                                                           printf("\n\n\n\n\n\n\n\n\t\t");
                                                                                           printf("\t\tCONGRATULATIONS!");
                                                                                           printf("\n\n\n\n\t\t\t   ");
                                                                                           printf("You have finished Level 3.");
                                                                                           printf("\n\n\n\n\n\n\n\n\n");
                                                                                           printf("\n\t\t\t\t\t   ");
                                                                                           system("pause");
                                                                                           playing_record=0;
                                                                                           }
                                                                                    else   {
                                                                                           system("cls");
                                                                                           printf("\n\n\n\n\n\n\n\n\t\t");
                                                                                           printf("\t\tCONGRATULATIONS!");
                                                                                           printf("\n\n\n\n\t\t     ");
                                                                                           printf("You have completed all three levels  ");
                                                                                           printf("%c\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t   ",2);
                                                                                           system("pause");
                                                                                           playing_record=0;
                                                                                           }
                                                                                    }
                                                                             }
                                                                      }
                                                               }
                                                        else   {selection=0;select_Lv=1;L=1;Back=0;select_combi=0;}
                                                        break;
                                                 case 8: case 27:
                                                        {selection=0;select_Lv=1;L=1;Back=0;select_combi=0;}
                                                        break;
                                                 case 'L':case 'l':
                                                        select_Lv=1;
                                                        select_combi=0;
                                                        Back=0;
                                                        break;
                                                 case 'C':case 'c':
                                                        select_Lv=0;
                                                        select_combi=1;
                                                        Back=0;
                                                        break;
                                                 case 'B':case 'b':
                                                        select_Lv=0;
                                                        select_combi=0;
                                                        Back=1;
                                                        break;
                                                 default:
                                                        pdirections();timed_getch(5);
                                             }       /* compound statement 2 */
                                          if(select_Lv==1)
                                                 {
                                                 if(opt>='0'&&opt<='1')     L=1;
                                                 else if(opt=='2')          L=2;
                                                 else if(opt>='3'&&opt<='9')L=3;
                                                 }
                                          if(select_combi==1)
                                                 {
                                                 if(opt>='0'&&opt<='3')combi_set=3;
                                                 else if(opt=='4')          combi_set=4;
                                                 else if(opt>='5'&&opt<='9')combi_set=5;
                                                 }
                                          }       /* compound statement 1 */
                                   }       /* compound statement 14 */
                            else if(top==1)
                                   {       /* compound statement 14 */
                                   L=3;
                                   selection=1;
                                   while(selection==1)
                                          {       /* compound statement 1 */
                                          system("cls");
                                          printf("\n\n");
                                          printf("\t\t\t\t\t   ");
                                          if(select_Lv==1)printf("%c",30);
                                          printf("\n\n");
                                          printf("\t ");
                                          if(Back==1)printf("%c",17); else printf(" ");
                                          printf("  Back                    Level  %d",L);
                                          printf("\n\n");
                                          printf("\t\t\t\t\t   ");
                                          if(select_Lv==1)printf("%c",31);
                                          printf("\n\n\n\n");
                                          printf("\t\t\t     H I G H    S C O R E S\n\n");
                                          if(L==3)
                                                 {
                                                 for(i=1;i<top_Lv3;i++)
                                                        {
                                                        if(i==1)plcdgt=place_value(top_ave[i]);
                                                        if(i<top_Lv3-1)if(top_ave[i+1]>top_ave[i])plcdgt=place_value(top_ave[i+1]);
                                                        }
                                                 for(i=1;i<6;i++)
                                                        {
                                                        printf("\n");
                                                        printf("\t   %d.",i);
                                                        if(i<top_Lv3)
                                                               {
                                                               printf("  %s",top_player[i]);
                                                               for(j=22-strlen(top_player[i]);j>0;--j)printf(" ");
                                                               for(j=0;j<top_combi_set[i];j++)printf("%c ",2);
                                                               for(j=15-2*top_combi_set[i];j>0;--j)printf(" ");
                                                               align_right(top_ave[i], plcdgt);
                                                               printf("%.2f seconds",top_ave[i]);
                                                               }
                                                        printf("\n");
                                                        }
                                                 }
                                     else if(L==2)
                                                 {
                                                 for(i=6;i<top_Lv2;i++)
                                                        {
                                                        if(i==6)plcdgt=place_value(top_ave[i]);
                                                        if(i<top_Lv2-1)if(top_ave[i+1]>top_ave[i])plcdgt=place_value(top_ave[i+1]);
                                                        }
                                                 for(i=6;i<11;i++)
                                                        {
                                                        printf("\n");
                                                        printf("\t   %d.",i-5);
                                                        if(i<top_Lv2)
                                                               {
                                                               printf("  %s",top_player[i]);
                                                               for(j=22-strlen(top_player[i]);j>0;--j)printf(" ");
                                                               for(j=0;j<top_combi_set[i];j++)printf("%c ",2);
                                                               for(j=15-2*top_combi_set[i];j>0;--j)printf(" ");
                                                               align_right(top_ave[i], plcdgt);
                                                               printf("%.2f seconds",top_ave[i]);
                                                               }
                                                        printf("\n");
                                                        }
                                                 }
                                     else if(L==1)
                                                 {
                                                 for(i=11;i<top_Lv1;i++)
                                                        {
                                                        if(i==11)plcdgt=place_value(top_ave[i]);
                                                        if(i<top_Lv1-1)if(top_ave[i+1]>top_ave[i])plcdgt=place_value(top_ave[i+1]);
                                                        }
                                                 for(i=11;i<16;i++)
                                                        {
                                                        printf("\n");
                                                        printf("\t   %d.",i-10);
                                                        if(i<top_Lv1)
                                                               {
                                                               printf("  %s",top_player[i]);
                                                               for(j=22-strlen(top_player[i]);j>0;--j)printf(" ");
                                                               for(j=0;j<top_combi_set[i];j++)printf("%c ",2);
                                                               for(j=15-2*top_combi_set[i];j>0;--j)printf(" ");
                                                               align_right(top_ave[i], plcdgt);
                                                               printf("%.2f seconds",top_ave[i]);
                                                               }
                                                        printf("\n");
                                                        }
                                                 }
                                          opt=getch();
                                          switch(opt)
                                             {       /* compound statement 2 */
                                             case 224: opti=getch();switch(opti)
                                                 {
                                                 case 77:
                                                        if(select_Lv==1)
                                                               {
                                                               select_Lv=0;
                                                               Back=1;
                                                               }
                                                        else
                                                               {
                                                               Back=0;
                                                               select_Lv=1;
                                                               }
                                                        break;
                                                 case 75:
                                                        if(select_Lv==1)
                                                               {
                                                               select_Lv=0;
                                                               Back=1;
                                                               }
                                                        else   {
                                                               Back=0;
                                                               select_Lv=1;
                                                               }
                                                        break;
                                                 case 72:
                                                        if(select_Lv==1)if(L>=1&&L<=2)L++;
                                                        break;
                                                 case 80:
                                                        if(select_Lv==1)if(L>=2&&L<=3)--L;
                                                 default:{}
                                                 }
                                                 break;
                                                 case 48:case 49:case 50:case 51:case 52:case 53:case 54:case 55:case 56:case 57:
                                                        break;
                                                 case 13:
                                                        if(Back==1)
                                                               {selection=0;select_Lv=1;L=1;Back=0;}
                                                        break;
                                                 case 8: case 27:
                                                        {selection=0;select_Lv=1;L=1;Back=0;}
                                                        break;
                                                 case 'L':case 'l':
                                                        select_Lv=1;
                                                        Back=0;
                                                        break;
                                                 case 'B':case 'b':
                                                        select_Lv=0;
                                                        Back=1;
                                                        break;
                                                 default:
                                                        pdirections();timed_getch(5);
                                             }       /* compound statement 2 */
                                          if(select_Lv==1)
                                                 {
                                                 if(opt>='0'&&opt<='1')     L=1;
                                                 else if(opt=='2')          L=2;
                                                 else if(opt>='3'&&opt<='9')L=3;
                                                 }
                                          if(select_combi==1)
                                                 {
                                                 if(opt>='0'&&opt<='3')     combi_set=3;
                                                 else if(opt=='4')          combi_set=4;
                                                 else if(opt>='5'&&opt<='9')combi_set=5;
                                                 }
                                          }       /* compound statement 1 */
                                   }       /* compound statement 14 */
                            else if(instruction==1)
                                   {
                                   system("cls");
                                   printf("\n\n\n\n\t\t\t     I N S T R U C T I O N\n\n\n\n");
                                   printf("\t   Level 1: You have 3 seconds to view and memorize a number.\n\n");
                                   printf("\t   Level 2: You have 5 seconds to view and memorize a number.\n\n");
                                   printf("\t   Level 3: You have 7 seconds to view and memorize a number.\n\n\n");
                                   printf("\t   Enter the same number after the given time.\n\n");
                                   printf("\t   Your time shall be recorded.\n\n\n\n\n");
                                   printf("\t\t\t\t\t   ");  system("pause");  system("cls");
                                   printf("\n\n\n\n\t\t\t     I N S T R U C T I O N\n\n\n\n");
                                   printf("\t   To see a summary of your recorded time, enter `S'.\n\n\n");
                                   printf("\t   To view the same number again, enter `V'.\n\n");
                                   printf("\t   Viewing the same number again shall take 3 seconds for Level 1,\n\n");
                                   printf("\t   5 seconds for Level 2, and 7 seconds for Level 3.\n\n\n");
                                   printf("\t   To quit the game, enter `Q'.\n\n\n\n");
                                   printf("\t\t\t\t\t   ");  system("pause");
                                   }
                            else if(about==1)
                                   {
                                   //title();
                                   //printf("\t\t\t  This program was created by");
                                   //printf("\n\n\t\t\t      Cabatingan, Andr%c M.",130);
                                   //printf("\n\n");
                                   
                                   strcpy(text[0],"                                    2011379511                                                                                                                  ");
                                   strcpy(text[1],"                                                                                                                      CSPROG                                    ");
                                   strcpy(text[2],"                BS Applied Mathematics with Information Technology                                         Fundamentals of Programming                          ");
                                   strcpy(text[3],"                                ( AMIT )   student                                                          Professor Edward P. Andaya                          ");
                                   for(countdown=0,opt=1;!kbhit();)
                                          {
                                          system("cls");
                                          printf("\n\n\t\t\t\t\t\t\t  Press any key to");
                                          printf("\n\n\t\t\t     M E M O R Y   G A M E           continue . . .\n\n\n\n");
                                          printf("\t\t\t  This program was created by");
                                          printf("\n\n\t\t\t      Cabatingan, Andr%c M.",130);
                                          printf("\n\n");
                                          for(i=0;i<4;i++)
                                                 {
                                                 text[i][160]=text[i][0];
                                                 for(j=0;j<160;j++)
                                                        {
                                                        text[i][j]=text[i][j+1];
                                                        }
                                                 text[i][160]=text[i][80];
                                                 text[i][80]='\0';
                                                 puts(text[i]);
                                                 text[i][80]=text[i][160];
                                                 }
                                          printf("\n\t\t\t     Far Eastern University\n");
                                          if(countdown==80)
                                                 {
                                                 millis=5000;
                                                 clock_t endwait;
                                                 endwait=clock()+(millis/1000)*CLK_TCK;
                                                 while(clock()<endwait)if(kbhit())break;
                                                 opt++;
                                                 }
                                          else if(countdown==0)
                                                 {
                                                 millis=5000;
                                                 clock_t endwait;
                                                 endwait=clock()+(millis/1000)*CLK_TCK;
                                                 while(clock()<endwait)if(kbhit())break;
                                                 --opt;
                                                 }
                                          else   {
                                                 millis=10;
                                                 clock_t endwait;
                                                 endwait=clock()+(millis/1000)*CLK_TCK;
                                                 while(clock()<endwait)if(kbhit())break;
                                                 }
                                          if(opt==0)countdown++; else --countdown;
                                          }
                                   j=getch();
                                   if(j==224)getch();
                                   /*
                                   printf("\n\n\t\t\t\t     CSPROG\n\n");
                                   printf("\t\t\t  Fundamentals of Programming\n\n");
                                   printf("\t\t\t   Professor Edward P. Andaya\n");
                                   printf("\n\n\n\t\t\t\t\t   ");*/
                                   
                                   
                                   //printf("\n\t\t\t   Far Eastern University");
                                   }
                            else if(exit==1)
                                   {       /* compound statement 21 */
                                   on=1;
                                   while(on_!=0)
                                          {       /* compound statement 20 */
                                          system("cls");
                                          printf("\n\n\n\n\n\n\n\t\t\t Are you sure ");
                                          printf("you want to exit?\n\n\n\n\n\t\t\t");
                                          if(on==1)printf("%c",17); else printf(" ");
                                          printf("  YES  ");
                                          if(on==1)printf("%c",16); else printf(" ");
                                          printf("\t\t");
                                          if(on==2)printf("%c",17); else printf(" ");
                                          printf("  NO  ");
                                          if(on==2)printf("%c",16);
                                          printf("\n");
                                          opt=getch();
                                          switch(opt)
                                             {       /* compound statement 19 */
                                             case 224: opti=getch();switch(opti)
                                                 {
                                                 case 72: case 75: case 80: case 77:
                                                        if(on==1)     on=2;
                                                        else if(on==2)on=1;
                                                 default:{}
                                                 }
                                                 break;
                                                 case 'Y': case 'y':
                                                        on=0;on_=0;
                                                        break;
                                                 case 'N': case 'n':
                                                        start=1;exit=0;on_=0;
                                                        break;
                                                 case 8: case 27:
                                                        on_=0;
                                                        break;
                                                 case 13:
                                                        if(on==1){on=0;on_=0;}
                                                        else if(on==2){start=1;exit=0;on_=0;}
                                                 default:{}
                                             }       /* compound statement 19 */
                                          }       /* compound statement 20 */
                                   }       /* compound statement 21 */
                            break;
                     case 27:
                            {       /* compound statement 21 */
                                   on=1;
                                   while(on_!=0)
                                          {       /* compound statement 20 */
                                          system("cls");
                                          printf("\n\n\n\n\n\n\n\t\t\t Are you sure ");
                                          printf("you want to exit?\n\n\n\n\n\t\t\t");
                                          if(on==1)printf("%c",17); else printf(" ");
                                          printf("  YES  ");
                                          if(on==1)printf("%c",16); else printf(" ");
                                          printf("\t\t");
                                          if(on==2)printf("%c",17); else printf(" ");
                                          printf("  NO  ");
                                          if(on==2)printf("%c",16);
                                          printf("\n");
                                          opt=getch();
                                          switch(opt)
                                             {       /* compound statement 19 */
                                             case 224: opti=getch();switch(opti)
                                                 {
                                                 case 72: case 75: case 80: case 77:
                                                        if(on==1)     on=2;
                                                        else if(on==2)on=1;
                                                 default:{}
                                                 }
                                                 break;
                                                 case 'Y': case 'y':
                                                        on=0;on_=0;
                                                        break;
                                                 case 'N': case 'n':
                                                        start=1;top=0;instruction=0;about=0;exit=0;on_=0;
                                                        break;
                                                 case 8: case 27:
                                                        on_=0;
                                                        break;
                                                 case 13:
                                                        if(on==1){on=0;on_=0;}
                                                        else if(on==2){start=1;top=0;instruction=0;about=0;exit=0;on_=0;}
                                                 default:{}
                                             }       /* compound statement 19 */
                                          }       /* compound statement 20 */
                                   }       /* compound statement 21 */
                            break;
                     case 8:
                     case 32:
                            break;
                     default:
                            pdirections();timed_getch(5);
                 }       /* compound statement 17 */
              }       /* compound statement 18 */
       }

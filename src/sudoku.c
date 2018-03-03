#include<stdio.h>
#include<string.h>
#include<time.h>
#define UP    72
#define LEFT  75
#define RIGHT 77
#define DOWN  80
#define DEL   83
struct info
   {
   int generated, ava[9],
       restrict;
   
   int  val;  // the real value
   char par,  // appearance in normal mode
        leg;  // legend   appearance in legend mode
   };
struct info sudoku[9][9];
struct hs
   {
   char player[41];
   int   Lv,h,m,s;
   float duration;
   };
struct hs top[9];
complement(int available[9], int existing[9])
   {
   int i, n;
   for(i=0;i<9;i++)
      {
      for(n=0;n<9;n++)
         {
         if(existing[i]==available[n])available[n]=0;
         }
      }
   }
compress(int set[9])
   {
   int fill, get;
   fill=0;
   while(fill<9-1)
      {
      if(set[fill]==0)
         {
         get=1;
         while(set[fill+get]==0)
            {
            if(fill+get>=9-1){break;}
            get++;
            }
         if(fill+get<9)
            {
            set[fill]=set[fill+get];
            set[fill+get]=0;
            }
         }
      fill++;
      }
   }
generate_Sudoku(struct info sudoku[9][9])
   {
   int col,x,f, bcol,
       row,y,d, brow,
       taken[9], i, members[9],
       s, picked_index,
       abyss,backtrack,passthrough=0;
   
   srand(time(NULL));
   s=0;
   while(s==0)
      {
      for(row=0;row<9;row++)
         {
         for(col=0;col<9;col++)
            {
            sudoku[row][col].generated=0;
            for(i=0;i<9;i++)sudoku[row][col].ava[i]=i+1;
            }
         }
      s=1;
      passthrough=0;
      col=0;
      row=0;
      while(row<9)
         {
         if(sudoku[row][col].generated==0)
            {
            for(i=0;i<9;i++)taken[i]=0;
            y=row;
            while(0<y)
               {
               taken[y-1]=sudoku[y-1][col].generated;
               --y;
               }
            complement(sudoku[row][col].ava,taken);
            compress  (sudoku[row][col].ava);
            for(i=0;i<9;i++)taken[i]=0;
            x=col;
            while(0<x)
               {
               taken[x-1]=sudoku[row][x-1].generated;
               --x;
               }
            complement(sudoku[row][col].ava,taken);
            compress  (sudoku[row][col].ava);
            for(i=0;i<9;i++)taken[i]=0;
            i=0;
            y=row;while(0<y%3)--y;
            d=y+3;
            while(y<d)
               {
               x=col;while(0<x%3)--x;
               f=x+3;
               while(x<f)
                  {
                  taken[i]=sudoku[y][x].generated;
                  x++;
                  if(i<9-1)i++;
                  }
               y++;
               }
            complement(sudoku[row][col].ava,taken);
            compress  (sudoku[row][col].ava);
            sudoku[row][col].restrict=0;
            i=0;
            while(i<9)
               {
               if(0<sudoku[row][col].ava[i])(sudoku[row][col].restrict)++;
               i++;
               }
            if(0<sudoku[row][col].restrict)
               {
               i = rand();
               if(sudoku[row][col].restrict<1)sudoku[row][col].restrict=1;
               picked_index = i % sudoku[row][col].restrict;
               sudoku[row][col].generated = sudoku[row][col].ava[picked_index];
               sudoku[row][col].ava[picked_index] = 0;
               --(sudoku[row][col].restrict);
               col++;
               if(col==9)
                  {
                  col-=9;
                  row++;
                  }
               }
            else
               {
               bcol = col ;
               brow = row ;
               while(sudoku[brow][bcol].restrict<1)--bcol;
               backtrack=1;
               while(backtrack==1)
                  {
                  backtrack=0;
                  abyss = sudoku[brow][bcol].generated;
                  sudoku[brow][bcol].generated = 0;
                  y=row;
                  while(0<y)
                     {
                     if(sudoku[y-1][col].generated==abyss)backtrack=1;
                     --y;
                     }
                  y=row;while(0<y%3)--y;
                  d=y+3;
                  while(y<d)
                     {
                     x=col;while(0<x%3)--x;
                     f=x+3;
                     while(x<f)
                        {
                        if(sudoku[y][x].generated==abyss)backtrack=1;
                        x++;
                        }
                     y++;
                     }
                  for(i=0;i<9;i++)
                     {
                     y=brow;
                     while(0<y)
                        {
                        if(sudoku[brow][bcol].ava[i]==sudoku[y-1][bcol].generated)
                           {
                           if(0<sudoku[y-1][bcol].generated)
                              {
                              sudoku[brow][bcol].ava[i] = 0;
                              --(sudoku[brow][bcol].restrict);
                              }
                           }
                        --y;
                        }
                     x=bcol;
                     while(0<x)
                        {
                        if(sudoku[brow][bcol].ava[i]==sudoku[brow][x-1].generated)
                           {
                           if(0<sudoku[brow][x-1].generated)
                              {
                              sudoku[brow][bcol].ava[i] = 0;
                              --(sudoku[brow][bcol].restrict);
                              }
                           }
                        --x;
                        }
                     y=brow;while(0<y%3)--y;
                     d=y+3;
                     while(y<d)
                        {
                        x=bcol;while(0<x%3)--x;
                        f=x+3;
                        while(x<f)
                           {
                           if(sudoku[brow][bcol].ava[i]==sudoku[y][x].generated)
                              {
                              if(0<sudoku[y][x].generated)
                                 {
                                 sudoku[brow][bcol].ava[i] = 0;
                                 --(sudoku[brow][bcol].restrict);
                                 }
                              }
                           x++;
                           }
                        y++;
                        }
                     }   
                  if((sudoku[brow][bcol].restrict)<1)backtrack=1;
                  compress(sudoku[brow][bcol].ava);
                  sudoku[brow][bcol].generated = abyss;
                  if(backtrack==1)--bcol;
                  if(bcol<0)
                     {
                     bcol+=9;
                     --brow;
                     }
                  if(brow<0)
                     {
                     passthrough=1;
                     break;
                     brow=0;
                     }
                  }
               if(passthrough==1)break;
               sudoku[row][col].generated = sudoku[brow][bcol].generated;
               i = rand();
               if(sudoku[brow][bcol].restrict<1)sudoku[brow][bcol].restrict=1;
               picked_index = i % sudoku[brow][bcol].restrict;
               sudoku[brow][bcol].generated = sudoku[brow][bcol].ava[picked_index];
               sudoku[brow][bcol].ava[picked_index] = 0;
               --(sudoku[brow][bcol].restrict);
               col++;
               if(col==9)
                  {
                  col-=9;
                  row++;
                  }
               }
            }
         }
      for(d=0;d<3;d++)
         {
         for(f=0;f<3;f++)
            {
            for(i=0;i<9;i++)members[i]=i+1;
            for(y=0;y<3;y++)
               {
               for(x=0;x<3;x++)
                  {
                  for(i=0;i<9;i++)
                     {
                     if(sudoku[y+d*3][x+f*3].generated==members[i])members[i]=0;
                     }
                  }
               }
            for(i=0;i<9;i++)
               {
               if(members[i]>0)s=0;
               }
            }
         }
      
      for(col=0;col<9;col++)
         {
         for(i=0;i<9;i++)members[i]=i+1;
         for(row=0;row<9;row++)
            {
            for(i=0;i<9;i++)
               {
               if(sudoku[row][col].generated==members[i])members[i]=0;
               }
            }
         for(i=0;i<9;i++)
            {
            if(members[i]>0)s=0;
            }
         }
      for(row=0;row<9;row++)
         {
         for(i=0;i<9;i++)members[i]=i+1;
         for(col=0;col<9;col++)
            {
            for(i=0;i<9;i++)
               {
               if(sudoku[row][col].generated==members[i])members[i]=0;
               }
            }
         for(i=0;i<9;i++)
            {
            if(members[i]>0)s=0;
            }
         }
      }
   }
wait(int milliseconds)
   {
   clock_t endwait;
   endwait=clock()+milliseconds*((clock_t)1);
   while(clock()<endwait){}
   }
timed_getch(int milliseconds)
   {
   clock_t endwait; int x;
   endwait=clock()+milliseconds*((clock_t)1);
   while(clock()<endwait)
      {
      if(kbhit())
         {
         x=getch();
         if(x==224)getch();break;
         }
      }
   }
main()
   {
   system("color f0");
   int on=1,press,scroll,
       select=1,selectLv,exit,
       Lv=1, car,game, quit=0,     stopwatch = 0 ,
       a,e,i,r, x,f, y,d, taken[9],difficulty[3]={16,21,26}/*{16,21,26}*/,
       full, col,row, legend,correct,members[9],LvUp,
       blink=1, hh,mm,ss,  fill=0,
       opt, countdown;
   float second, duration;
   char player[41],letter,displetter, title[10]={"SUDOKU   "},text[4][162];
   clock_t interval,start,end;
   while(on==1)
      {
      system("cls");
      system("color f0");
      printf("\n\n\n\n      S\n\t\t\t\t\t\t      ");
      if(select==1)printf("%c  PLAY",175);else
                   printf("  Play");
      printf("\n      U\n\n");
      printf("      D                                               ");
      if(select==2)printf("%c  HIGH SCORES",175);else
                   printf("  High Scores");
      printf("\n\n");
      printf("      O\n\t\t\t\t\t\t      ");
      if(select==3)printf("%c  INSTRUCTION",175);else
                   printf("  Instruction");
      printf("\n      K\n\n      U\t\t\t\t\t\t      ");
      if(select==4)printf("%c  ABOUT",175);else
                   printf("  About");
      printf("\n\n\n\n\n\t\t\t\t\t\t      ");
      if(select==5)printf("%c  EXIT",175);else
                   printf("  Exit");
      putchar('\n');
      press=getch();
      if(press==224)
         {
         scroll=getch();
         if(scroll==UP)
            {
            if(1<select)--select;else select=5;
            }
         else if(scroll==DOWN)
            {
            if(select<5)select++;else select=1;
            }
         }else
      if(press==13)
         {
         if(select==1)
            {
            selectLv=1;
            blink=1;
            while(selectLv==1)
               {
               interval = clock() + 900*((clock_t)1);
               while(clock() < interval)
                  {
                  system("cls");
                  printf("\n\n\n\n      S\n\n      U\n\t\t\t\t\t\t Select difficulty :");
                  printf("\n      D\n\n      O\n\n      K\n\t\t\t\t\t\t\t\t  ");
                  if(blink==1)putchar(24);else putchar(' ');
                  printf("\n      U                                                    LEVEL  %d",Lv);
                  printf("\n\t\t\t\t\t\t\t\t  ");
                  if(blink==1)putchar(25);else putchar(' ');
                  putchar('\n');
                  if(kbhit())
                     {
                     press=getch();
                     if(press==224)
                        {
                        scroll=getch();
                        if(scroll==UP)
                           {
                           if(Lv<3)Lv++;
                           }
                        else if(scroll==DOWN)
                           {
                           if(1<Lv)--Lv;
                           }
                        }
                     else if('0'<=press&&press<'2')Lv=1;
                     else if(press=='2')Lv=2;
                     else if('2'<press&&press<='9')Lv=3;
                     else if(press==13)
                        {
                        selectLv=0;
                        game=1;
                        break;
                        }
                     else if(press==27||press==8)
                        {
                        selectLv=0;
                        game=0;
                        break;
                        }
                     }
                  }
               if(blink==1)blink=0;else blink=1;
               }
            if(game==1)
               {
               do {
                  system("cls");
                  printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\tEnter Player Name :   ");
                  gets(player);
                  if(strlen(player)>15||(strlen(player)<2&&strlen(player)>0))
                     {
                     system("cls");
                     printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t  ");
                     if(strlen(player)>15)printf("        MAX of 15 characters ONLY %c\n",19);
                     else printf("       Enter AT LEAST 2 characters %c\n",19);
                     timed_getch(4000);
                     }
                  }while(strlen(player)>15||strlen(player)<2);
               car=1;
               while(car==1)
                  {
                  generate_Sudoku(sudoku);
                  for(row=0;row<9;row++)
                     {
                     for(col=0;col<9;col++)
                        {
                        sudoku[row][col].val = sudoku[row][col].generated;
                        sudoku[row][col].par = sudoku[row][col].generated+48;
                        sudoku[row][col].leg = sudoku[row][col].generated+48;
                        }
                     }
                  e = difficulty[Lv-1];
                  letter='A';
                  while(0<e)
                     {
                     x = rand() % 9;
                     y = rand() % 9;
                     if(0<sudoku[y][x].val)
                        {
                        sudoku[y][x].val = 0;
                        sudoku[y][x].par = letter;
                        sudoku[y][x].leg = letter;
                        letter++;
                        --e;
                        }
                     }
                  displetter='A';
                  legend=0;
                  quit=0;
                  start=clock();
                  while(game==1)
                     {
                     system("cls");
                     if(legend==0)
                        {
                        system("color f0");
                        if(quit<3)
                           {
                           full=1;
                           for(row=0;row<9;row++)
                              {
                              for(col=0;col<9;col++)
                                 {
                                 if(sudoku[row][col].val==0)full=0;
                                 }
                              }
                           if(full==1)
                              {
                              for(d=0;d<3;d++)
                                 {
                                 for(f=0;f<3;f++)
                                    {
                                    for(i=0;i<9;i++)taken[i]=0; i=0;
                                    for(y=0;y<3;y++)
                                       {
                                       for(x=0;x<3;x++)
                                          {
                                          taken[i]=sudoku[y+d*3][x+f*3].val;
                                          i++;
                                          }
                                       }
                                    for(i=0;i<9;i++)
                                       {
                                       for(a=i+1;a<9;a++)
                                          {
                                          if(0<taken[i])
                                             {
                                             if(taken[i]==taken[a])system("color fc");
                                             }
                                          }
                                       }
                                    }
                                 }
                              for(col=0;col<9;col++)
                                 {
                                 for(row=0;row<9;row++)
                                    {
                                    for(a=row+1;a<9;a++)
                                       {
                                       if(0<sudoku[row][col].val)
                                          {
                                          if(sudoku[row][col].val==sudoku[a][col].val)system("color fc");
                                          }
                                       }
                                    }
                                 }
                              for(row=0;row<9;row++)
                                 {
                                 for(col=0;col<9;col++)
                                    {
                                    for(a=col+1;a<9;a++)
                                       {
                                       if(0<sudoku[row][col].val)
                                          {
                                          if(sudoku[row][col].val==sudoku[row][a].val)system("color fc");
                                          }
                                       }
                                    }
                                 }
                              }
                           }
                        }
                     else system("color f1");
                     printf("\n\n");
                     if(quit==0)printf("    [Escape]  - Quit");
                     printf("\n\n");
                     if(quit==0)printf("    [Delete]  - Clear cell                      ");else
                     if(quit==1||quit==2)printf("\tAre you sure you want to quit?          ");else
                     if(quit==3||quit==4)printf("\tDo you want to see the solution?        ");
                     for(col=0;col<9;col++)
                        {
                        if(legend==0)printf("%c  ",sudoku[0][col].par);else
                        if(legend==1)printf("%c  ",sudoku[0][col].leg);
                        }
                     printf("\n\n");
                     if(quit==0)
                        {
                        printf("   [Spacebar] - ");
                        if(legend==0)printf("Toggle Legend        ");
                        else printf("Return to normal mode");
                        printf("           ");
                        }else
                     if(1<=quit&&quit<=4)printf("\t\t\t\t\t\t");
                     for(col=0;col<9;col++)
                        {
                        if(legend==0)printf("%c  ",sudoku[1][col].par);else
                        if(legend==1)printf("%c  ",sudoku[1][col].leg);
                        }
                     printf("\n\n");
                     printf("\t\t\t\t\t\t");
                     for(col=0;col<9;col++)
                        {
                        if(legend==0)printf("%c  ",sudoku[2][col].par);else
                        if(legend==1)printf("%c  ",sudoku[2][col].leg);
                        }
                     printf("\n\t\t\t   ");
                     if(quit==0)printf("         ");else
                     if(quit==1||quit==3)printf("   yes   ");else
                     if(quit==2||quit==4)printf("%c  YES  %c",175,174);
                     printf("\n\t\t\t\t\t\t");
                     for(col=0;col<9;col++)
                        {
                        if(legend==0)printf("%c  ",sudoku[3][col].par);else
                        if(legend==1)printf("%c  ",sudoku[3][col].leg);
                        }
                     printf("\n\n");
                     if(quit==0)
                        {
                        printf("       ");
                        printf("%s",player);
                        for(r=41-strlen(player);0<r;--r)putchar(' ');
                        }
                     else
                        {
                        printf("\t\t\t   ");
                        if(quit==1||quit==3)printf("%c  NO   %c",175,174);else
                        if(quit==2||quit==4)printf("   no    ");
                        printf("            ");
                        }
                     for(col=0;col<9;col++)
                        {
                        if(legend==0)printf("%c  ",sudoku[4][col].par);else
                        if(legend==1)printf("%c  ",sudoku[4][col].leg);
                        }
                     printf("\n\n\t\t\t\t\t\t");
                     for(col=0;col<9;col++)
                        {
                        if(legend==0)printf("%c  ",sudoku[5][col].par);else
                        if(legend==1)printf("%c  ",sudoku[5][col].leg);
                        }
                     printf("\n       ");
                     if(quit==0)printf("LEVEL  %d",Lv);
                     printf("\n\t\t\t\t\t\t");
                     for(col=0;col<9;col++)
                        {
                        if(legend==0)printf("%c  ",sudoku[6][col].par);else
                        if(legend==1)printf("%c  ",sudoku[6][col].leg);
                        }
                     for(row=7;row<9;row++)
                        {
                        printf("\n\n\t\t\t\t\t\t");
                        for(col=0;col<9;col++)
                           {
                           if(legend==0)printf("%c  ",sudoku[row][col].par);else
                           if(legend==1)printf("%c  ",sudoku[row][col].leg);
                           }
                        }
                     printf("\n       ");
                     if(stopwatch)
                        {
                        duration=clock()-start;
                        second=duration/1000;
                        hh=second/60/60;
                        mm=second/60;
                        mm%=60;
                        ss=second;
                        ss%=60;
                        if(hh<10)putchar('0');
                        printf("%d:",hh);
                        if(mm<10)putchar('0');
                        printf("%d:",mm);
                        if(ss<10)putchar('0');
                        printf("%d",ss);
                        }else
                     printf("        ");
                     if(!quit)
                        {
                        printf(" \t       %c    ",displetter);
                        for(row=0;row<9;row++)
                           {
                           for(col=0;col<9;col++)
                              {
                              if(sudoku[row][col].leg==displetter)
                                 {
                                 if(0<sudoku[row][col].val)printf("%d\b",sudoku[row][col].val);
                                 }
                              }
                           }
                        }else putchar('\n');
                     correct=1;
                     for(d=0;d<3;d++)
                        {
                        for(f=0;f<3;f++)
                           {
                           for(i=0;i<9;i++)members[i]=i+1;
                           for(y=0;y<3;y++)
                              {
                              for(x=0;x<3;x++)
                                 {
                                 for(i=0;i<9;i++)
                                    {
                                    if(sudoku[y+d*3][x+f*3].val==members[i])members[i]=0;
                                    }
                                 }
                              }
                           for(i=0;i<9;i++)
                              {
                              if(members[i]>0)correct=0;
                              }
                           }
                        }
                     for(col=0;col<9;col++)
                        {
                        for(i=0;i<9;i++)members[i]=i+1;
                        for(row=0;row<9;row++)
                           {
                           for(i=0;i<9;i++)
                              {
                              if(sudoku[row][col].val==members[i])members[i]=0;
                              }
                           }
                        for(i=0;i<9;i++)
                           {
                           if(members[i]>0)correct=0;
                           }
                        }
                     for(row=0;row<9;row++)
                        {
                        for(i=0;i<9;i++)members[i]=i+1;
                        for(col=0;col<9;col++)
                           {
                           for(i=0;i<9;i++)
                              {
                              if(sudoku[row][col].val==members[i])members[i]=0;
                              }
                           }
                        for(i=0;i<9;i++)
                           {
                           if(members[i]>0)correct=0;
                           }
                        }
                     if(correct==1)
                        {
                        end=clock();
                        duration=end-start;
                        second=duration/1000;
                        hh=second/60/60;
                        mm=second/60;
                        mm%=60;
                        ss=second;
                        ss%=60;
                        
                        strcpy(top[fill].player,player);
                        top[fill].h = hh;
                        top[fill].m = mm;
                        top[fill].s = ss;
                        top[fill].duration = second;
                        top[fill].Lv = Lv;
                        
                        i=fill;
                        while(  ( top[i-1].Lv<top[i].Lv||  (top[i-1].Lv==top[i].Lv&&top[i-1].duration>top[i].duration) )  &&0<i  )
                           {
                           strcpy(top[8].player,top[i-1].player);
                           top[8].h = top[i-1].h;
                           top[8].m = top[i-1].m;
                           top[8].s = top[i-1].s;
                           top[8].duration = top[i-1].duration;
                           top[8].Lv = top[i-1].Lv;
                           
                           strcpy(top[i-1].player,top[i].player);
                           top[i-1].h = top[i].h;
                           top[i-1].m = top[i].m;
                           top[i-1].s = top[i].s;
                           top[i-1].duration = top[i].duration;
                           top[i-1].Lv = top[i].Lv;
                           
                           strcpy(top[i].player,top[8].player);
                           top[i].h = top[8].h;
                           top[i].m = top[8].m;
                           top[i].s = top[8].s;
                           top[i].duration = top[8].duration;
                           top[i].Lv = top[8].Lv;
                           
                           --i;
                           }
                        if(fill<7)fill++;
                        
                        wait(3000);
                        system("cls");
                        system("color f0");
                        printf("\n\n");
                        for(row=0;row<2;row++)
                           {
                           printf("\n\n\t\t\t\t\t\t");
                           for(col=0;col<9;col++)
                              {
                              printf("%d  ",sudoku[row][col].val);
                              }
                           }
                        printf("\n\t      CONGRATULATIONS%c\n\t\t\t\t\t\t",19);
                        for(col=0;col<9;col++)printf("%d  ",sudoku[2][col].val);
                        printf("\n\n\t\t\t\t\t\t");
                        for(col=0;col<9;col++)printf("%d  ",sudoku[3][col].val);
                        printf("\n\t You have solved the puzzle\n\t\t\t\t\t\t");
                        for(col=0;col<9;col++)printf("%d  ",sudoku[4][col].val);
                        printf("\n\t       in a matter of\n\t\t\t\t\t\t");
                        for(col=0;col<9;col++)printf("%d  ",sudoku[5][col].val);
                        printf("\n\n\t\t  ");
                        if(hh<10)putchar('0');
                        printf("%d:",hh);
                        if(mm<10)putchar('0');
                        printf("%d:",mm);
                        if(ss<10)putchar('0');
                        printf("%d",ss);
                        printf("                      ");
                        for(col=0;col<9;col++)printf("%d  ",sudoku[6][col].val);
                        for(row=7;row<9;row++)
                           {
                           printf("\n\n\t\t\t\t\t\t");
                           for(col=0;col<9;col++)
                              {
                              printf("%d  ",sudoku[row][col].val);
                              }
                           }
                        printf("\n    ");
                        system("pause");
                        break;
                        }
                     if(kbhit()||stopwatch==0)
                        {
                        if(quit>0)press=getch();
                        if(quit==0)
                           {
                           press=getche();
                           if(press==224)
                              {
                              scroll=getch();
                              if(scroll==DEL)
                                 {
                                 for(row=0;row<9;row++)
                                    {
                                    for(col=0;col<9;col++)
                                       {
                                       if(sudoku[row][col].leg==displetter)
                                          {
                                          sudoku[row][col].val=0;
                                          sudoku[row][col].par=sudoku[row][col].leg;
                                          }
                                       }
                                    }
                                 }
                              }else
                           if(press=='0')
                              {
                              for(row=0;row<9;row++)
                                 {
                                 for(col=0;col<9;col++)
                                    {
                                    if(sudoku[row][col].leg==displetter)
                                       {
                                       sudoku[row][col].val=0;
                                       sudoku[row][col].par=sudoku[row][col].leg;
                                       }
                                    }
                                 }
                              }else
                           if('1'<=press&&press<='9')
                              {
                              for(row=0;row<9;row++)
                                 {
                                 for(col=0;col<9;col++)
                                    {
                                    if(sudoku[row][col].leg==displetter)
                                       {
                                       sudoku[row][col].val=press-48;
                                       sudoku[row][col].par=press;
                                       }
                                    }
                                 }
                              }else
                           if('A'<=press&&press<='Z')
                              {
                              for(row=0;row<9;row++)
                                 {
                                 for(col=0;col<9;col++)
                                    {
                                    if(press==sudoku[row][col].leg)
                                       {
                                       displetter=sudoku[row][col].leg;
                                       }
                                    }
                                 }
                              }else
                           if('a'<=press&&press<='z')
                              {
                              for(row=0;row<9;row++)
                                 {
                                 for(col=0;col<9;col++)
                                    {
                                    if(press-32==sudoku[row][col].leg)
                                       {
                                       displetter=sudoku[row][col].leg;
                                       }
                                    }
                                 }
                              }else
                           if(press==27)quit=2;else
                           if(press==8)
                              {
                              for(row=0;row<9;row++)
                                 {
                                 for(col=0;col<9;col++)
                                    {
                                    if(sudoku[row][col].leg==displetter)
                                       {
                                       sudoku[row][col].val=0;
                                       sudoku[row][col].par=sudoku[row][col].leg;
                                       }
                                    }
                                 }
                              }else
                           if(press==' ')
                              {
                              if(legend==1)legend=0;else legend=1;
                              }else
                           if(press==92)
                              {
                              if(stopwatch==1)stopwatch=0;else stopwatch=1;
                              }
                           }else
                        if(quit==1)
                           {
                           if(press==224)
                              {
                              scroll=getch();
                              if(scroll==LEFT||scroll==UP||scroll==DOWN||scroll==RIGHT)quit++;
                              }else
                           if(press==27)quit=0;else
                           if(press==8)quit=0;else
                           if(press==13)--quit;else
                           if(press==92)
                              {
                              if(stopwatch==1)stopwatch=0;else stopwatch=1;
                              }
                           }else
                        if(quit==2)
                           {
                           if(press==224)
                              {
                              scroll=getch();
                              if(scroll==LEFT||scroll==UP||scroll==DOWN||scroll==RIGHT)--quit;
                              }else
                           if(press==27)quit=0;else
                           if(press==8)quit=0;else
                           if(press==13)
                              {
                              quit+=2;
                              stopwatch=0;
                              }else
                           if(press==92)
                              {
                              if(stopwatch==1)stopwatch=0;else stopwatch=1;
                              }
                           }else
                        if(quit==3)
                           {
                           if(press==224)
                              {
                              scroll=getch();
                              if(scroll==LEFT||scroll==UP||scroll==DOWN||scroll==RIGHT)quit++;
                              }else
                           if(press==13)
                              {
                              game=0;
                              car=0;
                              }
                           }else
                        if(quit==4)
                           {
                           if(press==224)
                              {
                              scroll=getch();
                              if(scroll==LEFT||scroll==UP||scroll==DOWN||scroll==RIGHT)--quit;
                              }else
                           if(press==13)
                              {
                              system("cls");
                              system("color f0");
                              printf("\n\n");
                              for(row=0;row<9;row++)
                                 {
                                 printf("\n\n      %c \t\t\t\t\t",title[row]);
                                 for(col=0;col<9;col++)
                                    {
                                    printf("%d  ",sudoku[row][col].generated);
                                    }
                                 }
                              printf("\n    ");
                              system("pause");
                              game=0;
                              car=0;
                              }
                           }
                        }
                     }
                  if(correct==1)
                     {
                     if(Lv<3)
                        {
                        LvUp=2;
                        while(0<LvUp)
                           {
                           system("cls");
                           printf("\n\n");
                           for(row=0;row<2;row++)
                              {
                              printf("\n\n\t\t\t\t\t\t");
                              for(col=0;col<9;col++)printf("%d  ",sudoku[row][col].val);
                              }
                           printf("\n\n\t\t   Proceed to Level %d?          ",Lv+1);
                           for(col=0;col<9;col++)printf("%d  ",sudoku[2][col].val);
                           for(row=3;row<5;row++)
                              {
                              printf("\n\n\t\t\t\t\t\t");
                              for(col=0;col<9;col++)printf("%d  ",sudoku[row][col].val);
                              }
                           printf("\n\t\t\t   ");
                           if(LvUp==2)printf("%c  YES  %c",175,174);else
                           if(LvUp==1)printf("   yes   ");
                           printf("\n\t\t\t\t\t\t");
                           for(col=0;col<9;col++)printf("%d  ",sudoku[5][col].val);
                           printf("\n\n\t\t\t   ");
                           if(LvUp==2)printf("   no    ");else
                           if(LvUp==1)printf("%c  NO   %c",175,174);
                           printf("            ");
                           for(col=0;col<9;col++)printf("%d  ",sudoku[6][col].val);
                           for(row=7;row<9;row++)
                              {
                              printf("\n\n\t\t\t\t\t\t");
                              for(col=0;col<9;col++)printf("%d  ",sudoku[row][col].val);
                              }
                           putchar('\n');
                           press=getch();
                           if(press==224)
                              {
                              scroll=getch();
                              if(scroll==LEFT||scroll==UP||scroll==DOWN||scroll==RIGHT)
                                 {
                                 if(LvUp==1)LvUp=2;else LvUp=1;
                                 }
                              }else
                           if(press==13)
                              {
                              if(LvUp==1)
                                 {
                                 car=0;
                                 }else
                              if(LvUp==2)
                                 {
                                 if(Lv<3)Lv++;
                                 correct=0;
                                 }
                              LvUp=0;
                              }
                           }
                        }else
                     if(Lv==3)car=0;
                     }
                  }
               }
            }
         else if(select==2)
            {
            system("cls");
            printf("\n\n\n\t\t\tPlayer Name             Duration       Level\n      S\n");
            for(i=0;i<7;i++)
               {
               printf("\n      %c\n\t\t   %d.",title[i+1],i+1);
               if(i<fill)
                  {
                  printf("  %s",top[i].player);
                  for(r=25-strlen(top[i].player);0<r;--r)putchar(' ');
                  if(top[i].h<10)putchar('0');
                  printf("%d:",top[i].h);
                  if(top[i].m<10)putchar('0');
                  printf("%d:",top[i].m);
                  if(top[i].s<10)putchar('0');
                  printf("%d",top[i].s);
                  printf("         %d",top[i].Lv);
                  }
               }
            printf("\n\n\n\n\t\t\t       ");
            system("pause");
            }
         else if(select==3)
            {
            system("cls");
            printf("\n\n\n");
            printf("\t\t   Complete the sudoku by filling it up with the");
            printf("\n      S\n");
            printf("\t\t   numbers 1 through 9 so that each number from");
            printf("\n      U\n");
            printf("\t\t   1 to 9 occurs once and only once in each row,");
            printf("\n      D\n");
            printf("\t\t   in each column, and in each 3x3 block.");
            printf("\n      O\n\n      K\n");
            printf("\t\t   Cells to be filled up are marked by specific");
            printf("\n      U\n");
            printf("\t\t   letters. To fill such cell with a desired number,");
            printf("\n\n\t\t   press the corresponding letter and then press the");
            printf("\n\n\t\t   desired number.\n\n\n\n");
            printf("\t\t\t       ");
            system("pause");
            system("cls");
            printf("\n\n\n");
            printf("\t\t   Press  ``Spacebar''  to toggle legend. The legend");
            printf("\n      S\n");
            printf("\t\t   shall show which cells are fixed and which cells");
            printf("\n      U\n");
            printf("\t\t   are marked by a specific letter.   To clear a");
            printf("\n      D\n");
            printf("\t\t   previously modified cell of a number, press the");
            printf("\n      O\n");
            printf("\t\t   corresponding letter and then press  ``Delete'' .");
            printf("\n      K\n");
            printf("\t\t   To quit the game, press  ``Escape'' .");
            printf("\n      U\n");
            printf("\t\t   High scores are ranked first according to");
            printf("\n\n\t\t   difficulty level and then according to the");
            printf("\n\n\t\t   time spent completing the sudoku.");
            printf("\n\n\n\n\t\t\t       ");
            system("pause");
            }
         else if(select==4)
            {
            strcpy(text[0],"                                    2011379511                                                                                                                  ");
            strcpy(text[1],"                                                                                                                      CSPROG                                    ");
            strcpy(text[2],"                BS Applied Mathematics with Information Technology                                         Fundamentals of Programming                          ");
            strcpy(text[3],"                                ( AMIT )   student                                                          Professor Edward P. Andaya                          ");
            for(countdown=0,opt=1;!kbhit();)
               {
               system("cls");
               printf("\n\n\t\t\t\t\t\t\t  Press any key to");
               printf("\n\n\t\t\t\t\t\t\t     continue . . .");
               printf("\n\t\t\t\t  S U D O K U\n\n\n");
               printf("\t\t\t  This program was created by");
               printf("\n\n\t\t\t      Cabatingan, Andr%c M.",130);
               printf("\n\n");
               for(i=0;i<4;i++)
                  {
                  text[i][160]=text[i][0];
                  for(a=0;a<160;a++)
                     {
                     text[i][a]=text[i][a+1];
                     }
                  text[i][160]=text[i][80];
                  text[i][80]='\0';
                  puts(text[i]);
                  text[i][80]=text[i][160];
                  }
               printf("\n\t\t\t     Far Eastern University\n");
               if(countdown==80)
                  {
                  duration=5000;
                  interval=clock()+(duration/1000)*CLK_TCK;
                  while(clock()<interval)if(kbhit())break;
                  opt++;
                  }else
               if(countdown==0)
                  {
                  duration=5000;
                  interval=clock()+(duration/1000)*CLK_TCK;
                  while(clock()<interval)if(kbhit())break;
                  --opt;
                  }
               else
                  {
                  duration=10;
                  interval=clock()+(duration/1000)*CLK_TCK;
                  while(clock()<interval)if(kbhit())break;
                  }
               if(opt==0)countdown++;else --countdown;
               }
            a=getch();
            if(a==224)getch();
            }
         else if(select==5)
            {
            exit=1;
            while(1)
               {
               system("cls");
               printf("\n\n\n\n      S\n\n      U\n");
               printf("\t\t\t\t      Are you sure you want to exit?");
               printf("\n      D\n\n      O\n\n");
               printf("      K                                                   ");
               if(exit==1)printf("%c  OK",175);else
                          printf("  OK");
               printf("\n\n      U\n");
               printf("\t\t\t\t\t\t\t  ");
               if(exit==0)printf("%c  CANCEL");else
                          printf("  Cancel");
               putchar('\n');
               press=getch();
               if(press==224)
                  {
                  scroll=getch();
                  if(scroll==UP||scroll==DOWN||scroll==LEFT||scroll==RIGHT)
                     {
                     if(exit==1)exit=0;else exit=1;
                     }
                  }else
               if(press==13)
                  {
                  if(exit==1)
                     {
                     on=0;
                     break;
                     }
                  else if(exit==0)
                     {
                     select=1;
                     break;
                     }
                  }else
               if(press==8||press==27)break;
               }
            }
         }else
      if(press==27)
         {
         exit=1;
         while(1)
            {
            system("cls");
            printf("\n\n\n\n      S\n\n      U\n");
            printf("\t\t\t\t      Are you sure you want to exit?");
            printf("\n      D\n\n      O\n\n");
            printf("      K                                                   ");
            if(exit==1)printf("%c  OK",175);else
                       printf("  OK");
            printf("\n\n      U\n");
            printf("\t\t\t\t\t\t\t  ");
            if(exit==0)printf("%c  CANCEL");else
                       printf("  Cancel");
            putchar('\n');
            press=getch();
            if(press==224)
               {
               scroll=getch();
               if(scroll==UP||scroll==DOWN||scroll==LEFT||scroll==RIGHT)
                  {
                  if(exit==1)exit=0;else exit=1;
                  }
               }else
            if(press==13)
               {
               if(exit==1)
                  {
                  on=0;
                  break;
                  }
               else if(exit==0)
                  {
                  select=1;
                  break;
                  }
               }else
            if(press==8||press==27)break;
            }
         }
      }
   }

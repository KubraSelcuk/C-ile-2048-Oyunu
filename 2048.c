#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include <time.h>
#define MAXRANDOMVALUE 3 //Buda Ayni 
#define MAXPREV 3 //Burda o islemci komutuyla global olarak tanimladik.Her fonk kullanabilmek için
int arr[4][4]={0},c[4],temp=0,len=0,score=0,highscore=0,count=0,ch=0;//COUNT WILL COUNT THE NO OF STEPS
void print()    //Yazdirma fonk nu olusturuyoruz
{
        int i,j,k,len1;

        printf("\n\t\t\t\t\t              Hosgeldiniz            \n");
        
          if(score<highscore) //eger score  buyukse yuksek score dan 
          {
              printf("HIGH SCORE=%d\t\t\t\t\t\n",highscore); //goster yuksek scoru
          }
          else //degilse
          {
              highscore=score;  //highscore kucukse score dan score degerini highscore ata
              printf("HIGH SCORE=%d\t\t\t\t\t\n",highscore); //ve gosterdik yuksek score
          }
     //     time_t basla,bit;
     //struct tm *zmn;
     //time(&basla);
     //zmn = localtime(&basla);
     //printf("Baslangic :%02d :%02d :%02d\r",zmn->tm_hour,zmn->tm_min,zmn->tm_sec); ////zaman
        printf("YOUR SCORE=%d",score); //su anki score gosteriyor
        printf("\nPREV      ->Z");
        printf("\nRESTART   ->R");
        printf("\nEXIT      ->E");   
    printf("\t\t\t\t.................................\n");
    for (i=0;i<4;i++) //4 satir  Burda oyunumuzun arayuzunu olusturduk 
    {
        for(j=0;j<4;j++)//4 sutun olusturduk
        {
            if(j==0) //eger  j == 0 
            {
                printf("\t\t\t\t\t/"); // 5 adet tap boslugu birakarak / yazdiriyor
            }
            if(arr[i][j]!=0) //eger arr satir ve sutunu degeri esit degilse 0 ra
            {
                len1=findlen(arr[i][j]); //buldugumuz ilk arr satir ve sutun degiri len1 atar 

                for(k=0;k<4-len;k++) 
                {
                    printf(" "); //Bos Bosluklari gosterdik 4 tane
                }
                printf("%d",arr[i][j]);//Bos bosluklara arr satir ve sutulerine deger gosterdik

                for(k=0;k<4-len;k++)
                {
                    printf(" "); //Burdada ayni
                }
                for(k=0;k<len-1;k++)
                {
                    printf(" ");
                }
                printf("/");
            }
            else
            {
                for(k=0;k<8-2*len-1;k++) //Buraya bakicas
				{
                printf(" ");
				}
				printf("/");
            }
            len=0;
        }
        if(i!=3)
        {
        printf("\n");
    printf("\t\t\t\t\t.................................\n");
        }
    }
    printf("\n\t\t\t\t\t.................................\n");
     
    printf("\t\t\t\t\tENTER YOUR CHOISE -> W,S,A,D\n\t\t\t\t\t");

}
void movevalue(int k)//hereket etdirdigimizde calisacak fonksiyon w s d a girildiginde
{
    int i;
    if(k==3 )
    {
        return;
    }
    for(i=k;i<4;i++)
    {
        if(c[i]!=0) //eger c dizimizin degeri 0 ra esit degilse
        {
            movevalue(i+1); // i 1 artdirarak burda ozyinileme kullandik 
            for(;i<4;i++) //baslangic deger kullanmadik
            {
                if(c[i+1]!=0) //eger i birsonraki degeri 0 ra esitdegilese bu fonk dan cik atla
                {
                    break;
                }
                    c[i+1]=c[i]; //degilse 
                    c[i]=0;
            }


        }
    }
}
int findlen(int n)  
{

        if(n==0) //findlen degeri 0 ra esitse
        {

            return len; //geri dondur len
        }
        else  //degilese
        {
            len++; //len 1 artir
            findlen(n/10);//Burdada ozyinele kullanarak degeri /10 a
        }
}
void addrandomno() //rastgele sayi uretme fonks
{
    int no;
     srand(time(NULL)); // her defasinda farkli sayi uretiyor
    int i,j; //RANDOM INDEX
    do
    {
    i=(rand ())%(MAXRANDOMVALUE+1); // 4sayi araliginda uretdigimiz sayiyi i ve j atadik
    j=(rand ())%(MAXRANDOMVALUE+1);
    }
    while(arr[i][j]!=0); //arr satir ve sutu esit degilse 0 ra
   //printf("%d %d",i,j);
    no=2*((rand ()%10)+1); //uretdigimiz sayi no ya atadik
    if(no==3 || no==2)//Burdada uretdigimiz sayi 3 veya 2 esitse
    {
        arr[i][j]=4; //diziye 4 ekliyor
    }
    else //degilse
    {
        arr[i][j]=2; // 2 ekliyor
    }
}
void rupdate() //Degeri gunceleyen fonk
{
    int i,j;
    for(i=3;i>0;i--)
    {
        if(c[i]==c[i-1] )
        {
            c[i]+=c[i-1];
            score=score+c[i];
            if(score>highscore)
            {
            	
            }
            temp=1;
            c[i-1]=0;
        }
        else if(c[i-1]==0 && c[i]!=0 )
        {
            c[i-1]=c[i];
            c[i]=0;
            temp=1;
        }
        else if(c[i]==0)
        {
            temp=1;
        }
    }
        movevalue(0);

}
void createprev(int ***p)//geri aldigimizda olusan yenei degerler
{
      int i,j,k; 
      FILE *ptr; //dosya tanimladik
      ptr=fopen("hstr.txt","a");//acilan hstr.txt dosyasina ekleme yapar
      fprintf(ptr,"%d ",score); //ve dosyayi kayt etdik
      fclose(ptr);//ve kapatdik

    if(count==MAXPREV+1)
    {
        for(i=MAXPREV;i>0;i--)
        {
            for(j=0;j<4;j++)
            {
                for(k=0;k<4;k++)
                {
                        p[i][j][k]=p[i-1][j][k];
                }
            }

        }
        count=MAXPREV;
    }

    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            p[MAXPREV-count][i][j]=arr[i][j];
        }

    }
}
void updatearrtoprev(int ***p)//geri aldigimizda guncellened hali 
{
    int data,i,j;
    if(count==0)
    {
        printf("\n\t\t\t\t\t******FURTHER MORE PREV NOT POSSIBLE********");
        return;
    }
    FILE *ptr=fopen("hstr.txt","r+");
        for(i=0;i<count;i++)
        {
            fscanf(ptr,"%d ",&data);
        }
        score=data;

    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            arr[i][j]=p[MAXPREV-count][i][j];
        }
    }
    count--;



}
void resetgame()
{
            int i,j;
            for(i=0;i<4;i++)//Burdada arr dizimizin satir ve sutune 0 ladik 
            {
                for(j=0;j<4;j++)
                {
                    arr[i][j]=0;

                }
            }
            system("cls") ; //pencereyi kapadik
            score=0;//scoruda 0 ladik
            addrandomno();//rastgele 1 sayi uredik 

}
int main()
{
	system("color 4");//ilk acilis pencere rengini ayarladik
    int i,j,k,m,n,same=0,islem;//gerekken degiskenlerimizi taimladik
    //int fark,islem;
	//time_t basla, bit;
    char choise,s=177,reschk;//char karakterþ tanimladi ve 177 ASCÝÝ koduyla tanimladik
    printf("\n\t\t\t\t\t1)    ->Gelistiriceler  icin ");
    printf("\n\t\t\t\t\t2)    ->Konsol komut Bilgileri ");
    printf("\n\t\t\t\t\t3)    ->Oyuna Baslamak ");
    printf("\n\t\t\t\t\tLutfen 1 ve 2 veya 3 seciniz:");
    scanf("%d",&islem);
    switch(islem) 
    {
case 1:         printf("\nIsim\t\tSoyadi");
    	        printf("\nB\t\t");
				printf("\nM\t\t");
				printf("\nYusup\t\tNarkuvatov");
				printf("\nN\t\t");
				printf("\n\t\t\tOyuna Baslamak icin herhangi tusa basiniz...");
				system("color 3");
				getch();
				system("cls");
				break;			 
case 2:	        printf("\n\n\t\tKonsol Komutlari\n");
		        printf("\n\t\t\t\tYukari      ->'W' veya 'W'");
		        printf("\n\t\t\t\tAsagi       ->'S' veya 's' ");
				printf("\n\t\t\t\tSola        ->'A' veya 'a'");
				printf("\n\t\t\t\tSaga        ->'D' veya 'd'");
				printf("\n\t\t\t\tGeri Alma   -> 'Z' veya 'z'");
				printf("\n\t\t\t\tRestart     ->'R' veya 'r'");
				printf("\n\t\t\t\tCikis       ->'E' veya 'e'");
				printf("\n\n\t\t\t\t\tOyuna Baslamak icin herhangi tusa basiniz...");
				system("color 3");
				getch();
				system("cls");break;
	}
	
  for(i=0;i<1;i++)
    {
    printf("\n\t\t\t**************Oyununuz Hazirlaniyor Lutfen Bekleyin**************");
	sleep(3);	//Burda 3mlsaniye bekletdik
	}
     printf("\n\n\t\t\t\tLOADING ");
    for( i=0; i<36;i++)  //Burdada ASCII karakter koduyla 36 kadar saydirdik
    {
    	system("color 2"); //Burda renk kdunu kullnarak renk degistirdik
        printf("%c",s);
        j=i;
        if(i%2!=0 && i<20) //Eger i/2 kalan 0 ise i<20 den kücük ise ikiside dogru oldugu surece bekletilecek
		{
            sleep(1);
        }
    }
    sleep(1);
    system("cls"); //ve Pecereyi Kapatdik
                 
    int ***p; //Burda pointer olusturduk
    p=(int ***)malloc(sizeof(int *)*(MAXPREV+1)); //Burdada malloc fonk ile yer olusturduk
    for(i=0;i<MAXPREV+1;i++)  //Burdada   
    {
        *(p+i)=(int **)malloc(sizeof(int *)*4);  //Buraya anlamadim
    }
    for(i=0;i<MAXPREV+1;i++)
    {
        for( j=0;j<4;j++)
        {
            p[i][j]=(int *)malloc(sizeof(int)*4);
        }
    }
    createprev(p);

    FILE *ptr;     //ptr Adinda Dosya taimladik
    ptr=fopen("highscore.txt","r"); //  highscore.txt adindaki  dosyayi  acdik okuna bilir olarak
    fscanf(ptr,"%d",&highscore); //olsurdugumuz dosyanin icinde veri varsada bicimlendirerek yeni deger girilmesi icin
    fclose(ptr); //ve dosyamizi kapatdik
    ptr=fopen("hstr.txt","w"); // hstr.txt dosyamizi olusturarak actik yazma amacli    
    fclose(ptr);        //ve kappatdik
    addrandomno();       //Yukarida olusturdugumuz rastgele fonksiyonu ile rastgele sayi atadik 
    print();             //olusturduguuz print fonk ile yazdirdik
    while(1) //sonsuz dogu olusturduk
    {
            if(score>highscore) //eger bizim score buyukse highscore dan 
            {
            ptr=fopen("highscore.txt","w"); //dosyayi olusturduk  
            fprintf(ptr,"%d",score);        //bicimlendirerek yeni veri yi kaytetdik
            fclose(ptr);                    //ve kapatdik
            }
        choise=getch();   
       if(choise=='D' || choise =='d')  //Burdada D veya d ikisinden biri dogruysa asagdaki islemler gerceklesecekdir
        {
            count++;ch++;
              createprev(p);// ayni ola degerleri toplayarak yenideger olusturmus oluyor
            for(i=0;i<4;i++)//Burdada D tuslandiginda 4 satir ve sutun sola ilerler
            {
                for(j=0;j<4;j++)
                {
                    c[j]=arr[i][j]; //ve yeni degeri c dizisine atar
                }
                    rupdate();//ve yeni degeri gunceller
                for(k=0;k<4;k++)
                {
                    arr[i][k]=c[k];
                }
            }
        }
        else if(choise=='a' || choise=='A')
        {
            count++;
            ch++;
            createprev(p);
            for(i=0;i<4;i++)
            {
                for(j=3;j>=0;j--)
                {
                    c[3-j]=arr[i][j];
                }
                rupdate();
                for(k=0;k<4;k++)
                {
                    arr[i][3-k]=c[k];
                }
            }
        }
        else if(choise=='S' || choise =='s')
        {
            count++;ch++;

               createprev(p);
            for(i=0;i<4;i++)
            {
                for(j=0;j<4;j++)
                {
                    c[j]=arr[j][i];
                }
                rupdate();
                for(k=0;k<4;k++)
                {
                    arr[k][i]=c[k];
                }
            }
        }
        else if(choise=='W' || choise=='w')
        {
            count++;ch++;

              createprev(p);
            for(i=0;i<4;i++)
            {
                for(j=3;j>=0;j--)
                {
                    c[3-j]=arr[j][i];
                }
                rupdate();
                for(k=0;k<4;k++)
                {
                  arr[3-k][i]=c[k];
                }
            }
        }
        else if(choise=='Z' || choise =='z')
        {

            updatearrtoprev(p);

            temp=8;
        }
        else if(choise=='R' || choise=='r')
        {
            count=0;
            resetgame();
            print();
            continue;
        }
        else if(choise=='e'||choise=='E')
        {
            exit(0);
        }
            if(temp==1)
            {
                temp=0;
                system("cls") ;
                printf("\n%c\n",choise);
                addrandomno();
                print();

            }
            else if(temp==8)
            {
                temp=0;
                print();
            }
            else
            {
                for(m=0;m<4;m++)
                {
                    for(n=3;n>0;n--)
                    {
                        if(arr[m][n]==arr[m][n-1] || arr[m][n]==0 || arr[m][n-1]==0)
                        {
                                same=1;
                                break;
                        }
                        if(arr[n][m]==arr[n-1][m] || arr[m][n]==0 || arr[m][n-1]==0)
                        {
                            same=1;
                            break;
                        }
                    }
                    if(same==1)
                        break;
                }
               if(same==1)
                {
                    printf("\n\t\t\t\t\t*************Gecersiz Anahtar************\n");
                    same=0;


                }
                else
                {
                     //zaman eklenecek
                    printf("\n\t\t\t\t\t************GAME OVER**************");
                    printf("\n\n\t\t\t\t\tTekrar oynamak istermisiniz: Y/N??\n");
                    printf("\t\t\t\t\tTekrardan Baslamak icin Y komutunu kullanin\n");
                    printf("\t\t\t\t\tCikis yapmak icin N komutunu kullanin"),
                    reschk=getch();
                    switch (reschk)
                    {
                        case 'Y':
                        case 'y':resetgame(); print();break;
                        case 'n':
                        case 'N':exit(0);
                    }
                    continue;

                }
            }
    }
    return 0;
}


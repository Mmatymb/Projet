#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char* argv[])
{
 int i;
 char *type=NULL;
 int trace;
 char *urlhttp=NULL;
 char *nomficin=NULL;
 char *nomficout=NULL;
  if(argc==7){
    if(type_donnee_entree(argc,argv)==1)
    {
     type=recuperationtype(argv,argc);

     trace=verificationdet(argv,argc);

     //urlhttp=recuperationurl(argv,argc);

     nomficin=recuperationficin(argv,argc);

     nomficout=recuperationficout(argv,argc);

    //Vérification et récupération des valeurs pris en entrée
     printf("%d\n",trace); 
     printf("%s\n",type);
     printf("%s\n",urlhttp);
     printf("%s\n",nomficin);
     printf("%s\n",nomficout);
    //Extension du fichier d'entrée
    //printf("%s\n",extensionfic(nomficin));
    //Verification et traitement de l'extension
    //traitementtypeetextension(extensionfic(nomficin),type,nomficin);
     }

     else
     {
       type=recuperationtype(argv,argc);

       trace=verificationdet(argv,argc);

       urlhttp=recuperationurl(argv,argc);

       nomficout=recuperationficout(argv,argc);
     }
    //system("json el -u test.json");
     }
  else if(argc==8)
  	{
      if(type_donnee_entree(argv,argc)==-1){
        printf("Vous devez entrer qu'un seul fichier d'entrée");
      }
      else{
        printf("Vous avez donné des informations inutiles");
      }


        }
   else{
     printf("Les informations données ne sont pas bonnes");
    }

 return 0;
}



char*extensionfic(char*nomficin)
{
char *extension=NULL; 
int i,j;
i=0;
while(i<strlen(nomficin)&&nomficin[i]!='.')
	{
        i=i+1;
    }
if(i>strlen(nomficin)){
        printf("Le fichier n'a pas d'extension");
    }
else{
   char c ;   
    size_t len = strlen(nomficin)-i; int k=0; extension = malloc(len + 1 );
for(j=i+1;j<strlen(nomficin);j++)
{
c=nomficin[j];
extension[k]=c;
k=k+1;
}
extension[len-1 ] = '\0';
 printf( "%s\n", extension ); /* prints "blablablaH" */
}
return extension;
}

void validitedunfichierjson(char*nomficin){
  //Création d'une variable contenant la commande de vérification de la validité du fichier json
    char*test=NULL;
   //Initialisation de cette variable
    test=(char *)malloc((strlen("json val --well-formed -e")+strlen(nomficin))+1);
    strcpy(test,"json val --well-formed -e ");
    strcat(test,nomficin);
//Vérification syntaxique du document
system(test); printf("syntaxiquement\n");
//Test par rapport à une DTD interne
system(test);printf("valide par rapport a son DTD");
//Par rapport à une DTD externe
//system("json val --dtd document.dtd -e document.json");
}

void traitementtypeetextension(char*extension,char*type,char*nomficin)
{
if(strcmp(type,"json")!=0 &&strcmp(type,"json")!=0){
    printf("Le type du fichier doit etre json\n");
}
else if(strcmp(extension,"json")!=0 &&strcmp(extension,"json")!=0){
    printf("L'extension du fichier doit etre json\n");
}
else if(strcmp(extension,type)!=0){
    printf("Vous avez indique %s donc l'extension du fichier doit etre .%s\n",type,type);
}
else{
    validitedunfichierjson(nomficin);
}
}

 //Fonction de recupération du type
char* recuperationtype(char*argv[],int argc){
  int i;
  char*type=NULL;
  i=1;
  while(i<argc && strcmp(argv[i],"-i")!=0){
       i=i+1;
        }
  if(strcmp(argv[i],"-i")==0){type=argv[i+1];}
  else{
            printf("Vous devez  indiquer le type de votre document");
        }
  return type;
}

//Fonction de vérification du paramétre -t
int verificationdet(char*argv[],int argc){
int i;
int trace;
 i=0;
    while(i<argc&&strcmp(argv[i],"-t")!=0){
         i=i+1;
        }

      if(strcmp(argv[i-1],"-t")!=0){trace=0;}
      else{trace=1;}
        return trace;
}

  //Fonction de récupération de l'url si on importe les données avec un flux http
  char* recuperationurl(char*argv[],int argc){
    int i; char*urlhttp=NULL;
    i=1;
    while(i<argc&&strcmp(argv[i],"-h")!=0){
            i=i+1;
        }
    if(strcmp(argv[i],"-h")==0){urlhttp=argv[i+1];}
    else{
    printf("Vous devez donner le nom de votre fichier d'entree");
        }
    return urlhttp;
  }

 //Fonction de récupération du nom du fichier texte d'entrée
 char* recuperationficin(char*argv[],int argc){
 char *nomficin=NULL; 
 int i;
   i=1;
    while(i<argc&&strcmp(argv[i],"-f")!=0){
            i=i+1;
        }
    if(strcmp(argv[i],"-f")==0){nomficin=argv[i+1];}
    else{
    printf("Vous devez donner le nom de votre fichier d'entree");
 }
 return nomficin;
 }

  //Fonction de récupération du nom du fichier de sortie
  char* recuperationficout(char*argv[],int argc){
   int i; 
   char*nomficout=NULL;
   i=1;
   while(i<argc&&strcmp(argv[i],"-o")!=0){
            i=i+1;
        }
   if(strcmp(argv[i],"-o")==0){nomficout=argv[i+1];}
   else{
    printf("Vous devez donner le nom de votre fichier d'entree");
  }
  return nomficout;
  }


  int type_donnee_entree(char*argv[],int argc){
   if(recuperationficin(argv,argc)!=NULL){
    return 1;
   }
   else if(recuperationurl(argv,argc)!=NULL){
    return 0;
   }
   else{
    return -1;
   }
  }




/*

XJ_Convertor [-i json/json] [-t ][-h url_FluxHTTP] [-f FichierInput] -o nomFichier.svg
[-i json/json] : permet de dire si l’input est en json ou en json
[-t] permet de dire si on veut les traces (affichage sur écran de la liste des entités et des relations)
[-h url_FluxHTTP] : permet de désigner un input en flux http
[-f FichierInput] : permet de désigner un input de type fichier
-o nomFichier.svg : permet de designer le fichier de sortie

*/






























#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void contrasena(int *, int);
void ImprPant(int *, int);
void ImprFich(int *, int);

int main(){
    int *c,lon;
    char elec;
    // Mensaje de incio de programa
    printf("\n\t%cHola!\n\n\tEn este programa se genera contrase%cas con caracteres mediante pseualeatoriedad.\n",173,164);
    printf("\tLos caracteres utilizados son de la 'a' a la 'z', sin contar la %c, del 0 al 9 y \n",164);
    printf("\totros caracteres del tipo $,&,@...\n");
    printf("\tNo olvides apuntar la contrase%ca ya que muy f%ccil de recordar no es :)\n\n",164,160);
    // Tamaño de la contraseña
    printf("\t%cC%cmo de larga quieres la contrase%ca?\n",168,162,164);
    printf("\t--> ");
        scanf("%d",&lon);
    // Inicialización y creación de la contraseña
    c=(int*)malloc(lon*sizeof(int));
    contrasena(c,lon);
    // Muestra por pantalla contraseña
    printf("\tEsta es tu contrase%ca:\n",164);
    printf("\t--> ");
        ImprPant(c,lon);
    printf("\n\n\t%cQuieres almacenarla en una nota?",168);
    printf("\n\ta) S%c\tb) No",161);
    printf("\n\t--> ");
        fflush(stdin);
        scanf("%c",&elec);
    if(elec=='a'){
        ImprFich(c,lon);
    }
    system("pause");
    return 0;
}

void contrasena(int *c,int lon){
    srand(time(NULL));
    int i,num,nu_ale;
    for(i=0;i<lon;i++){
        nu_ale=rand()%(4); //Elige un número aleatorio entre 0 y 4
        switch(nu_ale){
            case 0: //Letras {a,...,z}/{ñ}
                c[i]=97+rand()%(26);
                break;
            case 1: //Letras {A,...,Z}/{Ñ}
                c[i]=65+rand()%(26);
                break;
            case 2: //Caracteres {#,$,%,&}
                c[i]=35+rand()%(4);
                break;
            case 3: //Numeros {0,1,...,9}
                c[i]=48+rand()%(10);
                break;
        }
    }
}

void ImprFich(int *c, int lon){
    FILE *fp;
    char *cad,e;
    int i=0;
    fp=fopen("contrasena.txt","a");
    if(fp==NULL){
        printf("\n\tHa habido un error al abrir el fichero");
    }
    else{
        fprintf(fp,"Aqui tienes:\n");
        for(i=0;i<lon;i++){
            fprintf(fp,"%c",c[i]);
        }
        fprintf(fp,"\n\n");
        fclose(fp);
    }
}

void ImprPant(int *c, int lon){
    int i;
    for(i=0;i<lon;i++){
        printf("%c",c[i]);
    }
}

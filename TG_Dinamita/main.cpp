#include <iostream>
#include <string>
#include<graphics.h>
#include <stdio.h>
#include <cmath>
#include <cstdlib>
#define pi 3.1416
#pragma GCC diagnostic ignored "-Wwrite-strings"

using namespace std;

int letra(char);
char indice(int);
void Incidencia(int[],int[],int,int,bool,int[][20],int [][20]);
void Adyacencia(int[],int[],int,int,bool,int[][20],int [][20]);
void Accesibilidad(int[][20],int,int,int[][20]);
void grados(int[][20],int, int,bool,int[],int[],int[],int[],int[]);
void clasificacion_nodos(int[],int[],int[],int[],int[],int,bool);
void bucles(int[],int[],int);
void Lineasparalelas(int[],int[],int,bool,int[],int);
void lineas_en_serie(int[],int[],int[],int[],int,int,bool);
bool GraficaSimple(int[],int[],int,int);
bool GraficaConectada(int[][20],int);
void GraficaRegular(int[],int[],int[],bool,int);
void GraficaCompleta(int[][20],bool,int,int);
bool GraficaBalanceada(int[],int[],int,bool);
void arbol(bool,bool,int,int);
void GraficaSimetrica(int[][20],int,int,bool);
void Euleriana(bool,int[],bool,int,bool);
void Unicursal(bool,int[],int[],int[],int,bool);



int matriz[20][20]={0},matriz2[20][20]={0},matriz3[20][20]={0},V_paralelas[20]={0},N_paralelas,N_p,Grados[20]={0};
int GradosInt[20]={0},GradosExt[20]={0};

 main(){
 	cout<<"#########################################################################################"<<endl;
	cout<<"\tPrograma de proyecto final. Teoria de graficas\n"<<endl;
	cout<<"\tEquipo: \tDinamita "<<endl;
	cout<<"\tMiembros:"<<endl;
	cout<<"\tRamirez Maximo Abraham Santiago:"<<endl;
	cout<<"\tGomez Vaca Jose Manuel"<<endl;
	cout<<"\tZetina Martinez Angelica"<<endl;
	cout<<"\tAvila Moreno Emilio"<<endl;
	cout<<"#########################################################################################"<<endl;
	putchar('\n');
	cout<<"\tPara usar las sentencias las opciones son "<<endl;
	cout<<"\tSI= S o s  y NO= N o n"<<endl;
	system("pause");
	system("cls");
int n,e;
char resp,opc;
bool tipo,simple,conectada,balanceada;

//recopilacion de dato de tabla 
do{
	cout<<"Dime cuantos vertices hay en la grafica: ";
	cin>>n;
	cout<<"Dime el numero de lineas que hay: ";
	cin>>e;
	cout<<"La grafica es dirigida [s/n] ? ";
	cin>>opc;
	cout<<"Estan bien los datos que ingresaste [s/n]?  ";
	cin>>resp;
}while(resp=='n' or resp=='N');

	int sale[e],llega[e];
	
	if(opc=='s' or opc=='S'){
		cout<<"La grafica es una dirigida"<<endl;
		tipo=true;
	}else{
		cout<<"la grafica es una no dirigida"<<endl;
		tipo=false;
	}
	char x;
for(int i=1;i<=e;i++){
	cout<<"De donde sale la linea "<<i<<" ? ";
	cin>>x;
	sale[i]=letra(x);
	cout<<"En donde llega la linea "<<i<<" ? ";
	cin>>x;
	llega[i]=letra(x);
	
}

cout<<"\nTabla de lineas y sus direcciones "<<endl;
	cout<<"Linea|\tsale|\tllega|"<<endl;
	for(int i=1;i<=e;i++){
	cout<<i<<"\t|"<<indice(sale[i])<<"|\t|";
	cout<<indice(llega[i])<<"|"<<endl;
}
	double X[n],Y[n],largo=800,alto=600,radioNodo=15,radio=100,radioflecha=5,bucle=4;

initwindow(1000,800);
	
	outtext("toca la pantalla y luego presiona espacio");
	outtextxy(10,10,"Lineas son color blanco");
	outtextxy(10,20,"vertices son de azul");
	outtextxy(10,30,"bucles son rojos");
	outtextxy(10,40,"las flechas para las graficas Dirigidas  ");
	outtextxy(10,50,"podemos verlas como la parte pintada de amarillo "); 
	
	for(int i=1;i<=n;i++){
		X[i]=(largo/2)+radio*cos((2*pi*i)/n);
		Y[i]=(alto/2)+radio*sin((2*pi*i)/n);
	}
	//dibujar lineas y bucles 
	for(int i=1;i<=e;i++){
	
	if(tipo==true){
		if(sale[i]==llega[i]){
			setcolor(4);
		
			arc(X[llega[i]],Y[llega[i]],150,10,(radioNodo+bucle));
			
		}
		line(X[sale[i]],Y[sale[i]],X[llega[i]],Y[llega[i]]);
	
	}else{
		if(sale[i]==llega[i]){
			setcolor(4);
		arc(X[llega[i]],Y[llega[i]],150,10,(radioNodo+bucle));	
		}
	line(X[sale[i]],Y[sale[i]],X[llega[i]],Y[llega[i]]);	
	}	
	}
	//dibujar circulos
	for(int i=1;i<=n;i++){
		setcolor(1);
		circle(X[i],Y[i],radioNodo);		
	}
	
	
//para poner la letras

setcolor(15);
	for(int i=1;i<=n;i++){
		
		switch(i){
			case 1:
			outtextxy(X[i],Y[i],"A");	
				break;
			case 2:
			outtextxy(X[i],Y[i],"B");	
				break;
			case 3:
			outtextxy(X[i],Y[i],"C");	
				break;
			case 4:
			outtextxy(X[i],Y[i],"D");	
				break;
			case 5:
			outtextxy(X[i],Y[i],"E");	
				break;
			case 6:
			outtextxy(X[i],Y[i],"F");	
				break;
			case 7:
			outtextxy(X[i],Y[i],"G");	
				break;
			case 8:
			outtextxy(X[i],Y[i],"H");	
				break;
			case 9:
			outtextxy(X[i],Y[i],"I");	
				break;
			case 10:
			outtextxy(X[i],Y[i],"J");	
				break;
			case 11:
			outtextxy(X[i],Y[i],"K");	
				break;
			case 12:
			outtextxy(X[i],Y[i],"L");	
				break;
			case 13:
			outtextxy(X[i],Y[i],"M");	
				break;
			case 14:
			outtextxy(X[i],Y[i],"N");	
				break;
			case 15:
			outtextxy(X[i],Y[i],"O");	
				break;
			
		}
		
	}
	int auxX,auxY;
	for(int i=1;i<=e;i++){
	if(tipo==true){
		
		auxX=((X[sale[i]]+X[llega[i]])/2);
		auxY=((Y[sale[i]]+Y[llega[i]])/2);
		setcolor(14);
		line(auxX,auxY,X[llega[i]],Y[llega[i]]);
		
	
			
	}}
	

	
	getch();
	closegraph();
	
	system("pause");
	Incidencia(llega,sale,e,n,tipo,matriz,matriz2);
	
	Adyacencia(llega,sale,e,n,tipo,matriz,matriz2);
	
	Accesibilidad(matriz2,n,e,matriz3);
	
	system("pause");
	grados(matriz,e,n,tipo,llega,sale,Grados,GradosInt,GradosExt);

	bucles(llega,sale,e);
	
	Lineasparalelas(llega,sale,e,tipo,V_paralelas,N_paralelas);
	
	
	simple=GraficaSimple(sale,llega,N_paralelas,e);
	
	
	GraficaCompleta(matriz2,simple,n,N_paralelas);

	
	conectada=GraficaConectada(matriz3,n);

	
	GraficaRegular(Grados,GradosInt,GradosExt,tipo,n);
system("pause");
	
	if(tipo==false){
	arbol(simple,conectada,e,n);

	lineas_en_serie(Grados,sale,llega,V_paralelas,n,e,tipo);

	}else{
	balanceada=GraficaBalanceada(GradosInt,GradosExt,n,tipo);
	
		
	GraficaSimetrica(matriz2,n,N_p,tipo);
	
	
	}
	Euleriana(conectada,Grados,balanceada,n,tipo);
	
	Unicursal(conectada,Grados,GradosInt,GradosExt,n,tipo);
	system("pause");

}

void Euleriana(bool conectada,int Grados[],bool balanceada,int n,bool tipo){
	bool gradopar=true;
	int i=1;
	cout<<endl;
	if(tipo==true){
		if(conectada==true and balanceada==true){
		cout<<"La digrafica es conectada y balanceada por lo tanto es Euleriana"<<endl;
		}else{
		cout<<"La digrafica no es Euleriana por que no es conectada o no es balanceada"<<endl;
		}
	}else{
		if(conectada==true){
			while(gradopar==true and i<=n){
				if(Grados[i]%2==0){
					gradopar=true;
				}else{
					gradopar=false;
				}
				i+=1;
			}
			if(gradopar==true){
		cout<<"la grafica es conectada y los grados son par, por lo tanto es Euleriana"<<endl;
			}else{
				cout<<"la grafica no es Euleriana"<<endl;
			}
		}else{
			cout<<"la grafica no es conectada por lo tanto no puede ser Euleriana"<<endl;
		}
	}
	cout<<endl;
}

void Unicursal(bool conectada,int Grados[],int GradosInt[],int GradosExt[],int n,bool DI){
int conte=0,i; bool gradopar=true;
	if(DI==true){
		while(gradopar==true and i<=n){
				if(GradosInt[i]==GradosExt[i]){
					gradopar=true;
				}else{
					if(GradosInt[i]!=GradosExt[i] and conte<3){
					gradopar=true;
					conte+=1;
					}else{
					gradopar=false;
					}
					
				}
				i+=1;
			}
			if(gradopar==false ){
				cout<<"la digrafica  y los grados interno y externo son iguales, excepto 2 de ellos, por lo tanto es Unicursal"<<endl;
			}else{
				cout<<"La digrafica no puede ser Unicursal "<<endl;
			}
	}else{
		if(conectada==true){
			while(gradopar==true and i<=n){
				if((Grados[i]%2)==0){
					gradopar=true;
				}else{
					if((Grados[i]%2)!=0 and conte<3){
					gradopar=true;	
					}else{
					gradopar=false;
					}
					
				}
				i+=1;
			}
			if(gradopar==false){
				cout<<"la grafica es conectada y los grados son par, excepto 2 de ellos, por lo tanto es Unicursal"<<endl;
			}else{
				cout<<"La grafica no puede ser Unicursal ya que tiene grado par todos "<<endl;
			}
		}else{
			cout<<"La grafica no puede ser Unicursal ya que no es conectada"<<endl;
		}
	}
	cout<<endl;
}
char indice(int y){
int z;

z=64+y;
return z;	
}


int letra(char x){
	int ascii;
	ascii=x;
	if(ascii>=65&&ascii<=90){
		//este if es para las letras Mayusculas
		return (ascii-64);
	}else{
		//este if tiene un rango de 97 a 122, y se usa para letras minusculas.
		if(ascii>=97&&ascii<=122){
			return (ascii-96);
		}
}
}
//checar esta parte con la profe

void GraficaSimetrica(int matriz2[][20],int n,int N_p,bool tipo){
		bool simetrica=true;int i,j;
		
		if(N_p>=0 and tipo==true){
			simetrica=true;
			i=1;
			do{
				j=1;
				do{
					
					if(matriz2[i][j]==matriz2[j][i]){
						simetrica=true;
					}else{
						simetrica=false;
					}
					j+=1;
				}while(simetrica==true and j<=n);
				i+=1;
			}while(simetrica==true and i<=n);
			cout<<endl;
			if(simetrica==true){
			cout<<"La grafica es simetrica"<<endl;	
			}else{
				cout<<"La grafica es asimetrica"<<endl;
			}
	}
}

void arbol(bool simple,bool conectada,int e,int n){
	cout<<endl;
	if(conectada==true and simple==true and e==(n-1)){
		cout<<"La grafica es un arbol"<<endl;
	}else{
		cout<<"La grafica no es un arbol"<<endl;
	}
}

bool GraficaBalanceada(int GradosInt[],int GradosExt[],int n,bool tipo){
	bool balanceada1;int i;
	if(tipo==true){
	balanceada1=true;
		i=1;
		do{
			if(GradosInt[i]==GradosExt[i]){
				balanceada1=true;
			}else{
				balanceada1=false;
			}
			i+=1;
		}while(balanceada1==true and i<=n);
		cout<<endl;
		if(balanceada1==true){
			cout<<"La grafica dirigida es balanceada "<<endl;
		}else{
			cout<<"la grafica dirigida no es balanceada"<<endl;
		}
	}
	return balanceada1;
}

void GraficaCompleta(int matriz2[][20],bool simple,int n,int N_paralelas){
	bool complet=true,bucles=false;int i,j;
	
	if(simple==true){
	i=1;
	do{
		j=1;
		do{
			if(i==j){
				if(matriz2[i][j]==0){
					complet=true;
				}else{
					complet=false;	
				}
			}else{
				if(matriz2[i][j]==1){
					complet=true;	
				}else{
					complet=false;
				}
			}
			j+=1;
		}while(j<=n and complet==true );
		i+=1;
	}while(i<=n and complet==true );
	}else{
	i=1;
	do{
		j=1;
		do{
			if(i==j){
				if(matriz2[i][j]==1){
					bucles=true;
				}else{
					bucles=false;	
				}
			}else{
				if(matriz2[i][j]==1){
					complet=true;
				}else{
					complet=false;
				}
			}
			j+=1;
		}while(j<=n and bucles==true and complet==true);
		i+=1;
	}while(i<=n and bucles==true and complet==true);
		
	}
cout<<endl;
	if(simple==true and complet==true){
		cout<<"La grafica es completa"<<endl;
	}else{
		if(complet==true and bucles==true and N_paralelas==0){
			cout<<"La grafica es completa con bucles"<<endl;
		}else{
		cout<<"la grafica no es completa"<<endl;
		}
	}
}

void GraficaRegular(int Grados[],int GradosInt[],int GradosExt[],bool tipo,int n){
	bool regular=true;int AuxGrado,auxgrado2;
	
	int i=2;
	if(tipo==false){
		AuxGrado=Grados[1];
		do{
			if(Grados[i]==AuxGrado){
				regular=true;
			}else{
				regular=false;
			}
			i+=1;
		}while(regular==true and i<=n);
	}else{
		AuxGrado=GradosInt[1];
		auxgrado2=GradosExt[1];
		do{
			if(GradosInt[i]==AuxGrado and GradosExt[i]==auxgrado2){
				regular=true;
			}else{
				regular=false;
			}
			i+=1;
		}while(regular==true and i<=n);
	}
	cout<<endl;
	if(regular==true){
		cout<<"La grafica es regular"<<endl;
	}else{
		cout<<"La grafica no es regular"<<endl;
	}
}

bool GraficaConectada(int matriz3[][20],int n){
	bool conect=true;int i=1,j=1;
	i=1;
	do{
		j=1;
		do{
			if(matriz3[i][j]==0){
				conect=false;
			}else{
				conect=true;
			}
			j+=1;
		}while(j<=n and conect==true);
		i+=1;
	}while(i<=n and conect==true);
	
	cout<<endl;
	if(conect==true){
		cout<<"La grafica es conectada "<<endl;
		conect=true;
	}else{
		cout<<"La grafica es desconectada"<<endl;
		conect=false;
	}
	return conect;
}

bool GraficaSimple(int sale[],int llega[],int N_paralelas,int e){
	bool simple=true;int i=1;
	if(N_paralelas>=1){
		simple=false;
	}else{
		do{
			if(sale[i]==llega[i]){
				simple=false;
			}else{
				simple=true;
			}
			i+=1;
		}while(simple==true and i<=e);
	}
	cout<<endl;
	if(simple==true){
		cout<<"La grafica es simple "<<endl;
		simple=true;
	}else{
		cout<<"La grafica es general"<<endl;
		simple=false;
	}
	return simple;
}

void lineas_en_serie(int Grados[],int sale[],int llega[],int V_paralelas[],int n,int e,bool tipo){
	int linea1=0,linea2=0;bool encontrel1=false,encontrel2=false;
cout<<endl;
	if(tipo==true){
		cout<<"Las graficas dirigidas no tienen lineas en serie "<<endl;
	}else{
		for(int i=1;i<=n;i++){
			if(Grados[i]==2){
				linea1=0;encontrel1=false;
				while(encontrel1==false){
					for(int j=1;j<=e;j++){
						if(llega[j]==i){
							linea1=j;
							encontrel1=true;
						}
					}
				}
				linea2=0;encontrel2=false;
				while(encontrel2==false){
					for(int k=1;k<=e;k++){
						if(sale[k]==i){
							linea2=k;
							encontrel2=true;
						}
					}
				}
				
				if(V_paralelas[linea1]==0 and V_paralelas[linea2]==0 and sale[linea1]!= llega[linea1]and sale[linea2]!= llega[linea2]){
					
					cout<<"las lineas "<<linea1<<" y la linea "<<linea2<<" estan en serie"<<endl;
				}
			}
		
				
			}
			
		}
		
	}


void Lineasparalelas(int llega[],int sale[],int lineas,bool DI,int V_paralelas[],int N_paralelas){
	int paralelas[lineas],grupoParalelas=1;bool encontreParalelas=false;int cont=0;
	for(int i=1;i<=lineas;i++){paralelas[i]=0;V_paralelas[i]=0;}
	cout<<endl;
	for(int i=1;i<=(lineas-1);i++){
		if(paralelas[i]==0){
			for(int j=1;j<=lineas;j++){
					if(sale[i]==sale[j] and llega[i]==llega[j]){
						if(i==j){
						}else{
						cout<<"las lineas "<<i<<", "<<j<<"son parlelas"<<endl;
						paralelas[i]=grupoParalelas;
						paralelas[j]=grupoParalelas;
						cont+=1;
						encontreParalelas=true;
					}
					}else{
						if(DI==false){
							if(sale[i]==llega[j] and llega[i]==sale[j]){
								cout<<"las lineas "<<i<<", "<<j<<"son parlelas"<<endl;
								
								paralelas[i]=grupoParalelas;
								paralelas[j]=grupoParalelas;
								cont+=1;
								encontreParalelas=true;
							}
						}else{
							if(sale[i]==sale[j] and llega[i]==llega[j]){
								cout<<"las lineas "<<i<<", "<<j<<"son parlelas"<<endl;
								
								paralelas[i]=grupoParalelas;
								paralelas[j]=grupoParalelas;
								cont+=1;
								encontreParalelas=true;
						}
						
					}
				
			}}
		
	}
	if(encontreParalelas==false and i==(lineas-1)){
		cout<<"no hay lineas paralelas"<<endl;
	}
	grupoParalelas=cont;
	N_paralelas=grupoParalelas;
	N_p=grupoParalelas;
}
}

void bucles(int llega[],int sale[],int e){
	cout<<endl;
	bool bucle=false;
	for(int i=1;i<=e;i++){
		if(sale[i]==llega[i]){
			cout<<"la linea "<<i<<" es un bucle en el nodo "<<indice(sale[i])<<endl;
			bucle=true;
		}
	}
	if(bucle==false){
		cout<<"no hay bucles en la grafica"<<endl;
	}
}

void grados(int matriz[20][20],int e,int n,bool tipo,int llega[],int sale[],int Grados[],int GradosInt[],int GradosExt[]){
	int grado[n],Grado_int[n],grado_ext[n];
	for(int i=1;i<=n;i++){
		grado[i]=0;Grado_int[i]=0;grado_ext[i]=0;
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=e;j++){
			if(tipo==true){
				if(matriz[i][j]==2){
					grado_ext[i]=grado_ext[i]+1;
					GradosExt[i]=grado_ext[i];
					Grado_int[i]=Grado_int[i]+1;
					GradosInt[i]=Grado_int[i];
				}
				if(matriz[i][j]==1){
					grado_ext[i]=grado_ext[i]+1;
					GradosExt[i]=grado_ext[i];
				}else{
					if(matriz[i][j]==-1){
						Grado_int[i]=Grado_int[i]+1;
						GradosInt[i]=Grado_int[i];
					}
				}
			}else{
				if(matriz[i][j]==1){
					grado[i]=grado[i]+1;
					
					}
				}
			}
		}
		cout<<endl;
		cout<<"| Grado de los nodos |"<<endl;
		for(int i=1;i<=n;i++){
			if(tipo==true){
				if(i==1){
				cout<<"|nodo|Grado Interno|Grado Externo|"<<endl;	
				cout<<"|"<<indice(i)<<"   |\t  "<<Grado_int[i]<<"  \t|\t"<<grado_ext[i]<<"\t|"<<endl;
				}else{
				cout<<"|"<<indice(i)<<"   |\t  "<<Grado_int[i]<<"  \t|\t"<<grado_ext[i]<<"\t|"<<endl;
				}
				
				/*cout<<"el grado interno del nodo "<<indice(i)<<" es "<<Grado_int[i]<<endl;
				cout<<"el grado externo del nodo "<<indice(i)<<" es "<<grado_ext[i]<<endl;*/
			}else{
				if(i==1){
				cout<<"|nodo|Grado|"<<endl;	
				cout<<"|"<<indice(i)<<"   |  "<<grado[i]<<"  |"<<endl;
				}else{
				cout<<"|"<<indice(i)<<"   |  "<<grado[i]<<"  |"<<endl;
				}
				Grados[i]=grado[i];
				
				}
			}
			clasificacion_nodos(grado,Grado_int,grado_ext,sale,llega,n,tipo);
		}
		
void clasificacion_nodos(int grado[],int Grado_int[],int grado_ext[],int sale[],int llega[],int n,bool tipo){
cout<<endl;
cout<<"|Clasificacion de nodos|"<<endl;
cout<<"________________________"<<endl;
cout<<"|nodo|  clasificacion  |"<<endl;
if(tipo==true){
	for(int i=1;i<=n;i++){
	if(Grado_int[i]==0 and grado_ext[i]==0){
		cout<<"|"<<indice(i)<<"   |"<<"  es aislado     |"<<endl;
		
	}else{
		if(Grado_int[i]==0 and grado_ext[i]!=0){
		cout<<"|"<<indice(i)<<"   |"<<"   es inicial    |"<<endl;
			
		}else{
		cout<<"|"<<indice(i)<<"   |"<<"   es final      |"<<endl;
			
		}
	}
	}
}else{
	for(int i=1;i<=n;i++){
	if(grado[i]==0){
		cout<<"|"<<indice(i)<<"   |"<<"   es aislado    |"<<endl;
		
	}else{
		if(grado[i]==1 and sale[i]!=llega[i]){
			cout<<"|"<<indice(i)<<"   |"<<"es colgante  |"<<endl;
			
		}	
	}
	}
}	
					
}

void Incidencia(int llega[],int sale[],int e,int n,bool tipo,int matriz[20][20],int matriz2[20][20]){
	int y=0;
	int **AG=(int**)malloc(n * sizeof(int*));
	for(int i=1;i<=n; i++){
	AG[i]=(int*)malloc(e*sizeof(int));	
	}
	
	for(int i=1;i<=n;i++){
	for(int j=1;j<=e;j++){
	AG[i][j]=0;
	}}
	
	for(int i=1;i<=e;i++){
		AG[sale[i]][i]=1;
		if(tipo==true){
			if(sale[i]==llega[i]){
				AG[llega[i]][i]=2;
			}else{
			AG[llega[i]][i]=-1;	
			}	
		}else{
			AG[llega[i]][i]=1;
		}	
	}
	cout<<endl;
	cout<<"Si sale un simbolo de ? significa que es un +- (masmenos)"<<endl;
	cout<<"| Matriz de Incidencia |"<<endl;
	cout<<"___________________________"<<endl;
	cout<<"   |";
	for(int j=1;j<=e;j++){cout<<j<<"  |";}cout<<endl;
	
	for(int i=1;i<=n;i++){
		cout<<indice(i)<<"  |";
		
	for(int j=1;j<=e;j++){
		if(AG[i][j]==2){
			printf("%c",241);cout<<"1";
		//cout<<indice(177)<<"1";
		cout<<"  ";	
		
		matriz[i][j]=AG[i][j];
		}else{
			if(AG[i][j]==1 or AG[i][j]==0){
			matriz[i][j]=AG[i][j];
			cout<<AG[i][j]<<"  |";	
			}else{
			matriz[i][j]=AG[i][j];
		cout<<AG[i][j]<<" |";	
			}
		}
	}cout<<endl;}
	cout<<endl;
	free(AG);
}

void Adyacencia(int llega[],int sale[],int e,int n,bool tipo,int matriz[20][20],int matriz2[20][20]){

int **XG=(int**)malloc(n*sizeof(int*));
for(int i=1;i<=n;i++){
XG[i]=(int*)malloc(n*sizeof(int));	
}

for(int i=1;i<=n;i++){for(int j=1;j<=n;j++){XG[i][j]=0;}}

for(int i=1;i<=e;i++){
	XG[sale[i]][llega[i]]=1;
	if(tipo==false){
		XG[llega[i]][sale[i]]=1;
	}

}
cout<<endl;
cout<<"| Matriz de Adyacencia |"<<endl;
cout<<"___________________________"<<endl;
cout<<"   |";
for(int i=1;i<=n;i++){cout<<indice(i)<<"  |";}
cout<<endl;
for(int i=1;i<=n;i++){
	cout<<indice(i)<<"  |";
for(int j=1;j<=n;j++){
	matriz2[i][j]=XG[i][j];
cout<<XG[i][j]<<"  |";}cout<<endl;}
free(XG);

}

void Accesibilidad(int XG[][20],int N,int e,int matriz3[][20]){
	
	int **MG=(int**)malloc(N * sizeof(int*));
for(int i=1;i<=N; i++){
MG[i]=(int*)malloc(N*sizeof(int));	
}
	
	int **poten=(int**)malloc(N * sizeof(int*));
for(int i=1;i<=N; i++){
poten[i]=(int*)malloc(N*sizeof(int));	
}
	
	
	for(int i=1;i<=N;i++){for(int j=1;j<=N;j++){MG[i][j]=0;poten[i][j]=0;}}

	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
		poten[i][j]=XG[i][j];
		MG[i][j]=poten[i][j];
		}	}
	
	//checar esta parte para hacer la multiplicacion de matrices
	int suma,producto[N][N];
	
	for(int i=1;i<=N;i++){for(int j=1;j<=N;j++){producto[i][j]=0;}}
	
		
	for(int w=1;w<=(N-1);w++){
	//1
		for(int i=1;i<=N;i++){//2 a
			for(int j=1;j<=N;j++){//3 i
				suma=0;
				for(int k=1;k<=N;k++){//4 j
				suma+=(poten[j][k]*MG[k][i]);	
				}
			producto[j][i]=suma;
		}
	}
		for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
		MG[i][j]=MG[i][j]+producto[i][j];	
		}}

}
cout<<endl;
	cout<<"| Matriz de Accesibilidad |"<<endl;
	cout<<"___________________________"<<endl;
	
	cout<<"   |";
	for(int i=1;i<=N;i++){cout<<indice(i)<<"  |";}cout<<endl;
	for(int i=1;i<=N;i++){
		cout<<indice(i)<<"  |";
		for(int j=1;j<=N;j++){
			matriz3[i][j]=MG[i][j];
			if(MG[i][j]==0){
				cout<<"0"<<"  |";
			}else{
				cout<<"+"<<"  |";
			}
		}
		cout<<endl;
	}
	cout<<endl;
	free(MG);
}

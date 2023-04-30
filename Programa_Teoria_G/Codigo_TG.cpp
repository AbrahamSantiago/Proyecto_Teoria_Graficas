#include <graphics.h>
#include <iostream>
using namespace std;

void dibuja_grafica_noDirigida(int v, int l){
	// Se crean los vértices
   circle(100, 100, 30);
   circle(300, 100, 30);
   circle(200, 250, 30);

   // Se crean las líneas
   line(85, 85, 285, 85);
   line(85, 85, 200, 220);
   line(285, 85, 200, 220);
   
   cout<<"numero de vertices:  "<<v<<"\n";
   cout<<"numero de lienas:  "<<l;
	
	
}


int main()
{
   int gd = DETECT, gm;
   initgraph(&gd, &gm, "");
   int vertices; int lineas;
   cout<<"Ingrese el numero de vertices ";
   cin>>vertices;
   cout<<"Ingrese el numero de lineas ";
   cin>>lineas;
   dibuja_grafica_noDirigida(vertices,lineas);

   getch();
   closegraph();
   return 0;
}

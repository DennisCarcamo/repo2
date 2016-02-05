#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
using std::setw;
using std::cout;
using std::cin;
using std::endl;

int adivinarnumero(int size, int magic);
const int rangonumero=10;
const int size=3;

int main(int argc ,char*argcv[]){
	int opcion=0,arreglo[size],defaultvalue=999;
	bool resp=true;
	//setiando valores default
	for(int i=0;i<=size;i++){
		arreglo[i]=defaultvalue;
	}
	for(int i=0;i<=size;i++){
		cout<<arreglo[i]<<endl;
	}

	
	
	srand (time(NULL));
	cout<<"Que ejercicio desea ejecutar "<<endl
	    <<"1 para adivinar numero"<<endl
	    <<"2 para la tabla de scores"<<endl;
	cin>>opcion;
	if(opcion==1){
		int oportunidades=0,aux2;
		char seguir;
		while(resp==true){
			
			for(int j=0;j<=size;j++){
				int magic=rand()%rangonumero-5;
				oportunidades=adivinarnumero(size,magic);
				cout<<"Oportunidad"<<oportunidades<<endl;
				if(oportunidades >arreglo[j]){
					aux2=arreglo[j];
					arreglo[j]=oportunidades;
					//corrinedo los scores
					for(int k=0;k<j;k--){
						arreglo[j]=arreglo[j-1];
					}
							
				}else{
					arreglo[j]=oportunidades;					
				}
					
			 }
			
			 //mostrando el arreglo

			 cout<<""<<endl;
			 cout<<"Score"<<endl;
			 for(int i=0;i<=size;i++){
				cout<<arreglo[i]<<endl;
			 }

			 cout<<"desea seguir jugando? [S/n]"<<endl;
			 cin>>seguir;
			 if(seguir=='s' || seguir=='S'){
				resp=true;
				cout<<""<<endl;
			 }else{
				resp=false;
		 	 }
		}
		

		//arreglando el arreglo
		int aux=0;
		for(int i=0;i<=size;i++){
			for(int j=i+1;j<=size;j++){
				if(arreglo[i]>=arreglo[j]){
					aux=arreglo[j];
					arreglo[j]=arreglo[i];
					arreglo[i]=aux;
				}
			}
		}
		
		//mostrando el arreglo

		cout<<""<<endl;
		cout<<"Score"<<endl;
		for(int i=0;i<=size;i++){
			cout<<arreglo[i]<<endl;
		}
		
				
	}else if(opcion==2){
	//programa 2
		int row=3,colum=2;
		int matris[row][colum];
		for(int i=0;i<=row;i++){
			for(int j=0;j<=colum;j++){
				if(j==0)
      				matris[i][j]=rand()% 116+85;	
				if(j==1)
					matris[i][j]=rand()% 51+75;
 				
				if(j==2)
					matris[i][j]=rand()% 201+150;
			 
					
			}
		}
	//imprimir matris
		for(int i=0;i<=colum;i++){
			for(int j=0;j<=row;j++){
				cout<<setw(5)<<matris[i][j];
			}
			cout<<""<<endl;	
		}
		char seg;
		bool bandera=true;
		while(bandera==true){
			int ganador=0;
			int jug1_ataq,jug1_def,jug1_velo,jug2_ataq,jug2_def,jug2_velo,jugador1,jugador2;

			jug1_ataq=matris[rand()%4][0];
			jug1_def=matris[rand()%4][1];
			jug1_velo=matris[rand()%4][2];
		

			jug2_ataq=matris[rand()%4][0];
			jug2_def=matris[rand()%4][1];
			jug2_velo=matris[rand()%4][2];
	
			jugador1=jug1_ataq-jug2_def;
			jugador2=jug2_ataq-jug1_def;
		
				//si es un empate
				if(jug1_ataq==jug2_ataq){
					if(jug1_velo>jug2_velo){
						ganador=1;
						cout<<"El ganador es el jugador 1 por velocidad, con una diferencia de "<<jugador1-jugador2<<endl;	
					}else if(jug2_velo>jug1_velo){
						ganador=2;
						cout<<"El ganador es el jugador 2 por velocidad, con una diferencia de "<<jugador2-jugador2<<endl;
					}else if(jug2_velo=jug1_velo){
						cout<<":)******* empate total ********(:"<<endl;				
					}
				}else if(jugador1>jugador2){
					cout<<"El ganador es el jugador 1, con una diferencia de "<<jugador1-jugador2<<endl;
				}else if(jugador2>jugador1){
					cout<<"El ganador es el jugador 1, con una diferencia de "<<jugador2-jugador1<<endl;
				}else{
					cout<<":)******* empate ********(:"<<endl;		
				}
				cout<<"desea seguir jugando? [S], cualquier cosa para salir"<<endl;
				cin>>ganador;
			if(seg=='s' || seg=='S')
				bandera=true;
				 
			else
				bandera=false;
		 	
			
		}
			
	
		
	}
	
	 
	
	
	return 0;
}

int adivinarnumero(int size, int magic){
	int suma=0,numero=600;
	
	while (numero!=magic){
		cout<<"Ingrese un numero "<<endl;
		cin>>numero;
			if(numero<magic){
				cout<<"Ingrese un numero mas alto"<<endl;
			}else if (numero>magic){
				cout<<"Ingrese un numero mas peque?o"<<endl;
			}else if (numero==magic){
				cout<<"*****Adivino*******"<<endl;
				break;
			}
		 suma++;
	 }
	
	 return suma;
	
}

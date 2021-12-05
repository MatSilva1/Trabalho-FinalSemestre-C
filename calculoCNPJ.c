#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<locale.h>
#include<stdlib.h>
bool ehdigito(char c){
	return (c >='0' && c <= '9');
}
int convertenumerico(char c){
	return c - '0';	
}
void converteentrada(char entrada[], int cnpj[]){
	int i = strlen(entrada)-1,j = 13;
	while (i >=0){
		if(ehdigito(entrada[i])){
			cnpj[j] = convertenumerico(entrada[i]);
			j--; 
		}
		i--;		
	}
	while (j>=0){
		cnpj[j]=0;
		j--;
	}
}
int calculadigito(int cnpj[],int m[],int n){
		int i,soma = 0,digito;
		for(i=0;i<n;i++){
			soma = soma +cnpj[i]*m[i];
		}
		if((soma%11)<2)	digito = 0;
		else digito = 11 - (soma%11);
		return digito;
	}
int main (){
	int cnpj[14];
	int m1[12]={5,4,3,2,9,8,7,6,5,4,3,2};
	int m2[13]={6,5,4,3,2,9,8,7,6,5,4,3,2};
	int i,j;
	char entrada[20];
	setlocale(LC_ALL,"portuguese");
	printf("Entre com os 14 dígitos do CNPJ:\n");
	fgets (entrada, sizeof(entrada), stdin);
	converteentrada(entrada,cnpj);
	if (cnpj[12]==(calculadigito(cnpj,m1,12)) && cnpj[13]==(calculadigito(cnpj,m2,13))){
		printf("CNPJ valido\n");
	}
	else printf("CNPJ inválido\n");
	system("pause");
	return 0;
}
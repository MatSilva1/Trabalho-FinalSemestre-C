#include <stdio.h>
#include <stdlib.h>

void main() {
  int s, i, r, numero, multiplica;
  char digito13, digito14, cnpj[14];
  printf("Informe o valor do CNPJ:\n");
  fgets(cnpj, sizeof(cnpj), stdin);

// Calcula o 1º digito verificador do CNPJ
  s = 0; multiplica = 2;
  for (i=11; i>=0; i--) {
    numero = cnpj[i] - 48;	// Transforma o caracter 0 no inteiro 0
			                // (Sendo que 48 é a posição de 0 na tabela ASCII)
    s = s + (numero * multiplica);
    multiplica = multiplica + 1;
    if (multiplica == 10)
       multiplica = 2;
  }
  r = s % 11;
  if ((r == 0) || (r == 1))
     digito13 = '0';
  else
     digito13 = (11 - r) + 48;

// calcula o 2º digito verificador do CNPJ
  s = 0; multiplica = 2;
  for (i=12; i>=0; i--) {
    numero = cnpj[i] - 48;
    s = s + (numero * multiplica);
    multiplica = multiplica + 1;
    if (multiplica == 10)
       multiplica = 2;
  }
  r = s % 11;
  if ((r == 0) || (r == 1))
     digito14 = '0';
  else
     digito14 = (11 - r) + 48;

// Faz a comparaçãp dos dígitos calculados com os dígitos informados
  if ((digito13 == cnpj[12]) && (digito14 == cnpj[13]))
     printf("\nO CNPJ informado eh válido.");
  else
     printf("\nO CNPJ informado eh inválido.");
}
#include "acceso.h"
#include "utilidades.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * comrpueba que usuario introducido esté registrado
 * @param  v referencia al vector user
 * @return posición iésima del usuario / -1 si nº de intentos se ha superado
 */
static int check_user(vUsuarios *v) {
  int logincount = 0, i;
  char user[6];
  char pass[9];
  CLEAN;
  while (logincount < 3) {
    printf("Usuario: ");
    scanf("%5s", user);
    flush_in();

    printf("Contrase%ca: ",164);
    scanf("%8s", pass);
    flush_in();
    for (i = 0; i < v->tam; ++i) {
      if (strcmp(v->user[i].User, user) == 0 &&
          strcmp(v->user[i].Login, pass) == 0)
        return i;
    }
    CLEAN;
    logincount++;
    printf("Usuario y/o Contrase%ca Incorrectos\n",164);
    printf("Vuelta a intentarlo\n");
  }
  return -1;
}

int *acceder(vUsuarios *v) {
  static int check[2];
  check[0] = check_user(v);
  check[1] = -1;
  if (check[0] > -1) {
    if (v->user[check[0]].Perfil_usuario == 0)
      check[1] = 0;
    else
      check[1] = 1;
  } else {
    printf("El numero de intentos ha sido superado\n");
    exit(1);
  }
  return check;
}

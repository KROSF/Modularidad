#include <stdio.h>
#include "cargar.h"
#include "acceso.h"
#include "menu.h"
int main(){

  vUsuarios user;
  vIncidencias inci;
  vViajes viaje;
  vVehiculos vehi;
  init(&user,&inci,&viaje,&vehi);
    int *accs = acceder(&user);
    if(accs[1] > -1 )
    {
        if(accs[1] == 0) menuAdmin(&user,accs[0]);
        else menuUser(&user,accs[0]);
    }
    else printf("No se puede determinar el tipo de usuario\n");
  save(&user,&inci,&viaje,&vehi);
  return 0;
}

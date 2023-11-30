#include <pthread.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 256
#define NUM_TUNELES 4
#define cant 10

int canal1[2];
int canal2[2];
int canal3[2];
int canal4[2];

int m;
int n;

struct tunel {
  int cod;
  char nombre[100];
  char salida_tunel[100];
  int cont;
};

struct tunel tuneles[NUM_TUNELES] = {
    {0, "A", "B", 0}, {1, "B", "A", 0}, {2, "E", "D", 0},{3,"D","E",0}};

pthread_mutex_t mutex;
void handle_sigalrm(int sig) {
  printf(
      "Ambulancia con Prioridad, den Paso\n************\n");
  n = 0;
}

void *autos(void *arg) {
    int id = *((int *)arg);
    pthread_mutex_lock(&mutex);
    
    unsigned int seed = (unsigned int)pthread_self();
    srand(seed);
    m = rand() % 4;
    n = rand() % 3 + 1;
    sleep(1);

    if (n == 0) {
    printf("la ambulancia pasara por el tunel %s \n", tuneles[m].nombre);
    // Mensaje a enviar desde el Canal A
    char msj[200];
    sprintf(msj, "aviso de que la ambulancia pasara por el tunel %s",
            tuneles[m].nombre);
    printf("ambulancia envia aviso a monitor\n");
    // Escribir en el pipe de Canal A a Canal B
    write(canal1[1], msj, sizeof(msj));

    // Recibir
    char buffer[BUFFER_SIZE];
    read(canal2[0], buffer, sizeof(buffer));
    printf("ambulancia recibe el mensaje %s", buffer);
    printf("la ambulancia pasa \n");
    if (m == 0 || m == 1) {
      printf("pasa por el tunel C\n");
    }
    char msj2[200];
    sprintf(msj2, "ambulancia  sale por el tunel %s,el tunel %s esta libre",
            tuneles[m].salida_tunel, tuneles[m].nombre);
    printf("ambulancia envia aviso a monitor de que ya salio\n");
    // Escribir en el pipe de Canal A a Canal B
    write(canal3[1], msj2, sizeof(msj2));

    char buffer2[BUFFER_SIZE];
    read(canal4[0], buffer2, sizeof(buffer2));
    printf("ambulancia recibe respuesta : %s\n\n", buffer2);
    if (m == 0) {
      tuneles[0].cont++;
    }
    if (m == 1) {
      tuneles[1].cont++;
    }
    if (m == 2) {
      tuneles[2].cont++;
    }
    if (m == 3) {
      tuneles[3].cont++;
    }

  } else {
    printf("El auto %d quiere pasar por el tunel %s \n", id, tuneles[m].nombre);
    // Mensaje a enviar desde el Canal A
    char msj[200];
    sprintf(msj, "solicitud del auto %d para pasar el tunel %s", id,
            tuneles[m].nombre);
    printf("Auto envia solicitud a monitor\n");
    // Escribir en el pipe de Canal A a Canal B
    write(canal1[1], msj, sizeof(msj));

    // recivir
    char buffer[BUFFER_SIZE];
    read(canal2[0], buffer, sizeof(buffer));
    printf("Auto %d recibe el mensaje %s", id, buffer);
    printf("El auto cruza el tunel\n");
    if (m == 0 || m == 1) {
      printf("pasa por el tunel C\n");
    }
    char msj2[200];
    sprintf(msj2, "Auto sale por el tunel %s, el tunel %s esta libre",
            tuneles[m].salida_tunel, tuneles[m].nombre);
    printf("Auto %d envia aviso a monitor de que ya salio\n", id);
    // Escribir en el pipe de Canal A a Canal B
    write(canal3[1], msj2, sizeof(msj2));

    char buffer2[BUFFER_SIZE];
    read(canal4[0], buffer2, sizeof(buffer2));
    printf("Auto %d recibe respuesta : %s\n\n", id, buffer2);

    if (m == 0) {
      tuneles[0].cont++;
    }
    if (m == 1) {
      tuneles[1].cont++;
    }
    if (m == 2) {
      tuneles[2].cont++;
    }
    if (m == 3) {
      tuneles[3].cont++;
    }
  }

  pthread_mutex_unlock(&mutex);
  pthread_exit(NULL);
}

void *monitor(void *arg) {

  char buffer[BUFFER_SIZE];
  read(canal1[0], buffer, sizeof(buffer));
  printf("monitor: Mensaje recibido %s\n", buffer);

  // Respuesta
  char reply[50]; // Tamaño suficiente para contener la cadena resultante
  snprintf(reply, sizeof(reply), "puede pasar por el tunel %s\n",
           tuneles[m].nombre);
  printf("monitor envia respuesta al tunel %s\n", tuneles[m].nombre);
  // Escribir en el pipe de Canal B a Canal A
  write(canal2[1], reply, sizeof(reply));

  char buffer2[BUFFER_SIZE];
  read(canal3[0], buffer2, sizeof(buffer2));
  printf("monitor: Mensaje recibido: %s\n", buffer2);

  // Respuesta
  char reply2[] = "que tenga buen dia";
  printf("monitor envia respuesta \n");
  // Escribir en el pipe de Canal B a Canal A
  write(canal4[1], reply2, sizeof(reply2));

  pthread_exit(NULL);
}

int main() {
  pthread_mutex_init(&mutex, NULL);
  
  srand(time(NULL));
  int a=rand()%cant;
  alarm(a);  
  signal(SIGALRM, handle_sigalrm);
  
  if (pipe(canal1) == -1 || pipe(canal2) == -1 || pipe(canal3) == -1 ||
      pipe(canal4) == -1) {
    perror("Error al crear los pipes");
    exit(EXIT_FAILURE);
  }

  pthread_t Auto[cant], Monitor[cant];
  int IDS[cant];
  for (int i = 0; i < cant; ++i) {
    IDS[i] = i + 1;
    if (pthread_create(&Auto[i], NULL, autos, (void *)&IDS[i]) != 0 ||
        pthread_create(&Monitor[i], NULL, monitor, NULL) != 0) {
      perror("Error al crear los hilos");
      exit(EXIT_FAILURE);
    }
  }

  for (int i = 0; i < cant; ++i) {
    pthread_join(Auto[i], NULL);
    pthread_join(Monitor[i], NULL);
  }
  int contC;

  contC = tuneles[0].cont + tuneles[1].cont;
  printf("Pasaron %d vehiculos por el tunel %s\n",
         tuneles[0].cont + tuneles[1].cont, tuneles[0].nombre);
  printf("Pasaron %d vehiculos por el tunel %s\n",
     tuneles[0].cont + tuneles[1].cont, tuneles[1].nombre);
  printf("Pasaron %d vehiculos por el tunel C\n", contC);
  printf("Pasaron %d vehiculos por el tunel %s\n",
     tuneles[2].cont + tuneles[3].cont , tuneles[2].nombre );
  printf("Pasaron %d vehiculos por el tunel %s\n", tuneles[3].cont + tuneles[2].cont, tuneles[3].nombre);
  
  close(canal1[0]);
  close(canal1[1]);
  close(canal2[0]);
  close(canal2[1]);
  close(canal3[0]);
  close(canal3[1]);
  close(canal4[0]);
  close(canal4[1]);
  return 0;
}
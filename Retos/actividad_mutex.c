#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define N 3 
#define B 3 

int x = 0; //variable global

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER; 
//PTHREAD_MUTEX_INITIALIZER es una macro que inicializa un mutex estático, estableciendo sus atributos en los valores predeterminados. Esta macro sólo se debe utilizar para exclusiones mutuas estáticas, ya que no se realiza ninguna comprobación de errores
pthread_barrier_t b; 

void *hilo(void *arg) {
  int numero_hilo = (int)arg; 
  int operacion; 
  int valor; 
  
  srand(pthread_self());
  //pthread_self() es una función que devuelve el identificador del hilo que la invoca. Esta función se puede usar para distinguir los hilos entre sí o para obtener información sobre el hilo actual
  //la función rand () para obtener números aleatorios. La función pthread_self () devuelve el identificador del hilo actual, que es un valor único y opaco
  valor = rand() % 10 + 1;
  
  operacion = rand() % 2;
  //devuelve entre 0 y 1
  
  pthread_mutex_lock(&lock);
  
  printf("Hilo %d: Ingresando al recurso compartido\n", numero_hilo);
  if (operacion == 0) {
    x = x + valor;
    printf("Hilo %d: Sumando %d a x\n", numero_hilo, valor);
  }
  else {
    x = x - valor;
    printf("Hilo %d: Restando %d a x\n", numero_hilo, valor);
  }
  printf("Hilo %d: Saliendo del recurso compartido\n", numero_hilo);
  
  pthread_mutex_unlock(&lock);
  
  printf("Hilo %d: Esperando a la barrera\n", numero_hilo);
  pthread_barrier_wait(&b);
  printf("Hilo %d: Pasando la barrera\n", numero_hilo);
  pthread_exit(NULL);
}

int main() {
  pthread_t hilos[N]; 
  int i, retorno_funcion;
  
  pthread_barrier_init(&b, NULL, B);
  for (i = 0; i < N; i++) {
    retorno_funcion = pthread_create(&hilos[i], NULL, hilo, (void *)i);
    if (retorno_funcion != 0) {
      perror("Error al crear el hilo");
      exit(-1);
    }
  }
  for (i = 0; i < N; i++) {    
    retorno_funcion = pthread_join(hilos[i], NULL);
    if (retorno_funcion != 0) {
      perror("Error al esperar al hilo");
      exit(-1);
    }
  }
  pthread_barrier_destroy(&b);
  //destruye la barrera para liberar el recurso
  
  printf("Valor final de x = %d\n", x);
  return 0;
}

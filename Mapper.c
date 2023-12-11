#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>

struct data_struct
{
    unsigned short int          version;        //  Versión del dato n1.                            2
    unsigned short int          drxVersion;     //  Versión del DRX que generó el dato n1.          2
    const int                   RESERVED_1;     //  RESERVADO                                       4
    double                      initCW;         //  Inicio de la ventana de recepción, en segundos. 8
    float                       azimuth;        //  Apuntamiento acimut en grados.                  4
    float                       elevation;      //  Apuntamiento elevación en grados.               4
    unsigned short int          idVolumen;      //  Identificador de volumen.                       2
    unsigned short int          idBarrido;      //  Identificador de barrido.                       2
    unsigned short int          idCnjunto;      //  Identificador de conjunto.                      2
    unsigned short int          idGrupo;        //  Identificador de grupo.                         2
    unsigned short int          idPulso;        //  Identificador de pulso.                         2
    bool                        iniBarrido;     //  Bandera del primer pulso de barrido.            1
    bool                        finBarrido;     //  Bandera del último pulso de barrido.            1
    bool                        finGrupo;       //  Bandera del último pulso del grupo.             1
    bool                        inhibido;       //  Bandera de transmisión inhibida.                1
    unsigned short int          validSamples;   //  Cantidad de muestras complejas válidas.         2
    unsigned short int          nroAdquisicion; //  Contador de adquisiciones.                      2
    const unsigned short int    RESERVED_2;     //  RESERVADO                                       2
    unsigned int                nroSecuencia;   //  Número de secuencia.                            4
    unsigned long int           readTime_high;  //  Campo alto de la marca de tiempo.               8
    unsigned long int           readTime_low;   //  Campo bajo de la marca de tiempo.               8
    const unsigned long int     RESERVED_3[8];  //  RESERVADO                                       64
};

int main(){

    int data_fd = open("Rawdata/datos",O_RDONLY);

     if (data_fd == -1)
    {
        printf("Error al abrir el archivo.\n");
        exit(1);
    }

    struct stat binary_stats;

/*The fstat function is used to retrieve information about an open file descriptor. 
    It provides a way to obtain detailed information about a file,
    including its size, permissions, and other attributes.*/

    if (fstat(data_fd, &binary_stats) == -1){
        printf("Error al obtener stats");
        exit(EXIT_FAILURE);
    }

    printf("File Size: %ld bytes\n", binary_stats.st_size);//384
    printf("Size of struct: %ld\n", sizeof(struct data_struct)); //128
    printf("Cant de muestras: %ld\n ",(binary_stats.st_size)/(sizeof(struct data_struct)));
    
    return 0;

}
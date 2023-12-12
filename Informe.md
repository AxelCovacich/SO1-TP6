## Laboratorio N6
# mmap
### SOI - FCEFyN - UNC
## Desarrollo
Primero se creo una estructura en C capaz de almacenar las muestras del binario
```
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
```
Se abre el binario con `open()` ,se guarda el file descriptor perteneciente al bnario y con la ayuda de `fstat()` se lee el tamaño del binario para saber cuantas muestras contiene.
Acto seguido, se instancia un puntero a esta estructura, con `mmap()` se mapea en memoria el binario y usando aritmética de arrays se obtiene la información necesaria de cada muestra.




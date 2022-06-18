#ifndef fonctionS
  #define fonctionS
  
  typedef struct cases
{

    int bombe;     /// O si pas de bombe 1 si bombe
    int cote;     /// nombre de cote qui touche bombe
    char marquage; /// 0 si pas de marqueur 1 si marque
    int etatb;    /// 0 si encore active 1 si decouverte
    int etatcote; /// 0 si pas decouvert 1 si decouvert


} t_cases;

#endif

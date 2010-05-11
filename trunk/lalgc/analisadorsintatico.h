#ifndef ANALISADORSINTATICO_H
#define ANALISADORSINTATICO_H

#include "analisadorlexico.h"
#include "erro.h"
#include <algorithm>
#include <set>
using namespace std;


class AnalisadorSintatico
{
public:
    AnalisadorSintatico(AnalisadorLexico * aLex);
    ~AnalisadorSintatico();
    void asd();

private:
    void programa(set<string> setPai);
    void corpo(set<string> setPai);
    void dc(set<string> setPai);
    void dc_v(set<string> setPai);
    void tipo_var(set<string> setPai);
    void variaveis(set<string> setPai);
    void mais_var(set<string> setPai);
    void dc_p(set<string> setPai);
    void parametros(set<string> setPai);
    void lista_par(set<string> setPai);
    void mais_par(set<string> setPai);
    void corpo_p(set<string> setPai);
    void dc_loc(set<string> setPai);
    void lista_arg(set<string> setPai);
    void argumentos(set<string> setPai);
    void mais_ident(set<string> setPai);
    void pfalsa(set<string> setPai);
    void comandos(set<string> setPai);
    void cmd(set<string> setPai);
    void ident(set<string> setPai);
    void condicao(set<string> setPai);
    void relacao(set<string> setPai);
    void expressao(set<string> setPai);
    void op_un(set<string> setPai);
    void outros_termos(set<string> setPai);
    void op_ad(set<string> setPai);
    void termo(set<string> setPai);
    void mais_fatores(set<string> setPai);
    void op_mul(set<string> setPai);
    void fator(set<string> setPai);
    void erro(set<string> seguidor);
    void imprimirEstagio(string msg);
    void imprimirToken();
    void imprimirErro(string msg);

    void init_Seguidores();


    //set<string>::iterator itAux;
    set<string> segAuxiliar;
    //set<string> setPai;


    set<string> segPrograma;
    set<string> segCorpo;
    set<string> segDc;
    set<string> segDc_v;
    set<string> segTipo_var;
    set<string> segVariaveis;
    set<string> segMais_var;
    set<string> segDc_p;
    set<string> segParametros;
    set<string> segLista_par;
    set<string> segMais_par;
    set<string> segCorpo_p;
    set<string> segDc_loc;
    set<string> segLista_arg;
    set<string> segArgumentos;
    set<string> segMais_ident;
    set<string> segPfalsa;
    set<string> segComandos;
    set<string> segCmd;
    set<string> segIdent_c;
    set<string> segCondicao;
    set<string> segRelacao;
    set<string> segExpressao;
    set<string> segOp_un;
    set<string> segOutros_termos;
    set<string> segOp_ad;
    set<string> segTermo;
    set<string> segMais_fatores;
    set<string> segOp_mul;
    set<string> segFator;


    set<string> priPrograma;
    set<string> priCorpo;
    set<string> priDc;
    set<string> priDc_v;
    set<string> priTipo_var;
    set<string> priVariaveis;
    set<string> priMais_var;
    set<string> priDc_p;
    set<string> priParametros;
    set<string> priLista_par;
    set<string> priMais_par;
    set<string> priCorpo_p;
    set<string> priDc_loc;
    set<string> priLista_arg;
    set<string> priArgumentos;
    set<string> priMais_ident;
    set<string> priPfalsa;
    set<string> priComandos;
    set<string> priCmd;
    set<string> priIdent_c;
    set<string> priCondicao;
    set<string> priRelacao;
    set<string> priExpressao;
    set<string> priOp_un;
    set<string> priOutros_termos;
    set<string> priOp_ad;
    set<string> priTermo;
    set<string> priMais_fatores;
    set<string> priOp_mul;
    set<string> priFator;


    AnalisadorLexico * aLex;
    Simbolo simbolo;
    int contagemErros;

    /**
     * Variaveis logicas usadas para depurar o programa.
     */
    bool imprimirEstagios;
    bool imprimirSimbolos;
};

#endif // ANALISADORSINTATICO_H

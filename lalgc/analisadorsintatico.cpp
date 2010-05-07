#include "analisadorsintatico.h"

/**
 * Analisador Sintatico Descendente Preditivo Recursivo
 */
AnalisadorSintatico::AnalisadorSintatico(AnalisadorLexico * aLex)
{
    this->aLex = aLex;
}


AnalisadorSintatico::~AnalisadorSintatico()
{
}


void AnalisadorSintatico::asd()
{
    token = aLex->obterToken();
    programa();
}


void AnalisadorSintatico::programa()
{
    imprimirMensagem(token.simbolo);
    if (!strcmp("program", token.simbolo)) {
        token = aLex->obterToken();
    }
    else {
        imprimirErro("program esperado");
        erro();
    }
    imprimirMensagem(token.simbolo);
    if (!strcmp("IDENTIFICADOR", token.tipo)) {
        token = aLex->obterToken();
    }
    else {
        imprimirErro("identificador de programa esperado");
        erro();
    }
    imprimirMensagem(token.simbolo);
    if (!strcmp(";", token.simbolo)) {
        token = aLex->obterToken();
    }
    else {
        imprimirErro("ponto e virgula esperado");
        erro();
    }
    corpo();
    imprimirMensagem(token.simbolo);
    if (!strcmp(".", token.simbolo)) {
        token = aLex->obterToken();
    }
    else {
        imprimirErro("ponto esperado");
        erro();
    }
    imprimirMensagem(token.simbolo);
    if (strcmp("EOF", token.simbolo)) {
        imprimirErro("fim de arquivo esperado");
        erro();
    }
}


void AnalisadorSintatico::corpo()
{
    dc();
    imprimirMensagem(token.simbolo);
    if (!strcmp("begin", token.simbolo)) {
        token = aLex->obterToken();
    }
    else {
        imprimirErro("begin esperado");
        erro();
    }
    comandos();
    imprimirMensagem(token.simbolo);
    if (!strcmp("end", token.simbolo)) {
        token = aLex->obterToken();
    }
    else {
        imprimirErro("end esperado");
        erro();
    }
}


void AnalisadorSintatico::dc()
{
    dc_v();
    dc_p();
}


void AnalisadorSintatico::dc_v()
{
    /**
     * @todo o que fazer com o λ???
    */
    //var <variaveis> : <tipo_var> ; <dc_v> | λ;

    imprimirMensagem(token.simbolo);
    if (!strcmp("var", token.simbolo)) {
        token = aLex->obterToken();
    }
    else {
        /**
         * @todo if (ehSeguidor(token))
         */
        if (1) {
            return;
        }
        else {
            imprimirErro("var esperado");
            erro();
        }
        return;
    }
    variaveis();
    imprimirMensagem(token.simbolo);
    if (!strcmp(":", token.simbolo)) {
        token = aLex->obterToken();
    }
    else {
        imprimirErro("':' esperado");
        erro();
    }
    tipo_var();
    imprimirMensagem(token.simbolo);
    if (!strcmp(";", token.simbolo)) {
        token = aLex->obterToken();
    }
    else {
        imprimirErro("';' esperado");
        erro();
    }
    dc_v();
}


void AnalisadorSintatico::tipo_var()
{
    imprimirMensagem(token.simbolo);
    if (!strcmp("real", token.simbolo) || !strcmp("integer", token.simbolo)) {
        token = aLex->obterToken();
    }
    else {
        imprimirErro("tipo de variavel esperado");
        erro();
    }
}


void AnalisadorSintatico::variaveis()
{
    imprimirMensagem(token.simbolo);
    if (!strcmp("IDENTIFICADOR", token.tipo)) {
        token = aLex->obterToken();
    }
    else {
        imprimirErro("identificador esperado");
        erro();
    }
    mais_var();
}


void AnalisadorSintatico::mais_var()
{
    imprimirMensagem(token.simbolo);
    if (!strcmp(",", token.simbolo)) {
        token = aLex->obterToken();
    }
    else {
        if (1) {
            return;
        }
        else {
            imprimirErro("virgula esperado");
            erro();
        }
    }
    variaveis();
}


void AnalisadorSintatico::dc_p()
{
    imprimirMensagem(token.simbolo);
    if (!strcmp("procedure", token.simbolo)) {
        token = aLex->obterToken();
    }
    else {
        if (1) {
            return;
        }
        else {
            imprimirErro("procedure esperado");
            erro();
        }
    }
    imprimirMensagem(token.simbolo);
    if (!strcmp("IDENTIFICADOR", token.tipo)) {
        token = aLex->obterToken();
    }
    else {
        imprimirErro("identificador esperado");
        erro();
    }
    parametros();
    imprimirMensagem(token.simbolo);
    if (!strcmp(";", token.simbolo)) {
        token = aLex->obterToken();
    }
    else {
        imprimirErro("ponto e virgula esperado");
        erro();
    }
    corpo_p();
    dc_p();
}


void AnalisadorSintatico::parametros()
{
    imprimirMensagem(token.simbolo);
    if (!strcmp("(", token.simbolo)) {
        token = aLex->obterToken();
    }
    else {
        if (1) {
            return;
        }
        else {
            imprimirErro("( esperado");
            erro();
        }
    }
    lista_par();
    imprimirMensagem(token.simbolo);
    if (!strcmp(")", token.simbolo)) {
        token = aLex->obterToken();
    }
    else {
        imprimirErro(") esperado");
        erro();
    }
}


void AnalisadorSintatico::lista_par()
{
    variaveis();
    imprimirMensagem(token.simbolo);
    if (!strcmp(":", token.simbolo)) {
        token = aLex->obterToken();
    }
    else {
        imprimirErro("':' esperado");
        erro();
    }
    tipo_var();
    mais_par();
}


void AnalisadorSintatico::mais_par()
{
    //; <lista_par> | λ
    imprimirMensagem(token.simbolo);
    if (!strcmp(";", token.simbolo)) {
        token = aLex->obterToken();
    }
    else {
        if (1) {
            return;
        }
        else {
            imprimirErro("';' esperado");
            erro();
        }
    }
    lista_par();
}


void AnalisadorSintatico::corpo_p()
{
    dc_loc();
    imprimirMensagem(token.simbolo);
    if (!strcmp("begin", token.simbolo)) {
        token = aLex->obterToken();
    }
    else {
        imprimirErro("begin esperado");
        erro();
    }
    comandos();
    imprimirMensagem(token.simbolo);
    if (!strcmp("end", token.simbolo)) {
        token = aLex->obterToken();
    }
    else {
        imprimirErro("end esperado");
        erro();
    }
    imprimirMensagem(token.simbolo);
    if (!strcmp(";", token.simbolo)) {
        token = aLex->obterToken();
    }
    else {
        imprimirErro("';' esperado");
        erro();
    }
}


void AnalisadorSintatico::dc_loc()
{
    dc_v();
}


void AnalisadorSintatico::lista_arg()
{
    imprimirMensagem(token.simbolo);
    if (!strcmp("(", token.simbolo)) {
        token = aLex->obterToken();
    }
    else {
        if (1) {
            return;
        }
        else {
            imprimirErro("'(' esperado");
            erro();
        }
    }
    argumentos();
    imprimirMensagem(token.simbolo);
    if (!strcmp(")", token.simbolo)) {
        token = aLex->obterToken();
    }
    else {
        imprimirErro("')' esperado");
        erro();
    }
}


void AnalisadorSintatico::argumentos()
{
    imprimirMensagem(token.simbolo);
    if (!strcmp("IDENTIFICADOR", token.tipo)) {
        token = aLex->obterToken();
    }
    else {
        imprimirErro("identificador de programa esperado");
        erro();
    }
    mais_ident();
}


void AnalisadorSintatico::mais_ident()
{
    imprimirMensagem(token.simbolo);
    if (!strcmp(";", token.simbolo)) {
        token = aLex->obterToken();
    }
    else {
        if (1) {
            return;
        }
        else {
            imprimirErro("';' esperado");
            erro();
        }
    }
    argumentos();
}


void AnalisadorSintatico::pfalsa()
{
    imprimirMensagem(token.simbolo);
    if (!strcmp("else", token.simbolo)) {
        token = aLex->obterToken();
    }
    else {
        if (1) {
            return;
        }
        else {
            imprimirErro("else esperado");
            erro();
        }
    }
    cmd();
}


void AnalisadorSintatico::comandos()
{
    //token eh seguidor de comandos = {end}
    if (1) {
        return;
    }
    cmd();
    imprimirMensagem(token.simbolo);
    if (!strcmp(";", token.simbolo)) {
        token = aLex->obterToken();
    }
    else {
        imprimirErro("';' esperado");
        erro();
    }
    comandos();
}


void AnalisadorSintatico::cmd()
{
    imprimirMensagem(token.simbolo);
    if (!strcmp("read", token.tipo) || !strcmp("write", token.tipo)) {
        token = aLex->obterToken();
        imprimirMensagem(token.simbolo);
        if (!strcmp("(", token.simbolo)) {
            token = aLex->obterToken();
            variaveis();
            token = aLex->obterToken();
            imprimirMensagem(token.simbolo);
            if (!strcmp(")", token.simbolo)) {
            }
        }
    }
    if (!strcmp("while", token.simbolo)) {
        token = aLex->obterToken();
        condicao();
        imprimirMensagem(token.simbolo);
        if (!strcmp("do", token.simbolo)) {
            token = aLex->obterToken();
            imprimirMensagem(token.simbolo);
            cmd();
        }
    }
    if (!strcmp("repeat", token.simbolo)) {
        token = aLex->obterToken();
        imprimirMensagem(token.simbolo);
        cmd();
        if (!strcmp("until", token.simbolo)) {
            token = aLex->obterToken();
            imprimirMensagem(token.simbolo);
            condicao();
        }
    }
    if (!strcmp("if", token.simbolo)) {
        token = aLex->obterToken();
        imprimirMensagem(token.simbolo);
        condicao();
        if (!strcmp("then", token.simbolo)) {
            token = aLex->obterToken();
            imprimirMensagem(token.simbolo);
            cmd();
            pfalsa();
        }
    }
    imprimirMensagem(token.simbolo);
    if (!strcmp("IDENTIFICADOR", token.tipo)) {
        token = aLex->obterToken();
        ident();
    }
    if (!strcmp("begin", token.simbolo)) {
        comandos();
        if (!strcmp("end", token.simbolo)) {
            token = aLex->obterToken();
        }
    }
}


void AnalisadorSintatico::ident()
{
    imprimirMensagem(token.simbolo);
    if (!strcmp(":=", token.simbolo)) {
        token = aLex->obterToken();
        expressao();
    }
    else {
        if (1) {
            lista_arg();
        }
        else {
            erro();
        }
    }
}


void AnalisadorSintatico::condicao()
{
    expressao();
    relacao();
    expressao();
}


void AnalisadorSintatico::relacao()
{
    imprimirMensagem(token.simbolo);
    if (!strcmp("=",  token.tipo) || !strcmp("<>", token.tipo) ||
        !strcmp(">=", token.tipo) || !strcmp("<=", token.tipo) ||
        !strcmp(">",  token.tipo) || !strcmp("<",  token.tipo))
    {
        token = aLex->obterToken();
    }
    else {
        imprimirErro("operador relacional esperado");
        erro();
    }
}


void AnalisadorSintatico::expressao()
{
    termo();
    outros_termos();

}


void AnalisadorSintatico::op_un()
{
    imprimirMensagem(token.simbolo);
    if (!strcmp("+", token.tipo) || !strcmp("-", token.tipo)) {
        token = aLex->obterToken();
    }
    else {
        if (1) {
            return;
        }
        else {
            imprimirErro("operador unario esperado");
            erro();
        }
    }
}


void AnalisadorSintatico::outros_termos()
{
    if (1) {
        return;
    }
    op_ad();
    termo();
    outros_termos();
}


void AnalisadorSintatico::op_ad()
{
    imprimirMensagem(token.simbolo);
    if (!strcmp("+", token.tipo) || !strcmp("-", token.tipo)) {
        token = aLex->obterToken();
    }
    else {
        imprimirErro("operador adicao esperado");
        erro();
    }
}


void AnalisadorSintatico::termo()
{
    op_un();
    fator();
    mais_fatores();
}


void AnalisadorSintatico::mais_fatores()
{
    if (1) {
        return;
    }
    op_mul();
    fator();
    mais_fatores();
}


void AnalisadorSintatico::op_mul()
{
    imprimirMensagem(token.simbolo);
    if (!strcmp("*", token.tipo) || !strcmp("/", token.tipo)) {
        token = aLex->obterToken();
    }
    else {
        imprimirErro("operador adicao esperado");
        erro();
    }
}


void AnalisadorSintatico::fator()
{
    imprimirMensagem(token.simbolo);
    if (!strcmp("IDENTIFICADOR", token.tipo) ||
        !strcmp("NUM_INTEIRO", token.tipo) ||
        !strcmp("NUM_REAL", token.tipo)) {
        token = aLex->obterToken();
    }
    else {
        if (!strcmp("(", token.tipo)) {
            token = aLex->obterToken();
            expressao();
            if (!strcmp(")", token.tipo)) {
                token = aLex->obterToken();
            }
            else {
                imprimirErro("')' esperado");
                erro();
            }
        }
        else {
            imprimirErro("identificador, numero real, numero inteiro ou '(' esperado");
            erro();
        }
    }
}


void AnalisadorSintatico::erro()
{
    while (0) {
        token = aLex->obterToken();
    }
}


void AnalisadorSintatico::imprimirMensagem(string msg)
{
    #ifndef saidaLexico
    cout << msg << endl;
    #endif
}


void AnalisadorSintatico::imprimirErro(string msg)
{
    cerr << "ERRO: " << msg << endl;
}

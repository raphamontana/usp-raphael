#include "analisadorsintatico.h"

/**
 * Analisador Sintatico Descendente Preditivo Recursivo
 */
AnalisadorSintatico::AnalisadorSintatico(AnalisadorLexico * aLex)
{
    this->aLex = aLex;
}


/**
 * Destrutor
 */
AnalisadorSintatico::~AnalisadorSintatico()
{
}


/**
 * Metodo inicializador da analise
 */
void AnalisadorSintatico::asd()
{
    imprimirMensagem("Inicio da analise sintatica.");
    token = aLex->obterToken();
    programa();
    imprimirMensagem("Fim da analise sintatica.");
}


void AnalisadorSintatico::programa()
{
    imprimirMensagem(" Inicio do programa.");
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
    //imprimirMensagem(token.simbolo);
    if (strcmp("EOF", token.tipo)) {
        imprimirErro("fim de arquivo esperado");
        erro();
    }
    imprimirMensagem(" Fim do programa.");
}


void AnalisadorSintatico::corpo()
{
    imprimirMensagem("  Inicio do corpo.");
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
    imprimirMensagem("  Fim do corpo.");
}


void AnalisadorSintatico::dc()
{
    imprimirMensagem("   Inicio do bloco de declaracoes");
    dc_v();
    dc_p();
    imprimirMensagem("   Fim do bloco de declaracoes");
}


void AnalisadorSintatico::dc_v()
{
    imprimirMensagem("    Inicio da declaracao de variaveis");
    if (!strcmp("var", token.simbolo)) {
        imprimirMensagem(token.simbolo);
        token = aLex->obterToken();
    }
    else {
        if (1) {
            imprimirMensagem("    Fim da declaracao de variaveis");
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
    imprimirMensagem("    Fim da declaracao de variaveis");
}


void AnalisadorSintatico::tipo_var()
{
    imprimirMensagem("     Inicio do tipo de variavel");
    imprimirMensagem(token.simbolo);
    if (!strcmp("real", token.simbolo) || !strcmp("integer", token.simbolo)) {
        token = aLex->obterToken();
    }
    else {
        imprimirErro("tipo de variavel esperado");
        erro();
    }
    imprimirMensagem("     Fim do tipo de variavel");
}


void AnalisadorSintatico::variaveis()
{
    imprimirMensagem("     Inicio de variaveis");
    imprimirMensagem(token.simbolo);
    if (!strcmp("IDENTIFICADOR", token.tipo)) {
        token = aLex->obterToken();
    }
    else {
        imprimirErro("identificador esperado");
        erro();
    }
    mais_var();
    imprimirMensagem("     Fim de variaveis");
}


void AnalisadorSintatico::mais_var()
{
    imprimirMensagem("      Inicio de mais variaveis");
    if (!strcmp(",", token.simbolo)) {
        imprimirMensagem(token.simbolo);
        token = aLex->obterToken();
    }
    else {
        if (1) {
            imprimirMensagem("      Fim de mais variaveis");
            return;
        }
        else {
            imprimirErro("virgula esperado");
            erro();
        }
    }
    variaveis();
    imprimirMensagem("      Fim de mais variaveis");
}


void AnalisadorSintatico::dc_p()
{
    imprimirMensagem("Inicio da declaracao de procedimentos");
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
    imprimirMensagem("Fim da declaracao de procedimetos");
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
    if (!strcmp("read", token.simbolo) || !strcmp("write", token.simbolo)) {
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
    if (!strcmp("=",  token.simbolo) || !strcmp("<>", token.simbolo) ||
        !strcmp(">=", token.simbolo) || !strcmp("<=", token.simbolo) ||
        !strcmp(">",  token.simbolo) || !strcmp("<",  token.simbolo))
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
    if (!strcmp("+", token.simbolo) || !strcmp("-", token.simbolo)) {
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
    if (!strcmp("+", token.simbolo) || !strcmp("-", token.simbolo)) {
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
    if (!strcmp("*", token.simbolo) || !strcmp("/", token.simbolo)) {
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
        if (!strcmp("(", token.simbolo)) {
            token = aLex->obterToken();
            expressao();
            if (!strcmp(")", token.simbolo)) {
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


/**
 * Gerenciador de erros no modo panico
 */
void AnalisadorSintatico::erro()
{
    while (0) {
        token = aLex->obterToken();
    }
}


/**
 * Emissor de mensagens
 */
void AnalisadorSintatico::imprimirMensagem(string msg)
{
    #ifdef saidaLexico
    cout << msg << endl;
    #endif
    fflush(stdout);
}


/**
 * Emissor de erros
 */
void AnalisadorSintatico::imprimirErro(string msg)
{
    cerr << "ERRO: " << msg << endl;
}

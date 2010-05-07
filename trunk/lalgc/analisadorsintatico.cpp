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
    imprimirEstagio("Inicio da analise sintatica.");
    token = aLex->obterToken();
    programa();
    imprimirEstagio("Fim da analise sintatica.");
}


void AnalisadorSintatico::programa()
{
    imprimirEstagio(" Inicio do programa.");
    imprimirToken(token.simbolo);
    if (!strcmp("program", token.simbolo)) {
        token = aLex->obterToken();
    }
    else {
        imprimirErro("program esperado");
        erro();
    }
    imprimirToken(token.simbolo);
    if (!strcmp("IDENTIFICADOR", token.tipo)) {
        token = aLex->obterToken();
    }
    else {
        imprimirErro("identificador de programa esperado");
        erro();
    }
    imprimirToken(token.simbolo);
    if (!strcmp(";", token.simbolo)) {
        token = aLex->obterToken();
    }
    else {
        imprimirErro("ponto e virgula esperado");
        erro();
    }
    corpo();
    imprimirToken(token.simbolo);
    if (!strcmp(".", token.simbolo)) {
        token = aLex->obterToken();
    }
    else {
        imprimirErro("ponto esperado");
        erro();
    }
    //imprimirToken(token.simbolo);
    if (strcmp("EOF", token.tipo)) {
        imprimirErro("fim de arquivo esperado");
        erro();
    }
    imprimirEstagio(" Fim do programa.");
}


void AnalisadorSintatico::corpo()
{
    imprimirEstagio("  Inicio do corpo.");
    dc();
    if (!strcmp("begin", token.simbolo)) {
        imprimirToken(token.simbolo);
        token = aLex->obterToken();
    }
    else {
        imprimirToken(token.simbolo);
        imprimirErro("begin esperado");
        erro();
    }
    comandos();
    imprimirToken(token.simbolo);
    if (!strcmp("end", token.simbolo)) {
        token = aLex->obterToken();
    }
    else {
        imprimirErro("end esperado");
        erro();
    }
    imprimirEstagio("  Fim do corpo.");
}


void AnalisadorSintatico::dc()
{
    imprimirEstagio("   Inicio do bloco de declaracoes");
    dc_v();
    dc_p();
    imprimirEstagio("   Fim do bloco de declaracoes");
}


void AnalisadorSintatico::dc_v()
{
    imprimirEstagio("    Inicio da declaracao de variaveis");
    if (!strcmp("var", token.simbolo)) {
        imprimirToken(token.simbolo);
        token = aLex->obterToken();
    }
    else {
        if (1) {
            imprimirEstagio("    Fim da declaracao de variaveis");
            return;
        }
        else {
            imprimirErro("var esperado");
            erro();
        }
        return;
    }
    variaveis();
    imprimirToken(token.simbolo);
    if (!strcmp(":", token.simbolo)) {
        token = aLex->obterToken();
    }
    else {
        imprimirErro("':' esperado");
        erro();
    }
    tipo_var();
    imprimirToken(token.simbolo);
    if (!strcmp(";", token.simbolo)) {
        token = aLex->obterToken();
    }
    else {
        imprimirErro("';' esperado");
        erro();
    }
    dc_v();
    imprimirEstagio("    Fim da declaracao de variaveis");
}


void AnalisadorSintatico::tipo_var()
{
    imprimirEstagio("     Inicio do tipo de variavel");
    imprimirToken(token.simbolo);
    if (!strcmp("real", token.simbolo) || !strcmp("integer", token.simbolo)) {
        token = aLex->obterToken();
    }
    else {
        imprimirErro("tipo de variavel esperado");
        erro();
    }
    imprimirEstagio("     Fim do tipo de variavel");
}


void AnalisadorSintatico::variaveis()
{
    imprimirEstagio("     Inicio de variaveis");
    imprimirToken(token.simbolo);
    if (!strcmp("IDENTIFICADOR", token.tipo)) {
        token = aLex->obterToken();
    }
    else {
        imprimirErro("identificador esperado");
        erro();
    }
    mais_var();
    imprimirEstagio("     Fim de variaveis");
}


void AnalisadorSintatico::mais_var()
{
    imprimirEstagio("      Inicio de mais variaveis");
    if (!strcmp(",", token.simbolo)) {
        imprimirToken(token.simbolo);
        token = aLex->obterToken();
    }
    else {
        if (1) {
            imprimirEstagio("      Fim de mais variaveis");
            return;
        }
        else {
            imprimirErro("virgula esperado");
            erro();
        }
    }
    variaveis();
    imprimirEstagio("      Fim de mais variaveis");
}


void AnalisadorSintatico::dc_p()
{
    imprimirEstagio("    Inicio da declaracao de procedimentos");
    if (!strcmp("procedure", token.simbolo)) {
        imprimirToken(token.simbolo);
        token = aLex->obterToken();
    }
    else {
        if (1) {
            imprimirEstagio("    Fim da declaracao de procedimetos");
            return;
        }
        else {
            imprimirErro("procedure esperado");
            erro();
        }
    }
    imprimirToken(token.simbolo);
    if (!strcmp("IDENTIFICADOR", token.tipo)) {
        token = aLex->obterToken();
    }
    else {
        imprimirErro("identificador esperado");
        erro();
    }
    parametros();
    imprimirToken(token.simbolo);
    if (!strcmp(";", token.simbolo)) {
        token = aLex->obterToken();
    }
    else {
        imprimirErro("ponto e virgula esperado");
        erro();
    }
    corpo_p();
    dc_p();
    imprimirEstagio("    Fim da declaracao de procedimetos");
}


void AnalisadorSintatico::parametros()
{
    imprimirEstagio("     Inicio da declaracao de parametros");
    imprimirToken(token.simbolo);
    if (!strcmp("(", token.simbolo)) {
        token = aLex->obterToken();
    }
    else {
        if (1) {
            imprimirEstagio("     Fim da declaracao de parametros");
            return;
        }
        else {
            imprimirErro("( esperado");
            erro();
        }
    }
    lista_par();
    imprimirToken(token.simbolo);
    if (!strcmp(")", token.simbolo)) {
        token = aLex->obterToken();
    }
    else {
        imprimirErro(") esperado");
        erro();
    }
    imprimirEstagio("     Fim da declaracao de parametros");
}


void AnalisadorSintatico::lista_par()
{
    imprimirEstagio("      Inicio da lista de parametros");
    variaveis();
    imprimirToken(token.simbolo);
    if (!strcmp(":", token.simbolo)) {
        token = aLex->obterToken();
    }
    else {
        imprimirErro("':' esperado");
        erro();
    }
    tipo_var();
    mais_par();
    imprimirEstagio("      Fim da lista de parametros");
}


void AnalisadorSintatico::mais_par()
{
    imprimirEstagio("       Inicio de mais parametros");
    imprimirToken(token.simbolo);
    if (!strcmp(";", token.simbolo)) {
        token = aLex->obterToken();
    }
    else {
        if (1) {
            imprimirEstagio("       Fim de mais parametros");
            return;
        }
        else {
            imprimirErro("';' esperado");
            erro();
        }
    }
    lista_par();
    imprimirEstagio("       Fim de mais parametros");
}


void AnalisadorSintatico::corpo_p()
{
    imprimirEstagio("       Inicio do corpo do procedimento");
    dc_loc();
    imprimirToken(token.simbolo);
    if (!strcmp("begin", token.simbolo)) {
        token = aLex->obterToken();
    }
    else {
        imprimirErro("begin esperado");
        erro();
    }
    comandos();
    imprimirToken(token.simbolo);
    if (!strcmp("end", token.simbolo)) {
        token = aLex->obterToken();
    }
    else {
        imprimirErro("end esperado");
        erro();
    }
    imprimirToken(token.simbolo);
    if (!strcmp(";", token.simbolo)) {
        token = aLex->obterToken();
    }
    else {
        imprimirErro("';' esperado");
        erro();
    }
    imprimirEstagio("       Fim do corpo do procedimento");
}


void AnalisadorSintatico::dc_loc()
{
    imprimirEstagio("       Inicio de declaracoes locais");
    dc_v();
    imprimirEstagio("       Fim de declaracoes locais");
}


void AnalisadorSintatico::lista_arg()
{
    imprimirEstagio("       Inicio da lista de argumentos");
    imprimirToken(token.simbolo);
    if (!strcmp("(", token.simbolo)) {
        token = aLex->obterToken();
    }
    else {
        if (1) {
            imprimirEstagio("       Fim da lista de argumentos");
            return;
        }
        else {
            imprimirErro("'(' esperado");
            erro();
        }
    }
    argumentos();
    imprimirToken(token.simbolo);
    if (!strcmp(")", token.simbolo)) {
        token = aLex->obterToken();
    }
    else {
        imprimirErro("')' esperado");
        erro();
    }
    imprimirEstagio("       Fim da lista de argumentos");
}


void AnalisadorSintatico::argumentos()
{
    imprimirEstagio("       Inicio dos argumentos");
    imprimirToken(token.simbolo);
    if (!strcmp("IDENTIFICADOR", token.tipo)) {
        token = aLex->obterToken();
    }
    else {
        imprimirErro("identificador de programa esperado");
        erro();
    }
    mais_ident();
    imprimirEstagio("       Fim dos argumentos");
}


void AnalisadorSintatico::mais_ident()
{
    imprimirEstagio("       Inicio de mais identificadores");
    imprimirToken(token.simbolo);
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
    imprimirEstagio("       Fim de mais identificadores");
}


void AnalisadorSintatico::pfalsa()
{
    imprimirEstagio("       Inicio de proposicao falsa");
    imprimirToken(token.simbolo);
    if (!strcmp("else", token.simbolo)) {
        token = aLex->obterToken();
    }
    else {
        if (1) {
            imprimirEstagio("       Fim de proposicao falsa");
            return;
        }
        else {
            imprimirErro("else esperado");
            erro();
        }
    }
    cmd();
    imprimirEstagio("       Fim de proposicao falsa");
}


void AnalisadorSintatico::comandos()
{
    set<string> primeiro;
    primeiro.insert("read");
    primeiro.insert("write");
    primeiro.insert("while");
    primeiro.insert("repeat");
    primeiro.insert("if");
    primeiro.insert("IDENTIFICADOR");
    primeiro.insert("begin");
    imprimirEstagio("   Inicio de comandos");
    if ((primeiro.find(token.simbolo) == primeiro.end()) && (primeiro.find(token.tipo) == primeiro.end())) {
        imprimirEstagio("   Fim de comandos");
        return;
    }
    cmd();
    imprimirToken(token.simbolo);
    if (!strcmp(";", token.simbolo)) {
        token = aLex->obterToken();
    }
    else {
        imprimirErro("';' esperado");
        erro();
    }
    imprimirEstagio("   Fim de comandos");
    comandos();
}


void AnalisadorSintatico::cmd()
{
    imprimirToken(token.simbolo);
    if (!strcmp("read", token.simbolo) || !strcmp("write", token.simbolo)) {
        token = aLex->obterToken();
        imprimirToken(token.simbolo);
        if (!strcmp("(", token.simbolo)) {
            token = aLex->obterToken();
            variaveis();
            token = aLex->obterToken();
            imprimirToken(token.simbolo);
            if (!strcmp(")", token.simbolo)) {
            }
        }
    }
    else if (!strcmp("while", token.simbolo)) {
        token = aLex->obterToken();
        condicao();
        imprimirToken(token.simbolo);
        if (!strcmp("do", token.simbolo)) {
            token = aLex->obterToken();
            imprimirToken(token.simbolo);
            cmd();
        }
    }
    else if (!strcmp("repeat", token.simbolo)) {
        token = aLex->obterToken();
        imprimirToken(token.simbolo);
        cmd();
        if (!strcmp("until", token.simbolo)) {
            token = aLex->obterToken();
            imprimirToken(token.simbolo);
            condicao();
        }
    }
    else if (!strcmp("if", token.simbolo)) {
        token = aLex->obterToken();
        imprimirToken(token.simbolo);
        condicao();
        if (!strcmp("then", token.simbolo)) {
            token = aLex->obterToken();
            imprimirToken(token.simbolo);
            cmd();
            pfalsa();
        }
    }
    else if (!strcmp("IDENTIFICADOR", token.tipo)) {
        token = aLex->obterToken();
        ident();
    }
    else if (!strcmp("begin", token.simbolo)) {
        comandos();
        if (!strcmp("end", token.simbolo)) {
            token = aLex->obterToken();
        }
    }
}


void AnalisadorSintatico::ident()
{
    imprimirToken(token.simbolo);
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
    imprimirToken(token.simbolo);
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
    if (!strcmp("+", token.simbolo) || !strcmp("-", token.simbolo)) {
        imprimirToken(token.simbolo);
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
    if (token.simbolo[0] == ';') {
        return;
    }
    op_ad();
    termo();
    outros_termos();
}


void AnalisadorSintatico::op_ad()
{
    imprimirToken(token.simbolo);
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
    cout << "AQUI" << endl;
    if (token.simbolo[0]==';') {
        return;
    }
    op_mul();
    fator();
    mais_fatores();
}


void AnalisadorSintatico::op_mul()
{
    imprimirToken(token.simbolo);
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
    imprimirToken(token.simbolo);
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
void AnalisadorSintatico::imprimirEstagio(string msg)
{
    #ifdef imprimirEstagios
    cout << msg << endl;
    #endif
    fflush(stdout);
}


/**
 * Emissor de mensagens
 */
void AnalisadorSintatico::imprimirToken(string msg)
{
    #ifdef imprimirSaidaLexico
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

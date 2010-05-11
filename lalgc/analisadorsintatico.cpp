#include "analisadorsintatico.h"

/**
 * Analisador Sintatico Descendente Preditivo Recursivo
 */
AnalisadorSintatico::AnalisadorSintatico(AnalisadorLexico * aLex)
{
    this->aLex = aLex;
    contagemErros = 0;
    imprimirEstagios = true;
    imprimirSimbolos = true;
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
    simbolo = aLex->obterSimbolo();
    programa();
    imprimirEstagio("Fim da analise sintatica.");
}


/**
 * Producao inicial da linguagem LALG
 */
void AnalisadorSintatico::programa()
{
    imprimirEstagio(" Inicio do programa.");
    imprimirToken();
    if (simbolo.cadeia == "program") {
        simbolo = aLex->obterSimbolo();
    }
    else {
        imprimirErro("program esperado");
        erro();
    }
    imprimirToken();
    if (simbolo.token == "IDENTIFICADOR") {
        simbolo = aLex->obterSimbolo();
    }
    else {
        imprimirErro("identificador de programa esperado");
        erro();
    }
    imprimirToken();
    if (simbolo.cadeia == ";") {
        simbolo = aLex->obterSimbolo();
    }
    else {
        imprimirErro("ponto e virgula esperado");
        erro();
    }
    corpo();
    imprimirToken();
    if (simbolo.cadeia == ".") {
        simbolo = aLex->obterSimbolo();
    }
    else {
        imprimirErro("ponto esperado");
        erro();
    }
    if (simbolo.token != "EOF") {
        imprimirErro("fim de arquivo esperado");
        erro();
    }
    imprimirEstagio(" Fim do programa.");
}


void AnalisadorSintatico::corpo()
{
    imprimirEstagio("  Inicio do corpo.");
    dc();
    if (simbolo.cadeia == "begin") {
        imprimirToken();
        simbolo = aLex->obterSimbolo();
    }
    else {
        imprimirToken();
        imprimirErro("begin esperado");
        erro();
    }
    comandos();
    imprimirToken();
    if (simbolo.cadeia == "end") {
        simbolo = aLex->obterSimbolo();
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
    if (simbolo.cadeia == "var") {
        imprimirToken();
        simbolo = aLex->obterSimbolo();
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
    imprimirToken();
    if (simbolo.cadeia == ":") {
        simbolo = aLex->obterSimbolo();
    }
    else {
        imprimirErro("':' esperado");
        erro();
    }
    tipo_var();
    imprimirToken();
    if (simbolo.cadeia == ";") {
        simbolo = aLex->obterSimbolo();
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
    imprimirToken();
    if (simbolo.cadeia == "real" || simbolo.cadeia == "integer") {
        simbolo = aLex->obterSimbolo();
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
    imprimirToken();
    if (simbolo.token == "IDENTIFICADOR") {
        simbolo = aLex->obterSimbolo();
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
    if (simbolo.cadeia == ",") {
        imprimirToken();
        simbolo = aLex->obterSimbolo();
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
    if (simbolo.cadeia == "procedure") {
        imprimirToken();
        simbolo = aLex->obterSimbolo();
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
    imprimirToken();
    if (simbolo.token == "IDENTIFICADOR") {
        simbolo = aLex->obterSimbolo();
    }
    else {
        imprimirErro("identificador esperado");
        erro();
    }
    parametros();
    imprimirToken();
    if (simbolo.cadeia == ";") {
        simbolo = aLex->obterSimbolo();
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
    imprimirToken();
    if (simbolo.cadeia == "(") {
        simbolo = aLex->obterSimbolo();
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
    imprimirToken();
    if (simbolo.cadeia == ")") {
        simbolo = aLex->obterSimbolo();
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
    imprimirToken();
    if (simbolo.cadeia == ":") {
        simbolo = aLex->obterSimbolo();
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
    imprimirToken();
    if (simbolo.cadeia == ";") {
        simbolo = aLex->obterSimbolo();
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
    imprimirToken();
    if (simbolo.cadeia == "begin") {
        simbolo = aLex->obterSimbolo();
    }
    else {
        imprimirErro("begin esperado");
        erro();
    }
    comandos();
    imprimirToken();
    if (simbolo.cadeia == "end") {
        simbolo = aLex->obterSimbolo();
    }
    else {
        imprimirErro("end esperado");
        erro();
    }
    imprimirToken();
    if (simbolo.cadeia == ";") {
        simbolo = aLex->obterSimbolo();
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
    if (simbolo.cadeia == "(") {
        imprimirToken();
        simbolo = aLex->obterSimbolo();
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
    imprimirToken();
    if (simbolo.cadeia == ")") {
        simbolo = aLex->obterSimbolo();
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
    imprimirToken();
    if (simbolo.token == "IDENTIFICADOR") {
        simbolo = aLex->obterSimbolo();
    }
    else {
        imprimirErro("identificador esperado");
        erro();
    }
    mais_ident();
    imprimirEstagio("       Fim dos argumentos");
}


void AnalisadorSintatico::mais_ident()
{
    imprimirEstagio("       Inicio de mais identificadores");
    if (simbolo.cadeia == ";") {
        imprimirToken();
        simbolo = aLex->obterSimbolo();
    }
    else {
        if (1) {
            imprimirEstagio("       Fim de mais identificadores");
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
    if (simbolo.cadeia == "else") {
        imprimirToken();
        simbolo = aLex->obterSimbolo();
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
    if ((primeiro.find(simbolo.cadeia) == primeiro.end()) && (primeiro.find(simbolo.token) == primeiro.end())) {
        imprimirEstagio("   Fim de comandos");
        return;
    }
    cmd();
    imprimirToken();
    if (simbolo.cadeia == ";") {
        simbolo = aLex->obterSimbolo();
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
    imprimirEstagio("Inicio de cmd");
    imprimirToken();
    if (simbolo.cadeia == "read" || simbolo.cadeia == "write") {
        simbolo = aLex->obterSimbolo();
        imprimirToken();
        if (simbolo.cadeia == "(") {
            simbolo = aLex->obterSimbolo();
            variaveis();
            imprimirToken();
            if (simbolo.cadeia == ")") {
                simbolo = aLex->obterSimbolo();
            }
            else {
                imprimirErro("')' esperado");
                erro();
            }
        }
    }
    else if (simbolo.cadeia == "while") {
        simbolo = aLex->obterSimbolo();
        condicao();
        imprimirToken();
        if (simbolo.cadeia == "do") {
            simbolo = aLex->obterSimbolo();
            cmd();
        }
        else {
            imprimirErro("do esperado");
            erro();
        }
    }
    else if (simbolo.cadeia == "repeat") {
        simbolo = aLex->obterSimbolo();
        imprimirToken();
        cmd();
        if (simbolo.cadeia == "until") {
            simbolo = aLex->obterSimbolo();
            imprimirToken();
            condicao();
        }
    }
    else if (simbolo.cadeia == "if") {
        simbolo = aLex->obterSimbolo();
        condicao();
        if (simbolo.cadeia == "then") {
            imprimirToken();
            simbolo = aLex->obterSimbolo();
            cmd();
            imprimirToken();
            simbolo = aLex->obterSimbolo();
            pfalsa();
            imprimirToken();
        }
        else {
            imprimirToken();
            erro();
        }
    }
    else if (simbolo.token == "IDENTIFICADOR") {
        simbolo = aLex->obterSimbolo();
        ident();
    }
    else if (simbolo.cadeia == "begin") {
        imprimirToken();
        simbolo = aLex->obterSimbolo();
        comandos();
        imprimirToken();
        if (simbolo.cadeia == "end") {
            imprimirToken();
            simbolo = aLex->obterSimbolo();
        }
    }
    else {
        imprimirToken();
        erro();
    }
    imprimirEstagio("Fim de cmd");
}


void AnalisadorSintatico::ident()
{
    imprimirEstagio("Inicio ident");
    if (simbolo.cadeia == ":=") {
        imprimirToken();
        simbolo = aLex->obterSimbolo();
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
    imprimirEstagio("Fim ident");
}


void AnalisadorSintatico::condicao()
{
    imprimirEstagio("Inicio de condicao");
    expressao();
    relacao();
    expressao();
    imprimirEstagio("Fim de condicao");
}


void AnalisadorSintatico::relacao()
{
    imprimirEstagio("Inicio de relacao");
    imprimirToken();
    if (simbolo.cadeia == "="  || simbolo.cadeia == "<>" ||
        simbolo.cadeia == ">=" || simbolo.cadeia == "<=" ||
        simbolo.cadeia == ">"  || simbolo.cadeia == "<"  )
    {
        simbolo = aLex->obterSimbolo();
    }
    else {
        imprimirErro("operador relacional esperado");
        erro();
    }
    imprimirEstagio("Fim de relacao");
}


void AnalisadorSintatico::expressao()
{
    imprimirEstagio("Inicio de expressao");
    termo();
    outros_termos();
    imprimirEstagio("Fim de expressao");
}


void AnalisadorSintatico::op_un()
{
    imprimirEstagio("Inicio de operador unario");
    if (simbolo.cadeia == "+" || simbolo.cadeia == "-") {
        imprimirToken();
        simbolo = aLex->obterSimbolo();
    }
    else {
        if (1) {
            imprimirEstagio("Fim de operador unario");
            return;
        }
        else {
            imprimirErro("operador unario esperado");
            erro();
        }
    }
    imprimirEstagio("Fim de operador unario");
}


void AnalisadorSintatico::outros_termos()
{
    imprimirEstagio("Inicio de outros termos");
    if ((simbolo.cadeia != "+") && (simbolo.cadeia != "-")) {
        imprimirEstagio("Fim de outros termos");
        return;
    }
    op_ad();
    termo();
    imprimirEstagio("Fim de outros termos");
    outros_termos();
}


void AnalisadorSintatico::op_ad()
{
    imprimirEstagio("Inicio de operador de adicao");
    imprimirToken();
    if (simbolo.cadeia == "+" || simbolo.cadeia == "-") {
        simbolo = aLex->obterSimbolo();
    }
    else {
        imprimirErro("operador adicao esperado");
        erro();
    }
    imprimirEstagio("Fim de operador de adicao");
}


void AnalisadorSintatico::termo()
{
    imprimirEstagio("Inicio de termo");
    op_un();
    fator();
    mais_fatores();
    imprimirEstagio("Fim de termo");
}


void AnalisadorSintatico::mais_fatores()
{
    imprimirEstagio("Inicio de mais fatores");
    if ((simbolo.cadeia != "*") && (simbolo.cadeia != "/")) {
        imprimirEstagio("Fim de mais fatores");
        return;
    }
    op_mul();
    fator();
    imprimirEstagio("Fim de mais fatores");
    mais_fatores();
}


void AnalisadorSintatico::op_mul()
{
    imprimirEstagio("Inicio de operador de multiplicacao");
    imprimirToken();
    if (simbolo.cadeia == "*" || simbolo.cadeia == "/") {
        simbolo = aLex->obterSimbolo();
    }
    else {
        imprimirErro("operador adicao esperado");
        erro();
    }
    imprimirEstagio("Fim de operador de multiplicacao");
}


void AnalisadorSintatico::fator()
{
    imprimirEstagio("Inicio de fator");
    imprimirToken();
    if (simbolo.token == "IDENTIFICADOR" ||
        simbolo.token == "NUM_INTEIRO" ||
        simbolo.token == "NUM_REAL")
    {
        simbolo = aLex->obterSimbolo();
    }
    else {
        if (simbolo.cadeia == "(") {
            simbolo = aLex->obterSimbolo();
            expressao();
            imprimirToken();
            if (simbolo.cadeia == ")") {
                simbolo = aLex->obterSimbolo();
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
    imprimirEstagio("Fim de fator");
}


/**
 * Gerenciador de erros no modo panico
 */
void AnalisadorSintatico::erro()
{
    imprimirEstagio("Inicio modo panico");
    contagemErros++;
    while (0) {
        simbolo = aLex->obterSimbolo();
    }
    imprimirEstagio("Fim modo panico");
}


/**
 * Emissor de mensagens
 */
void AnalisadorSintatico::imprimirEstagio(string msg)
{
    if (imprimirEstagios) {
        cout << msg << endl;
        fflush(stdout);
    }
}


/**
 * Emissor de tokens
 */
void AnalisadorSintatico::imprimirToken()
{
    if (imprimirSimbolos) {
        cout << simbolo.cadeia << endl;
        fflush(stdout);
    }
}


/**
 * Emissor de erros
 */
void AnalisadorSintatico::imprimirErro(string msg)
{
    cerr << "ERRO: " << msg << endl;
}

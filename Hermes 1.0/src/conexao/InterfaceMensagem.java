/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package conexao;

/**
 *
 * @author Raphael
 */
public interface InterfaceMensagem {

    String imprimirMensagem();

    String mensagemParaString();

    Mensagem stringParaMensagem(String linha);

}

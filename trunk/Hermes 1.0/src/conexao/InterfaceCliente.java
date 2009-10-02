/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package conexao;

import java.awt.event.KeyEvent;

/**
 *
 * @author Raphael
 */
public interface InterfaceCliente {

    /**
     * Metodo utilizado para mudar o apelido de um usuário.
     *
     * @param nick
     * Novo nome inserido pelo usuário
     * @author Raphael Montanari
     * @since 29 de Novembro de 2008
     */
    void alterarApelido(String nick);

    /**
     * Metodo utilizado para trocar de sala.
     *
     * @param room
     * Sala em que o usuário deseja entrar.
     * @author Raphael Montanari
     * @since 29 de Novembro de 2008
     */
    void alterarSala(String room);

    /**
     * Metodo utilizado para conectar-se com o servidor.
     *
     * @return
     *         verdadeiro caso o cliente conectou, falso caso contrário
     * @author Raphael Montanari
     * @since 06 de Outubro de 2008
     */
    boolean conectar();

    /**
     * Metodo utilizado para desconectar-se do servidor.
     *
     * @author Raphael Montanari
     * @since 06 de Outubro de 2008
     */
    void desconectar();

    /**
     * Metodo utilizado para enviar mensagens para o servidor.
     *
     * @param tecla
     * Tecla pressionada, se for <Enter>, envia a mensagem.
     * @author Raphael Montanari
     * @since 06 de Outubro de 2008
     */
    void enviarMensagem(KeyEvent tecla);

    /**
     * Metodo para checar se o cliente está conectado.
     *
     * @return
     *         verdadeiro caso esteja conectado, falso caso contrario.
     * @author Raphael Montanari
     * @since 06 de Novembro de 2008
     */
    boolean estaConectado();

    /**
     * Metodo utilizado para acessar o apelido do cliente a partir de um objeto
     *
     * @return Apelido do usuário
     * @author Raphael Montanari
     * @since 01 de Dezembro de 2008
     */
    String lerApelido();

    /**
     * Metodo utilizado para acessar o campo sala.
     *
     * @return Sala
     * Sala em que o usuário está.
     * @author Raphael Montanari
     * @since 29 de Novembro de 2008
     */
    String lerSala();

    void run();

}

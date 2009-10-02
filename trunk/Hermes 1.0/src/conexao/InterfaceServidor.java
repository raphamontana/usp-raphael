/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package conexao;

/**
 *
 * @author Raphael
 */
public interface InterfaceServidor {

    boolean aceitarConexoes();

    boolean adicionarSala();

    boolean estaAberto();

    void iniciar();

    String[] listarSalas();

    boolean removerSala(Sala sala);

    void run();

    void terminar();

}

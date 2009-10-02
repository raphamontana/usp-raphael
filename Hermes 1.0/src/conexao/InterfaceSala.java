/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package conexao;

/**
 *
 * @author Raphael
 */
public interface InterfaceSala {

    void inserirCliente(String cliente);

    String[] listarClientes();

    int nClientes();

    String nomeSala();

    void removerCliente(String cliente);

}

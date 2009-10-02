package conexao;

import java.util.Vector;

/**
 *
 * @author Raphael, Salvati
 */
public class Sala extends Thread implements InterfaceSala {

	public Vector<String> listaClientes;
	private String nome;

	public Sala(String name) {
		listaClientes = new Vector<String>();
		nome = name;
	}

	public void inserirCliente(String cliente) {
		listaClientes.addElement(cliente);
	}

	public void removerCliente(String cliente) {
		listaClientes.remove(cliente);
	}

	public String nomeSala() {
		return nome;
	}

	public String[] listarClientes() {
		String[] str = new String[listaClientes.size()];
		if (listaClientes != null) {
			for (int i = 0; i < listaClientes.size(); i++) {
				str[i] = listaClientes.firstElement();
			}
		}
		return str;
	}

	public int nClientes() {
		return listaClientes.size();
	}

}

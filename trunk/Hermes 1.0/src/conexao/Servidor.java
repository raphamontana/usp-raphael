package conexao;

import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Vector;

/**
 * Servidor do chat Hermes
 *
 * @author Raphael Montanari, Anderson Salvati, Gabriel Bressan.
 * @since 06 de Novembro de 2008
 */
public class Servidor extends Thread implements InterfaceServidor {

	private Socket soquete = null;
	private ServerSocket soqueteServidor = null;
	private boolean estaAberto;
	final int porta = 9801;
	public Vector<Sala> listaSalas;

	public Servidor() {
		soquete = null;
		soqueteServidor = null;
		estaAberto = false;
		listaSalas = new Vector<Sala>();
	}

	public void iniciar() {
		try {
			soqueteServidor = new ServerSocket(porta);
		} catch (IOException e) {
			System.err.println("Este endereço já está em uso");
		}
		estaAberto = true;
		Sala room = new Sala("Sala 1");
		listaSalas.addElement(room);
		while (true) {
			try {
				soquete = soqueteServidor.accept();
			} catch (IOException e) {
				System.out.println("Conexao encerrada.");
			}

			listaSalas.elementAt(listaSalas.indexOf(room)).inserirCliente(
					"Apelido");
			System.out
					.println(listaSalas.elementAt(listaSalas.indexOf(room)).listaClientes
							.firstElement());
			ManipuladorThreads manipulador = new ManipuladorThreads(soquete);
			manipulador.start();
		}
	}

	public boolean aceitarConexoes() {
		try {
			soquete = soqueteServidor.accept();
		} catch (IOException e) {
			System.out.println("Conexao encerrada.");
			return false;
		}
		String nome = "Apelido";

		listaSalas.elementAt(listaSalas.indexOf("Sala 1")).inserirCliente(nome);
		ManipuladorThreads manipulador = new ManipuladorThreads(soquete);
		manipulador.start();
		return true;
	}

	public boolean estaAberto() {
		return estaAberto;
	}

	public boolean adicionarSala() {
		listaSalas.addElement(new Sala("Sala " + (listaSalas.size() + 1)));
		return true;
	}

	public String[] listarSalas() {
		String[] str = new String[listaSalas.size()];
		if (listaSalas != null) {
			for (int i = 0; i < listaSalas.size(); i++) {
				str[i] = listaSalas.get(i).nomeSala();
			}
		}
		return str;
	}

	public boolean removerSala(Sala sala) {
		if (listaSalas.contains(sala)) {
			listaSalas.removeElement(sala);
			return true;
		} else
			return false;
	}

	public void terminar() {
		interrupt();
		try {
			soqueteServidor.close();
		} catch (IOException e) {
			System.err.println("Nao conseguiu fechar o servidor");
		}
	}

	public void run() {
		iniciar();
	}
}

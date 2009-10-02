package conexao;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.net.Socket;
import java.util.Vector;

/**
 * Classe para criar e manipular as threads
 *
 * @author Raphael Montanari, Anderson Salvati, Gabriel Bressan.
 * @since 06 de Novembro de 2008
 */
public class ManipuladorThreads extends Thread {

	static Vector<ManipuladorThreads> listaClientes = new Vector<ManipuladorThreads>(
			10);
	private Socket soquete;
	private BufferedReader entrada;
	private PrintWriter saida;

	// Construtor: Inicia a Thread
	public ManipuladorThreads(Socket socket) {
		this.soquete = socket;
		// cria um canal de comunicao com esse socket
		// envia msgs para o cliente quando ele iniciar uma conexao
		try {
			entrada = new BufferedReader(new InputStreamReader(soquete
					.getInputStream()));
			saida = new PrintWriter(new OutputStreamWriter(soquete
					.getOutputStream()));
		} catch (IOException e) {
			System.err.println(e.getMessage());
		}
	}

	public void run() {
		synchronized (listaClientes) {
			listaClientes.addElement(this);
		}
		String linha;
		try {
			while (!(linha = entrada.readLine()).equalsIgnoreCase("/quit")) {
				for (int i = 0; i < listaClientes.size(); i++) {
					synchronized (listaClientes) {
						ManipuladorThreads manipulador = (ManipuladorThreads) listaClientes
								.elementAt(i);
						manipulador.saida.println(linha);
						manipulador.saida.flush();
					}
				}
			}
		} catch (IOException excecaoES) {
			excecaoES.printStackTrace();
		} finally {
			try {
				entrada.close();
				saida.close();
				soquete.close();
			} catch (IOException excecaoES) {
			} finally {
				synchronized (listaClientes) {
					listaClientes.removeElement(this);
				}
			}
		}
	}
}

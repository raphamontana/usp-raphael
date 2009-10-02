package conexao;

import java.awt.event.KeyEvent;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.net.Socket;

import javax.swing.JTextPane;

/**
 * Esta classe contem os metodos responsaveis por fazer a conexao da interface
 * grafica (GUI) do cliente com o servidor.
 *
 * @author Raphael Montanari, Anderson Salvati, Gabriel Bressan
 * @since 06 de Outubro de 2008
 */
public class Cliente extends Thread implements InterfaceCliente {

	private String apelido;
	private String nomeServidor;
	final private int porta = 9801;
	private String sala;
	private String destino;
	private Socket soquete;
	private BufferedReader entrada;
	private PrintWriter saida;
    /**
     * Este Painel guarda e exibe as mensagens enviadas e recebidas.
     */
    public JTextPane msgRecebidas;
    /**
     * Este Painel armazena o buffer de mensagens digitadas pelo usuário.
     */
    public JTextPane msgDigitada;

	/**
	 * Construtor da classe Cliente
	 *
     * @param nick
     *             Apelido do usuário.
     * @param sName
     *              Endereço do Servidor.
	 * @author Raphael Montanari
	 * @since 06 de Outubro de 2008
	 */
	public Cliente(String nick, String sName) {

		apelido = nick;
		nomeServidor = sName;
		sala = "0";
		destino = "Todos";
		soquete = null;
		entrada = null;
		saida = null;
		msgRecebidas = new JTextPane();
		msgDigitada = new JTextPane();
	}

	/**
	 * Metodo utilizado para acessar o apelido do cliente a partir de um objeto
	 *
	 * @return Apelido do usuário
	 * @author Raphael Montanari
	 * @since 01 de Dezembro de 2008
	 */
	public String lerApelido() {
		return apelido;
	}

	/**
	 * Metodo utilizado para mudar o apelido de um usuário.
	 *
	 * @param nick
	 *            Novo nome inserido pelo usuário
	 * @author Raphael Montanari
	 * @since 29 de Novembro de 2008
	 */
	public void alterarApelido(String nick) {
		apelido = nick;
	}

	/**
	 * Metodo utilizado para acessar o campo sala.
	 *
	 * @return Sala
	 *            Sala em que o usuário está.
	 * @author Raphael Montanari
	 * @since 29 de Novembro de 2008
	 */
	public String lerSala() {
		return sala;
	}

	/**
	 * Metodo utilizado para trocar de sala.
	 *
	 * @param room
	 *            Sala em que o usuário deseja entrar.
	 * @author Raphael Montanari
	 * @since 29 de Novembro de 2008
	 */
	public void alterarSala(String room) {
		sala = room;
	}

	/**
	 * Metodo utilizado para conectar-se com o servidor.
	 *
     * @return
     *         verdadeiro se conectou, falso caso contrário.
	 * @author Raphael Montanari
	 * @since 06 de Outubro de 2008
	 */
	public boolean conectar() {
		if (estaConectado() == true) {
			return false; // se já estiver conectado, retorna imediatamente
		}

		try { // abrir soquete de conexão com o servidor
			soquete = new Socket(nomeServidor, porta);
			entrada = new BufferedReader(new InputStreamReader(soquete
					.getInputStream()));
			saida = new PrintWriter(new OutputStreamWriter(soquete
					.getOutputStream()));
			saida.flush();
			saida.println(sala + "#" + apelido + "#" + destino + "#"
					+ " acaba de se conectar.");
			saida.flush();
			msgRecebidas
					.setText("===============          Bem vindo ao Servidor Hermes          ==============\n");
			msgRecebidas
					.setText(msgRecebidas.getText()
							+ "----------------------          digite sua mensagem e tecle ENTER          ---------------------\n\n");
			start();
			return true;
		} catch (IOException e) {
			msgRecebidas.setText("O servidor nao está ativado.");
			return false;
		}
	}

	/**
	 * Metodo para checar se o cliente está conectado.
	 *
     * @return
     *         verdadeiro caso esteja conectado, falso caso contrario
     * @author Raphael Montanari
	 * @since 06 de Novembro de 2008
	 */
	public boolean estaConectado() {
		if ((soquete == null) || !soquete.isConnected() || soquete.isClosed())
			return false;
		else
			return true;
	}

	/**
	 * Metodo utilizado para enviar mensagens para o servidor.
	 *
	 * @param tecla
	 *            Tecla pressionada, se for <Enter>, envia a mensagem.
	 * @author Raphael Montanari
	 * @since 06 de Outubro de 2008
	 */
	public void enviarMensagem(KeyEvent tecla) {
		if ((!estaConectado()) || (tecla == null))
			return;

		if (tecla.getKeyCode() == 10) {
			if (msgDigitada.getText().length() > 1) {
				saida.println(sala + "#" + apelido + "#" + destino + "#"
						+ msgDigitada.getText());
				saida.flush();
			}
			msgDigitada.setText("");
		}
	}

	/**
	 * Metodo para receber mensagens enviadas pelo servidor.
	 *
	 * @param s
	 *            String para levar a mensagem
	 * @exception IOEexception
	 *                Problemas ao receber mensagem do dispositivo de E/S.
	 * @author Raphael Montanari
	 * @since 06 de Outubro de 2008
	 */
	private void receberMensagem() {
		if (!estaConectado())
			return;
		String linha;
		Mensagem nova = new Mensagem();
		String vetor[];
		try {
			linha = entrada.readLine();
			vetor = linha.split("#");
			nova.sala = vetor[0];
			nova.autor = vetor[1];
			nova.destinatário = vetor[2];
			nova.mensagem = vetor[3];
			if (!nova.sala.equals(String.valueOf(sala)))
				return;
			else {
				msgRecebidas.setText(msgRecebidas.getText()
						+ nova.imprimirMensagem());
				msgRecebidas.setCaretPosition(msgRecebidas.getText().length());
			}
		} catch (IOException e1) {
			System.err
					.println("Problemas ao receber mensagem do dispositivo de E/S");
		} catch (ArrayIndexOutOfBoundsException e) {
		}
	}

	/**
	 * Metodo utilizado para desconectar-se do servidor.
	 *
	 * @author Raphael Montanari
	 * @since 06 de Outubro de 2008
	 */
	public void desconectar() {
		if (!estaConectado())
			return;
		try {
			saida.println(sala + "#" + apelido + "#Todos#" + apelido
					+ " se desconectou.");
			saida.println("/quit");
			saida.flush();
			entrada.close();
			saida.close();
			soquete.close();
			msgRecebidas.setText("Voce se desconectou.");
		} catch (IOException e) {
			System.err.println("Erro ao tentar fechar as conexoes: "
					+ e.getMessage());
		}
	}

	public void run() {
		while (estaConectado()) {
			enviarMensagem(null);
			receberMensagem();
		}
	}
}

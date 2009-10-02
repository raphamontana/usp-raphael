package conexao;

public class Mensagem implements InterfaceMensagem {

	public String sala;
	public String autor;
	public String destinat�rio;
	public String mensagem;

	public Mensagem() {
		sala = "0";
		autor = "";
		destinat�rio = "";
		mensagem = "";
	}

	public Mensagem(String room, String name, String dest, String msg) {
		sala = room;
		autor = name;
		destinat�rio = dest;
		mensagem = msg;
	}

	public String mensagemParaString() {
		return (sala + "#" + autor + "#" + destinat�rio + "#" + mensagem);
	}

	public Mensagem stringParaMensagem(String linha) {
		Mensagem nova = new Mensagem();
		String msg[];
		msg = linha.split("#");

		try {
			nova.sala = msg[0];
			nova.autor = msg[1];
			nova.destinat�rio = msg[2];
			nova.mensagem = msg[3];
		} catch (ArrayIndexOutOfBoundsException e) {
		}

		System.out.println("Aqui " + nova.mensagem);
		return nova;
	}

	public String imprimirMensagem() {
		if (!mensagem.equals(" acaba de se conectar."))
			return (autor + " disse: " + mensagem + "\n");
		else
			return (autor + mensagem + "\n");
	}
}

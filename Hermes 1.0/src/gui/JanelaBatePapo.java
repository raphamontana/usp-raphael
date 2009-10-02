package gui;

import java.awt.GridBagConstraints;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;

import javax.swing.DefaultListModel;
import javax.swing.ImageIcon;
import javax.swing.JCheckBoxMenuItem;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JList;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JSeparator;
import javax.swing.JSplitPane;
import javax.swing.SwingConstants;
import javax.swing.WindowConstants;

import conexao.Cliente;
import conexao.Sala;
import conexao.Servidor;

/**
 * JanelaBatePapo Gráfica do Usuário
 *
 * @author Raphael Montanari, Anderson Salvati, Gabriel Bressan
 * @since 30 de Novembro de 2008
 */
@SuppressWarnings("serial")
public class JanelaBatePapo extends JFrame {

	Inicial anterior;
	Cliente cliente;
	Servidor servidor;

	/** Cria um novo quadro */
	public JanelaBatePapo(Inicial referencia, Cliente c, Servidor s) {
		anterior = referencia;
		cliente = c;
		servidor = s;

		GridBagConstraints gridBagConstraints;

		painelImagem = new JPanel();
		painelFrente = new JPanel();
		divisorMsg = new JSplitPane();
		painelRolagemSuperior = new JScrollPane();
		painelRolagemInferior = new JScrollPane();
		rotuloSalas = new JLabel();
		painelSalas = new JScrollPane();
		painelClientes = new JScrollPane();
		rotuloUsuarios = new JLabel();
		rotuloQuadro = new JLabel();
		imagemFundo = new JLabel();
		barraMenus = new JMenuBar();
		menuArquivo = new JMenu();
		opcaoEntrar = new JMenuItem();
		opcaoSair = new JMenuItem();
		opcaoFechar = new JMenuItem();
		menuFerramentas = new JMenu();
		opcaoSempreVisivel = new JCheckBoxMenuItem();
		jSeparator1 = new JSeparator();
		opcaoConfigurar = new JMenuItem();
		menuAjuda = new JMenu();
		opcaoSobre = new JMenuItem();

		setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
		setTitle("Hermes");

		painelImagem.setMinimumSize(new java.awt.Dimension(1, 1));
		painelImagem.setLayout(new java.awt.GridBagLayout());

		painelFrente.setOpaque(false);

		divisorMsg.setDividerLocation(350);
		divisorMsg.setOrientation(JSplitPane.VERTICAL_SPLIT);

		cliente.msgDigitada.addKeyListener(new KeyListener() {
			public void keyPressed(KeyEvent tecla) {
			}

			public void keyReleased(KeyEvent tecla) {
				cliente.enviarMensagem(tecla);
			}

			public void keyTyped(KeyEvent tecla) {
			}
		});
		cliente.msgRecebidas.setEditable(false);
		painelRolagemSuperior.setViewportView(cliente.msgRecebidas);
		divisorMsg.setLeftComponent(painelRolagemSuperior);

		painelRolagemInferior.setViewportView(cliente.msgDigitada);
		divisorMsg.setRightComponent(painelRolagemInferior);

		/**********************************************************************/
		rotuloSalas.setText("Lista de Salas");

		dadosSalas = new DefaultListModel();
		for (int i = 0; i < servidor.listaSalas.size(); i++) {
			dadosSalas.addElement(servidor.listaSalas.get(i).nomeSala());
		}
		new JList(dadosSalas);

		painelSalas.setViewportView(new JList(dadosSalas));

		dadosClientes = new DefaultListModel();
        dadosClientes.addElement(cliente.lerApelido());
		painelClientes.setViewportView(new JList(dadosClientes));

		/**********************************************************************/
		rotuloUsuarios.setText("Lista de Usuários");

		rotuloQuadro.setText("Quadro de Mensagens");

		org.jdesktop.layout.GroupLayout painelFrenteLayout = new org.jdesktop.layout.GroupLayout(
				painelFrente);
		painelFrente.setLayout(painelFrenteLayout);
		painelFrenteLayout
				.setHorizontalGroup(painelFrenteLayout
						.createParallelGroup(
								org.jdesktop.layout.GroupLayout.LEADING)
						.add(
								painelFrenteLayout
										.createSequentialGroup()
										.addContainerGap()
										.add(
												painelFrenteLayout
														.createParallelGroup(
																org.jdesktop.layout.GroupLayout.LEADING)
														.add(
																painelClientes,
																org.jdesktop.layout.GroupLayout.DEFAULT_SIZE,
																162,
																Short.MAX_VALUE)
														.add(rotuloSalas)
														.add(
																painelSalas,
																org.jdesktop.layout.GroupLayout.DEFAULT_SIZE,
																162,
																Short.MAX_VALUE)
														.add(rotuloUsuarios))
										.addPreferredGap(
												org.jdesktop.layout.LayoutStyle.RELATED)
										.add(
												painelFrenteLayout
														.createParallelGroup(
																org.jdesktop.layout.GroupLayout.LEADING)
														.add(
																divisorMsg,
																org.jdesktop.layout.GroupLayout.DEFAULT_SIZE,
																452,
																Short.MAX_VALUE)
														.add(rotuloQuadro))
										.addContainerGap()));
		painelFrenteLayout
				.setVerticalGroup(painelFrenteLayout
						.createParallelGroup(
								org.jdesktop.layout.GroupLayout.LEADING)
						.add(
								painelFrenteLayout
										.createSequentialGroup()
										.addContainerGap()
										.add(
												painelFrenteLayout
														.createParallelGroup(
																org.jdesktop.layout.GroupLayout.BASELINE)
														.add(rotuloSalas).add(
																rotuloQuadro))
										.addPreferredGap(
												org.jdesktop.layout.LayoutStyle.RELATED)
										.add(
												painelFrenteLayout
														.createParallelGroup(
																org.jdesktop.layout.GroupLayout.LEADING)
														.add(
																org.jdesktop.layout.GroupLayout.TRAILING,
																divisorMsg,
																org.jdesktop.layout.GroupLayout.DEFAULT_SIZE,
																417,
																Short.MAX_VALUE)
														.add(
																painelFrenteLayout
																		.createSequentialGroup()
																		.add(
																				painelSalas,
																				org.jdesktop.layout.GroupLayout.PREFERRED_SIZE,
																				185,
																				org.jdesktop.layout.GroupLayout.PREFERRED_SIZE)
																		.addPreferredGap(
																				org.jdesktop.layout.LayoutStyle.UNRELATED)
																		.add(
																				rotuloUsuarios)
																		.addPreferredGap(
																				org.jdesktop.layout.LayoutStyle.RELATED)
																		.add(
																				painelClientes,
																				org.jdesktop.layout.GroupLayout.DEFAULT_SIZE,
																				201,
																				Short.MAX_VALUE)))
										.addContainerGap()));

		gridBagConstraints = new java.awt.GridBagConstraints();
		gridBagConstraints.gridx = 0;
		gridBagConstraints.gridy = 0;
		gridBagConstraints.fill = java.awt.GridBagConstraints.BOTH;
		gridBagConstraints.weightx = 1.0;
		gridBagConstraints.weighty = 1.0;
		painelImagem.add(painelFrente, gridBagConstraints);

		imagemFundo.setHorizontalAlignment(SwingConstants.CENTER);
		imagemFundo.setIcon(new ImageIcon(getClass().getResource(
				"/imagens/fundoBatePapo.png"))); // NOI18N
		gridBagConstraints = new java.awt.GridBagConstraints();
		gridBagConstraints.gridx = 0;
		gridBagConstraints.gridy = 0;
		gridBagConstraints.fill = java.awt.GridBagConstraints.BOTH;
		gridBagConstraints.weightx = 1.0;
		gridBagConstraints.weighty = 1.0;
		painelImagem.add(imagemFundo, gridBagConstraints);

		menuArquivo.setText("Arquivo");

		opcaoEntrar.setIcon(new ImageIcon(getClass().getResource(
				"/imagens/entrar.png"))); // NOI18N
		opcaoEntrar.setText("Entrar");
		opcaoEntrar.setEnabled(false);
		menuArquivo.add(opcaoEntrar);

		opcaoSair.setIcon(new ImageIcon(getClass().getResource(
				"/imagens/sair.png"))); // NOI18N
		opcaoSair.setText("Sair");
		opcaoSair.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent evt) {
				opcaoSairActionPerformed(evt);
			}
		});
		menuArquivo.add(opcaoSair);

		opcaoFechar.setIcon(new ImageIcon(getClass().getResource(
				"/imagens/fechar.png"))); // NOI18N
		opcaoFechar.setText("Fechar");
		menuArquivo.add(opcaoFechar);

		barraMenus.add(menuArquivo);

		menuFerramentas.setText("Ferramentas");
		menuFerramentas.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent evt) {
				menuFerramentasActionPerformed(evt);
			}
		});

		opcaoSempreVisivel.setSelected(true);
		opcaoSempreVisivel.setText("Sempre Visível");
		opcaoSempreVisivel.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent evt) {
				opcaoSempreVisivelActionPerformed(evt);
			}
		});
		menuFerramentas.add(opcaoSempreVisivel);
		menuFerramentas.add(jSeparator1);

		opcaoConfigurar.setIcon(new ImageIcon(getClass().getResource(
				"/imagens/configurar.png"))); // NOI18N
		// opcaoConfigurar.setText("Opções");
		opcaoConfigurar.setText("Criar nova sala");
		opcaoConfigurar.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent evt) {
				opcaoConfigurarActionPerformed(evt);
			}
		});
		menuFerramentas.add(opcaoConfigurar);

		barraMenus.add(menuFerramentas);

		menuAjuda.setText("Ajuda");

		opcaoSobre.setIcon(new ImageIcon(getClass().getResource(
				"/imagens/sobre.png"))); // NOI18N
		opcaoSobre.setText("Sobre");
		opcaoSobre.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent evt) {
				opcaoSobreActionPerformed(evt);
			}
		});
		menuAjuda.add(opcaoSobre);

		barraMenus.add(menuAjuda);

		setJMenuBar(barraMenus);

		org.jdesktop.layout.GroupLayout layout = new org.jdesktop.layout.GroupLayout(
				getContentPane());
		getContentPane().setLayout(layout);
		layout.setHorizontalGroup(layout.createParallelGroup(
				org.jdesktop.layout.GroupLayout.LEADING).add(painelImagem,
				org.jdesktop.layout.GroupLayout.DEFAULT_SIZE, 640,
				Short.MAX_VALUE));
		layout.setVerticalGroup(layout.createParallelGroup(
				org.jdesktop.layout.GroupLayout.LEADING).add(painelImagem,
				org.jdesktop.layout.GroupLayout.DEFAULT_SIZE, 459,
				Short.MAX_VALUE));

		pack();

		cliente.conectar();
	}

	private void opcaoSempreVisivelActionPerformed(ActionEvent evt) {
	}

	private void opcaoConfigurarActionPerformed(ActionEvent evt) {
		String nomeSala = "Sala " + (servidor.listaSalas.size() + 1);
		dadosSalas.addElement(nomeSala);
		servidor.listaSalas.addElement(new Sala(nomeSala));
		cliente.alterarSala(nomeSala);
	}

	private void menuFerramentasActionPerformed(ActionEvent evt) {
		this.setAlwaysOnTop(menuFerramentas.isSelected());
	}

	private void opcaoSairActionPerformed(ActionEvent evt) {
		anterior.setVisible(true);
		dispose();
	}

	private void opcaoSobreActionPerformed(ActionEvent evt) {
		new Sobre().setVisible(true);
	}

	// Variables declaration - do not modify//GEN-BEGIN:variables
	private JMenuBar barraMenus;
	private JLabel imagemFundo;
	private DefaultListModel dadosSalas;
	private DefaultListModel dadosClientes;
	private JScrollPane painelSalas;
	private JScrollPane painelClientes;
	private JSeparator jSeparator1;
	private JMenu menuAjuda;
	private JMenu menuArquivo;
	private JMenu menuFerramentas;
	private JMenuItem opcaoConfigurar;
	private JMenuItem opcaoEntrar;
	private JMenuItem opcaoFechar;
	private JMenuItem opcaoSair;
	private JCheckBoxMenuItem opcaoSempreVisivel;
	private JMenuItem opcaoSobre;
	private JPanel painelFrente;
	private JPanel painelImagem;
	private JScrollPane painelRolagemSuperior;
	private JScrollPane painelRolagemInferior;
	private JSplitPane divisorMsg;
	private JLabel rotuloQuadro;
	private JLabel rotuloSalas;
	private JLabel rotuloUsuarios;
	// End of variables declaration//GEN-END:variables

}

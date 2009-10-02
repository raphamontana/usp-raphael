package gui;

import java.io.IOException;
import java.net.Socket;
import java.net.UnknownHostException;

import conexao.Cliente;
import conexao.Servidor;

/**
 * Tela inicial do mensageiro instantâneo
 *
 * @author Raphael Montanari, Anderson Salvati, Gabriel Bressan
 * @since 30 de Novembro de 2008
 */
@SuppressWarnings("serial")
public class Inicial extends javax.swing.JFrame {

	Servidor servidor;
	Cliente cliente;

	/** Construtor: inicia a interface gráfica\ */
	public Inicial() {
		servidor = new Servidor();

		java.awt.GridBagConstraints gridBagConstraints;

		painelImagem = new javax.swing.JPanel();
		painelFrente = new javax.swing.JPanel();
		rotuloIP = new javax.swing.JLabel();
		campoNome = new javax.swing.JTextField();
		campoIP = new javax.swing.JTextField();
		botaoEntrar = new javax.swing.JButton();
		rotuloStatus = new javax.swing.JLabel();
		rotuloNomeUsuario = new javax.swing.JLabel();
		imagemHermes = new javax.swing.JLabel();
		botaoServidor = new javax.swing.JButton();
		botaoAtualizar = new javax.swing.JButton();
		imagemFundo = new javax.swing.JLabel();
		barraMenus = new javax.swing.JMenuBar();
		menuArquivo = new javax.swing.JMenu();
		opcaoEntrar = new javax.swing.JMenuItem();
		opcaoSair = new javax.swing.JMenuItem();
		opcaoFechar = new javax.swing.JMenuItem();
		menuFerramentas = new javax.swing.JMenu();
		opcaoSempreVisivel = new javax.swing.JCheckBoxMenuItem();
		jSeparator1 = new javax.swing.JSeparator();
		opcaoConfigurar = new javax.swing.JMenuItem();
		menuAjuda = new javax.swing.JMenu();
		opcaoSobre = new javax.swing.JMenuItem();

		setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
		setTitle("Hermes");
		setResizable(false);

		painelImagem.setMinimumSize(new java.awt.Dimension(1, 1));
		painelImagem.setLayout(new java.awt.GridBagLayout());

		painelFrente.setMaximumSize(new java.awt.Dimension(580, 1278));
		painelFrente.setMinimumSize(new java.awt.Dimension(290, 639));
		painelFrente.setOpaque(false);
		painelFrente.setPreferredSize(new java.awt.Dimension(290, 639));

		rotuloIP.setText("  Endereço IP do Servidor:");

		campoNome.setText(System.getProperty("user.name"));
		campoNome.addActionListener(new java.awt.event.ActionListener() {
			public void actionPerformed(java.awt.event.ActionEvent evt) {
				campoNomeActionPerformed(evt);
			}
		});

		campoIP.setText("127.0.0.1");
		campoIP.addActionListener(new java.awt.event.ActionListener() {
			public void actionPerformed(java.awt.event.ActionEvent evt) {
				campoIPActionPerformed(evt);
			}
		});

		botaoEntrar.setText("Entrar");
		botaoEntrar.requestFocus();
		botaoEntrar.addActionListener(new java.awt.event.ActionListener() {
			public void actionPerformed(java.awt.event.ActionEvent evt) {
				botaoEntrarActionPerformed(evt);
			}
		});

		rotuloStatus.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
		rotuloStatus.setText("Status do Servidor: Fechado");
		rotuloStatus.addMouseListener(new java.awt.event.MouseAdapter() {
			public void mouseEntered(java.awt.event.MouseEvent evt) {
				rotuloStatusMouseEntered(evt);
			}
		});

		rotuloNomeUsuario.setText("  Nome de usuário:");

		imagemHermes.setIcon(new javax.swing.ImageIcon(getClass().getResource(
				"/imagens/hermes.png"))); // NOI18N

		botaoServidor.setText("Iniciar Servidor");
		botaoServidor
				.setHorizontalTextPosition(javax.swing.SwingConstants.CENTER);
		botaoServidor.addActionListener(new java.awt.event.ActionListener() {
			public void actionPerformed(java.awt.event.ActionEvent evt) {
				botaoServidorActionPerformed(evt);
			}
		});

		botaoAtualizar.setText("Atualizar");
		botaoAtualizar.addActionListener(new java.awt.event.ActionListener() {
			public void actionPerformed(java.awt.event.ActionEvent evt) {
				botaoAtualizarActionPerformed(evt);
			}
		});

		org.jdesktop.layout.GroupLayout painelFrenteLayout = new org.jdesktop.layout.GroupLayout(
				painelFrente);
		painelFrente.setLayout(painelFrenteLayout);
		painelFrenteLayout
				.setHorizontalGroup(painelFrenteLayout
						.createParallelGroup(
								org.jdesktop.layout.GroupLayout.LEADING)
						.add(
								org.jdesktop.layout.GroupLayout.TRAILING,
								painelFrenteLayout
										.createSequentialGroup()
										.addContainerGap(61, Short.MAX_VALUE)
										.add(
												painelFrenteLayout
														.createParallelGroup(
																org.jdesktop.layout.GroupLayout.TRAILING)
														.add(rotuloStatus).add(
																botaoServidor))
										.add(91, 91, 91))
						.add(
								painelFrenteLayout
										.createSequentialGroup()
										.add(
												painelFrenteLayout
														.createParallelGroup(
																org.jdesktop.layout.GroupLayout.TRAILING,
																false)
														.add(
																org.jdesktop.layout.GroupLayout.LEADING,
																painelFrenteLayout
																		.createSequentialGroup()
																		.addContainerGap()
																		.add(
																				rotuloNomeUsuario))
														.add(
																org.jdesktop.layout.GroupLayout.LEADING,
																painelFrenteLayout
																		.createSequentialGroup()
																		.addContainerGap()
																		.add(
																				rotuloIP))
														.add(
																org.jdesktop.layout.GroupLayout.LEADING,
																painelFrenteLayout
																		.createSequentialGroup()
																		.add(
																				101,
																				101,
																				101)
																		.add(
																				botaoEntrar,
																				org.jdesktop.layout.GroupLayout.PREFERRED_SIZE,
																				72,
																				org.jdesktop.layout.GroupLayout.PREFERRED_SIZE))
														.add(
																org.jdesktop.layout.GroupLayout.LEADING,
																painelFrenteLayout
																		.createSequentialGroup()
																		.addContainerGap()
																		.add(
																				campoIP,
																				org.jdesktop.layout.GroupLayout.PREFERRED_SIZE,
																				174,
																				org.jdesktop.layout.GroupLayout.PREFERRED_SIZE)
																		.addPreferredGap(
																				org.jdesktop.layout.LayoutStyle.RELATED)
																		.add(
																				botaoAtualizar))
														.add(
																org.jdesktop.layout.GroupLayout.LEADING,
																painelFrenteLayout
																		.createSequentialGroup()
																		.addContainerGap()
																		.add(
																				campoNome)))
										.add(24, 24, 24)).add(
								painelFrenteLayout.createSequentialGroup().add(
										78, 78, 78).add(imagemHermes)
										.addContainerGap(83, Short.MAX_VALUE)));
		painelFrenteLayout
				.setVerticalGroup(painelFrenteLayout
						.createParallelGroup(
								org.jdesktop.layout.GroupLayout.LEADING)
						.add(
								painelFrenteLayout
										.createSequentialGroup()
										.add(48, 48, 48)
										.add(imagemHermes)
										.add(97, 97, 97)
										.add(rotuloNomeUsuario)
										.addPreferredGap(
												org.jdesktop.layout.LayoutStyle.RELATED)
										.add(
												campoNome,
												org.jdesktop.layout.GroupLayout.PREFERRED_SIZE,
												org.jdesktop.layout.GroupLayout.DEFAULT_SIZE,
												org.jdesktop.layout.GroupLayout.PREFERRED_SIZE)
										.add(18, 18, 18)
										.add(rotuloIP)
										.addPreferredGap(
												org.jdesktop.layout.LayoutStyle.RELATED)
										.add(
												painelFrenteLayout
														.createParallelGroup(
																org.jdesktop.layout.GroupLayout.BASELINE)
														.add(
																campoIP,
																org.jdesktop.layout.GroupLayout.PREFERRED_SIZE,
																org.jdesktop.layout.GroupLayout.DEFAULT_SIZE,
																org.jdesktop.layout.GroupLayout.PREFERRED_SIZE)
														.add(botaoAtualizar))
										.add(18, 18, 18).add(botaoEntrar).add(
												67, 67, 67).add(rotuloStatus)
										.add(18, 18, 18).add(botaoServidor)
										.addContainerGap(90, Short.MAX_VALUE)));

		painelImagem.add(painelFrente, new java.awt.GridBagConstraints());

		imagemFundo.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
		imagemFundo.setIcon(new javax.swing.ImageIcon(getClass().getResource(
				"/imagens/fundo.jpg"))); // NOI18N
		gridBagConstraints = new java.awt.GridBagConstraints();
		gridBagConstraints.gridx = 0;
		gridBagConstraints.gridy = 0;
		gridBagConstraints.fill = java.awt.GridBagConstraints.BOTH;
		gridBagConstraints.weightx = 1.0;
		gridBagConstraints.weighty = 1.0;
		painelImagem.add(imagemFundo, gridBagConstraints);

		menuArquivo.setText("Arquivo");
		menuArquivo.addActionListener(new java.awt.event.ActionListener() {
			public void actionPerformed(java.awt.event.ActionEvent evt) {
				menuArquivoActionPerformed(evt);
			}
		});

		opcaoEntrar.setIcon(new javax.swing.ImageIcon(getClass().getResource(
				"/imagens/entrar.png"))); // NOI18N
		opcaoEntrar.setText("Entrar");
		opcaoEntrar.addActionListener(new java.awt.event.ActionListener() {
			public void actionPerformed(java.awt.event.ActionEvent evt) {
				opcaoEntrarActionPerformed(evt);
			}
		});
		menuArquivo.add(opcaoEntrar);

		opcaoSair.setIcon(new javax.swing.ImageIcon(getClass().getResource(
				"/imagens/sair.png"))); // NOI18N
		opcaoSair.setText("Sair");
		opcaoSair.setEnabled(false);
		menuArquivo.add(opcaoSair);

		opcaoFechar.setIcon(new javax.swing.ImageIcon(getClass().getResource(
				"/imagens/fechar.png"))); // NOI18N
		opcaoFechar.setText("Fechar");
		opcaoFechar.addActionListener(new java.awt.event.ActionListener() {
			public void actionPerformed(java.awt.event.ActionEvent evt) {
				opcaoFecharActionPerformed(evt);
			}
		});
		menuArquivo.add(opcaoFechar);

		barraMenus.add(menuArquivo);

		menuFerramentas.setText("Ferramentas");
		menuFerramentas.addActionListener(new java.awt.event.ActionListener() {
			public void actionPerformed(java.awt.event.ActionEvent evt) {
				menuFerramentasActionPerformed(evt);
			}
		});

		opcaoSempreVisivel.setSelected(true);
		opcaoSempreVisivel.setText("Sempre Visível");
		opcaoSempreVisivel
				.addActionListener(new java.awt.event.ActionListener() {
					public void actionPerformed(java.awt.event.ActionEvent evt) {
						opcaoSempreVisivelActionPerformed(evt);
					}
				});
		menuFerramentas.add(opcaoSempreVisivel);
		menuFerramentas.add(jSeparator1);

		opcaoConfigurar.setIcon(new javax.swing.ImageIcon(getClass()
				.getResource("/imagens/configurar.png"))); // NOI18N
		opcaoConfigurar.setText("Opções");
		opcaoConfigurar.addActionListener(new java.awt.event.ActionListener() {
			public void actionPerformed(java.awt.event.ActionEvent evt) {
				opcaoConfigurarActionPerformed(evt);
			}
		});
		menuFerramentas.add(opcaoConfigurar);

		barraMenus.add(menuFerramentas);

		menuAjuda.setText("Ajuda");
		menuAjuda.addActionListener(new java.awt.event.ActionListener() {
			public void actionPerformed(java.awt.event.ActionEvent evt) {
				menuAjudaActionPerformed(evt);
			}
		});

		opcaoSobre.setIcon(new javax.swing.ImageIcon(getClass().getResource(
				"/imagens/sobre.png"))); // NOI18N
		opcaoSobre.setText("Sobre");
		opcaoSobre.addActionListener(new java.awt.event.ActionListener() {
			public void actionPerformed(java.awt.event.ActionEvent evt) {
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
				org.jdesktop.layout.GroupLayout.DEFAULT_SIZE, 289,
				Short.MAX_VALUE));
		layout.setVerticalGroup(layout.createParallelGroup(
				org.jdesktop.layout.GroupLayout.LEADING).add(painelImagem,
				org.jdesktop.layout.GroupLayout.DEFAULT_SIZE, 618,
				Short.MAX_VALUE));

		pack();
	}

	private void botaoEntrarActionPerformed(java.awt.event.ActionEvent evt) {// GEN-FIRST:event_botaoEntrarActionPerformed
		if (rotuloStatus.getText().equals("Status do Servidor: Aberto")) {
			JanelaBatePapo inter;
			inter = new JanelaBatePapo(this, new Cliente(campoNome.getText(),
					campoIP.getText()), servidor);
			inter.setVisible(true);
			setVisible(false);
		}
	}

	private void campoIPActionPerformed(java.awt.event.ActionEvent evt) {
	}

	private void campoNomeActionPerformed(java.awt.event.ActionEvent evt) {// GEN-FIRST:event_campoNomeActionPerformed

	}// GEN-LAST:event_campoNomeActionPerformed

	private void rotuloStatusMouseEntered(java.awt.event.MouseEvent evt) {// GEN-FIRST:event_rotuloStatusMouseEntered

	}// GEN-LAST:event_rotuloStatusMouseEntered

	private void opcaoSempreVisivelActionPerformed(
			java.awt.event.ActionEvent evt) {// GEN-FIRST:event_opcaoSempreVisivelActionPerformed

	}// GEN-LAST:event_opcaoSempreVisivelActionPerformed

	private void opcaoConfigurarActionPerformed(java.awt.event.ActionEvent evt) {// GEN-FIRST:event_opcaoConfigurarActionPerformed

	}// GEN-LAST:event_opcaoConfigurarActionPerformed

	private void menuFerramentasActionPerformed(java.awt.event.ActionEvent evt) {// GEN-FIRST:event_menuFerramentasActionPerformed
		setAlwaysOnTop(menuFerramentas.isSelected());
	}// GEN-LAST:event_menuFerramentasActionPerformed

	private void botaoServidorActionPerformed(java.awt.event.ActionEvent evt) {// GEN-FIRST:event_botaoServidorActionPerformed
		if (servidor.estaAberto()) {
			servidor.terminar();
			campoIP.setEditable(true);
			rotuloStatus.setText("Status do Servidor: Fechado");
			botaoServidor.setText("Iniciar Servidor");
		} else {
			servidor.start();
			campoIP.setEditable(false);
			rotuloStatus.setText("Status do Servidor: Aberto");
			botaoServidor.setText("Fechar Servidor");
		}
	}// GEN-LAST:event_botaoServidorActionPerformed

	private void opcaoFecharActionPerformed(java.awt.event.ActionEvent evt) {// GEN-FIRST:event_opcaoFecharActionPerformed
		System.exit(0);
	}// GEN-LAST:event_opcaoFecharActionPerformed

	private void menuArquivoActionPerformed(java.awt.event.ActionEvent evt) {// GEN-FIRST:event_menuArquivoActionPerformed

	}// GEN-LAST:event_menuArquivoActionPerformed

	private void menuAjudaActionPerformed(java.awt.event.ActionEvent evt) {// GEN-FIRST:event_menuAjudaActionPerformed
		Sobre janelaSobre = new Sobre();
		janelaSobre.setVisible(true);
	}// GEN-LAST:event_menuAjudaActionPerformed

	private void opcaoSobreActionPerformed(java.awt.event.ActionEvent evt) {// GEN-FIRST:event_opcaoSobreActionPerformed
		new Sobre().setVisible(true);
	}// GEN-LAST:event_opcaoSobreActionPerformed

	private void botaoAtualizarActionPerformed(java.awt.event.ActionEvent evt) {// GEN-FIRST:event_botaoAtualizarActionPerformed
		try {
			Socket socket = new Socket(campoIP.getText(), 9801);
			if (socket.isConnected())
				rotuloStatus.setText("Status do Servidor: Aberto");
		} catch (UnknownHostException e) {
			// System.err.println("Servidor não está disponível.");
		} catch (IOException e) {
			// System.err.println(e.getMessage());
		}
	}

	private void opcaoEntrarActionPerformed(java.awt.event.ActionEvent evt) {// GEN-FIRST:event_opcaoEntrarActionPerformed
		if (rotuloStatus.getText().equals("Status do Servidor: Aberto")) {
			JanelaBatePapo inter;
			inter = new JanelaBatePapo(this, new Cliente(campoNome.getText(),
					campoIP.getText()), servidor);
			inter.setVisible(true);
			setVisible(false);
		}
	}

	// Variables declaration - do not modify//GEN-BEGIN:variables
	private javax.swing.JMenuBar barraMenus;
	private javax.swing.JButton botaoAtualizar;
	private javax.swing.JButton botaoEntrar;
	private javax.swing.JButton botaoServidor;
	private javax.swing.JTextField campoIP;
	private javax.swing.JTextField campoNome;
	private javax.swing.JLabel imagemFundo;
	private javax.swing.JLabel imagemHermes;
	private javax.swing.JSeparator jSeparator1;
	private javax.swing.JMenu menuAjuda;
	private javax.swing.JMenu menuArquivo;
	private javax.swing.JMenu menuFerramentas;
	private javax.swing.JMenuItem opcaoConfigurar;
	private javax.swing.JMenuItem opcaoEntrar;
	private javax.swing.JMenuItem opcaoFechar;
	private javax.swing.JMenuItem opcaoSair;
	private javax.swing.JCheckBoxMenuItem opcaoSempreVisivel;
	private javax.swing.JMenuItem opcaoSobre;
	private javax.swing.JPanel painelFrente;
	private javax.swing.JPanel painelImagem;
	private javax.swing.JLabel rotuloIP;
	private javax.swing.JLabel rotuloNomeUsuario;
	private javax.swing.JLabel rotuloStatus;
	// End of variables declaration//GEN-END:variables

}

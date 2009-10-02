package gui;

/**
 * Tela inicial do mensageiro instantâneo
 *
 * @author Raphael Montanari, Anderson Salvati, Gabriel Bressan
 * @since 30 de Novembro de 2008
 */
@SuppressWarnings("serial")
public class Sobre extends javax.swing.JFrame {

	/** Cria um novo quadro */
	public Sobre() {
		initComponents();
	}

	/** Este método é chamado pelo construtor para iniciar a janela */
	// <editor-fold defaultstate="collapsed"
	// desc="Generated Code">//GEN-BEGIN:initComponents
	private void initComponents() {
		java.awt.GridBagConstraints gridBagConstraints;

		painelImagem = new javax.swing.JPanel();
		painelFrente = new javax.swing.JPanel();
		rotuloNome = new javax.swing.JLabel();
		rotuloIP = new javax.swing.JLabel();
		botaoEntrar = new javax.swing.JButton();
		rotuloSenha = new javax.swing.JLabel();
		imagemHermes = new javax.swing.JLabel();
		rotuloSenha1 = new javax.swing.JLabel();
		jLabel1 = new javax.swing.JLabel();
		jLabel2 = new javax.swing.JLabel();
		jLabel3 = new javax.swing.JLabel();
		imagemFundo = new javax.swing.JLabel();

		setDefaultCloseOperation(javax.swing.WindowConstants.DISPOSE_ON_CLOSE);
		setTitle("Sobre o Hermes");

		painelImagem.setMinimumSize(new java.awt.Dimension(1, 1));
		painelImagem.setLayout(new java.awt.GridBagLayout());

		painelFrente.setOpaque(false);

		rotuloNome.setText("Versão 1.0");

		rotuloIP.setFont(new java.awt.Font("Tahoma", 1, 18));
		rotuloIP.setText("Mensageiro Instantâneo Hermes");

		botaoEntrar.setText("OK");
		botaoEntrar.addActionListener(new java.awt.event.ActionListener() {
			public void actionPerformed(java.awt.event.ActionEvent evt) {
				botaoEntrarActionPerformed(evt);
			}
		});

		rotuloSenha.setText("Copyright © 2008 Grupo 10.");

		imagemHermes.setIcon(new javax.swing.ImageIcon(getClass().getResource(
				"/imagens/hermes.png"))); // NOI18N

		rotuloSenha1.setText("Todos os direitos reservados");

		jLabel1.setText("Raphael Montanari");

		jLabel2.setText("Anderson C. P. Salvati");

		jLabel3.setText("Gabriel L. Bressan");

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
										.add(
												painelFrenteLayout
														.createParallelGroup(
																org.jdesktop.layout.GroupLayout.LEADING)
														.add(
																painelFrenteLayout
																		.createSequentialGroup()
																		.add(
																				30,
																				30,
																				30)
																		.add(
																				painelFrenteLayout
																						.createParallelGroup(
																								org.jdesktop.layout.GroupLayout.LEADING,
																								false)
																						.add(
																								jLabel2)
																						.add(
																								painelFrenteLayout
																										.createParallelGroup(
																												org.jdesktop.layout.GroupLayout.TRAILING)
																										.add(
																												painelFrenteLayout
																														.createSequentialGroup()
																														.add(
																																rotuloSenha)
																														.addPreferredGap(
																																org.jdesktop.layout.LayoutStyle.RELATED)
																														.add(
																																rotuloSenha1))
																										.add(
																												rotuloNome)
																										.add(
																												rotuloIP))
																						.add(
																								painelFrenteLayout
																										.createSequentialGroup()
																										.add(
																												jLabel3)
																										.addPreferredGap(
																												org.jdesktop.layout.LayoutStyle.RELATED,
																												org.jdesktop.layout.GroupLayout.DEFAULT_SIZE,
																												Short.MAX_VALUE)
																										.add(
																												botaoEntrar,
																												org.jdesktop.layout.GroupLayout.PREFERRED_SIZE,
																												72,
																												org.jdesktop.layout.GroupLayout.PREFERRED_SIZE)
																										.add(
																												20,
																												20,
																												20))
																						.add(
																								jLabel1)))
														.add(
																painelFrenteLayout
																		.createSequentialGroup()
																		.add(
																				116,
																				116,
																				116)
																		.add(
																				imagemHermes)))
										.addContainerGap(54, Short.MAX_VALUE)));
		painelFrenteLayout
				.setVerticalGroup(painelFrenteLayout
						.createParallelGroup(
								org.jdesktop.layout.GroupLayout.LEADING)
						.add(
								painelFrenteLayout
										.createSequentialGroup()
										.addContainerGap()
										.add(imagemHermes)
										.addPreferredGap(
												org.jdesktop.layout.LayoutStyle.RELATED)
										.add(rotuloIP)
										.add(
												painelFrenteLayout
														.createParallelGroup(
																org.jdesktop.layout.GroupLayout.LEADING)
														.add(
																painelFrenteLayout
																		.createSequentialGroup()
																		.add(
																				2,
																				2,
																				2)
																		.add(
																				rotuloNome,
																				org.jdesktop.layout.GroupLayout.PREFERRED_SIZE,
																				14,
																				org.jdesktop.layout.GroupLayout.PREFERRED_SIZE))
														.add(
																painelFrenteLayout
																		.createSequentialGroup()
																		.add(
																				18,
																				18,
																				18)
																		.add(
																				painelFrenteLayout
																						.createParallelGroup(
																								org.jdesktop.layout.GroupLayout.BASELINE)
																						.add(
																								rotuloSenha,
																								org.jdesktop.layout.GroupLayout.PREFERRED_SIZE,
																								14,
																								org.jdesktop.layout.GroupLayout.PREFERRED_SIZE)
																						.add(
																								rotuloSenha1))))
										.add(15, 15, 15)
										.add(jLabel2)
										.addPreferredGap(
												org.jdesktop.layout.LayoutStyle.RELATED)
										.add(
												painelFrenteLayout
														.createParallelGroup(
																org.jdesktop.layout.GroupLayout.BASELINE)
														.add(jLabel3).add(
																botaoEntrar))
										.addPreferredGap(
												org.jdesktop.layout.LayoutStyle.RELATED)
										.add(jLabel1).add(51, 51, 51)));

		gridBagConstraints = new java.awt.GridBagConstraints();
		gridBagConstraints.gridx = 0;
		gridBagConstraints.gridy = 0;
		gridBagConstraints.fill = java.awt.GridBagConstraints.BOTH;
		gridBagConstraints.weightx = 1.0;
		gridBagConstraints.weighty = 1.0;
		painelImagem.add(painelFrente, gridBagConstraints);

		imagemFundo.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
		imagemFundo.setIcon(new javax.swing.ImageIcon(getClass().getResource(
				"/imagens/fundoSobre.png"))); // NOI18N
		gridBagConstraints = new java.awt.GridBagConstraints();
		gridBagConstraints.gridx = 0;
		gridBagConstraints.gridy = 0;
		gridBagConstraints.fill = java.awt.GridBagConstraints.BOTH;
		gridBagConstraints.weightx = 1.0;
		gridBagConstraints.weighty = 1.0;
		painelImagem.add(imagemFundo, gridBagConstraints);

		org.jdesktop.layout.GroupLayout layout = new org.jdesktop.layout.GroupLayout(
				getContentPane());
		getContentPane().setLayout(layout);
		layout.setHorizontalGroup(layout.createParallelGroup(
				org.jdesktop.layout.GroupLayout.LEADING).add(painelImagem,
				org.jdesktop.layout.GroupLayout.DEFAULT_SIZE, 381,
				Short.MAX_VALUE));
		layout.setVerticalGroup(layout.createParallelGroup(
				org.jdesktop.layout.GroupLayout.LEADING).add(painelImagem,
				org.jdesktop.layout.GroupLayout.DEFAULT_SIZE, 319,
				Short.MAX_VALUE));

		pack();
	}// </editor-fold>//GEN-END:initComponents

	private void botaoEntrarActionPerformed(java.awt.event.ActionEvent evt) {// GEN-FIRST:event_botaoEntrarActionPerformed
		dispose();
	}// GEN-LAST:event_botaoEntrarActionPerformed

	// Variables declaration - do not modify//GEN-BEGIN:variables
	private javax.swing.JButton botaoEntrar;
	private javax.swing.JLabel imagemFundo;
	private javax.swing.JLabel imagemHermes;
	private javax.swing.JLabel jLabel1;
	private javax.swing.JLabel jLabel2;
	private javax.swing.JLabel jLabel3;
	private javax.swing.JPanel painelFrente;
	private javax.swing.JPanel painelImagem;
	private javax.swing.JLabel rotuloIP;
	private javax.swing.JLabel rotuloNome;
	private javax.swing.JLabel rotuloSenha;
	private javax.swing.JLabel rotuloSenha1;
	// End of variables declaration//GEN-END:variables

}

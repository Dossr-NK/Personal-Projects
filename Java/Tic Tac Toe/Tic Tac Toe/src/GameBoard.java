import javax.swing.*;
import javax.swing.border.Border;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class GameBoard extends JFrame implements ActionListener {

    String let;
    String scoreString;
    boolean playerturn;
    JFrame frame = new JFrame();
    JFrame frame2 = new JFrame();
    JFrame frame3 = new JFrame();
    JPanel topPanel = new JPanel();
    JPanel btPanel = new JPanel();
    JPanel score = new JPanel();
    public static int turns = 0;
    public static JLabel turn = new JLabel();
    public static int xScore = 0;
    public static int oScore = 0;
    public static JButton[] buttons = new JButton[9];

    final Font mainFont = new Font("Montserrat", Font.BOLD, 150);
    final Font smallerFont = new Font("Montserrat", Font.BOLD, 40);
    Border blackline = BorderFactory.createLineBorder(Color.BLACK, 5);
    Border outsideborder = BorderFactory.createEmptyBorder(25, 25, 25, 25);
    Border outsideborder2 = BorderFactory.createEmptyBorder(10, 10, 10, 10);
    Border compBorder = BorderFactory.createCompoundBorder(outsideborder2, blackline);

    public void StartGame() {

        frame.setTitle("TicTacToe");
        frame.setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
        frame.setVisible(true);
        frame.setLayout(new BorderLayout());
        frame.setBackground(new Color(25, 24, 26));

        JButton enter = new JButton("Enter the game!");
        enter.setBorder(outsideborder);
        enter.setFont(new Font("Montserrat", Font.BOLD, 25));
        enter.setForeground(new Color(209, 232, 226));
        enter.setBackground(new Color(44, 53, 49));
        JButton exit = new JButton("Exit the game!");
        exit.setBorder(outsideborder);
        exit.setFont(new Font("Montserrat", Font.BOLD, 25));
        exit.setForeground(new Color(209, 232, 226));
        exit.setBackground(new Color(44, 53, 49));
        JPanel welcomeBtScreen = new JPanel();
        welcomeBtScreen.setLayout(new GridBagLayout());
        GridBagConstraints gbc = new GridBagConstraints();
        gbc.insets = new Insets(0, 50, 10, 50);
        welcomeBtScreen.setBackground(new Color(209, 232, 226));
        welcomeBtScreen.setBorder(outsideborder);
        welcomeBtScreen.add(enter, gbc);
        welcomeBtScreen.add(exit, gbc);

        JPanel welcomePanel = new JPanel();
        JLabel welcome = new JLabel("Welcome To Tic-Tac-Toe!",
                SwingConstants.CENTER);
        welcome.setFont(new Font("Montserrat", Font.BOLD, 50));
        welcome.setForeground(new Color(25, 24, 26));
        welcome.setBorder(BorderFactory.createEmptyBorder(10, 40, 10, 25));
        welcomePanel.setBackground(new Color(209, 232, 226));
        welcomePanel.add(welcome);

        JLabel askforplayer = new JLabel("Who is playing first?",
                SwingConstants.CENTER);
        askforplayer.setBackground(new Color(209, 232, 226));
        askforplayer.setForeground(new Color(25, 24, 26));
        askforplayer.setFont(new Font("Montserrat", Font.BOLD, 30));
        JTextField firstturn = new JTextField();
        firstturn.setSize(150, 20);
        firstturn.setFont(mainFont);
        JPanel firstplayerpanel = new JPanel();
        GridBagConstraints c = new GridBagConstraints();
        firstplayerpanel.setLayout(new GridBagLayout());
        c.weightx = 0.5;
        c.gridx = 1;
        c.gridy = 0;
        firstplayerpanel.add(askforplayer, c);
        c.ipady = 20;
        c.weightx = 0.0;
        c.gridwidth = 3;
        c.gridx = 0;
        c.gridy = 1;
        c.fill = GridBagConstraints.HORIZONTAL;
        c.insets = new Insets(15, 50, 15, 50);
        firstplayerpanel.add(firstturn, c);
        firstplayerpanel.setBackground(new Color(209, 232, 226));

        enter.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String temp = firstturn.getText();
                if (temp.equals("x")) {
                    let = temp.toUpperCase();
                    if (let.equals("X")) {
                        playerturn = true;
                    }
                } else if (temp.equals("o")) {
                    let = temp.toUpperCase();
                    if (let.equals("O")) {
                        playerturn = false;
                    }
                } else {
                    let = temp;
                    if (let.equals("X")) {
                        playerturn = true;
                    }
                }
                turns = 0;
                frame.dispose();
                frame2.setVisible(true);
            }
        });

        exit.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                System.exit(0);
            }
        });

        frame.add(welcomePanel, BorderLayout.NORTH);
        frame.add(firstplayerpanel, BorderLayout.CENTER);
        frame.add(welcomeBtScreen, BorderLayout.SOUTH);
        frame.pack();
        frame.setLocationRelativeTo(null);
    }

    public GameBoard() {

        frame2.setVisible(false);
        StartGame();

        turn.setFont(smallerFont);
        turn.setForeground(new Color(209, 232, 226));
        turn.setText(let + "'s Turn.");
        turn.setBorder(outsideborder);
        topPanel.setBackground(new Color(44, 53, 49));
        topPanel.setBorder(compBorder);
        topPanel.add(turn);

        btPanel.setLayout(new GridLayout(3, 3));
        btPanel.setBackground(new Color(44, 53, 49));
        btPanel.setBorder(outsideborder);

        for (int i = 0; i < 9; i++) {
            buttons[i] = new JButton();
            btPanel.add(buttons[i]);
            buttons[i].setFont(mainFont);
            buttons[i].setBorder(BorderFactory.createLineBorder(Color.BLACK, 2));
            buttons[i].setBackground(Color.WHITE);
            buttons[i].setFocusable(false);
            buttons[i].addActionListener(this);
        }

        JLabel xWinCount = new JLabel();
        xWinCount.setText("X: " + xScore + "        ");
        xWinCount.setFont(smallerFont);
        xWinCount.setBorder(outsideborder);
        xWinCount.setForeground(new Color(209, 232, 226));
        JLabel oWinCount = new JLabel();
        oWinCount.setText("O: " + oScore);
        oWinCount.setFont(smallerFont);
        oWinCount.setBorder(outsideborder);
        oWinCount.setForeground(new Color(209, 232, 226));
        score.setBackground(new Color(44, 53, 49));
        score.setBorder(compBorder);
        score.add(xWinCount);
        score.add(oWinCount);

        frame2.setTitle("TicTacToe");
        frame2.setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
        frame2.setLayout(new BorderLayout());
        frame2.setBackground(new Color(44, 53, 49));
        frame2.setSize(700, 800);
        frame2.setMinimumSize(new Dimension(300, 400));

        frame2.add(topPanel, BorderLayout.NORTH);
        frame2.add(btPanel, BorderLayout.CENTER);
        frame2.add(score, BorderLayout.SOUTH);
        frame2.setLocationRelativeTo(null);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        for (int i = 0; i < 9; i++) {
            if (e.getSource() == buttons[i]) {
                if (playerturn) {
                    if (buttons[i].getText() == "") {
                        buttons[i].setText("X");
                        buttons[i].setBackground(new Color(17, 100, 102));
                        buttons[i].setForeground(new Color(209, 232, 226));
                        playerturn = false;
                        turn.setText("O's Turn.");
                        turns++;
                        Logic.matchCheck();
                    }
                } else {
                    if (buttons[i].getText() == "") {
                        buttons[i].setText("O");
                        buttons[i].setBackground(new Color(255, 150, 150));
                        buttons[i].setForeground(new Color(209, 232, 226));
                        playerturn = true;
                        turn.setText("X's Turn.");
                        turns++;
                        Logic.matchCheck();
                    }
                }
            }
        }
    }

    public void resetGame(String s) {

        frame2.dispose();
        frame3 = new JFrame();

        scoreString = "X: " + xScore + "    O: " + oScore;

        frame3.setTitle("TicTacToe");
        frame3.setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
        frame3.setVisible(true);
        frame3.setLayout(new BorderLayout());
        frame3.setBackground(new Color(217, 205, 202));

        JLabel win = new JLabel(s);
        win.setFont(new Font("Montserrat", Font.BOLD, 75));
        win.setBorder(outsideborder);
        win.setForeground(new Color(44, 53, 49));
        JPanel winPanel = new JPanel();
        winPanel.setBackground(new Color(209, 232, 226));
        winPanel.add(win);

        JLabel score = new JLabel(scoreString, SwingConstants.CENTER);
        score.setFont(smallerFont);
        score.setForeground(new Color(44, 53, 49));
        JPanel scorePanel = new JPanel();
        scorePanel.setBackground(new Color(209, 232, 226));
        scorePanel.add(score);


        JButton restart = new JButton("Restart!");
        restart.setFont(new Font("Montserrat", Font.BOLD, 25));
        restart.setBorder(outsideborder);
        restart.setForeground(new Color(209, 232, 226));
        restart.setBackground(new Color(44, 53, 49));
        JButton exit = new JButton("Exit.");
        exit.setFont(new Font("Montserrat", Font.BOLD, 25));
        exit.setBorder(outsideborder);
        exit.setForeground(new Color(209, 232, 226));
        exit.setBackground(new Color(44, 53, 49));
        JPanel endBtScreen = new JPanel();
        endBtScreen.setLayout(new GridBagLayout());
        GridBagConstraints gbc = new GridBagConstraints();
        gbc.insets = new Insets(0, 50, 10, 50);
        endBtScreen.setBackground(new Color(209, 232, 226));
        endBtScreen.setBorder(outsideborder);
        endBtScreen.add(restart, gbc);
        endBtScreen.add(exit, gbc);

        restart.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                frame3.dispose();
                new GameBoard();
            }
        });

        exit.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                System.exit(0);
            }
        });

        frame3.add(winPanel, BorderLayout.NORTH);
        frame3.add(scorePanel, BorderLayout.CENTER);
        frame3.add(endBtScreen, BorderLayout.SOUTH);
        frame3.pack();
        frame3.setLocationRelativeTo(null);
    }
}
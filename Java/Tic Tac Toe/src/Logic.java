
import java.awt.*;

public class Logic{

    static GameBoard obj = new GameBoard();

    public static void matchCheck() {
        if ((GameBoard.buttons[0].getText() == "X") && (GameBoard.buttons[1].getText() == "X") && (GameBoard.buttons[2].getText() == "X")) {
            xWins(0, 1, 2);
        }else if ((GameBoard.buttons[0].getText() == "X") && (GameBoard.buttons[4].getText() == "X") && (GameBoard.buttons[8].getText() == "X")) {
            xWins(0, 4, 8);
        }else if ((GameBoard.buttons[0].getText() == "X") && (GameBoard.buttons[3].getText() == "X") && (GameBoard.buttons[6].getText() == "X")) {
            xWins(0, 3, 6);
        }else if ((GameBoard.buttons[1].getText() == "X") && (GameBoard.buttons[4].getText() == "X") && (GameBoard.buttons[7].getText() == "X")) {
            xWins(1, 4, 7);
        }else if ((GameBoard.buttons[2].getText() == "X") && (GameBoard.buttons[4].getText() == "X") && (GameBoard.buttons[6].getText() == "X")) {
            xWins(2, 4, 6);
        }else if ((GameBoard.buttons[2].getText() == "X") && (GameBoard.buttons[5].getText() == "X") && (GameBoard.buttons[8].getText() == "X")) {
            xWins(2, 5, 8);
        }else if ((GameBoard.buttons[3].getText() == "X") && (GameBoard.buttons[4].getText() == "X") && (GameBoard.buttons[5].getText() == "X")) {
            xWins(3, 4, 5);
        }else if ((GameBoard.buttons[6].getText() == "X") && (GameBoard.buttons[7].getText() == "X") && (GameBoard.buttons[8].getText() == "X")) {
            xWins(6, 7, 8);
        }else if ((GameBoard.buttons[0].getText() == "O") && (GameBoard.buttons[1].getText() == "O") && (GameBoard.buttons[2].getText() == "O")) {
            oWins(0, 1, 2);
        }else if ((GameBoard.buttons[0].getText() == "O") && (GameBoard.buttons[3].getText() == "O") && (GameBoard.buttons[6].getText() == "O")) {
            oWins(0, 3, 6);
        }else if ((GameBoard.buttons[0].getText() == "O") && (GameBoard.buttons[4].getText() == "O") && (GameBoard.buttons[8].getText() == "O")) {
            oWins(0, 4, 8);
        }else if ((GameBoard.buttons[1].getText() == "O") && (GameBoard.buttons[4].getText() == "O") && (GameBoard.buttons[7].getText() == "O")) {
            oWins(1, 4, 7);
        }else if ((GameBoard.buttons[2].getText() == "O") && (GameBoard.buttons[4].getText() == "O") && (GameBoard.buttons[6].getText() == "O")) {
            oWins(2, 4, 6);
        }else if ((GameBoard.buttons[2].getText() == "O") && (GameBoard.buttons[5].getText() == "O") && (GameBoard.buttons[8].getText() == "O")) {
            oWins(2, 5, 8);
        }else if ((GameBoard.buttons[3].getText() == "O") && (GameBoard.buttons[4].getText() == "O") && (GameBoard.buttons[5].getText() == "O")) {
            oWins(3, 4, 5);
        }else if ((GameBoard.buttons[6].getText() == "O") && (GameBoard.buttons[7].getText() == "O") && (GameBoard.buttons[8].getText() == "O")) {
            oWins(6, 7, 8);
        }else if(GameBoard.turns == 9) {
            GameBoard.turn.setText("Match Tie");
            obj.resetGame("Match Tie!");
        }
    }

    public static void xWins(int x1, int x2, int x3) {
        GameBoard.buttons[x1].setBackground(Color.GREEN);
        GameBoard.buttons[x2].setBackground(Color.GREEN);
        GameBoard.buttons[x3].setBackground(Color.GREEN);
        GameBoard.turns = 0;
        ++GameBoard.xScore;
        for (int i = 0; i < 9; i++) {
            GameBoard.buttons[i].setEnabled(false);
        }
        obj.resetGame("X Wins!");
    }

    public static void oWins(int x1, int x2, int x3) {
        GameBoard.buttons[x1].setBackground(Color.GREEN);
        GameBoard.buttons[x2].setBackground(Color.GREEN);
        GameBoard.buttons[x3].setBackground(Color.GREEN);
        GameBoard.turns = 0;
        ++GameBoard.oScore;
        for (int i = 0; i < 9; i++) {
            GameBoard.buttons[i].setEnabled(false);
        }
        obj.resetGame("O Wins!");
    }
}
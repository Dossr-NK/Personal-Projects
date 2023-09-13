import java.util.Scanner;

public class Calculator {

    static Scanner main = new Scanner(System.in);
    static double num1;
    static double num2;

    public static double add() {
        double tempNum = num1 + num2;
        return tempNum;
    }

    public static double sub() {
        double tempNum = num1 - num2;
        return tempNum;
    }

    public static double multi() {
        double tempNum = num1 * num2;
        return tempNum;
    }

    public static double div() {
        double tempNum = num1 / num2;
        return tempNum;
    }

    public static double mod() {
        double tempNum = num1 % num2;
        return tempNum;
    }

    public static double pow() {
        double tempNum = Math.pow(num1, num2);
        return tempNum;
    }

    public static void sqrt() {
        double tempNum1 = Math.sqrt(num1);
        double tempNum2 = Math.sqrt(num2);
        System.out.println("Square root of first number: " + tempNum1);
        System.out.println("Square root of second number: " + tempNum2);
    }

    public static String binary() {
        String temp = "", rev = "";
        char ch;
        int i;
        int temp1 = (int) num1;
        int temp2 = temp1;

        while (temp2 != 0) {
            temp2 = temp1 / 2;
            temp1 %= 2;
            char a = (char) (temp1 + '0');
            temp += a;
            temp1 = temp2;
        }
        for (i = 0; i < temp.length(); i++) {
            ch = temp.charAt(i);
            rev = ch + rev;
        }
        return rev;
    }

    public static void cos() {
        double tempNum1 = Math.cos(num1);
        double tempNum2 = Math.cos(num2);
        System.out.println("cos(" + num1 + ") = " + tempNum1);
        System.out.println("cos(" + num2 + ") = " + tempNum2);
    }

    public static void sin() {
        double tempNum1 = Math.sin(num1);
        double tempNum2 = Math.sin(num2);
        System.out.println("sin(" + num1 + ") = " + tempNum1);
        System.out.println("sin(" + num2 + ") = " + tempNum2);
    }

    public static void tan() {
        double tempNum1 = Math.tan(num1);
        double tempNum2 = Math.tan(num2);
        System.out.println("tan(" + num1 + ") = " + tempNum1);
        System.out.println("tan(" + num2 + ") = " + tempNum2);
    }

    public static void cot() {
        double tempNum1 = 1.0 / Math.tan(num1);
        double tempNum2 = 1.0 / Math.tan(num2);
        System.out.println("cot(" + num1 + ") = " + tempNum1);
        System.out.println("cot(" + num2 + ") = " + tempNum2);
    }

    public static void csc() {
        double tempNum1 = 1.0 / Math.sin(num1);
        double tempNum2 = 1.0 / Math.sin(num2);
        System.out.println("csc(" + num1 + ") = " + tempNum1);
        System.out.println("csc(" + num2 + ") = " + tempNum2);
    }

    public static void sec() {
        double tempNum1 = 1.0 / Math.cos(num1);
        double tempNum2 = 1.0 / Math.cos(num2);
        System.out.println("sec(" + num1 + ") = " + tempNum1);
        System.out.println("sec(" + num2 + ") = " + tempNum2);
    }

    public static void acos() {
        double tempNum1 = Math.acos(num1);
        double tempNum2 = Math.acos(num2);
        System.out.println("arccos(" + num1 + ") = " + tempNum1);
        System.out.println("arccos(" + num2 + ") = " + tempNum2);
    }

    public static void asin() {
        double tempNum1 = Math.asin(num1);
        double tempNum2 = Math.asin(num2);
        System.out.println("arcsin(" + num1 + ") = " + tempNum1);
        System.out.println("arcsin(" + num2 + ") = " + tempNum2);
    }

    public static void atan() {
        double tempNum1 = Math.atan(num1);
        double tempNum2 = Math.atan(num2);
        System.out.println("arctan(" + num1 + ") = " + tempNum1);
        System.out.println("arctan(" + num2 + ") = " + tempNum2);
    }

    public static void main(String[] args) {
        int Op;
        System.out.println(
                "1. Add, 2. Sub, 3. Div, 4. Multi, 5. Power(First Number to the power of Second Number), 6. Square Root, 7. Modulus, 8. Binary(Only first number)");
        System.out
                .println("9. Cos, 10. Sin, 11. Tan, 12. Cot, 13. Csc, 14. Sec, 15. ArcCos, 16. ArcSin, or 17. ArcTan");
        System.out.println("What number of operation do you want to do? ");
        Op = main.nextInt();
        System.out.println("Enter first number: ");
        num1 = main.nextDouble();
        System.out.println("Enter second number: ");
        num2 = main.nextDouble();

        switch (Op) {
            case 1:
                System.out.println(add());
                break;
            case 2:
                System.out.println(sub());
                break;
            case 3:
                System.out.println(div());
                break;
            case 4:
                System.out.println(multi());
                break;
            case 5:
                System.out.println(pow());
                break;
            case 6:
                sqrt();
                break;
            case 7:
                System.out.println(mod());
                break;
            case 8:
                System.out.println("Binary value of first number: " + binary());
                break;
            case 9:
                cos();
                break;
            case 10:
                sin();
                break;
            case 11:
                tan();
                break;
            case 12:
                cot();
                break;
            case 13:
                csc();
                break;
            case 14:
                sec();
                break;
            case 15:
                acos();
                break;
            case 16:
                asin();
                break;
            case 17:
                atan();
                break;
            default:
                System.out.println("That Operation does not exist within this program.");
        }
    }
}

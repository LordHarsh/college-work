import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Arithmetic {
    private JFrame frame;
    private JTextField numField1, numField2;
    private JButton addButton, subButton, mulButton, divButton, exitButton;

    public Arithmetic() {
        frame = new JFrame("Arithmetic Calculator");
        frame.setLayout(new GridLayout(4, 2));

        JLabel label1 = new JLabel("Enter Number 1:");
        numField1 = new JTextField();
        JLabel label2 = new JLabel("Enter Number 2:");
        numField2 = new JTextField();

        addButton = new JButton("Addition");
        subButton = new JButton("Subtraction");
        mulButton = new JButton("Multiplication");
        divButton = new JButton("Division");
        exitButton = new JButton("Exit");

        addButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                performOperation("Addition", "+");
            }
        });

        subButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                performOperation("Subtraction", "-");
            }
        });

        mulButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                performOperation("Multiplication", "*");
            }
        });
        divButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                performOperation("Division", "/");
            }
        });

        exitButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                System.exit(0);
            }
        });

        frame.add(label1);
        frame.add(numField1);
        frame.add(label2);
        frame.add(numField2);
        frame.add(addButton);
        frame.add(subButton);
        frame.add(mulButton);
        frame.add(divButton);
        frame.add(exitButton);

        frame.setSize(400, 200);
        frame.setVisible(true);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }

    private void performOperation(String operationName, String operator) {
        try {
            double num1 = Double.parseDouble(numField1.getText());
            double num2 = Double.parseDouble(numField2.getText());

            double result = 0;
            switch (operator) {
                case "+":
                    result = num1 + num2;
                    break;
                case "-":
                    result = num1 - num2;
                    break;
                case "*":
                    result = num1 * num2;
                    break;
                case "/":
                    if (num2 == 0) {
                        JOptionPane.showMessageDialog(frame, "Division by zero is not allowed.");
                        return;
                    }
                    result = num1 / num2;
                    break;
            }

            JOptionPane.showMessageDialog(frame, operationName + " of two Numbers: " + result);
        } catch (NumberFormatException e) {
            JOptionPane.showMessageDialog(frame, "Invalid input. Please enter valid numbers.");
        }
    }

    public static void main(String[] args) {
        new Arithmetic();
    }
}

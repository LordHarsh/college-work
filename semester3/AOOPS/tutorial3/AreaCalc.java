import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class AreaCalc {
    private JFrame frame;
    private JTextField inputField1, inputField2;
    private JButton triangleButton, squareButton, rectangleButton, circleButton, exitButton;

    public AreaCalc() {
        frame = new JFrame("Geometry Calculator");
        frame.setLayout(new GridLayout(5, 2));

        JLabel label1 = new JLabel("Enter Value 1:");
        inputField1 = new JTextField();
        JLabel label2 = new JLabel("Enter Value 2 (if needed):");
        inputField2 = new JTextField();

        triangleButton = new JButton("Area of Triangle");
        squareButton = new JButton("Area of Square");
        rectangleButton = new JButton("Area of Rectangle");
        circleButton = new JButton("Area of Circle");
        exitButton = new JButton("Exit");

        triangleButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                calculateTriangleArea();
            }
        });

        squareButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                calculateSquareArea();
            }
        });

        rectangleButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                calculateRectangleArea();
            }
        });
        circleButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                calculateCircleArea();
            }
        });

        exitButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                System.exit(0);
            }
        });

        frame.add(label1);
        frame.add(inputField1);
        frame.add(label2);
        frame.add(inputField2);
        frame.add(triangleButton);
        frame.add(squareButton);
        frame.add(rectangleButton);
        frame.add(circleButton);
        frame.add(exitButton);

        frame.setSize(400, 200);
        frame.setVisible(true);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }
    private void calculateTriangleArea() {
        try {
            double base = Double.parseDouble(inputField1.getText());
            double height = Double.parseDouble(inputField2.getText());

            double area = 0.5 * base * height;

            JOptionPane.showMessageDialog(frame, "Area of Triangle = " + area);
        } catch (NumberFormatException e) {
            JOptionPane.showMessageDialog(frame, "Invalid input. Please enter valid numbers.");
        }
    }

    private void calculateSquareArea() {
        try {
            double side = Double.parseDouble(inputField1.getText());

            double area = side * side;

            JOptionPane.showMessageDialog(frame, "Area of Square = " + area);
        } catch (NumberFormatException e) {
            JOptionPane.showMessageDialog(frame, "Invalid input. Please enter a valid number.");
        }
    }
    private void calculateRectangleArea() {
        try {
            double length = Double.parseDouble(inputField1.getText());
            double width = Double.parseDouble(inputField2.getText());

            double area = length * width;

            JOptionPane.showMessageDialog(frame, "Area of Rectangle = " + area);
        } catch (NumberFormatException e) {
            JOptionPane.showMessageDialog(frame, "Invalid input. Please enter valid numbers.");
        }
    }

    private void calculateCircleArea() {
        try {
            double radius = Double.parseDouble(inputField1.getText());

            double area = Math.PI * radius * radius;

            JOptionPane.showMessageDialog(frame, "Area of Circle = " + area);
        } catch (NumberFormatException e) {
            JOptionPane.showMessageDialog(frame, "Invalid input. Please enter a valid number.");
        }
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(new Runnable() {
            public void run() {
                new AreaCalc();
            }
        });
    }
}
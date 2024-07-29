import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class RegistrationForm {
    private JFrame frame;
    private JPanel panel;
    private JLabel nameLabel, emailLabel, passwordLabel;
    private JTextField nameField, emailField;
    private JPasswordField passwordField;
    private JButton submitButton;

    public RegistrationForm() {
        frame = new JFrame("Registration Form");
        panel = new JPanel();
        panel.setLayout(new GridLayout(4, 2));

        nameLabel = new JLabel("Name:");
        emailLabel = new JLabel("Email:");
        passwordLabel = new JLabel("Password:");

        nameField = new JTextField();
        emailField = new JTextField();
        passwordField = new JPasswordField();

        submitButton = new JButton("Submit");
        submitButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                submitRegistration();
            }
        });

        panel.add(nameLabel);
        panel.add(nameField);
        panel.add(emailLabel);
        panel.add(emailField);
        panel.add(passwordLabel);
        panel.add(passwordField);
        panel.add(new JLabel()); // Empty label for spacing
        panel.add(submitButton);

        frame.add(panel);
        frame.setSize(300, 200);
        frame.setVisible(true);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }

    private void submitRegistration() {
        String name = nameField.getText();
        String email = emailField.getText();
        String password = new String(passwordField.getPassword());

        // You can perform further actions here, such as validating input and saving data to a database.

        JOptionPane.showMessageDialog(frame, "Registration submitted:\nName: " + name + "\nEmail: " + email);

        // Clear the fields after submission
        nameField.setText("");
        emailField.setText("");
        passwordField.setText("");
    }

    public static void main(String[] args) {
        new RegistrationForm();
    }
}
/* TemperatureConverter.java */
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class TemperatureConverter extends JFrame implements ActionListener {
    private JLabel inputLabel, resultLabel;
    private JTextField inputField, resultField;
    private JButton celsiusToFahrenheit, fahrenheitToCelsius;
    
    public TemperatureConverter() {
        setTitle("Temperature Converter");
        setSize(400, 200);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new GridLayout(3, 2, 10, 10));
        
        inputLabel = new JLabel("Enter Temperature:", SwingConstants.CENTER);
        inputField = new JTextField();
        
        resultLabel = new JLabel("Result:", SwingConstants.CENTER);
        resultField = new JTextField();
        resultField.setEditable(false);
        
        celsiusToFahrenheit = new JButton("Celsius to Fahrenheit");
        fahrenheitToCelsius = new JButton("Fahrenheit to Celsius");
        
        celsiusToFahrenheit.addActionListener(this);
        fahrenheitToCelsius.addActionListener(this);
        
        add(inputLabel);
        add(inputField);
        add(resultLabel);
        add(resultField);
        add(celsiusToFahrenheit);
        add(fahrenheitToCelsius);
        
        setVisible(true);
    }
    
    public void actionPerformed(ActionEvent e) {
        try {
            double temp = Double.parseDouble(inputField.getText());
            double convertedTemp;
            
            if (e.getSource() == celsiusToFahrenheit) {
                convertedTemp = (temp * 9/5) + 32;
                resultField.setText(String.format("%.2f °F", convertedTemp));
            } else {
                convertedTemp = (temp - 32) * 5/9;
                resultField.setText(String.format("%.2f °C", convertedTemp));
            }
        } catch (NumberFormatException ex) {
            JOptionPane.showMessageDialog(this, "Please enter a valid number!", 
                                        "Error", JOptionPane.ERROR_MESSAGE);
        }
    }
    
    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> new TemperatureConverter());
    }
}
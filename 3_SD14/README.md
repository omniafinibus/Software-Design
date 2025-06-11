# Week 1-2

## Assignment 1: Windows Welcome Application

Create a Windows Forms Application that serves as a welcome screen. Add a `PictureBox` to the form to display an image—this could be a photo of yourself or something you enjoy. Add a `Label` with a friendly message to greet the user.

---

## Assignment 2: GUI Design in Visual Studio

Learn the basics of designing a Graphical User Interface (GUI) in Visual Studio. Follow these steps to build your first interactive application:

1. **Form Title**: Select the form and change its `Text` property from the default "Form1" to something like "My First Program".

2. **Button Setup**: Add a `Button` control. Change its background color through the `BackColor` property. Double-click the button to create a `Click` event handler, and insert code such as:

   ```csharp
   MessageBox.Show("My name is ...");
   ```

3. **TrackBar Setup**: Add a `TrackBar` control. Set the `Minimum` to 0, `Maximum` to 100, and `Value` to 20. Optionally, adjust its `BackColor`.

4. **ProgressBar and Label**: Add a `ProgressBar` and a `Label` to your form. Set the same `Minimum` and `Maximum` values as the `TrackBar`. Increase the font size of the label for visibility.

5. **Synchronizing Values**: Double-click the `TrackBar` to generate a `Scroll` event. In the handler, add:

   ```csharp
   progressBar1.Value = trackBar1.Value;
   label1.Text = trackBar1.Value.ToString();
   ```

6. **RadioButtons**: Add three `RadioButton` controls. Set their `Text` to indicate color choices (e.g., "Make it red"). Double-click each to generate `CheckedChanged` methods, and set the form’s background color based on which one is selected:

   ```csharp
   this.BackColor = Color.Red;  // Example for one button
   ```

7. **Publishing**: When finished, go to the "Build" menu and select "Publish..." to generate setup files for distribution. Choose an empty folder to save the output.

---

## Assignment 3: Euro–Dollar Converter

Develop a currency converter for a travel agency. Create a Windows Forms Application with the following elements:

* **NumericUpDown** control for exchange rate selection (e.g., 1.05). Set its decimal precision to two digits, and make it increase/decrease by 0.01.
* Two `TextBox` controls—one for Euros, one for Dollars.
* Two `Button` controls:

  * One button converts Euros to Dollars using the exchange rate.
  * The other converts Dollars to Euros.

### Data Conversion in C#:

* From string to double:

  ```csharp
  double value = Convert.ToDouble(textBox1.Text);
  ```
* From double to string:

  ```csharp
  textBox1.Text = value.ToString();
  ```

Avoid entering non-numeric strings in the `TextBox` to prevent errors.

### Optional:

* Add more currencies (e.g., Pounds, Yuan).
* Use `ComboBox` controls for selecting different currencies for both input and output.

---

## Assignment 4: Distance per Tank of Gas

Create a program to calculate travel distance based on fuel usage. A car with a 20-gallon tank consumes:

* 21.5 mpg in town
* 26.8 mpg on highways

Design a simple GUI where users input the number of gallons and receive the calculated distances for both driving modes.

---

## Assignment 5 (Optional): Fuzzy Dice Order Form

Build an order form for fuzzy dice:

* **Input Fields**: `TextBox` controls for order number, customer name, and shipping address. Use placeholder text to indicate their purpose.
* **Dice Options**: Use `CheckBox` controls for color choices and additional `TextBox` controls to input quantities.
* **Pricing Logic**:

  * 5% tax rate
  * \$1.50 shipping for 20 dice or fewer; free shipping for more than 20
* **Updates**: Automatically recalculate total, tax, and shipping when any quantity changes.
* **Reset Button**: Include a button to reset all fields to default values.

---

## Assignment 6: Sorting Strings

Make a program where the user enters strings into a `TextBox`, which are then added to a `ListBox`. Ensure the `ListBox` stays sorted by enabling its `Sorted` property.

---

## Assignment 7: Using ComboBoxes

Create a program that:

* Displays 15 names in a `ComboBox`.
* When a name is selected, shows a message box with the selected name.
* Removes the selected name from the `ComboBox`.

---

## Assignment 8: ComboBoxes and ListBoxes Combined

Extend Assignment 7:

* Add a `ListBox`.
* When an item is selected from the `ComboBox`, move it to the `ListBox`.
* If the `ComboBox` is empty, show a message and terminate the program using:

  ```csharp
  Application.Exit();
  ```

---

## Assignment 9: Student Marks Processor

Create a program to process student grades. The GUI should include:

* Left Panel: A `ListBox`, a `TextBox` for entering marks, and two buttons—"Add" and "Clear".
* Right Panel: Display the number of marks, number of pass/fail grades, and the average in `TextBox` controls.

### Key Requirements:

* Marks are added individually via the `TextBox` and the "Add" button.
* The "Result" button calculates statistics based only on the `ListBox` contents.
* Use red font or background for the fail count display.
* Prevent resizing of the form by setting `ControlBox = false` and disabling maximize/minimize.

---

# Week 3

## Final Assignment: Software Design

Begin designing your final project (related to the SD22 course). The design must include:

* **Global Design**: Show overall modularity and structure of the system.
* **Communication Design**: Clearly define how the Arduino communicates with the Windows Forms application. Include:

  * Message format
  * Direction of communication
  * Message timing
* **Flowcharts**: Detailed flowcharts for each module. Focus on logical flow—not code.

**Important**: Do *not* start coding yet. Submit this design digitally by the end of week 4.

---

## Assignment 1: Windows GUI → Arduino Communication

Using the provided example code (or your own), create:

* **Arduino Setup**:

  * Circuit with at least two LEDs.
  * Arduino code that receives data and controls LEDs accordingly.
* **Windows App**:

  * GUI with buttons or other controls that send commands (bytes or strings) to the Arduino.

Test functionality using Visual Studio’s Serial Monitor or a terminal emulator.

---

## Assignment 2: Arduino → Windows GUI Communication

Extend your setup to allow the Arduino to send data *back* to the Windows GUI:

* Connect buttons to the Arduino.
* Modify the Arduino code to detect button presses and send messages.
* In your Windows Forms Application, update the GUI (e.g., toggle checkboxes) based on these messages.
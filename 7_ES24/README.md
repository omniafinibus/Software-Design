# Hexapod Controller

This assignment was part of an **embedded systems course**, where the goal was to design and build a **controllable walking robot**—specifically, a **hexapod** (a robot with six legs). The main challenge wasn’t just getting the robot to move, but building a full system that could receive commands remotely and react in real time.

## Objective

Design and implement a system that allows a user to:

* **Control a hexapod robot wirelessly**
* **Send commands from a computer or phone**
* **Receive feedback from the robot**
* **Easily test, debug, and adjust settings**

## What Was Built

1. **The Robot (Hexapod)**

   * A physical walking robot with six legs, controlled by small motors.

2. **Bluetooth Communication**

   * The robot can receive instructions from a nearby device via Bluetooth.
   * Custom communication rules were created to ensure reliable, structured messages.

3. **Command Shell**

   * A simple terminal interface lets a user send commands directly to the robot using text (like “start” or “test”).
   * It provides feedback messages, so the user knows what the robot is doing or if something went wrong.

4. **Modular Software**

   * Different parts of the robot—like the motors, sensors, and Bluetooth—were organized into separate building blocks in code.
   * This makes the system easier to understand, maintain, and expand in the future.

5. **Testing Tools**

   * A series of test cases were run to make sure Bluetooth messages were received correctly, and the robot responded as expected.

## Key Achievements

* **Fully functional Bluetooth communication system**
  Custom packets with error checking make sure messages are accurate.

* **Interactive shell for debugging and control**
  Makes it easy to experiment with the robot without needing to reprogram it.

* **Prepared for movement and sensing**
  Although some hardware functions like the ultrasonic sensor were marked "to be done," the foundation was laid for full control and interaction.

Sure! Here's a concise section that explains the **technical skills and knowledge** required to write and understand the code in relation to what it does:


## Technical Skills and Knowledge Applied

Writing the hexapod controller software required a solid understanding of both **embedded systems programming** and **digital communication protocols**. Specifically, the code demonstrates the following key skills:

### **Embedded C Programming**

* The code is written in **C**, the standard language for embedded systems.
* It uses **low-level control** over hardware components like UART (serial communication), which requires understanding of registers, memory buffers, and interrupts.

### **Microcontroller Configuration (PIC32)**

* The project uses a **PIC32MX370** microcontroller. Setting this up involves:
c
  * Configuring communication speeds (e.g., UART baud rate)
  * Managing hardware-specific libraries like `xc.h` and setting compiler options
  * Handling digital I/O, PWM outputs, and timers for real-time control

### **Serial and Bluetooth Communication**

* The `bluetooth_ReceivePackage()` function handles structured packet reception, meaning students needed to know:

  * How to **design custom protocols** (with start bytes, source/destination, length, checksums)
  * How to implement **packet validation**, including checksum logic
  * How to respond based on partial or complete reception of data

### **State Machine and Event Handling**

* The code uses **switch-case structures** to manage incoming Bluetooth data and user commands.
* This reflects understanding of **event-driven programming**, where different responses are triggered by external inputs (e.g., a Bluetooth message or shell command).

### **Debugging and User Interaction**

* The command shell requires interpreting user inputs in real time, managing buffers, and providing readable feedback.
* This involves:

  * Managing memory safely with strings and buffers
  * Using UART output for **live debugging**
  * Implementing a **user-friendly command interface** (even with playful output)

### **Modular Software Design**

* Functions are spread across custom libraries (`BT2.h`, `shell.h`, `sequencer.h`, etc.).
* This shows experience in **organizing code into reusable components**, which is crucial for larger embedded projects.


This section can help instructors or reviewers see the depth of understanding required—and applied—when building the software. Let me know if you’d like it tailored for a report, CV, or portfolio.

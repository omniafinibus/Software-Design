## Assignment 1: TestServo

This assignment introduces the use of a modular software architecture to control a servo motor using the Basys MX3 board. You begin by building foundational blocks and libraries for hardware interaction, and design a simple control system that adjusts the servo’s angle using button presses. The servo must respond predictably to input, including handling simultaneous button presses, and maintain its position between updates. The task emphasizes system structuring, real-time behavior, and signal integrity.

## Assignment 2: ServoControl

Expanding on the previous assignment, this task adds persistence and dynamic motion to servo control. The servo’s last position is saved to onboard flash memory, allowing it to be restored after a restart. The servo now moves gradually when buttons are held, simulating real-time movement. Additionally, the task introduces callback functions for handling interrupts more cleanly, reinforcing the separation of hardware and application logic in embedded software design.

## Assignment 3: Remote Login

In this assignment, UART communication is integrated into the servo control system. The user can interact with the system through a terminal on a PC by sending text-based commands. The system responds with status updates or executes servo commands based on input. This enables remote monitoring and control, simulating a shell interface where the microcontroller acts like a command-line device. It introduces string parsing, terminal interaction, and modular command processing.

## Assignment 4: Ultrasound I2C

This task adds a distance-sensing feature to the system using an ultrasonic sensor via I2C. A new command is added to the terminal interface, allowing the user to retrieve distance measurements. It teaches how to interface with I2C peripherals, manage timing without blocking the processor, and integrate sensor data into an existing system. The design continues to emphasize structured modularity and real-time responsiveness.

## Assignment 5: HTML

Shifting toward connectivity, this assignment introduces basic web development using HTML and CSS. You create a static web page designed to control and monitor the servo and sensor system. The goal is to define the structure and styling of a user interface that will later be deployed to a microcontroller-based web server. It focuses on layout, aesthetics, and preparing for interactive web control in later assignments.

## Assignment 6: Web Server

This assignment transitions the system into the domain of embedded networking. Using a web server framework, you run a basic server on the Basys MX3 board. The task explores how web content can be served directly from the microcontroller and how dynamic variables can be embedded into pages. It introduces the concept of embedded TCP/IP stacks and prepares the groundwork for full system control via a browser.

## Assignment 7: Web Control

In this final assignment, the previously created HTML interface becomes fully interactive. The system responds to browser-based commands to control the servo and read the distance sensor. The web server processes form submissions and updates the page with current sensor values. This brings the entire system online, completing the transition from local physical interaction to full web-based control and monitoring, uniting embedded programming, networking, and interface design.

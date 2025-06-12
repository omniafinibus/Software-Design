# Assignment 1: Our First Program

This assignment introduces you to bare-metal embedded programming using the MPLAB X IDE and the PIC32 microcontroller on the Basys MX3 board. The goal is to build a simple counter that uses onboard LEDs to display values from 0 to 15. You will interact with buttons to increment or decrement the counter, and ensure the system wraps around at the boundaries. You’ll also explore how to organize code, structure embedded applications, and apply basic debugging and debounce techniques.

## Assignment 2: Knight Rider Part Two (Without Interrupts)

Building on a previous assignment, this task requires implementing a state-based LED animation similar to the Knight Rider effect. The system transitions between multiple states in response to specific button press sequences. Each state triggers distinct LED patterns and display messages, simulating a conversation with the fictional KITT car. This assignment focuses on state machine design, timed LED transitions, and structured behavior without using interrupts.

## Assignment 3: RGB LED Controller

This assignment involves controlling an RGB LED by generating Pulse-Width Modulated (PWM) signals. The goal is to cycle through a sequence of color combinations and smoothly fade each color in and out over a fixed time period. It emphasizes time-based transitions, color mixing using RGB components, and software-controlled brightness modulation. It serves as a practical exercise in PWM control and LED behavior modeling.

## Assignment 4: Digital Voltmeter

In this assignment, you will develop a simple digital voltmeter using the onboard analog-to-digital converter (ADC). The system reads voltages from two analog input channels and displays the measurements on an LCD screen. You’ll ensure the readings are refreshed regularly and presented with appropriate precision. This task emphasizes analog signal sampling, data presentation, and user feedback through a display interface.
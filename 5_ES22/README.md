## Assignment 1: Knight Rider – Revisited

This assignment builds on the previous Knight Rider task but introduces interrupt-driven control to achieve more accurate timing and responsiveness. Instead of using delays or blocking loops, you now manage LED animations and button inputs through timers and interrupt service routines. This ensures the system runs efficiently, with smoother LED transitions and responsive button handling. You’ll revisit the same LED patterns and state transitions as before, but now implement them with non-blocking, event-driven logic.

## Assignment 2.1: Simple Digital Clock

This is the foundational assignment in a multi-part series on building a fully functional alarm clock system. The focus here is to develop a digital clock that can display and adjust the current time using physical buttons and a mode switch. The system supports three operating modes: TIME display, SET TIME, and SET ALARM. Users can increment values and navigate through settings using button presses. The display shows time in the format `HH:mm:ss`, and the system cycles through different modes using a dedicated hardware switch. The structure encourages modular design, with software components for display, state control, button handling, and time tracking.

## Assignment 2.2: Digital Alarm Clock with Audio & Visual Effects

This assignment extends the digital clock developed in 2.1 by adding alarm effects that are both visual (RGB LED) and auditory (audio signal output). When the alarm activates, RGB LEDs cycle through color patterns using smooth transitions, and sound is generated via PWM signals to simulate an alarm tone. The implementation encourages creativity in designing the audio effects, and modular expansion of the system with dedicated blocks for handling RGB and audio output. The emphasis is on integrating previously developed modules into a larger system with coordinated feedback when the alarm is triggered.

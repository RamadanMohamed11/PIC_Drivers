# PIC Microcontroller Drivers

This repository contains a collection of drivers for PIC microcontrollers, designed with a layered architecture to separate hardware-specific code from application logic. This project serves as a foundational library for developing embedded applications with PIC MCUs.

## Project Structure

The project is organized into two main layers:

-   **MCAL (Microcontroller Abstraction Layer):** This layer contains the low-level drivers that interact directly with the PIC microcontroller's hardware peripherals. Its main purpose is to provide a hardware-agnostic API to the upper layers.
-   **ECU (Electronic Control Unit):** This layer consists of drivers for external electronic components and modules. These drivers are built on top of the MCAL layer.

## Features & Modules

The following drivers are implemented in this project:

### MCAL Drivers

-   **GPIO:** Driver for General Purpose Input/Output pins, allowing for pin configuration (input/output) and state manipulation (high/low).

### ECU Drivers

-   **7-Segment Display:** Driver for controlling common anode or common cathode 7-segment displays.
-   **Button:** Driver for handling push-button inputs with built-in debouncing.
-   **DC Motor:** Driver for controlling the speed and direction of DC motors.
-   **Keypad:** Driver for interfacing with matrix keypads.
-   **LED:** Driver for simple LED control (on, off, toggle).
-   **Relay:** Driver for controlling relay modules.
-   **RGB LED:** Driver for controlling RGB LEDs to produce various colors.

## Getting Started

### Prerequisites

-   MPLAB X IDE
-   XC8 Compiler

### Building the Project

1.  Clone the repository to your local machine.
2.  Open the project in MPLAB X IDE.
3.  Configure the device-specific settings in `MCAL/device_config.c`.
4.  Build the project using the provided `Makefile` or the build button in the IDE.
5.  Flash the generated hex file to your PIC microcontroller.

## Application Example

The `application.c` file contains an example of how to use the drivers to implement a simple application. You can modify this file to create your own custom logic.

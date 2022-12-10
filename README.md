# Pothole Detection System

## PES (ECEN-5813) Course Project

This repository contains the project setup for PES (ECEN-5813) course project - Pothole Detection System. 
The project contains DEBUG target which ineterfaces an accelerometer available on FRDM-KL25Z board to detect the potholes on the road.

## Project Overview

This project implements a Pothole detection System that will detect the potholes and irregularities on the roads using sensor data. This system can be highly useful for the maintenance of road infrastructure.

## Objectives
* To develop an algorithm to detect the irregularities in the road surface based on the accelerometer data of a moving car.
* To interface MMA8451Q (3-axis accelerometer) present on FRDM-KL25Z board with I2C to measure the movement across X-axis.

## Block Diagram
![Block_diagram][Block_diagram]

## Hardware Requirements & Specifications
* Dev. board: FRDM-KL25Z
* Accelerometer: MMA8451Q (On-board FRDM-KL25Z)
* USB connector for a dev board

## Sofware Modules
* PES_Final_Project.c : Main file, Application entry point
* cbfifo.c/.h         : Contains the fuctions for circular buffer implementations and Pothole functions and also filter function for PT1.
* mma8451.c/.h        : Contains the configuration of accelerometer; A function that reads the data for the 3-axis acceleration using the I2C.
* i2c.c/.h            : Contains the configuration of I2C present on KL25Z for port-0. Contains the functions for data write, read operations.
* LED.c/.h            : Contains the configuration for LEDs and LED on/off functions, which is used to detect the pothole.
* delay.c/.h          : Contains a delay function

## UART Terminal Configuration
![UART_Configuration][UART_Configuration]

## Manual Test Routine


## Project Demo
Please click on the following link to watch the project demo video:
(Insert link)

## Learnings 
* Learnt to configure different hardware modules present on FRDM KL25Z like - Accelerometer, I2c, LEDs
* Learnt how I2c protocol works.
* Explored accelerometer present on the FRDM KL25Z
* UART communication
* While woeking on this project I could experience the complete software development cycle phases right from requirement analysis to the system testing.

## Challanges Faced
* I faced some challanges while deciding the threshold value for the pothole detection.
* Since this is a prototype model, configuring the system to real time scenario was kind of difficult.

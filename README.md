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


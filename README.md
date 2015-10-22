# 421_app_controlled_car
#### by John Michael Frullo and Cecilia Brookshier

Code and documents for Team MAHI's final project for BIOE 421

### Brainstorming

We will make a car that can be driven by an app on an iPhone. The user will be able to control the car’s direction as well as additional features (lights, noises, etc.) using the controller buttons in the app. The car will perform different actions under each mode. The car itself will feature two DC motors for driving the wheels, a servo motor for directional control, LEDs and a buzzer for aesthetics/appeal, and a portable battery pack. The car will run using control signals from an arduino. The arduino will receive the user input from the app using Adafruit’s Bluefruit LE UART Friend and control the motors using a motor shield. The app is Adafruit’s Bluefruit LE iOS application.

### Abstract

Our project is a motorized car that is controlled by a user via Adafruit’s Bluefried LE iOS application for iPhone. The project entails creating a car chassis that is outfitted with two DC motors for the back wheels.  An onboard Arduino controls the motors through a Motorshield, allowing each to be controlled independently. In addition to a normal drive mode that utilizes the app’s directional buttons, the user will have the option to select different modes. These different modes will activate LEDs and buzzers on the car and change the car’s driving actions. A portable battery pack will be used to power all the components of the app controlled car.


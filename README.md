# 421_LED_Display
#### by John Michael Frullo and Cecilia Brookshier

Code and documents for Team MAHI's final project for BIOE 421

### Brainstorming

We want to use the Adafruit's Flexible 8x32 NeoPixel RGB LED Matrix to display information and images to an audience.
Different ideas for the LED Display are:
* News Headlines (Rice Thresher)
* Music Spectrum (KTRU)
* Time Display
* Weather Display
* Stock Ticker
* Games (Maze, Frogger, Snake, PacMan, Tetris)
* Fun Visuals
* Manipulation of 2D images
* Drawing images

### Abstract

Our project is a to take advantage of the visual capabilities of Processing, the portability of the Raspberry Pi and Arduino Uno, and the programming simplicity of Adafruit’s Neopixel 8x32 LED display.  After installing Processing on the Pi, we introduced a handshake between the Uno and the Pi to send information serially back and forth. Once the information is sent to the Uno, it is visually represented on the Neopixel LED matrix. With this configuration, we can display data from the internet (weather, time, stock market information, etc.), create interactive art visuals (colorful shapes and images), and even play games (Tetris, Mario, PacMan). The DangerShield on the Uno allows for direct user input in selecting the various modes (internet, interactive art, and games) and the actions within those modes (choosing the data to display, rotation of the art, and playing the games, respectively). BIOE 421/521 focuses on the use of the Raspberry Pi but leaves it tethered to a computer monitor and keyboard. By integrating Processing’s image manipulation capabilities and Neopixel’s ease of operation with the familiar microcontrollers, we demonstrate the possibilities for a portable and interactive display.



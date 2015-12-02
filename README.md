# 421_LED_Display
#### by John Michael Frullo and Cecilia Brookshier

Code and documents for Team MAHI's final project for BIOE 421

### Brainstorming

We want to show the utility of using the DangerShield in controlling and interacting with various displays. We want to use Adafruit's Flexible 8x32 NeoPixel RGB LED Matrix to display text information and rudimentary images. For more complex, 3D images, we will use Processing and a monitor to show the user's manipulation of the objects with the DangerShield
Different ideas for the interactions are:
* News Headlines (Rice Thresher)
* Music Spectrum (KTRU)
* Time Display
* Weather Display
* Stock Ticker
* Games (Maze, Frogger, Snake, PacMan, Tetris)
* Fun Visuals
* Manipulation of 2D images
* Manipulation of 3D images
* Drawing images

### Abstract

Our project is to take advantage of the underutilized DangerShield for the Arduino Uno and to show how it may be used as a multipurpose controller. We plan on illustrating this using Adafruit's Neopixel 8x32 LED display and Processing, an open source software for visual arts programming. On the Neopixel, we plan to display text information pulled from the internet using Processing on the Raspberry Pi. The user can then interact with this information with the sliders and buttons on the DangerShield (text selection, speed, color, and brightness). To show the DangerShield's use for object manipulation, we will create complex images in Processing and display it via a computer monitor. The user will be able to translate and rotate the object in all 3 spatial dimensions. By integrating Processing and the Neopixel display with familiar microcontrollers, we have shown several instances where the DangerShield provides excellent user control; however, the applications can be extended to many other areas, such as: games and interactive visuals on the Neopixel or 3D manipulation of objects in CAD software or research settings.

### Currently

(12/1)
Code is completely finished for BIOE 421 project. For the 3D object manipulation, we are able to translate (x and y), zoom in and out (z), and rotate (x, y,and z) 3D objects through Processing, using the DangerShield sliders and buttons. For the Neopixel matrix, we are able to control the brightness, color, and speed of the display. We can also use the Dangershield sliders and buttons to navigate through different display windows and select what can be displayed. The current display options include a home screen, the date and time, and news headlines from the New York Times RSS feeds in selections of US news, sports news, science news, and tech news.

(11/12)
We are able to use the DangerShield to control the brightness, color, and speed of the date and time displayed on the Neopixel. We are now trying to input news headlines from the New York Times through RSS feeds and have the user scroll through and select the headlines.
We are also able to usee the sliders to control the x-, y-, and z-rotation of an image in Processing. We are now trying to add in translation and zooming features into the 3D object manipulation.

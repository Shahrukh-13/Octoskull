# Octoskull
This is my animatronic OctoSkull project. It is inspired by papercraft designer Methakura's OctoSkull papercraft.

![My_anima tronic_octoskull](https://github.com/user-attachments/assets/35480357-565d-4985-833a-e7f81111822b)

When I saw her papercraft I immediately thought that it will look so awesome if the tentacels could move, so I made this project. The skull is made of paper and its design is taken from Methakura's free OctoSkull papercraft. The tentacles use different servos and the frame is built mostly with MG996/MG995 servo brackets (I had to use some acrylic pieces for the microservos).

# Papercraft
The skull is made of paper. The design of the skull is from Methakura's free OctoSkull papercraft. This is the link of the designer's website: https://methakura.gumroad.com/

and this is the link of the OctoSkull papercraft where I took the skull from: https://methakura.gumroad.com/l/octoskull?layout=profile

I have added the PDF file of the paercraft in the /Papercraft/ folder. There are two versions of skull in this papercraft, if you want to make the one I made then use Page 1-8. The papercraft does not have the cutouts on the sides and the top of the skull, you will have to cut them out yourself and put WS2812 LED Rings inside. 

# Arduino
I am using Arduino Mega 2560 to control 12 Servos, WS2812 RGB LEDs, 3 Relays. 

The Reason I choose Arduino MEga 2560 is because I have both servos and WS2812 RGB LEDs in this project and if you use Arduino's servo library and FastLED library togeather is the same program, there are some issues: https://learn.adafruit.com/neopixels-and-servos/overview

Arduino Mega 2560 has 4 16-bit Timers and that allows us to control 12 servos. 

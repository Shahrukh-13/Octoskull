# Octoskull
This is my animatronic OctoSkull project. It is inspired by papercraft designer Methakura's OctoSkull papercraft.

![Animatronic_octoskull](https://github.com/user-attachments/assets/35480357-565d-4985-833a-e7f81111822b)

When I saw her papercraft I immediately thought that it will look so awesome if the tentacels could move, so I decided to make this animatronic project. The skull is made of paper and its design is taken from Methakura's free OctoSkull papercraft. The tentacles use different servos and the frame is built mostly with MG996/MG995 compatible servo brackets (I had to use some acrylic pieces for the microservos).

# System Block Diagram

![System block diagram](https://github.com/user-attachments/assets/56c909b7-f053-4203-b530-0f9aa01125a2)

# Schematic and PCB layout
The schematic and PCB layout are designed in Proteus Design Suite. The Proteus project and schematic PDF file is placed in Octoskull/Schematic-PCB/ folder. The PCB layout PDF file is placed in Octoskull/Schematic-PCB/PCB_layout_PDF folder.

## Schematic
As you can see from the sysytem block diagram, electrically the circuit is very simple. A 12V PSU supplies power to Arduino Mega2560, 100W stepdown voltage regulator, LM2596 stepdown voltage regulator and to three 12V-Relays. The relays are used here to provide a delay for servo power. What I have seen in prvious projects is that when Arduino and servo are powered up togeather, the servos twitch a little at startup before going to the position that is being written to them. I want to avoid this behaviour and an easy fix for this is to write the position to servo first and then enable power to them. In this circuit the relays are doing that, first Arduino writes the servo positions and then enables all the relays to supply power to the servos and LEDs.

## PCB layout
The PCB is designed for a single layer board (Ideally two layer board will be better), I am using a lot of jumpers in this layout which should be avoided. Now I know that the circuit works, I will move to a two layer PCB in the next rev. I will also try to place all the components in a different way so it occupies less space on the board.

# Blender project
In the blender project I have twelve armatures that represent the twelve servos, I have given Servo IDs 1-12. To setup armatures as servos you need to use Blender Servo Animation Add on: https://github.com/timhendriks93/blender-servo-animation. Once this addon is added you can set each armature as a servo and give it a unique ID.

![rec2-ezgif com-video-to-gif-converter](https://github.com/user-attachments/assets/b761d5fa-6bb4-4942-a8d3-2af8f3955650)

![Untitled1-ezgif com-video-to-gif-converter](https://github.com/user-attachments/assets/0c589af7-0f9e-4d46-a625-a6eb0865f5d2)

In live mode the unique servo ID is sent in the serial message to Arduino to control the corresponding servo. The serial message protocol is documented here: https://github.com/timhendriks93/blender-servo-animation?tab=readme-ov-file#command-protocol. Once the animation is exported, a bone[] array is generated for each servo. These bone[] arrays are used to play the animation in a loop.

# Arduino
I am using Arduino Mega 2560 to control 12 Servos, WS2812 RGB LEDs, 3 Relays. 

The Reason I choose Arduino Mega 2560 is because I have both servos and WS2812 RGB LEDs in this project and if you use Arduino's servo library and FastLED library togeather in the same program you will see some problems. The problem happens because of the interrupts, Arduino's servo library uses interrupts and FastLED disables innterupts when it is writting to the LEDs. You can read more about the issue here: https://learn.adafruit.com/neopixels-and-servos/overview

The easy solution is to use Arduino Mega 2560 as it has 4 16-bit Timers, this allows us to control total 12 servos on pins 2, 3, 5, 6, 7, 8, 11, 12, 13, 44, 45, 46. Adafruit has an alternate servo library called Adafruit_TiCoServo which makes it very easy to control servos on these pins.

There are 2 arduino sketches in the Octoskull/Arduino/ folder. Following is the brief description of each sketch:

1. **Octoskull-Animation.ino:** has the servo animation arrays that are generated by Blender, they are saved in the flash memeory of the microcontroller. The saved animation runs in a loop.
2. **Octoskull-Animation_live.ino:** reads serial data coming from blender to control the servo motors. This lets you do live animation from blender. You can use this sketch to create the animation, export the data and copy it in the Octoskull-Animation.ino sketch to run in a loop.

## Flowchart

![flowchart](https://github.com/user-attachments/assets/25cdc877-5eca-4f00-b7dd-fe03ea99a92a)
____________________________

![flowchart2 drawio (1)](https://github.com/user-attachments/assets/1f565036-1f94-49c3-a44e-1b38fa45d014)


## Arduino Libraries
I have the library files added in the Octoskull/Arduino/Library/ folder. I am also adding the Github links for the libraries here:

1. Adafruit_TiCoServo: https://github.com/adafruit/Adafruit_TiCoServo
2. FastLED: https://github.com/FastLED/FastLED

# Papercraft
The skull is made of paper. The design of the skull is from Methakura's free OctoSkull papercraft. This is the link of the designer's website: https://methakura.gumroad.com/

and this is the link of the OctoSkull papercraft where I took the skull from: https://methakura.gumroad.com/l/octoskull?layout=profile

I have added the PDF file of the paercraft in the Octoskull//Papercraft/ folder. There are two versions of skull in this papercraft, if you want to make the one I made then use Page 1-8. The papercraft does not have the cutouts on the sides and the top of the skull, you will have to cut them out yourself and put WS2812 LED Rings inside. 

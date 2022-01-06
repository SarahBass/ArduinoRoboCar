------------------------------------------------------------------------------------------
*ArduinoRoboCar*

A robotic car that filters out environmental data to target a living object that is sensed with movement, color, and heat. 

-------------------------------------------------------------------------------------------

Needed Parts:                          | Description:
-------                                | ------------------------------------------------------------------------------------------------
Roboduino Smart Robot Car from Yahboom | Contains: wifi camera to phone, remote, rgb lights, buzzer, ultrasonic sensor, servos, TT motors and  wheels, tracking.   

*Warning: Roboduino is not easily compatible with Mac and will require you to find mac version of CH340 Drive. Helloblock not Mac or Linux compatable. 
Wifi module must be detached from expansion board while usb port is in use or Arduino IDE will not work and will give error upon compile and run.*

- *See Link for more information on Roboduino : http://www.yahboom.net/study/roboduino*

- *See Link for CH340 Drive for Mac : https://sparks.gogo.co.nz/ch340.html*

- *See Link for Expansion board : https://category.yahboom.net/products/uno-drive-expansion-board*

- *See Link for Gesture Sensor : https://learn.sparkfun.com/tutorials/apds-9960-rgb-and-gesture-sensor-hookup-guide/all

Additional parts: | Descpriction:
----------------- | ------------------------------------------------------
a canakit 5V fan  | Cools Arduino while using the Wifi Camera Attachment 
                 
4 pin LCD screen  | To print out graphics or work as a serial monitor
----------------- | ------------------------------------------------------
APD69860 gesture  | To sense infared, color, and movement to find target

### Code Information : 

Some of the Code links are just my personalizations of the code provided by the Roboduino smart robot car repository.

On Board: For example I would like to clean up the RGB display .h and .cpp files to my preferences, deleting the "breathing light" functions (I just find them
a waste of processing and space and annoying to the eyes) and to get the brightness down on all RGB lights especially the single RGB pixel light. If you look
at the code the single RGB pixel light has a library full of what I believe is meaningess functions surrounding a 8*8 Pixel light matrix game that some how
is in the code to operate a single RGB light. The brightness (which is pre-set) at 255 is harmful to the eyes, so I have it dimmed to 1.  


On Board : The two eyes each can have a seperate color, but the code does not easily lend itself to shutting both of the eyes off because it has a limiter where only one eye at a time can be set to 0,0,0. When ever the robot is not performing a task, I have built a simple onboard customization to displays a pink/purple 
led to indicate the mode and turns off both eyes that way you can save power and not hurt your retinas. I did not include turning off the "breathing light" 
because I have deleted the breathing light entirely. 

Currently I am trying to rewrite the libraries and functions around the two eyes which are set to a system of reading color input
(from I believe a part of the Helloblock program (I couldn't get it working on my mac, so I don't know if the "courses" are related).
Each eye has an rgb light or possibly a couple of RGB lights and both eyes connect to a single port : 11. The code for the eyes included
uses a system of taking in a fake code such as 00FF00 and reading it - most of the code revolves around reading the color code network. The 
FF indicates max brightness at the R , G, or B input and the only colors available are red, green, blue, and a few others. It says you can 
type in your own color code , for example I used 010000 and it did display a dimmer verson of the color but then immediately started spitting 
out errors and freezing the machine. I would like to rewrite the code to display dimmed lights becuase I believe the 255 brightness is harmful
to the eyes after long periods of time. 

Car Whistle: I included a silly Harry Potter buzzer song and others under Car whistle that is not entirely my own creation. I sped up my included version and the pins are set to the Roboduino (which is standard- so it will work on any similar model). It also lights the eyes up and changes the RGB to blue. 

- *Music Library Link: https://github.com/robsoncouto/arduino-songs robsoncouto has an amazing library of songs.* 

>While programming I suggest you dampen the noise or your cover your ears. They are incredibly cheap buzzer speakers that can harm people, children, or pets if safety isn't followed. I covered mine with a silicone earbud cover to dampen the buzzer physically. 

Ultrasonic Eyes : Written to change color when object is within range based on centimeters. Red for close object, Green for no object or far object. 
Not the best system becuase the ultrasonic eyes often misread and will flash the wrong color. I may improve this with some sort of simple hamming code program
to make it smoother. 

Gesture Sensor and LCD Screen- 
Pins: VL GND VCC SDA SCL and INT(2) on expansion board are connected to Arduino Uno original pins and use of VCC from bluetooth port.
Pin VL is opitional but there is a 3.3 V pin available. I am using the 5V and GND pin on the other side of the Arduino Uno for the fan. 

LCD Screen into designated LCD module on Expansion board : GND VCC SCL SDA 

- *See The very cool Gesture Sensor Yahboom sells with a face led matrix: Link:https://category.yahboom.net/products/gesture*
- *I already owned a gesture and color sensor from Amazon Link: https://www.amazon.com/gp/product/B01NACU412/ref=ppx_yo_dt_b_asin_title_o00_s00?ie=UTF8&psc=1*
- *I also already owned a 4 pin LCD screen from Amazon link: https://www.amazon.com/gp/product/B082X9MGYR/ref=ppx_yo_dt_b_search_asin_title?ie=UTF8&psc=1*







 
 








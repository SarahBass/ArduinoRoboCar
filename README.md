------------------------------------------------------------------------------------------
*ArduinoRoboCar*

A robotic car created to follow and annoy a pet dog by filtering out environmental 
data to target an object that is sensed with movement, color, and heat. 

-------------------------------------------------------------------------------------------

Needed Parts:                          | Description:
-------                                | ------------------------------------------------------------------------------------------------
Roboduino Smart Robot Car from Yahboom | Contains: wifi camera to phone, remote, rgb lights, buzzer, ultrasonic sensor, servos, TT motors and  wheels, tracking..   

*Warning: Roboduino is not easily compatible with Mac and will require you to fin mac version of CH340 Drive. Helloblock not Mac or Linux compatable. 
Wifi module must be detached from expansion board while usb port is in use or Arduino IDE will not work and will give error upon compile and run.*

- *See Link for more information on Roboduino : http://www.yahboom.net/study/roboduino*

- *See Link for CH340 Drive for Mac : https://sparks.gogo.co.nz/ch340.html*


Additional parts: | Descpriction:
----------------- | ------------------------------------------------------
a canakit 5V fan  | Cools Arduino while using the Wifi Camera Attachment 
                 
4 pin LCD screen  | To print out graphics or work as a serial monitor
----------------- | ------------------------------------------------------
A gesture sensor  | To sense infared and movement to find target

### Code Information : 

Some of the Code links are just my personalizations of the code provided by the Roboduino smart robot car repository
For example I would like to clean up the RGB display .h and .cpp files to my preferences, deleting the "breathing light" functions (I just find them
a waste of processing and space and annoying to the eyes) and to get the brightness down on all RGB lights especially the single RGB pixel light. If you look
at the code the single RGB pixel light has a library full of what I believe is meaningess functions surrounding a 8*8 Pixel light matrix game that some how
is in the code to operate a single RGB light. The brightness (which is pre-set) at 255 is harmful to the eyes, so I have it dimmed to 1.  


The two eyes each can have a seperate color, but the code does not easily lend itself to shutting both of the eyes off because it has a limiter where only 
one eye at a time can be set to 0,0,0. When ever the robot is not performing a task, I have built a simple onboard customization to displays a pink/purple 
led and turns off both eyes that way you can save power and not hurt your retinas. 

Currently I am trying to rewrite the libraries and functions around the two eyes which are set to a system of reading color input (from I believe a part of the 






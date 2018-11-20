# Automatic preheater tool

Is a simple tool to reactivate the preheater in i.e. in VW T5 to survive the cold winter nights.

The PoC will be an Arduino nano with a DHT11 and a small servo motor to push the button on the remote.
Later on I thinking about to install it on an WeMos to send the data to a webservice and provide the option to control the temperature.


## The basic function

Just a simple tool to trigger the preheater button on the remote.
The remote should be set to heat for 120 mins. for this concept.

## Housing

Designed to 3D print in i.e. PLA (will take about 4h)
 * Infill
	I use 20% for all parts execpt for the "Mid_ButtonTrigger" part - this should be printed soild (100%).
 * Layerheight 
	Doesn't really matter, I will print it with 300 micron.
 * Support structure
	No, you shouldn't need it

## Software

The software will wait for 120mins and start the temperature check all 2 mins. As soon as the temperature drops below 19c. the remote button will be pushed and the loop starts again.

## BOM

* Arduino Nano
* Servo Motor (I used HS-303)
* DHT11
* 3 M5x20 screws
* some filament for your 3D printer - hope you own one
* some wires, solder, soldering iron

## Wireing

Servo:
Red(+): --> Arduino 5v
Black(-): --> Arduino ground
Yellow(Signal): --> Arduino D9

DHT11:
+: --> Arduino 3.3v
-: --> Arduino ground
Signal: --> Arduino D4


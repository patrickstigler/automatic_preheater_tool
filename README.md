# Automatic preheater tool

Is a simple tool to reactivate the preheater in i.e. in VW T5 to survive the cold winter nights.

The PoC will be an Arduino nano with a DHT11 and a small servo motor to push the button on the remote.
Later on I thinking about to install it on an WeMos to send the data to a webservice and provide the option to control the temperature.


##The basic function

Just a simple tool to trigger the preheater button on the remote.
The remote should be set to heat for 120 mins. for this concept.

The software will wait for 120mins and start the temperature check all 2 mins. 
As soon as the temperature drops below 20c. the remote button will be pushed and the loop starts again.
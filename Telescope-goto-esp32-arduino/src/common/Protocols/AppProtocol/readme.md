### ESP32 App Protcol (Master)

All comands should be able to get send via TCP and Bluetooth. All comands are getting send from the Master (App) and the Slave (ESP32) only answers. All comands end with a ";" and start with a ":". It should be possible to send multibile comands at once. 

------------
#### Comands
##### :trackingInfo;
response: ":true;" || ":false;"
With this comand one can get if client has the information requiered to enable tracking. If the client responds with a *:true;* that means that the client has no information about the Time, Date, UTC offset and location data which are needed to enable Tracking. 

##### :date=MM/DD/YY;
response: ""
With this comand one can send the client the current Date. Requierd for Tracking.

##### :time=HH:MM:SS;
response: ""
With this comand one can send the client the current Time. Requierd for Tracking.

##### :utcOffset=sHH.H;
response: ""
With this comand one can send the client the UTC offset. Requierd for Tracking.

##### :latitude=sHH.H;
response: ""
With this comand one can send the client the latitude. Requierd for Tracking.

##### :longitude=sHH.H;
response: ""
With this comand one can send the client the longitude. Requierd for Tracking.

##### :calibrationRa=HH:MM:SS#
response: ""
With this comand one can calibrate the telescope Ra (Homing).

##### :calibrationDec=sDD*MM:SS;
response: ""
With this comand one can calibrate the telescope Dec (Homing).

##### :move=<motor ID>:<on|off>:(<clockwise|counterclockwise>);
response: ""
With this comand one can move the motors clockwise or counterclockwise. The motors move until an "off" comand is send. 

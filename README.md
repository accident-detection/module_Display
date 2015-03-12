# module_Display
Implementation of display functions and using sensors to display info on the display.
The explanations inside the code are made in Croatian, because the project is made for Alegbra, Croatian university.

The CSVFormat function makes a CSV format (obviously..) string which will be used later to send to the server.
Separator we're using for now is ';', might change in the future. The CSV format string holds information about temperature, humidity and sensor status.

Error codes:
400 - OK
401 - Collected data is wrong
402 - Unable to make communication with the sensors (time-out error)
403 - Data pin isn't connected correctly
404 - Data pin connected to GND or low very low voltage
405 - Data pin connected to high voltage (+3.3V or greater)
410 - Unknown error

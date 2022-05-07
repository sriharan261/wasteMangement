ABOUT PROJECT:
     This project is about a waste separation device. This device, named the ICONIC BIN, seperates plastic wastes from other wastes. This will help people 
     segregate harmful plastic waste from others. We feel that this device will assist the efforts that are currently taken to protect the environment from harmful 
     plastic.

PREREQUISITES:
     Arduino Uno,
     IR Sensor,
     Semi-circular metallic sheet,
     Servo motor,
     Encoder Cable,
     Motor Cable.

WORKING:
     When the waste material is thrown in the bin, it passes through the IR transmitter and receiver system. The transmitter transmits IR rays which hit the object.
     Plastic has the ability to block IR rays. So if the receiver receives no input then the object is said to be plastic then it is pushed to the bin allotted  to
     plastic waste. If the receiver receives input then the object is a material that is not plastic. Hence it will be pushed to the bin containing other miscellaneous
     waste. There is a semi-circular metallic sheet which helps in directing the waste to their respective bins. This metallic sheet is driven by a servo motor. Arduino
     Uno is also used here. When plastic is detected by the IR sensor, the metallic sheet turns 180 degrees and directs the waste into the respective bin. A similar story
     happens with other wastes.

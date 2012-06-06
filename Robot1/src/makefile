SOURCES= main.c initLED.c RobotTime.c

local: 
		gcc -std=gnu99 -Wall $(SOURCES) -I ../include -lm -o MyController.exe 


clean: 
		rm -f *.o *.out *.gch *.a *.hex *.elf *.exe
		
all:
		avr-gcc -mmcu=atmega2561 -std=gnu99 -Wall $(SOURCES) -I ../include -o main.elf
		avr-objcopy -O ihex -R .eeprom -R .fuse -R .lock -R .signature main.elf main.hex
		avr-size -C --mcu=atmega2561 main.elf



















.build/uno/Adafruit_NeoMatrix/extras/gamma.o : lib/Adafruit_NeoMatrix/extras/gamma.c
	@echo [93mAdafruit_NeoMatrix/extras/gamma.c[0m
	@mkdir -p .build/uno/Adafruit_NeoMatrix/extras
	@/usr/bin/avr-gcc -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=101 -I/usr/share/arduino/hardware/arduino/cores/arduino -ffunction-sections -fdata-sections -g -Os -w -I/usr/share/arduino/hardware/arduino/variants/standard -Ilib/Adafruit_NeoMatrix -Ilib/Adafruit_NeoMatrix/extras -Ilib/Adafruit_NeoPixel -Ilib/Adafruit_GFX -I/usr/share/arduino/hardware/arduino/cores/arduino   -o $@ -c lib/Adafruit_NeoMatrix/extras/gamma.c
include .build/uno/Adafruit_NeoMatrix/extras/gamma.d






.build/uno/Adafruit_NeoMatrix/Adafruit_NeoMatrix.o : lib/Adafruit_NeoMatrix/Adafruit_NeoMatrix.cpp
	@echo [93mAdafruit_NeoMatrix/Adafruit_NeoMatrix.cpp[0m
	@mkdir -p .build/uno/Adafruit_NeoMatrix
	@/usr/bin/avr-g++ -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=101 -I/usr/share/arduino/hardware/arduino/cores/arduino -ffunction-sections -fdata-sections -g -Os -w -I/usr/share/arduino/hardware/arduino/variants/standard -Ilib/Adafruit_NeoMatrix -Ilib/Adafruit_NeoMatrix/extras -Ilib/Adafruit_NeoPixel -Ilib/Adafruit_GFX -I/usr/share/arduino/hardware/arduino/cores/arduino -fno-exceptions  -o $@ -c lib/Adafruit_NeoMatrix/Adafruit_NeoMatrix.cpp
include .build/uno/Adafruit_NeoMatrix/Adafruit_NeoMatrix.d



.build/uno/Adafruit_NeoMatrix/libAdafruit_NeoMatrix.a : .build/uno/Adafruit_NeoMatrix/extras/gamma.o .build/uno/Adafruit_NeoMatrix/Adafruit_NeoMatrix.o
	@echo [92mLinking libAdafruit_NeoMatrix.a[0m
	@/usr/bin/avr-ar rcs $@ $^







.build/uno/Adafruit_NeoPixel/esp8266.o : lib/Adafruit_NeoPixel/esp8266.c
	@echo [93mAdafruit_NeoPixel/esp8266.c[0m
	@mkdir -p .build/uno/Adafruit_NeoPixel
	@/usr/bin/avr-gcc -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=101 -I/usr/share/arduino/hardware/arduino/cores/arduino -ffunction-sections -fdata-sections -g -Os -w -I/usr/share/arduino/hardware/arduino/variants/standard -Ilib/Adafruit_NeoMatrix -Ilib/Adafruit_NeoMatrix/extras -Ilib/Adafruit_NeoPixel -Ilib/Adafruit_GFX -I/usr/share/arduino/hardware/arduino/cores/arduino   -o $@ -c lib/Adafruit_NeoPixel/esp8266.c
include .build/uno/Adafruit_NeoPixel/esp8266.d






.build/uno/Adafruit_NeoPixel/Adafruit_NeoPixel.o : lib/Adafruit_NeoPixel/Adafruit_NeoPixel.cpp
	@echo [93mAdafruit_NeoPixel/Adafruit_NeoPixel.cpp[0m
	@mkdir -p .build/uno/Adafruit_NeoPixel
	@/usr/bin/avr-g++ -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=101 -I/usr/share/arduino/hardware/arduino/cores/arduino -ffunction-sections -fdata-sections -g -Os -w -I/usr/share/arduino/hardware/arduino/variants/standard -Ilib/Adafruit_NeoMatrix -Ilib/Adafruit_NeoMatrix/extras -Ilib/Adafruit_NeoPixel -Ilib/Adafruit_GFX -I/usr/share/arduino/hardware/arduino/cores/arduino -fno-exceptions  -o $@ -c lib/Adafruit_NeoPixel/Adafruit_NeoPixel.cpp
include .build/uno/Adafruit_NeoPixel/Adafruit_NeoPixel.d



.build/uno/Adafruit_NeoPixel/libAdafruit_NeoPixel.a : .build/uno/Adafruit_NeoPixel/esp8266.o .build/uno/Adafruit_NeoPixel/Adafruit_NeoPixel.o
	@echo [92mLinking libAdafruit_NeoPixel.a[0m
	@/usr/bin/avr-ar rcs $@ $^







.build/uno/Adafruit_GFX/glcdfont.o : lib/Adafruit_GFX/glcdfont.c
	@echo [93mAdafruit_GFX/glcdfont.c[0m
	@mkdir -p .build/uno/Adafruit_GFX
	@/usr/bin/avr-gcc -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=101 -I/usr/share/arduino/hardware/arduino/cores/arduino -ffunction-sections -fdata-sections -g -Os -w -I/usr/share/arduino/hardware/arduino/variants/standard -Ilib/Adafruit_NeoMatrix -Ilib/Adafruit_NeoMatrix/extras -Ilib/Adafruit_NeoPixel -Ilib/Adafruit_GFX -I/usr/share/arduino/hardware/arduino/cores/arduino   -o $@ -c lib/Adafruit_GFX/glcdfont.c
include .build/uno/Adafruit_GFX/glcdfont.d






.build/uno/Adafruit_GFX/Adafruit_GFX.o : lib/Adafruit_GFX/Adafruit_GFX.cpp
	@echo [93mAdafruit_GFX/Adafruit_GFX.cpp[0m
	@mkdir -p .build/uno/Adafruit_GFX
	@/usr/bin/avr-g++ -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=101 -I/usr/share/arduino/hardware/arduino/cores/arduino -ffunction-sections -fdata-sections -g -Os -w -I/usr/share/arduino/hardware/arduino/variants/standard -Ilib/Adafruit_NeoMatrix -Ilib/Adafruit_NeoMatrix/extras -Ilib/Adafruit_NeoPixel -Ilib/Adafruit_GFX -I/usr/share/arduino/hardware/arduino/cores/arduino -fno-exceptions  -o $@ -c lib/Adafruit_GFX/Adafruit_GFX.cpp
include .build/uno/Adafruit_GFX/Adafruit_GFX.d



.build/uno/Adafruit_GFX/libAdafruit_GFX.a : .build/uno/Adafruit_GFX/glcdfont.o .build/uno/Adafruit_GFX/Adafruit_GFX.o
	@echo [92mLinking libAdafruit_GFX.a[0m
	@/usr/bin/avr-ar rcs $@ $^







.build/uno/arduino/wiring.o : /usr/share/arduino/hardware/arduino/cores/arduino/wiring.c
	@echo [93marduino/wiring.c[0m
	@mkdir -p .build/uno/arduino
	@/usr/bin/avr-gcc -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=101 -I/usr/share/arduino/hardware/arduino/cores/arduino -ffunction-sections -fdata-sections -g -Os -w -I/usr/share/arduino/hardware/arduino/variants/standard -Ilib/Adafruit_NeoMatrix -Ilib/Adafruit_NeoMatrix/extras -Ilib/Adafruit_NeoPixel -Ilib/Adafruit_GFX -I/usr/share/arduino/hardware/arduino/cores/arduino   -o $@ -c /usr/share/arduino/hardware/arduino/cores/arduino/wiring.c
include .build/uno/arduino/wiring.d

.build/uno/arduino/wiring_shift.o : /usr/share/arduino/hardware/arduino/cores/arduino/wiring_shift.c
	@echo [93marduino/wiring_shift.c[0m
	@mkdir -p .build/uno/arduino
	@/usr/bin/avr-gcc -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=101 -I/usr/share/arduino/hardware/arduino/cores/arduino -ffunction-sections -fdata-sections -g -Os -w -I/usr/share/arduino/hardware/arduino/variants/standard -Ilib/Adafruit_NeoMatrix -Ilib/Adafruit_NeoMatrix/extras -Ilib/Adafruit_NeoPixel -Ilib/Adafruit_GFX -I/usr/share/arduino/hardware/arduino/cores/arduino   -o $@ -c /usr/share/arduino/hardware/arduino/cores/arduino/wiring_shift.c
include .build/uno/arduino/wiring_shift.d

.build/uno/arduino/wiring_pulse.o : /usr/share/arduino/hardware/arduino/cores/arduino/wiring_pulse.c
	@echo [93marduino/wiring_pulse.c[0m
	@mkdir -p .build/uno/arduino
	@/usr/bin/avr-gcc -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=101 -I/usr/share/arduino/hardware/arduino/cores/arduino -ffunction-sections -fdata-sections -g -Os -w -I/usr/share/arduino/hardware/arduino/variants/standard -Ilib/Adafruit_NeoMatrix -Ilib/Adafruit_NeoMatrix/extras -Ilib/Adafruit_NeoPixel -Ilib/Adafruit_GFX -I/usr/share/arduino/hardware/arduino/cores/arduino   -o $@ -c /usr/share/arduino/hardware/arduino/cores/arduino/wiring_pulse.c
include .build/uno/arduino/wiring_pulse.d

.build/uno/arduino/WInterrupts.o : /usr/share/arduino/hardware/arduino/cores/arduino/WInterrupts.c
	@echo [93marduino/WInterrupts.c[0m
	@mkdir -p .build/uno/arduino
	@/usr/bin/avr-gcc -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=101 -I/usr/share/arduino/hardware/arduino/cores/arduino -ffunction-sections -fdata-sections -g -Os -w -I/usr/share/arduino/hardware/arduino/variants/standard -Ilib/Adafruit_NeoMatrix -Ilib/Adafruit_NeoMatrix/extras -Ilib/Adafruit_NeoPixel -Ilib/Adafruit_GFX -I/usr/share/arduino/hardware/arduino/cores/arduino   -o $@ -c /usr/share/arduino/hardware/arduino/cores/arduino/WInterrupts.c
include .build/uno/arduino/WInterrupts.d

.build/uno/arduino/wiring_digital.o : /usr/share/arduino/hardware/arduino/cores/arduino/wiring_digital.c
	@echo [93marduino/wiring_digital.c[0m
	@mkdir -p .build/uno/arduino
	@/usr/bin/avr-gcc -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=101 -I/usr/share/arduino/hardware/arduino/cores/arduino -ffunction-sections -fdata-sections -g -Os -w -I/usr/share/arduino/hardware/arduino/variants/standard -Ilib/Adafruit_NeoMatrix -Ilib/Adafruit_NeoMatrix/extras -Ilib/Adafruit_NeoPixel -Ilib/Adafruit_GFX -I/usr/share/arduino/hardware/arduino/cores/arduino   -o $@ -c /usr/share/arduino/hardware/arduino/cores/arduino/wiring_digital.c
include .build/uno/arduino/wiring_digital.d

.build/uno/arduino/wiring_analog.o : /usr/share/arduino/hardware/arduino/cores/arduino/wiring_analog.c
	@echo [93marduino/wiring_analog.c[0m
	@mkdir -p .build/uno/arduino
	@/usr/bin/avr-gcc -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=101 -I/usr/share/arduino/hardware/arduino/cores/arduino -ffunction-sections -fdata-sections -g -Os -w -I/usr/share/arduino/hardware/arduino/variants/standard -Ilib/Adafruit_NeoMatrix -Ilib/Adafruit_NeoMatrix/extras -Ilib/Adafruit_NeoPixel -Ilib/Adafruit_GFX -I/usr/share/arduino/hardware/arduino/cores/arduino   -o $@ -c /usr/share/arduino/hardware/arduino/cores/arduino/wiring_analog.c
include .build/uno/arduino/wiring_analog.d






.build/uno/arduino/Tone.o : /usr/share/arduino/hardware/arduino/cores/arduino/Tone.cpp
	@echo [93marduino/Tone.cpp[0m
	@mkdir -p .build/uno/arduino
	@/usr/bin/avr-g++ -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=101 -I/usr/share/arduino/hardware/arduino/cores/arduino -ffunction-sections -fdata-sections -g -Os -w -I/usr/share/arduino/hardware/arduino/variants/standard -Ilib/Adafruit_NeoMatrix -Ilib/Adafruit_NeoMatrix/extras -Ilib/Adafruit_NeoPixel -Ilib/Adafruit_GFX -I/usr/share/arduino/hardware/arduino/cores/arduino -fno-exceptions  -o $@ -c /usr/share/arduino/hardware/arduino/cores/arduino/Tone.cpp
include .build/uno/arduino/Tone.d

.build/uno/arduino/HardwareSerial.o : /usr/share/arduino/hardware/arduino/cores/arduino/HardwareSerial.cpp
	@echo [93marduino/HardwareSerial.cpp[0m
	@mkdir -p .build/uno/arduino
	@/usr/bin/avr-g++ -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=101 -I/usr/share/arduino/hardware/arduino/cores/arduino -ffunction-sections -fdata-sections -g -Os -w -I/usr/share/arduino/hardware/arduino/variants/standard -Ilib/Adafruit_NeoMatrix -Ilib/Adafruit_NeoMatrix/extras -Ilib/Adafruit_NeoPixel -Ilib/Adafruit_GFX -I/usr/share/arduino/hardware/arduino/cores/arduino -fno-exceptions  -o $@ -c /usr/share/arduino/hardware/arduino/cores/arduino/HardwareSerial.cpp
include .build/uno/arduino/HardwareSerial.d

.build/uno/arduino/IPAddress.o : /usr/share/arduino/hardware/arduino/cores/arduino/IPAddress.cpp
	@echo [93marduino/IPAddress.cpp[0m
	@mkdir -p .build/uno/arduino
	@/usr/bin/avr-g++ -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=101 -I/usr/share/arduino/hardware/arduino/cores/arduino -ffunction-sections -fdata-sections -g -Os -w -I/usr/share/arduino/hardware/arduino/variants/standard -Ilib/Adafruit_NeoMatrix -Ilib/Adafruit_NeoMatrix/extras -Ilib/Adafruit_NeoPixel -Ilib/Adafruit_GFX -I/usr/share/arduino/hardware/arduino/cores/arduino -fno-exceptions  -o $@ -c /usr/share/arduino/hardware/arduino/cores/arduino/IPAddress.cpp
include .build/uno/arduino/IPAddress.d

.build/uno/arduino/new.o : /usr/share/arduino/hardware/arduino/cores/arduino/new.cpp
	@echo [93marduino/new.cpp[0m
	@mkdir -p .build/uno/arduino
	@/usr/bin/avr-g++ -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=101 -I/usr/share/arduino/hardware/arduino/cores/arduino -ffunction-sections -fdata-sections -g -Os -w -I/usr/share/arduino/hardware/arduino/variants/standard -Ilib/Adafruit_NeoMatrix -Ilib/Adafruit_NeoMatrix/extras -Ilib/Adafruit_NeoPixel -Ilib/Adafruit_GFX -I/usr/share/arduino/hardware/arduino/cores/arduino -fno-exceptions  -o $@ -c /usr/share/arduino/hardware/arduino/cores/arduino/new.cpp
include .build/uno/arduino/new.d

.build/uno/arduino/Print.o : /usr/share/arduino/hardware/arduino/cores/arduino/Print.cpp
	@echo [93marduino/Print.cpp[0m
	@mkdir -p .build/uno/arduino
	@/usr/bin/avr-g++ -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=101 -I/usr/share/arduino/hardware/arduino/cores/arduino -ffunction-sections -fdata-sections -g -Os -w -I/usr/share/arduino/hardware/arduino/variants/standard -Ilib/Adafruit_NeoMatrix -Ilib/Adafruit_NeoMatrix/extras -Ilib/Adafruit_NeoPixel -Ilib/Adafruit_GFX -I/usr/share/arduino/hardware/arduino/cores/arduino -fno-exceptions  -o $@ -c /usr/share/arduino/hardware/arduino/cores/arduino/Print.cpp
include .build/uno/arduino/Print.d

.build/uno/arduino/USBCore.o : /usr/share/arduino/hardware/arduino/cores/arduino/USBCore.cpp
	@echo [93marduino/USBCore.cpp[0m
	@mkdir -p .build/uno/arduino
	@/usr/bin/avr-g++ -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=101 -I/usr/share/arduino/hardware/arduino/cores/arduino -ffunction-sections -fdata-sections -g -Os -w -I/usr/share/arduino/hardware/arduino/variants/standard -Ilib/Adafruit_NeoMatrix -Ilib/Adafruit_NeoMatrix/extras -Ilib/Adafruit_NeoPixel -Ilib/Adafruit_GFX -I/usr/share/arduino/hardware/arduino/cores/arduino -fno-exceptions  -o $@ -c /usr/share/arduino/hardware/arduino/cores/arduino/USBCore.cpp
include .build/uno/arduino/USBCore.d

.build/uno/arduino/HID.o : /usr/share/arduino/hardware/arduino/cores/arduino/HID.cpp
	@echo [93marduino/HID.cpp[0m
	@mkdir -p .build/uno/arduino
	@/usr/bin/avr-g++ -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=101 -I/usr/share/arduino/hardware/arduino/cores/arduino -ffunction-sections -fdata-sections -g -Os -w -I/usr/share/arduino/hardware/arduino/variants/standard -Ilib/Adafruit_NeoMatrix -Ilib/Adafruit_NeoMatrix/extras -Ilib/Adafruit_NeoPixel -Ilib/Adafruit_GFX -I/usr/share/arduino/hardware/arduino/cores/arduino -fno-exceptions  -o $@ -c /usr/share/arduino/hardware/arduino/cores/arduino/HID.cpp
include .build/uno/arduino/HID.d

.build/uno/arduino/main.o : /usr/share/arduino/hardware/arduino/cores/arduino/main.cpp
	@echo [93marduino/main.cpp[0m
	@mkdir -p .build/uno/arduino
	@/usr/bin/avr-g++ -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=101 -I/usr/share/arduino/hardware/arduino/cores/arduino -ffunction-sections -fdata-sections -g -Os -w -I/usr/share/arduino/hardware/arduino/variants/standard -Ilib/Adafruit_NeoMatrix -Ilib/Adafruit_NeoMatrix/extras -Ilib/Adafruit_NeoPixel -Ilib/Adafruit_GFX -I/usr/share/arduino/hardware/arduino/cores/arduino -fno-exceptions  -o $@ -c /usr/share/arduino/hardware/arduino/cores/arduino/main.cpp
include .build/uno/arduino/main.d

.build/uno/arduino/Stream.o : /usr/share/arduino/hardware/arduino/cores/arduino/Stream.cpp
	@echo [93marduino/Stream.cpp[0m
	@mkdir -p .build/uno/arduino
	@/usr/bin/avr-g++ -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=101 -I/usr/share/arduino/hardware/arduino/cores/arduino -ffunction-sections -fdata-sections -g -Os -w -I/usr/share/arduino/hardware/arduino/variants/standard -Ilib/Adafruit_NeoMatrix -Ilib/Adafruit_NeoMatrix/extras -Ilib/Adafruit_NeoPixel -Ilib/Adafruit_GFX -I/usr/share/arduino/hardware/arduino/cores/arduino -fno-exceptions  -o $@ -c /usr/share/arduino/hardware/arduino/cores/arduino/Stream.cpp
include .build/uno/arduino/Stream.d

.build/uno/arduino/WString.o : /usr/share/arduino/hardware/arduino/cores/arduino/WString.cpp
	@echo [93marduino/WString.cpp[0m
	@mkdir -p .build/uno/arduino
	@/usr/bin/avr-g++ -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=101 -I/usr/share/arduino/hardware/arduino/cores/arduino -ffunction-sections -fdata-sections -g -Os -w -I/usr/share/arduino/hardware/arduino/variants/standard -Ilib/Adafruit_NeoMatrix -Ilib/Adafruit_NeoMatrix/extras -Ilib/Adafruit_NeoPixel -Ilib/Adafruit_GFX -I/usr/share/arduino/hardware/arduino/cores/arduino -fno-exceptions  -o $@ -c /usr/share/arduino/hardware/arduino/cores/arduino/WString.cpp
include .build/uno/arduino/WString.d

.build/uno/arduino/WMath.o : /usr/share/arduino/hardware/arduino/cores/arduino/WMath.cpp
	@echo [93marduino/WMath.cpp[0m
	@mkdir -p .build/uno/arduino
	@/usr/bin/avr-g++ -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=101 -I/usr/share/arduino/hardware/arduino/cores/arduino -ffunction-sections -fdata-sections -g -Os -w -I/usr/share/arduino/hardware/arduino/variants/standard -Ilib/Adafruit_NeoMatrix -Ilib/Adafruit_NeoMatrix/extras -Ilib/Adafruit_NeoPixel -Ilib/Adafruit_GFX -I/usr/share/arduino/hardware/arduino/cores/arduino -fno-exceptions  -o $@ -c /usr/share/arduino/hardware/arduino/cores/arduino/WMath.cpp
include .build/uno/arduino/WMath.d

.build/uno/arduino/CDC.o : /usr/share/arduino/hardware/arduino/cores/arduino/CDC.cpp
	@echo [93marduino/CDC.cpp[0m
	@mkdir -p .build/uno/arduino
	@/usr/bin/avr-g++ -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=101 -I/usr/share/arduino/hardware/arduino/cores/arduino -ffunction-sections -fdata-sections -g -Os -w -I/usr/share/arduino/hardware/arduino/variants/standard -Ilib/Adafruit_NeoMatrix -Ilib/Adafruit_NeoMatrix/extras -Ilib/Adafruit_NeoPixel -Ilib/Adafruit_GFX -I/usr/share/arduino/hardware/arduino/cores/arduino -fno-exceptions  -o $@ -c /usr/share/arduino/hardware/arduino/cores/arduino/CDC.cpp
include .build/uno/arduino/CDC.d



.build/uno/arduino/libarduino.a : .build/uno/arduino/wiring.o .build/uno/arduino/wiring_shift.o .build/uno/arduino/wiring_pulse.o .build/uno/arduino/WInterrupts.o .build/uno/arduino/wiring_digital.o .build/uno/arduino/wiring_analog.o .build/uno/arduino/Tone.o .build/uno/arduino/HardwareSerial.o .build/uno/arduino/IPAddress.o .build/uno/arduino/new.o .build/uno/arduino/Print.o .build/uno/arduino/USBCore.o .build/uno/arduino/HID.o .build/uno/arduino/main.o .build/uno/arduino/Stream.o .build/uno/arduino/WString.o .build/uno/arduino/WMath.o .build/uno/arduino/CDC.o
	@echo [92mLinking libarduino.a[0m
	@/usr/bin/avr-ar rcs $@ $^















.build/uno/src/MatrixTest_8x32.o : .build/uno/src/MatrixTest_8x32.cpp
	@echo [93msrc/MatrixTest_8x32.cpp[0m
	@mkdir -p .build/uno/src
	@/usr/bin/avr-g++ -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=101 -I/usr/share/arduino/hardware/arduino/cores/arduino -ffunction-sections -fdata-sections -g -Os -w -I/usr/share/arduino/hardware/arduino/variants/standard -Ilib/Adafruit_NeoMatrix -Ilib/Adafruit_NeoMatrix/extras -Ilib/Adafruit_NeoPixel -Ilib/Adafruit_GFX -I/usr/share/arduino/hardware/arduino/cores/arduino -fno-exceptions -iquote src  -o $@ -c .build/uno/src/MatrixTest_8x32.cpp
include .build/uno/src/MatrixTest_8x32.d







.build/uno/firmware.elf : .build/uno/src/MatrixTest_8x32.o .build/uno/Adafruit_NeoMatrix/libAdafruit_NeoMatrix.a .build/uno/Adafruit_NeoPixel/libAdafruit_NeoPixel.a .build/uno/Adafruit_GFX/libAdafruit_GFX.a .build/uno/arduino/libarduino.a
	@echo [92mLinking firmware.elf[0m
	@/usr/bin/avr-gcc -mmcu=atmega328p -Wl,-Os -Wl,--gc-sections -o $@ $^ -lm


.build/uno/firmware.hex : .build/uno/firmware.elf
	@echo [92mConverting to firmware.hex[0m
	@/usr/bin/avr-objcopy -O ihex -R .eeprom $^ $@

include .build/uno/src/dependencies.d .build/uno/arduino/dependencies.d .build/uno/Adafruit_NeoMatrix/dependencies.d .build/uno/Adafruit_NeoPixel/dependencies.d .build/uno/Adafruit_GFX/dependencies.d

all : .build/uno/firmware.hex
	@true


Setup CubeMX on Linux
apt-get install openjdk-8-jre

Download CubeMX from the stm website
Unzip

Install it by calling the .exe as a jar file
java -jar SetupSTM32CubeMX-4.22.1.exe

Install gcc-arm-none-gnueabi
apt-get install gcc-arm-none-gnueabi


After generating a project with CubeMX make sure you add the path to your compiler in BINPATH
Get the path
which arm-gnu-eabi-gcc

Strip off arm-gnu-eabi-gcc
BINPATH = /usr/bin

Load the file
https://github.com/flitjes/stlink/blob/master/doc/tutorial.md

Note: after checking out stlink, copy the build/Release target cmake line and cd to this manually
Call the line you've copied
make
make install
export LD_LIBRARY_PATH=/usr/local/lib

st-util

Make sure to wipe the device with stm util from windows

apt-get install gdb-arm-none-eabi

arm-non-gnueabi-gdb *.elf
target extended localhost:4242


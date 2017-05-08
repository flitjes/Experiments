FROM ubuntu:xenial
MAINTAINER Christian Litjes <flitjesdev@gmail.com>

WORKDIR /workspace

RUN apt-get update -q \
     && apt-get install -y git build-essential libtool pkg-config autoconf automake texinfo libusb-1.0.0-dev vim usbutils tmux unzip wget telnet cscope\
     && git clone https://github.com/flitjes/openocd.git openocd-code \
     && cd openocd-code/ \
     && ./bootstrap \
     && ./configure --enable-stlink \
     && make \
     && make install \
     && cd /workspace \
     && wget https://developer.nordicsemi.com/nRF5_SDK/nRF5_SDK_v12.x.x/nRF5_SDK_12.2.0_f012efa.zip \
     && mkdir nrf5_sdk \
     && unzip nRF5_SDK_12.2.0_f012efa.zip -d nrf5_sdk \
     && echo "GNU_INSTALL_ROOT := /workspace/gcc-arm-none-eabi-6-2017-q1-update\nGNU_VERSION := 6.3.1\nGNU_PREFIX := arm-none-eabi" > /workspace/nrf5_sdk/components/toolchain/gcc/Makefile.posix \
     && wget https://developer.arm.com/-/media/Files/downloads/gnu-rm/6_1-2017q1/gcc-arm-none-eabi-6-2017-q1-update-linux.tar.bz2 \
     && tar xf gcc-arm-none-eabi-6-2017-q1-update-linux.tar.bz2 \

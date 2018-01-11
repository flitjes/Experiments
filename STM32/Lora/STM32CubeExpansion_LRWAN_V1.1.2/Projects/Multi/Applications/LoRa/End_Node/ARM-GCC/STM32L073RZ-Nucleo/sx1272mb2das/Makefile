######################################
# target
######################################
TARGET = End_Node


######################################
# building variables
######################################
# debug build?
DEBUG = 1
# optimization
OPT = -Og


#######################################
# paths
#######################################
# source path
SOURCES_DIR +=  \

# firmware library path
PERIFLIB_PATH = 

# Build path
BUILD_DIR = build

######################################
# source
######################################
# C sources
C_SOURCES +=  \
../../../../../../../../Drivers/CMSIS/Device/ST/STM32L0xx/Source/Templates/system_stm32l0xx.c \
../../../../../../../../Drivers/STM32L0xx_HAL_Driver/Src/stm32l0xx_hal.c \
../../../../../../../../Drivers/STM32L0xx_HAL_Driver/Src/stm32l0xx_hal_adc.c \
../../../../../../../../Drivers/STM32L0xx_HAL_Driver/Src/stm32l0xx_hal_adc_ex.c \
../../../../../../../../Drivers/STM32L0xx_HAL_Driver/Src/stm32l0xx_hal_cortex.c \
../../../../../../../../Drivers/STM32L0xx_HAL_Driver/Src/stm32l0xx_hal_dma.c \
../../../../../../../../Drivers/STM32L0xx_HAL_Driver/Src/stm32l0xx_hal_gpio.c \
../../../../../../../../Drivers/STM32L0xx_HAL_Driver/Src/stm32l0xx_hal_i2c.c \
../../../../../../../../Drivers/STM32L0xx_HAL_Driver/Src/stm32l0xx_hal_pwr.c \
../../../../../../../../Drivers/STM32L0xx_HAL_Driver/Src/stm32l0xx_hal_pwr_ex.c \
../../../../../../../../Drivers/STM32L0xx_HAL_Driver/Src/stm32l0xx_hal_rcc.c \
../../../../../../../../Drivers/STM32L0xx_HAL_Driver/Src/stm32l0xx_hal_rcc_ex.c \
../../../../../../../../Drivers/STM32L0xx_HAL_Driver/Src/stm32l0xx_hal_rtc.c \
../../../../../../../../Drivers/STM32L0xx_HAL_Driver/Src/stm32l0xx_hal_rtc_ex.c \
../../../../../../../../Drivers/STM32L0xx_HAL_Driver/Src/stm32l0xx_hal_spi.c \
../../../../../../../../Drivers/STM32L0xx_HAL_Driver/Src/stm32l0xx_hal_tim.c \
../../../../../../../../Drivers/STM32L0xx_HAL_Driver/Src/stm32l0xx_hal_tim_ex.c \
../../../../../../../../Drivers/STM32L0xx_HAL_Driver/Src/stm32l0xx_hal_uart.c \
../../../../../../../../Drivers/STM32L0xx_HAL_Driver/Src/stm32l0xx_hal_uart_ex.c \
../../../src/bsp.c \
../../../src/debug.c \
../../../src/hw_gpio.c \
../../../src/hw_rtc.c \
../../../src/hw_spi.c \
../../../src/main.c \
../../../src/stm32l0xx_hal_msp.c \
../../../src/stm32l0xx_hw.c \
../../../src/stm32l0xx_it.c \
../../../src/vcom.c \
../../../../../../../../Drivers/BSP/Components/hts221/HTS221_Driver.c \
../../../../../../../../Drivers/BSP/Components/hts221/HTS221_Driver_HL.c \
../../../../../../../../Drivers/BSP/Components/lps22hb/LPS22HB_Driver.c \
../../../../../../../../Drivers/BSP/Components/lps22hb/LPS22HB_Driver_HL.c \
../../../../../../../../Drivers/BSP/Components/lps25hb/LPS25HB_Driver.c \
../../../../../../../../Drivers/BSP/Components/lps25hb/LPS25HB_Driver_HL.c \
../../../../../../../../Drivers/BSP/Components/sx1272/sx1272.c \
../../../../../../../../Drivers/BSP/LRWAN_NS1/lrwan_ns1.c \
../../../../../../../../Drivers/BSP/LRWAN_NS1/lrwan_ns1_humidity.c \
../../../../../../../../Drivers/BSP/LRWAN_NS1/lrwan_ns1_pressure.c \
../../../../../../../../Drivers/BSP/LRWAN_NS1/lrwan_ns1_temperature.c \
../../../../../../../../Drivers/BSP/STM32L0xx_Nucleo/stm32l0xx_nucleo.c \
../../../../../../../../Drivers/BSP/sx1272mb2das/sx1272mb2das.c \
../../../../../../../../Middlewares/Third_Party/Lora/Core/lora.c \
../../../../../../../../Middlewares/Third_Party/Lora/Crypto/aes.c \
../../../../../../../../Middlewares/Third_Party/Lora/Crypto/cmac.c \
../../../../../../../../Middlewares/Third_Party/Lora/Mac/LoRaMac.c \
../../../../../../../../Middlewares/Third_Party/Lora/Mac/LoRaMacCrypto.c \
../../../../../../../../Middlewares/Third_Party/Lora/Utilities/delay.c \
../../../../../../../../Middlewares/Third_Party/Lora/Utilities/low_power.c \
../../../../../../../../Middlewares/Third_Party/Lora/Utilities/timeServer.c \
../../../../../../../../Middlewares/Third_Party/Lora/Utilities/utilities.c \
../../../../../../../../Middlewares/Third_Party/Lora/Mac/region/Region.c \
../../../../../../../../Middlewares/Third_Party/Lora/Mac/region/RegionAS923.c \
../../../../../../../../Middlewares/Third_Party/Lora/Mac/region/RegionAU915.c \
../../../../../../../../Middlewares/Third_Party/Lora/Mac/region/RegionCN470.c \
../../../../../../../../Middlewares/Third_Party/Lora/Mac/region/RegionCN779.c \
../../../../../../../../Middlewares/Third_Party/Lora/Mac/region/RegionCommon.c \
../../../../../../../../Middlewares/Third_Party/Lora/Mac/region/RegionEU433.c \
../../../../../../../../Middlewares/Third_Party/Lora/Mac/region/RegionEU868.c \
../../../../../../../../Middlewares/Third_Party/Lora/Mac/region/RegionIN865.c \
../../../../../../../../Middlewares/Third_Party/Lora/Mac/region/RegionKR920.c \
../../../../../../../../Middlewares/Third_Party/Lora/Mac/region/RegionUS915-Hybrid.c \
../../../../../../../../Middlewares/Third_Party/Lora/Mac/region/RegionUS915.c \

# ASM sources
ASM_SOURCES =  \
../startup_stm32l073xx.s


######################################
# firmware library
######################################
PERIFLIB_SOURCES = 


#######################################
# binaries
#######################################
BINPATH = /usr/bin/
PREFIX = arm-none-eabi-
CC = $(BINPATH)/$(PREFIX)gcc
AS = $(BINPATH)/$(PREFIX)gcc -x assembler-with-cpp
CP = $(BINPATH)/$(PREFIX)objcopy
AR = $(BINPATH)/$(PREFIX)ar
SZ = $(BINPATH)/$(PREFIX)size
HEX = $(CP) -O ihex
BIN = $(CP) -O binary -S
 
#######################################
# CFLAGS
#######################################
# cpu
CPU = -mcpu=cortex-m0plus

# fpu
# NONE for Cortex-M0/M0+/M3

# float-abi


# mcu
MCU = $(CPU) -mthumb $(FPU) $(FLOAT-ABI)

# macros for gcc
# AS defines
AS_DEFS = 

# C defines
C_DEFS =  \
-DUSE_HAL_DRIVER \
-DSTM32L073xx \
-DUSE_STM32L0XX_NUCLEO \
-DREGION_EU433 \

# AS includes
AS_INCLUDES = 

# C includes
C_INCLUDES +=  \
-I"../../../inc" \
-I"../../../../../../../../Drivers/BSP/STM32L0xx_Nucleo" \
-I"../../../../../../../../Drivers/STM32L0xx_HAL_Driver/Inc" \
-I"../../../../../../../../Drivers/CMSIS/Device/ST/STM32L0xx/Include" \
-I"../../../../../../../../Drivers/CMSIS/Include" \
-I"../../../../../../../../Middlewares/Third_Party/Lora/Crypto" \
-I"../../../../../../../../Middlewares/Third_Party/Lora/Mac" \
-I"../../../../../../../../Middlewares/Third_Party/Lora/Phy" \
-I"../../../../../../../../Middlewares/Third_Party/Lora/Utilities" \
-I"../../../../../../../../Middlewares/Third_Party/Lora/Core" \
-I"../../../../../../../../Drivers/BSP/Components/Common" \
-I"../../../../../../../../Drivers/BSP/Components/hts221" \
-I"../../../../../../../../Drivers/BSP/Components/lps22hb" \
-I"../../../../../../../../Drivers/BSP/Components/lps25hb" \
-I"../../../../../../../../Drivers/BSP/Components/sx1272" \
-I"../../../../../../../../Drivers/BSP/X_NUCLEO_IKS01A1" \
-I"../../../../../../../../Drivers/BSP/X_NUCLEO_IKS01A2" \
-I"../../../../../../../../Drivers/BSP/sx1272mb2das" \


# compile gcc flags
ASFLAGS = $(MCU) $(AS_DEFS) $(AS_INCLUDES) $(OPT) -Wall -fdata-sections -ffunction-sections

CFLAGS += $(MCU) $(C_DEFS) $(C_INCLUDES) $(OPT) -Wall -fdata-sections -ffunction-sections

ifeq ($(DEBUG), 1)
CFLAGS += -g -gdwarf-2
endif


# Generate dependency information
CFLAGS += -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)"


#######################################
# LDFLAGS
#######################################
# link script
LDSCRIPT = ../LRWAN-NS1/STM32L073RZTx_FLASH.ld

# libraries
LIBS = -lc -lm -lnosys
LIBDIR =
LDFLAGS = $(MCU) -specs=nano.specs -T$(LDSCRIPT) $(LIBDIR) $(LIBS) -Wl,-Map=$(BUILD_DIR)/$(TARGET).map,--cref -Wl,--gc-sections

# default action: build all
all: $(BUILD_DIR)/$(TARGET).elf $(BUILD_DIR)/$(TARGET).hex $(BUILD_DIR)/$(TARGET).bin


#######################################
# build the application
#######################################
# list of objects
OBJECTS = $(addprefix $(BUILD_DIR)/,$(notdir $(C_SOURCES:.c=.o)))
vpath %.c $(sort $(dir $(C_SOURCES)))
# list of ASM program objects
OBJECTS += $(addprefix $(BUILD_DIR)/,$(notdir $(ASM_SOURCES:.s=.o)))
vpath %.s $(sort $(dir $(ASM_SOURCES)))

$(BUILD_DIR)/%.o: %.c Makefile | $(BUILD_DIR) 
	$(CC) -c $(CFLAGS) -std=c99 -Wa,-a,-ad,-alms=$(BUILD_DIR)/$(notdir $(<:.c=.lst)) $< -o $@

$(BUILD_DIR)/%.o: %.s Makefile | $(BUILD_DIR)
	$(AS) -c $(CFLAGS) $< -o $@

$(BUILD_DIR)/$(TARGET).elf: $(OBJECTS) Makefile
	$(CC) $(OBJECTS) $(LDFLAGS) -o $@
	$(SZ) $@

$(BUILD_DIR)/%.hex: $(BUILD_DIR)/%.elf | $(BUILD_DIR)
	$(HEX) $< $@
	
$(BUILD_DIR)/%.bin: $(BUILD_DIR)/%.elf | $(BUILD_DIR)
	$(BIN) $< $@	
	
$(BUILD_DIR):
	mkdir $@		

#######################################
# clean up
#######################################
clean:
	-rm -fR .dep $(BUILD_DIR)
  
#######################################
# dependencies
#######################################
-include $(shell mkdir .dep 2>/dev/null) $(wildcard .dep/*)

# *** EOF ***

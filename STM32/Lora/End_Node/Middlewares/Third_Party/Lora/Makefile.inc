#######################################
# paths
#######################################
# source path
SOURCES_DIR =  \
Middlewares/Third_Party/Lora/Conf/Inc/ \
Middlewares/Third_Party/Lora/Core/ \
Middlewares/Third_Party/Lora/Crypto/ \
Middlewares/Third_Party/Lora/Mac/ \
Middlewares/Third_Party/Lora/Phy/ \
Middlewares/Third_Party/Lora/Utilities/ \

######################################
# source
######################################
# C sources
C_SOURCES += \
Middlewares/Third_Party/Lora/Crypto/aes.c \
Middlewares/Third_Party/Lora/Crypto/cmac.c \
Middlewares/Third_Party/Lora/Mac/LoRaMacCrypto.c \
Middlewares/Third_Party/Lora/Mac/LoRaMac.c \
Middlewares/Third_Party/Lora/Mac/region/RegionUS915.c \
Middlewares/Third_Party/Lora/Mac/region/RegionEU868.c \
Middlewares/Third_Party/Lora/Mac/region/RegionAU915.c \
Middlewares/Third_Party/Lora/Mac/region/RegionCN470.c \
Middlewares/Third_Party/Lora/Mac/region/RegionAS923.c \
Middlewares/Third_Party/Lora/Mac/region/RegionKR920.c \
Middlewares/Third_Party/Lora/Mac/region/Region.c \
Middlewares/Third_Party/Lora/Mac/region/RegionCN779.c \
Middlewares/Third_Party/Lora/Mac/region/RegionIN865.c \
Middlewares/Third_Party/Lora/Mac/region/RegionUS915-Hybrid.c \
Middlewares/Third_Party/Lora/Mac/region/RegionCommon.c \
Middlewares/Third_Party/Lora/Mac/region/RegionEU433.c \
Middlewares/Third_Party/Lora/Utilities/delay.c \
Middlewares/Third_Party/Lora/Utilities/timeServer.c \
Middlewares/Third_Party/Lora/Utilities/utilities.c \
Middlewares/Third_Party/Lora/Utilities/low_power.c \
Middlewares/Third_Party/Lora/Conf/Src/hw_gpio_template.c \
Middlewares/Third_Party/Lora/Conf/Src/hw_spi_template.c \
Middlewares/Third_Party/Lora/Conf/Src/hw_rtc_template.c \
Middlewares/Third_Party/Lora/Core/lora.c

# C defines
C_DEFS +=  \

# C includes
C_INCLUDES +=  \
-IMiddlewares/Third_Party/Lora/Conf/Inc/ \
-IMiddlewares/Third_Party/Lora/Core/ \
-IMiddlewares/Third_Party/Lora/Crypto/ \
-IMiddlewares/Third_Party/Lora/Mac/ \
-IMiddlewares/Third_Party/Lora/Phy/ \
-IMiddlewares/Third_Party/Lora/Utilities/ \


# *** EOF ***

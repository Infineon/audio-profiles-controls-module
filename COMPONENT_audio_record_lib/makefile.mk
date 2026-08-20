#
# $ Copyright 2016-YEAR Cypress Semiconductor $
#

NAME := audio_record_lib

COMMON_LIB_SRC := ../../../common/libraries/$(NAME)

$(NAME)_SOURCES := wiced_bt_audio_record.c
$(NAME)_SOURCES := pdm_aud_record.c

$(NAME)_SOURCES := $(addprefix $(COMMON_LIB_SRC)/,$($(NAME)_SOURCES))

########################################################################
################ DO NOT MODIFY FILE BELOW THIS LINE ####################
########################################################################
include $(LIBRARY_COMMON_MAKE)
